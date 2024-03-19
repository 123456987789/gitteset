#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int g_val = 100;

int
main() {
  pid_t id = vfork();
  if (id == 0) {
    g_val = 200;
    exit(0);
  }
  sleep(3);
  printf("g_val: %d\n", g_val);
  return 0;
}