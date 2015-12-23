#include <iostream>
#include <string>

struct word_time{
	string *word;
	int times;
};

struct node{
	struct word_time data;
	struct node left;
	struct node right;
};

typedef struct node leaf;
typedef struct word_time word_time;

using namespace std;

class BST{
public:
	BST();
	void insert(word_time data);
	bool Delete(word_time data);
	void printBST();

private:
	static void printBST(leaf *node);
	static bool compareTo(word_time d1, word_time d2);
	static int IsExistString(leaf *node, string *s);
	static leaf* InsertRecursion(leaf *node, word_time data);
	static leaf* deleteRecursion(leaf *node, word_time data);
	static leaf* GetMax(leaf *node);
	static leaf* GetNode(leaf *node, int data);
	leaf *root;
};