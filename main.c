#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void *
Routine(void *arg) {
  const char *msg = (char *)arg;
  while (1) {
    printf("I am %s\n", msg);
    sleep(1);
  }
  return NULL;
}

int
main() {
  pthread_t tid[5];
  for (int i = 0; i < 5; ++i) {
    char *buffer = (char *)malloc(64);
    sprintf(buffer, "thread %d", i);
    pthread_create(&tid[i], NULL, Routine, buffer);
  }
  while (1) {
    printf("I am main thread!\n");
    sleep(2);
  }
  return 0;
}