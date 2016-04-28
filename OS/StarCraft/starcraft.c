/*
--------------------
Julian Stoev 11B grade
Starcraft 3 alpha design
--------------------
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int minerals = 5000;
int acq_minerals = 0;
int workers = 5;
int soldiers = 0;

pthread_mutex_t mutex;

void work(void *w){
  int id = (int)w;
  while((minerals>0)&&(soldiers<8)){
    printf("SCV %d is mining\n", id+1);
    pthread_mutex_lock(&mutex);
      acq_minerals += 8;
      minerals -= 8;
    pthread_mutex_unlock(&mutex);
    printf("SCV %d is transporting minerals\n", id+1);
    sleep(2);
    printf("SCV %d delivered minerals to Command center 1\n", id+1);
  }
}

int main(){
  int i;
  char s;
  pthread_mutex_init(&mutex, NULL);
  pthread_t worker_threads[workers];
  for(i = 0; i < workers; i++){
      if(pthread_create(&worker_threads[i], NULL, work, (void*)i)){
        perror("Error while creating worker");
      }
  }
/*
Apparenly std input does work when threads are joined

  for(i = 0; i < workers; i++){
    pthread_join(worker_threads[i], NULL);
  }
*/
  while(1){
    scanf("%s", &s);
    if(s == 'm'){
      if (acq_minerals < 50){
        printf("Not enough minerals\n");
      } else {
        acq_minerals -= 50;
        sleep(1);
        soldiers = soldiers + 1;
        printf("You want a piece of me, boy?\n");
      }
    } else {
      printf("No such command\n");
    }
    if (soldiers >= 8){
      break;
    }
  }
  acq_minerals = soldiers*50 + acq_minerals; // Otherwise wont count the used resources
  printf("Starting minerals: 5000\n");
  printf("Remaining minerals: %d\n", minerals);
  printf("Collected minerals: %d\n", acq_minerals);
  pthread_mutex_destroy(&mutex);

  return 0;
}
