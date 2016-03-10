#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define ARRAY_SIZE 10000

int sum = 0;

pthread_mutex_t mutex;

void *sumfunc1(void *p){
    int i;
    for(i = 0; i < ARRAY_SIZE/2; i++){
      pthread_mutex_lock(&mutex);
      sum += sin(i) * sin(i) + cos(i) * cos(i);
      pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *sumfunc2(void *p){
  int i;
  for(i = ARRAY_SIZE/2; i < ARRAY_SIZE; i++){
    pthread_mutex_lock(&mutex);
    sum += sin(i) * sin(i) + cos(i) * cos(i);
    pthread_mutex_unlock(&mutex);
    return NULL;
  }
}

int main(){
  pthread_mutex_init(&mutex, NULL);

  pthread_t thread1;
  pthread_t thread2;

  pthread_create(&thread1, NULL, sumfunc1, NULL);
  pthread_create(&thread2, NULL, sumfunc2, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("%d\n", sum);
}
