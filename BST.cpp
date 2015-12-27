#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;


bool BST::times_string_compare(tree_node *n1, tree_node *n2){ // bigger return true
	if(n1->times > n2->times){
		return true;
	}
	else if(n1->times < n2->times){
		return false;
	}
	else{
		return string_compare(n1,n2);
	}
}

bool BST::string_compare(tree_node *n1, tree_node *n2){ // 擺前面 return true
	int i = 1;
	int min;
	string *s1 = n1->word;
	string *s2 = n2->word;
	if(s1->size() <= s2->size()){
		min = s1->size();
	}
	else{
		min = s2->size();
	}
	if(s1[0] < s2[0]){ // a < b
		return true;
	}
	else if(s1[0] > s2[0]){ // b > a
		return false;
	}
	else{
		while(i < min){
			if(s1[i] < s2[i]){ // a < b
				return true;
			}
			else if(s1[0] > s2[0]){ // b > a
				return false;
			}
			else{
				i++;
			}
		}
		if(s1->size() == min){
			return true;
		}
		else{
			return false;
		}
	}
}