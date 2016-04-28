#include <stdio.h>
#include <stdlib>
#include <pthread.h>
//#include <math.h>
#define CAR_DRIVERS 5
#define CARS 3

pthread_mutex_t mutex;
int cars[CARS];

void* rent(void* person){
  int renter = (int)person;
  int i;
  while((cars[0] = 0)||(cars[1] = 0)||(cars[2] = 0)){
    
  }
}

int main(){

  pthread_mutex_init(&mutex, NULL);
  pthread_t treads[CAR_DRIVERS];
  int i;
  for(i = 0; i < CAR_DRIVERS; i++){
    if(pthread_create(threads[i], NULL, rent, i)){
      perror("Error while creating");
    }
  }
  for(i = 0; i < CAR_DRIVERS; i++){
    if(pthread_join(threads[i], NULL, rent, i)){
      perror("Error while creating");
    }
  }


  pthread_mutex_destroy();
  return 0;

}
