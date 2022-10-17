/*
Problem Statement - Implement C program to demonstrate Reader-Writer problem with readers having priority using counting semaphores and mutex.
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t wrt; // A binary semaphore that will be used both for mutual exclusion and signalling
pthread_mutex_t mutex; // Provides mutual exclusion when readcount is being modified
int cnt = 1;
int numreader = 0; // To keep count of the total readers

void *writer(void *wno) {
  sem_wait(&wrt); // when a wariter starts writing(readcount=0) then the first reader get blocked on wait(wrt) and this blocks all the readers.
  // write operation here
  cnt = cnt * 2;

  printf("\nWriter %d modified ", (*((int *)wno)));
  sem_post(&wrt); // signal(wrt)
  // return (void *)1;
}

void *reader(void *rno) {
  // reader acquire the lock before modifying numreader
  pthread_mutex_lock(&mutex);
  numreader++;
  if (numreader == 1) {
    sem_wait(&wrt); // if the first reader executes wait(wrt) operation before the writer does, then the writer gets blocked.
  }
  pthread_mutex_unlock(&mutex);

  printf("\nReader %d: read ", (*((int *)rno)));

  // reader acquire the lock before modifying numreader
  pthread_mutex_lock(&mutex);
  numreader--;
  if (numreader == 0) { // writer can only write when readcount is zero ie there are no readers waiting.
    sem_post(&wrt); // when the last reader exits, it call the signal(wrt) operation signalling writer to continue
  }
  pthread_mutex_unlock(&mutex);
  // return (void *)1;
}

int main() {
  int n1, n2;
  printf("Enter number of readers:");
  scanf("%d", &n1);
  printf("Enter number of writers:");
  scanf("%d", &n2);
  pthread_t read[n1], write[n2];
  pthread_mutex_init(&mutex, NULL);
  sem_init(&wrt, 0, 1);

  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // just used for numbering the producer and consumer

  for (int i = 0; i < n1; i++) {
    pthread_create(&read[i], NULL, reader, (void *)&a[i]);
  }
  for (int i = 0; i < n2; i++) {
    pthread_create(&write[i], NULL, writer, (void *)&a[i]);
  }

  for (int i = 0; i < n1; i++) {
    pthread_join(read[i], NULL);
  }
  for (int i = 0; i < n2; i++) {
    pthread_join(write[i], NULL);
  }

  pthread_mutex_destroy(&mutex);
  sem_destroy(&wrt);

  return 0;
}

/*

gcc 'Assignment 4b.c' -o 'Assignment 4b.out' -lpthread
./'Assignment 4b.out'

*/