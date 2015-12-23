#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void *thread_a(void *params);

int sum = 0;
pthread_t threads[3];
pthread_mutex_t mutex_sum;

int main(){
	pthread_attr_t attr;

	pthread_mutex_init(&mutex_sum, NULL);
	pthread_attr_init(&attr);

	for(int i=0; i<3 ;i++){
		pthread_create(&threads[i], &attr, thread_a, (void *)i);
	}

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
}

void *thread_a(void* params){
	int input = (int)params;
	pthread_mutex_lock (&mutex_sum);
	sum = sum + 1;
	sleep(input);
	cout << sum << endl;
	pthread_mutex_unlock (&mutex_sum);
	pthread_exit(0);
};