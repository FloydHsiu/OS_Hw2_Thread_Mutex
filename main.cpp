#include <iostream>
#include <fstream>
#include <string>
#include <pthread.h>
#include "Stack.h"
#include "BST.h"

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

	BST *tree = new BST();
	string *temp_s;
	int times;

	pthread_mutex_init(&mutex_sum, NULL);
	pthread_attr_init(&attr);


	for(int i=0 ; i< argc-1 ; i++){
		pthread_create(&threads[i], &attr, openfile, argv[i+1]);
	}

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);

	stack_node *temp = word_stack->pop();
	while(temp != NULL){
		temp_s = temp->word;
		times = temp->times;
		tree->insert(temp_s, times);
		temp = word_stack->pop();
	}

	tree->printBST();
	

}

void *openfile(void *params){
	ifstream fp;
	string *temp = new string("");
	fp.open((char *)params);
	char c;
	if(fp.is_open()){
		while(fp){
			pthread_mutex_lock (&mutex_sum);
			//執行到這裡讓其他thread暫停，等待這邊執行，以防止衝突
			fp.get(c);
			while(IsInaWord(c)){
				c = ToLowerCase(c);
				temp->push_back(c);
				fp.get(c);
				if(!IsInaWord(c)){
					if(!(temp->compare("\'"))){//only ' is not a word
						
					}
					else if(temp->at(0) == '\''){
						temp->erase(0,1);
						word_stack->_push(temp);
					}
					else{
						word_stack->_push(temp);
					}
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