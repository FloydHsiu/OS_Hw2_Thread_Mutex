#include <iostream>
#include <fstream>
#include <string>
#include <pthread.h>
#include "Stack.h"

using namespace std;

pthread_t threads[3];
pthread_mutex_t mutex_sum;

Stack *word_stack = new Stack();

void *openfile(void *params);
bool IsInaWord(char c);
char ToLowerCase(char c);
void insertAllWords(ifstream &infile);

int main(int argc, char* argv[]){
	pthread_attr_t attr;

	pthread_mutex_init(&mutex_sum, NULL);
	pthread_attr_init(&attr);

	for(int i=0 ; i< argc-1 ; i++){
		pthread_create(&threads[i], &attr, openfile, argv[i+1]);
	}

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);

	for(int i=0; i < 4 ; i++){
		node* a = word_stack->pop();
		string *temp = a->word;
		cout << *temp << " " << a->times << endl;
	}

}

void *openfile(void *params){
	ifstream fp;
	string *temp = new string("");
	fp.open((char *)params);
	char c;
	if(fp.is_open()){
		while(fp){
			pthread_mutex_lock (&mutex_sum);
			//
			fp.get(c);
			while(IsInaWord(c)){
				c = ToLowerCase(c);
				temp->push_back(c);
				fp.get(c);
				if(!IsInaWord(c)){
					word_stack->push(temp);
					temp = new string("");
				}
			}
			pthread_mutex_unlock (&mutex_sum);
		}
	}
	else{

	}
	fp.close();
	pthread_exit(0);
}


void insertAllWords(ifstream &infile){
	string *temp = new string("");
	char c;
	while(infile){
		infile.get(c);
		while(IsInaWord(c)){
			c = ToLowerCase(c);
			temp->push_back(c);
			infile.get(c);
			if(!IsInaWord(c)){
				cout << temp << endl;
				temp = new string("");
			}
		}
	}
}

bool IsInaWord(char c){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z') || c == '\''){
		return true;
	}
	else{
		return false;
	}
}

char ToLowerCase(char c){
	int minus = 'A' - 'a';
	if(c >= 'A' && c<= 'Z'){
		c = c - minus;
	}
	return c;
}