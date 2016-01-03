#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

Stack::Stack(){
	root = NULL;
	tail = NULL;
}

bool Stack::push(string *input){
	stack_node* temp = root;
	stack_node* new_node;

	while(!(temp == NULL)){
		if(temp->word->compare(*input) == 0){
			temp->times++;
			return true;
		}
		temp = temp->next;
	}//check if the string is exist, if exist -> times++ and return, else create a new stack_node

	new_node = new stack_node;
	new_node->word = input;
	new_node->times = 1;
	new_node->next = NULL;
	if(root == NULL){
		root = new_node;
	}
	else{
		tail->next = new_node;
	}
	tail = new_node;
	return true;
}

stack_node* Stack::pop(){
	stack_node* temp = root;
	if(temp != NULL){
		root = root->next;
		temp->next = NULL;
		return temp;
	}
	else{
		return NULL;
	}
}