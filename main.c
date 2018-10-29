#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

long random() {
  int a = open("/dev/random", O_RDONLY);
  int c;
  int b = read(a, &c, sizeof(c));
  close(a);
  return c;
}

int main(){

  printf("Generating random numbers.\n");
  int array[10];
  for (int i = 0; i < 10; i++) {
    array[i] = random();
    printf("Random number %d: %d\n",i, array[i]);
  }

  int text = open("hello.txt", O_RDWR);
  int b = write( text, array, sizeof(array) );
  printf("\nWriting numbers to file.\n\n");

  int array2[10];
  int d = read(text, array2, sizeof(int));
  printf("Reading numbers from file.\n\n");

  printf("Verication that written values are the same.\n");
  for (int j = 0; j < 10; j++) {
    printf("Random number %d: %d\n",j, array[j]);
  }
  close(text);

  return 0;
}
