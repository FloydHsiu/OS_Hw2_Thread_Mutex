#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

Stack::Stack(){
	for(int i=0; i<26; i++){
		dic[i] = NULL;
	}
	root = NULL;
	tail = NULL;
	pop_root = NULL;
}

bool Stack::push(string *input){
	stack_node* temp = root;
	stack_node* new_node;

	//check if the string is exist, if exist -> times++ and return, else create a new stack_node

	while(!(temp == NULL)){
		if(temp->word->compare(*input) == 0){
			temp->times++;
			return true;
		}
		temp = temp->next;
	}

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

void Stack::_push(string *input){
	int index = input->at(0) - 'a';
	stack_node *new_node;

	//先找後方第一個非NULL
	stack_node *end;
	int end_index = next_not_null_dic(index);
	if(end_index<26){
		end = dic[end_index];
	}
	else{
		end = NULL;
	}

	//往前方找第一個遇到的非NULL
	stack_node *start;
	int start_index = front_not_null_dic(index);
	if(start_index > -1){
		start = dic[start_index];
	}
	else{
		start = NULL;
	}

	//分成dic是不是NULL來處理
	if(dic[index] != NULL){
		//值可能存在
		stack_node *temp = dic[index];
		while(temp != end){
			if(temp->word->compare(*input) == 0){
				temp->times++;
				return ;
			}
			temp = temp->next;
		}
		//值不存在
		new_node = new stack_node;
		new_node->word = input;
		new_node->times = 1;
		new_node->next = NULL;
		insert(dic[index], new_node);
		return ;
	}
	else{

		if(start != NULL){
			//把new node接在start 尾巴的next, 其next 接end
			stack_node *temp = get_front_tail(start, end);
			new_node = new stack_node;
			new_node->word = input;
			new_node->times = 1;
			new_node->next = end;
			temp->next = new_node;
			dic[index] = new_node;//記錄進表中
			return ;
		}
		else{
			//新增node, 並將root設為此node
			new_node = new stack_node;
			new_node->word = input;
			new_node->times = 1;
			new_node->next = NULL;
			root = new_node;
			root->next = end;
			dic[index] = new_node;//記錄進表中
			pop_root = root;//pop_root 需和 root相同
			return ;
		}
	}
}

void Stack::insert(stack_node *front, stack_node *new_node){
	//將一個新的node插在front後面
	stack_node *temp = front->next;
	front->next = new_node;
	new_node->next = temp;
}

int Stack::next_not_null_dic(int index){
	//找出當下index之後第一個不是NULL的
	index++;
	while(index < 26){
		if(dic[index] != NULL){
			return index;
		}
		index++;
	}
	return 26;
}

int Stack::front_not_null_dic(int index){
	//找出當下index往前第一個非NULL
	index--;
	while(index > -1){
		if(dic[index] != NULL){
			return index;
		}
		index--;
	}
	return -1;
}

stack_node* Stack::get_front_tail(stack_node* start, stack_node *end){
	//取前方第一個非NULL的end
	stack_node *temp = start;
	while(temp->next != end){
		temp = temp->next;
	}
	return temp;
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

stack_node* Stack::_pop(){
	//針對最後可以輸入單字並搜尋次數的功能，對於pop所做的特化
	//以不更動原始root的方式取值
	stack_node* temp = pop_root;
	if(temp != NULL){
		pop_root = pop_root->next;
		return temp;
	}
	else{
		return NULL;
	}
}