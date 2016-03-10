#include <time.h>
#include <stdlib.h>
#include <stdio.h>


double bank_balance = 0.0;
double ivan_account = 0.0;
double petar_account = 0.0;

pthread_mutex_t mutex;

void deposit(double amount, double *to) {
	// Adds amount to account *to
	// Adds amount to total bank balance
  pthread_mutex_lock(&mutex);
  *to += amount;
  bank_balance += amount;
  pthread_mutex_unlock(&mutex);
//  return NULL;
}

void withdraw(double amount, double *from) {
	// Removes amount from account *from
	// Removes amount from total bank balance
  pthread_mutex_lock(&mutex);
  *from -= amount;
  bank_balance -= amount;
  pthread_mutex_unlock(&mutex);
//   return NULL;
}

void *ivan(void *arg) {
	int i;
	for(i = 0; i < 1000000; i++) {
		if(rand() % 2 <= 1) {
			deposit(rand() % 10000, &ivan_account);
		}
		else {
			withdraw(rand() % 10000, &ivan_account);
		}

	}
}

void *petar(void *arg) {
	int i;
	for(i = 0; i < 1000000; i++) {
		if(rand() % 1000 <= 500) {
			deposit(rand() % 10000, &petar_account);
		}
		else {
			withdraw(rand() % 10000, &petar_account);
		}
	}
}


int main() {
	srand(time(NULL));

	// Something very clever

  pthread_mutex_init(&mutex, NULL);

  pthread_t thread1;
  pthread_t thread2;

  pthread_create(&thread1, NULL, ivan, NULL);
  pthread_create(&thread2, NULL, petar, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  pthread_mutex_destroy(&mutex, NULL);
	printf("%f %f\n", (ivan_account + petar_account), bank_balance);

	return 0;
}
