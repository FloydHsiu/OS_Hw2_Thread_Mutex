#include <iostream>
#include <fstream>
#include <pthread.h>
#include <ctime>
#include <unistd.h>

using namespace std;

void *openfile(void *file_name);

int main(int argc, char* argv[]){
	pthread_t tid[2];
	pthread_attr_t attr;

	if(argc > 1){
		for(int i=0 ; i<2 ; i++){
			pthread_attr_init(&attr);
			pthread_create(&tid[i], &attr, openfile, argv[i+1]);
		}
	}
	for(int i=0; i <5 ;i++){
		sleep(1);
		cout << "Run front of join" << endl;
	}
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	for(int i=0; i<5 ;i++){
		sleep(1);
		cout << "Run after of join" << endl;
	}
	
}

void *openfile(void *filename){
	ifstream fp;
	time_t currtime;
	fp.open((char *)filename);
	if(fp.is_open()){
		cout << "it open!" << endl;
	}
	for(int i=0 ; i<5 ; i++){
		sleep(1);
		cout << "I'm in thread" << endl;
	}
	pthread_exit(0);
}