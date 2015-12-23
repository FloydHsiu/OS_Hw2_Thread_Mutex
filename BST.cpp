#include <iostream>
#include "BST.h"
#include <cmath>
#include <string>

//maintain two binary search tree
//iterartor

BST::BST(){
	root = NULL;
}

void BST::insert(word_time data){
	leaf *node = root;
	int times;
	times = IsExistData(node, data->word);
	if(times){
		//如果單詞已存在，將原本的單詞的node, time+1之後重新insert
		this->Delete(data);
		data->times = times + 1;
		root = InsertRecursion(node, data)
	}
	else{
		root = InsertRecursion(node, data);
	}
}

leaf* BST::InsertRecursion(leaf *node, word_time data){
	if(node == NULL){
		 	//數字不存在，建立新的leaf
			leaf *temp = new leaf;
			temp->data = data;
			temp->left_subtree = NULL;
			temp->right_subtree = NULL;
			return temp;
	}
	if(data > node->data){
		node->right_subtree = InsertRecursion(node->right_subtree, data);
	}
	else if(data < node->data){
		node->left_subtree = InsertRecursion(node->left_subtree, data);
	}
	return node;
}

int BST::IsExistString(leaf *node,string *s){
	if(node==NULL){
		//Tree 是空的
		return 0;
	}
	if(s->compare(*(node->word))){
		//word 已經存在
		//回傳它已存在的次數
		return node->times;
	}
	else if(data > node->data){
		return IsExistData(node->right_subtree, data);
	}
	else{
		return IsExistData(node->left_subtree, data);
	}
}

bool BST::Delete(int data){
	if(IsExistData(root, data)){
		//數字存在才可以刪除
		root = deleteRecursion(root, data);
		return true;
	}
	else{
		return false;
	}
}
leaf* BST::deleteRecursion(leaf *node, int data){
	leaf *temp;
    if(data < node->data)
    {
            node->left_subtree = deleteRecursion(node->left_subtree, data);
    }
    else if(data > node->data)
    {
            node->right_subtree = deleteRecursion(node->right_subtree, data);
    }
    else
    {
        //兩片樹葉都存在 -> 可以取與它最近的值來替換，也就是左頁最大或右頁最小
        //這邊我取左頁最小來實作
        if(node->right_subtree && node->left_subtree)
        {
                /* Here we will replace with max element in the left_subtree */
                temp = GetMax(node->left_subtree);
                node -> data = temp->data; 
                /* As we replaced it with some other node, we have to delete that node */
                node -> left_subtree = deleteRecursion(node->left_subtree,temp->data);
        }
        else
        {
                /* If there is only one or zero children then we can directly 
                   remove it from the tree and connect its parent to its child */
                temp = node;
                if(node->left_subtree == NULL)
                        node = node->right_subtree;
                else if(node->right_subtree == NULL)
                        node = node->left_subtree;
                delete temp; /* temp is longer required */ 
        }
    }
    return node;
}

leaf* BST::GetNode(leaf *node, int data){
	if(data > node->data){
		return GetNode(node->right_subtree, data);
	}
	else if(data < node->data){
		return GetNode(node->left_subtree, data);
	}
	else{
		return node;
	}
}

leaf* BST::GetMax(leaf *node){
	if(node->right_subtree == NULL){
		return node;
	}
	else{
		return (GetMax(node->right_subtree));
	}
}

/*leaf* GetParent(leaf *parent, leaf *child, int data){
	//needs to check if data is existed in BST.
	if(data > child->data){
		return GetParent(child, child->right_subtree);
	}
	else if(data < child->data){
		return GetParent(child, child->left_subtree);
	}
	else{
		return parent;
	}

}*/

void BST::printBST(leaf *node){
	if(node==NULL)
	{
		return;
	}
    printBST(node->left_subtree);
    std::cout << node->data << " ";
    printBST(node->right_subtree);
}

void BST::printBST(){
	this->printBST(root);
}

int BST::TreeDegree(){//取的，樹有幾層
	int max = 0;
	if(root == NULL){

	}
	else{
		TreeDegree(root, &max, 1);
	}
	return max;
}

void BST::TreeDegree(leaf *node, int *max, int degree){
	if(node->left_subtree != NULL){
		TreeDegree(node->left_subtree, max, degree+1);
	}
	if(node->right_subtree != NULL){
		TreeDegree(node->right_subtree, max, degree+1);
	}
	if(!(node->right_subtree && node->right_subtree)){
		if(*max < degree){
			*max = degree;
		}
	}
}

void BST::printInLevel(){
	int Degree = this->TreeDegree();
	int size = std::pow(2, Degree) - 1;
	int *array = new int[size];
	for(int i=0; i<size ;i++){
		array[i] = 0;
	}
	printInLevel(array, root, 0);
	int k = 0;
	for(int i=0; i<Degree; i++){
		for(int j=0; j<std::pow(2,i); j++){
			if(array[k] == 0){
				
			}
			else{
				std::cout << array[k] << " ";
			}
			k ++;
		}
		std::cout << "| ";
	}
	std::cout << std::endl;
	delete[] array;
}
void BST::printInLevel(int *a, leaf *node, int n){
	if(node->left_subtree != NULL){
		printInLevel(a, node->left_subtree, 2*n+1);
	}
	if(node->right_subtree != NULL){
		printInLevel(a, node->right_subtree, 2*n+2);
	}
	a[n] = node->data;
	return;
}

void BST::computerize(int data){
	if(IsExistData(root, data)){
		leaf *temp = GetNode(root, data);
		int result = 0;
		computerize(&result, temp);
		std::cout << result << std::endl;
	}
	else{
		std::cout << "The data is not existed." << std::endl;
	}
}

void BST::computerize(int *result, leaf *node){
	if(node->left_subtree != NULL){
		computerize(result, node->left_subtree);
	}
	if(node->right_subtree != NULL){
		computerize(result, node->right_subtree);
	}
	*result += node->data;
}
