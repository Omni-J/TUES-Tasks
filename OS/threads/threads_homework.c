#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUMBER_OF_THREADS 4

int tester(void *start_point) {
	int error_status = 0, i = (int)start_point;
  double j;
  //printf("Hello from thread %d\n", i);
	for (i; i < 100000000; i++) {
		j = (cos (i) * cos (i)) + (sin (i) * sin (i));
		if (j > 1.0005 || j < 0.9995) {
			error_status = 1;
			break;
		}
	}
  return error_status;
}

int main(){
  pthread_t threads[NUMBER_OF_THREADS];
  int i, start_point = 0;
  for( i = 0; i < NUMBER_OF_THREADS; i++){
    //printf("Creating thread %d\n", i);
    if(pthread_create(&threads[i], NULL, tester, (void*)start_point)){
      perror("Erorr while creating thread");
    }
    start_point+=25000000;
  }
  int final_result = 0;
  for (i = 0; i < NUMBER_OF_THREADS; i++){
    void *thread_result;
    pthread_join(threads[i], (void **)&thread_result);
    if(thread_result){
      final_result = 1;
    }
  }
  printf("%d\n", final_result);
  pthread_exit(NULL);
  return 0;
}
