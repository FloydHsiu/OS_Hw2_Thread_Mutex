#include <iostream>
#include <string>

using namespace std;

Stack::Stack(){
	for(int i=0; i<26; i++){
		dic[i] = NULL;
	}
	root = NULL;
}

bool Stack::push(string *input){
	char first_char = input->at(0);
	int dic_index = 'a' - first_char;
	node *start, *end;
	start = dic[dic_index];
	end = dic[dic_index]
}