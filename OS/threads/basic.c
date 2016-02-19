#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#define NUM_OF_THREADS 5

void* test(void *p){
  int id = (int)p;
  int *result = malloc(sizeof(int));
  printf("Hello from thread %d\n", id);
  result = (id*id);
  return (void*)result;
}

int main(){

  pthread_t threads[NUM_OF_THREADS];
  int i;
  for (i = 0; i < NUM_OF_THREADS; i++){
    if (pthread_create(&threads[i], NULL, test, (void*)i)){
      perror("Error while creating");
    }
  }

  for (i = 0; i < NUM_OF_THREADS; i++){
    void *result;
    pthread_join(threads[i], (void**)&result);
    printf("Thread %d returned %d\n", i, result);
  }

  return 0;

}
