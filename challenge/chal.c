#include <stdlib.h>
#include <stdio.h>
#include<signal.h>

void win() {
  printf("\n\n");
  FILE *f = fopen("/flag", "r");
  if (f == NULL) {
    printf("You have successfully called win, but no flag file exists, create it and run the program again\n");
    return;
  }
  char flag[100];

  fgets(flag, 100, f);
  printf("yo nice, the flag is %s\n", flag);
}

void handler(int sig) {
  printf("\n\nSEGFAULT ;-;\n\nhint: winning address is %p", (void *)win);
  exit(1);
}

int main(int argc, char *argv[]) {
  char name[0x20];

  signal(SIGSEGV, handler);

  printf("Enter your name: ");
  fflush(stdout);
  scanf("%s", name);
  printf("Hello %s", name);
  fflush(stdout);

  return 0;
}
