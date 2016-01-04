#include <iostream>
#include <string>

using namespace std;

struct tree_node{
	string *word;
	int times;
	//用來以times優先,string第二搜尋
	struct tree_node *left;
	struct tree_node *right;
	//用來以string搜尋
	struct tree_node *dic_left;
	struct tree_node *dic_right;
};

typedef struct tree_node tree_node;

class BST{
public:
	BST();
	void insert(string *s, int times);
	void printBST();
	void printBST_terminal();

private:
	tree_node* root;
	tree_node* InsertRecursion(tree_node *node, tree_node *new_node);
	static bool times_string_compare(tree_node *n1, tree_node *n2);
	static bool string_compare(tree_node *n1, tree_node *n2);
	void printBST(tree_node *node, ofstream &fp);
	void printBST_terminal(tree_node *node);
};