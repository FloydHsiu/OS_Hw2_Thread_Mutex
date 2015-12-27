#include <iostream>
#include <string>

using namespace std;

bool string_compare(string *n1, string *n2);

int main(){
	string a("abcdabcd");
	string b("abcdabcda");
	string c("bbcdabcd");

	if(string_compare(&a,&b)){
		cout << a << " is 前面 " << b << endl;
	}
	else{
		cout << a << " is 後面 " << b << endl;
	}

	if(string_compare(&a,&c)){
		cout << a << " is 前面 " << c << endl;
	}
	else{
		cout << a << " is 後面 " << c << endl;
	}

	if(string_compare(&c,&a)){
		cout << c << " is 前面 " << a << endl;
	}
	else{
		cout << c << " is 後面 " << a << endl;
	}


}

bool string_compare(string *n1, string *n2){ //bigger return true
	int i = 1;
	int min;
	string *s1 = n1;
	string *s2 = n2;
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