/*
------------------
Julian Stoev 11B #29
------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TABLE_SIZE 10
#define MAX_CAKES 100

pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;

int producedCake = 0;
int Table[TABLE_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void Mom(){
  int momPosition = -1;
  while(producedCake < MAX_CAKES){
    if(momPosition == TABLE_SIZE-1){
      momPosition = 0;
    } else {
      momPosition++;
    }
    printf("Mom checks if there is a cake on place %d on the table...\n", momPosition+1);
    if (Table[momPosition] == 1){
      pthread_mutex_lock(&count_mutex);
      printf("Mom watches TV...\n");
      pthread_cond_wait(&count_threshold_cv, &count_mutex);
      pthread_mutex_unlock(&count_mutex);
    }
    printf("Mom starts baking a cake\n");
    sleep(2);
    pthread_mutex_lock(&count_mutex);
    Table[momPosition] = 1;
    printf("Mom puts a cake on place %d on the table...\n", momPosition + 1);
    pthread_mutex_unlock(&count_mutex);
    pthread_cond_signal(&count_threshold_cv);
    producedCake++;
  }
}

void Ivan(){
  int ivanPosition = -1;
  while(producedCake < MAX_CAKES){
    if(ivanPosition == TABLE_SIZE-1){
      ivanPosition = 0;
    } else {
      ivanPosition++;
    }
    printf("Ivan checks if there is a cake on place %d on the table.\n", ivanPosition + 1);
    if (Table[ivanPosition] == 0){
      pthread_mutex_lock(&count_mutex);
      printf("Ivan goes to play.\n");
      pthread_cond_wait(&count_threshold_cv, &count_mutex);
      pthread_mutex_unlock(&count_mutex);
    }
    printf("Ivan is eating a cake.\n");
    sleep(1);
    pthread_mutex_lock(&count_mutex);
    Table[ivanPosition] = 0;
    printf("Ivan ate the cake on place %d on the table.\n", ivanPosition + 1);
    pthread_mutex_unlock(&count_mutex);
    pthread_cond_signal(&count_threshold_cv);
  }
}

int main(){
  int i;
  pthread_t threads[1];

  pthread_cond_init (&count_threshold_cv, NULL);
  pthread_mutex_init(&count_mutex, NULL);

  pthread_create(&threads[0], NULL, Mom,    NULL);
  pthread_create(&threads[1], NULL, Ivan, NULL);

  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);

  pthread_mutex_destroy(&count_mutex);
  pthread_cond_destroy(&count_threshold_cv);

  return 0;
}
