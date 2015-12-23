#include <iostream>
#include <string>

using namespace std;
int main(){
	string *s = new string("hahaha");
	string *s2 = new string("hahaha");
	string *s3 = new string("hehehe");
	cout << *s;
	//s->insert(s->end(), "insertinsert");
	s->append("a");
	s->push_back('c');
	cout << *s << endl;
	cout << s->at(0);
	if(s->compare(*s2) == 0){
		cout << "same";
	}
	else{
		cout << "not same";
	}
	if(s->compare(*s3) == 0){
		cout << "same";
	}
	else{
		cout << "not same";
	}
}
