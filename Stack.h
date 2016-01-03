#include <string>
#include <iostream>

using namespace std;

struct node{
	string *word;
	int times;
	struct node *next;
};

typedef struct node stack_node;

class Stack{
public:
	Stack();
	bool push(string *input);
	stack_node* pop();

private:
	stack_node *root;
	stack_node *tail;
};
