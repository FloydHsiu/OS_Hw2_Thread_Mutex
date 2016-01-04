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
	void _push(string *input);
	stack_node* _pop();

private:
	void insert(stack_node *front, stack_node *new_node);
	int next_not_null_dic(int index);
	int front_not_null_dic(int index);
	stack_node* get_front_tail(stack_node* start, stack_node *end);
	stack_node *dic[26];
	stack_node *root;
	stack_node *tail;
	stack_node *pop_root;
};
