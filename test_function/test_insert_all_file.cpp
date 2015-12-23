#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void insertAllWords(ifstream &infile);
bool IsInaWord(char c);
char ToLowerCase(char c);

int main(int argc, char* argv[]){
	ifstream infile;

	if(argc > 1){
		infile.open(argv[1]);

		if(!infile.is_open()){
			cout << "Read file error!";
		}
		else{
			insertAllWords(infile);
		}
	}
	infile.close();
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
				cout << *temp << endl;
				temp = new string("");
			}
		}
	}
}

bool IsInaWord(char c){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z') || (c == '\'')){
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