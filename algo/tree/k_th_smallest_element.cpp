//check if two given arrays form the same binary tree
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

class BinaryTreeNode{
public:
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	int key;
	void print(){
		cout<<this->key<<' ';
	}
};
class BinaryTree{

	public:
	BinaryTreeNode* root;
	BinaryTree(){
		this->root = NULL;
	}
	BinaryTree(int a[],int size){
		this->root = NULL;
		cout<<endl<<"BinaryTree size:"<<size;
		for(int i=0;i<size;i++){
			this->root = insert(a[i]);
		}
	}
	BinaryTree(int key){
		this->root = NULL;
		this->root = newNode(key);
	}

	static BinaryTreeNode* newNode(int key){
		BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	BinaryTreeNode* insert(int key){
		return recursiveInsertImpl(this->root,key);
	}
	void printInorder(){
		cout<<endl<<"Inroder - [";
		printInorderRecursiveImpl(this->root);
		cout<<']';
	}
	void printPreorder(){
		cout<<endl<<"Preroder - [";
		printPreorderRecursiveImpl(this->root);
		cout<<']';
	}
	void printPostorder(){
		cout<<endl<<"Postorder - [";
		printPostorderRecursiveImpl(this->root);
		cout<<']';
	}

	BinaryTreeNode* deleteNode(int key){
		cout<<endl<<"Deleting - "<<key;
		this->root = deleteNodeImpl(this->root,key);
	}

	BinaryTreeNode* findInorderSuccessor(BinaryTreeNode* root){
		if(root == NULL) return NULL;
		BinaryTreeNode* searchedNode = findInorderSuccessor(root->left);
		return  (searchedNode == NULL)? root:searchedNode;
	}

	BinaryTreeNode* deleteNodeImpl(BinaryTreeNode* root,int key){
		if(root == NULL){
			return NULL;
		}
		if(key < root->key){
			root->left = deleteNodeImpl(root->left,key);
		}else if(key > root->key){
			root->right = deleteNodeImpl(root->right,key);
		}else if(root->key == key){
			if(root->left == NULL && root->right == NULL){
				//leaf
				cout<<endl<<"Deleting Leaf Node:"<<root->key;
				return NULL;
			}else if((root->left == NULL)^(root->right == NULL)){
				//ONE CHILD
				cout<<endl<<"Deleting non leaf with one node:"<<root->key;
				return (root->left!=NULL)?root->left:root->right;
			}else if((root->left != NULL)&&(root->right != NULL)){
				//2 child
				cout<<endl<<"Deleting non leaf with two node:"<<root->key;
				BinaryTreeNode* inorderSuccessor  = findInorderSuccessor(root->right);
				root->key = inorderSuccessor->key;
				deleteNodeImpl(root->right,inorderSuccessor->key);
				cout<<endl<<"inorderSuccessor:"<<inorderSuccessor->key;
				return root;
			}
		}
	}

	bool isPresent(int key){return isPresentImpl(this->root,key);}

	void printInorderRecursiveImpl(BinaryTreeNode* root){
		if(root == NULL) return;
		printInorderRecursiveImpl(root->left);
		root->print();
		printInorderRecursiveImpl(root->right);
	}

	void printPreorderRecursiveImpl(BinaryTreeNode* root){
		if(root == NULL) return;
		root->print();
		printInorderRecursiveImpl(root->left);
		printInorderRecursiveImpl(root->right);
	}

	void printPostorderRecursiveImpl(BinaryTreeNode* root){
		if(root == NULL) return;
		printInorderRecursiveImpl(root->left);
		printInorderRecursiveImpl(root->right);
		root->print();
	}

	BinaryTreeNode* recursiveInsertImpl(BinaryTreeNode* root,int key){
		if(root == NULL){
			return newNode(key);
		}
		if(key < root->key){
			root->left = recursiveInsertImpl(root->left,key);
		}else if(key > root->key){
			root->right = recursiveInsertImpl(root->right,key);
		}
		return root;
	}

	bool isPresentImpl(BinaryTreeNode* root,int key){
		if(root == NULL) return false;
		if(root->key == key) return true;
		if(key < root->key) if(isPresentImpl(root->left,key) == true)  return true;
		if(key > root->key) if(isPresentImpl(root->right,key) == true)  return true;
		return false;
	}

	void printLevelOrder(){
		queue<BinaryTreeNode*> q;
		q.push(this->root);
		cout<<endl<<"Level Order";
		int qlenght = 0;
		while(!q.empty()){
			qlenght = q.size();
			if(qlenght>0)
			cout<<endl<<"[";
			for(int i=0;i<qlenght;i++){
				BinaryTreeNode* currentNode = q.front();q.pop();
				currentNode->print();
				if(currentNode->left != NULL) q.push(currentNode->left);
				if(currentNode->right != NULL) q.push(currentNode->right);
			}
			cout<<"]";
			
		}
	}

	void printInorderWithStack(){
		stack<BinaryTreeNode*> stack;
		BinaryTreeNode* current = this->root;
		cout<<endl<<"Inorder with stack - [";
		bool done = false;
		while(!done){
			while(current!= NULL){
				stack.push(current);
				current = current->left;
			}
			if(!stack.empty()){
				current = stack.top();
				stack.pop();
				current->print();
				current=current->right;
			}else done = true;
		}
		cout<<']';
	}

	void printInorderWithoutRecursionNoStack(){
		BinaryTreeNode* pre= NULL;
		BinaryTreeNode* current = this->root;
		cout<<endl<<"Inorder Morris - [";
		while(current != NULL){
			if(current->left != NULL){
				pre = current->left;
				while(pre->right != NULL && pre->right != current) pre = pre->right;
				if(pre->right == NULL){
					pre->right = current;
					current=current->left;
				}else{
					current->print();
					current=pre->right->right;
					pre->right = NULL;
				}
			}else{
				current->print();
				current=current->right;
			}
		}
		cout<<']';
	}
};


int findFirst(int a[],int size,int starting_index,bool isMinSearch,int curr,int prev,bool isLeftSubtree){
	cout<<endl<<"finding min for curr:"<<curr<<" prev:"<<prev<<endl;
	for(int i=starting_index;i<size;i++){
		if(isMinSearch){
			if(isLeftSubtree){
				if(a[i]<curr){ return i;}
			}else{
				if((a[i]<curr) && (a[i] > prev)){ return i;}
			}
		}
		else{
			if(isLeftSubtree){
				if((a[i]>curr) && (a[i] < prev)){ return i;}
			}else{
				if(a[i]>curr){ return i;}
			}
		}
	}
	return -1;
}
BinaryTreeNode* getElement(BinaryTreeNode* root,int *k){
	if(root == NULL) return NULL;		
	BinaryTreeNode* result = NULL;
	result = getElement(root->left,k);
	if(result != NULL) return result;
	*k = (*k)-1;
	if(*k==0){
		return root;
	}
	result = getElement(root->right,k);
	if(result != NULL) return result;
}

int main(){
	// int a1[]={8,10,12,9,11,4,6,3,7};
	int a1[]={20,8,22,4,12,10,14};
	int na1 = (sizeof(a1)/sizeof(int));
	BinaryTree t1(a1,na1);
	t1.printLevelOrder();
	int k = 4;
	cout<<endl<<getElement(t1.root,&k)->key;	
	return 0;
}


















