#include <string>
#include <iostream>

using namespace std;

struct node{
	string *word;
	int times;
	struct node *next;
};

typedef struct node node;

class Stack{
public:
	Stack();
	bool push(string *input);
	node* pop();

private:
	node *dic[26];
	node *root;
}