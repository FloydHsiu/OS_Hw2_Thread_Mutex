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
	stack_node *dic[26];
	stack_node *root;
	stack_node *tail;
	stack_node *pop_index;//use to mantain the stack pop without change the root.
};