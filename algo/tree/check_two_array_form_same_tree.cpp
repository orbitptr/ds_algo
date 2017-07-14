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
	// for (int i = 0; i<size; i++){
	//     cout<<" " << a[i];
	// }
	// cout<<endl;

	for(int i=starting_index;i<size;i++){
		// cout<<endl<<"finding min a[i]: "<<a[i];
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

int findFirst(int a[],int size,int starting_index,bool isMinSearch,int curr){
	// cout<<endl<<"finding min for value:"<<value<<endl;
	// for (int i = 0; i<size; i++){
	//     cout<<" " << a[i];
	// }
	// cout<<endl;

	for(int i=starting_index;i<size;i++){
		// cout<<endl<<"finding min a[i]: "<<a[i];
		if(isMinSearch){
			if(a[i]<curr) return i;
		}
		else{
			if(a[i]>curr) return i;
		}
	}
	return -1;
}

/*bool checkSameBST2(int t1[],int t2[],int r1,int r2,int s1,int s2,int prev){
	cout<<endl<<"staring with:"<<t1[r1]<<"<---->"<<t2[r2]<<" r1:"<<r1<<" r2:"<<r2 <<" prev:"<<prev;
	if((r1==-1)&&(r2==-1)) {cout<<endl<<"<-true ((r1==-1)&&(r2==-1))";return true;}// leaf node
	if((r1==-1)^(r2==-1)) {cout<<endl<<"<-false ((r1==-1)^(r2==-1))";return false;} // one have root value and other is not
	if(s1 != s2) {cout<<endl<<"<-false s1 != s2 ";return false;}
	// cout<<endl<<t1[r1]<<"<-->"<<t2[r2];
	if(t1[r1] != t2[r2]) {cout<<endl<<"<-false (t1[r1] != t2[r2]) ";return false;}


	int curr = t1[r1];
	bool isLeftSubtree = (curr<prev)?true:false;
	//left
	if(r1 == 0){
		int t1_min = findFirst(t1,s1,r1+1,true,curr);
		int t2_min = findFirst(t2,s2,r2+1,true,curr);
		if(!checkSameBST(t1,t2,t1_min,t2_min,s1,s2,curr)) 
			return false;
		int t1_max = findFirst(t1,s1,r1+1,false,curr);
		int t2_max = findFirst(t2,s2,r2+1,false,curr);
		if(!checkSameBST(t1,t2,t1_max,t2_max,s1,s2,curr))
			return false;
	}else{
		
		int t1_min = findFirst(t1,s1,r1+1,true,curr,prev,isLeftSubtree);
		int t2_min = findFirst(t2,s2,r2+1,true,curr,prev,isLeftSubtree);
		int t1_max = findFirst(t1,s1,r1+1,false,curr,prev,isLeftSubtree);
		int t2_max = findFirst(t2,s2,r2+1,false,curr,prev,isLeftSubtree);
		cout<<endl<<"             t1_min:"<<t1_min<<" t2_min:"<<t2_min<<" t1_max:"<<t1_max<<" t2_max:"<<t2_max;
		if(!checkSameBST(t1,t2,t1_min,t2_min,s1,s2,curr)) 
			return false;
		if(!checkSameBST(t1,t2,t1_max,t2_max,s1,s2,curr))
			return false;		
	}
	return true;
}*/

bool checkSameBST(int t1[],int t2[],int r1,int r2,int s1,int s2){
	cout<<endl<<"staring with:"<<t1[r1]<<"<---->"<<t2[r2]<<" r1:"<<r1<<" r2:"<<r2;
	if((r1==-1)&&(r2==-1)) {cout<<endl<<"<-true ((r1==-1)&&(r2==-1))";return true;}// leaf node
	if((r1==-1)^(r2==-1)) {cout<<endl<<"<-false ((r1==-1)^(r2==-1))";return false;} // one have root value and other is not
	if(s1 != s2) {cout<<endl<<"<-false s1 != s2 ";return false;}
	if(t1[r1] != t2[r2]) {cout<<endl<<"<-false (t1[r1] != t2[r2]) ";return false;}
	int curr = t1[r1];


	int t1_min = findFirst(t1,s1,r1+1,true,curr);
	int t2_min = findFirst(t2,s2,r2+1,true,curr);
	if(!checkSameBST(t1,t2,t1_min,t2_min,s1,s2)) 
		return false;
	int t1_max = findFirst(t1,s1,r1+1,false,curr);
	int t2_max = findFirst(t2,s2,r2+1,false,curr);
	if(!checkSameBST(t1,t2,t1_max,t2_max,s1,s2))
		return false;


	return true;
}
int printArrayWithIndex(int a[],int size){
	cout<<endl<<" [";
	for(int i=0;i<size;i++){
		cout<<" ("<<i<<')'<<a[i];
	}
	cout<<"]";
}
int main(){
	int a1[]={8,10,12,9,11,4,6,3,7};
	int a2[]={8,10,9,12,11,4,6,3,7};
	// int a2[]={8,10,4,7,11,9,12,3,6};


	// int a2[]={8,4,6,3,10,12,9,11,7};
	// int a2[]={8,4,7,3,10,12,9,11,6};
	int na1 = (sizeof(a1)/sizeof(int));
	int na2 = (sizeof(a2)/sizeof(int));
	printArrayWithIndex(a1,na1);
	printArrayWithIndex(a2,na2);
	BinaryTree t1(a1,na1);
	BinaryTree t2(a2,na2);
	t1.printLevelOrder();
	t2.printLevelOrder();
	// cout<<endl<<"checkSameBST - "<<checkSameBST(a1,a2,0,0,na1,na2,a1[0]);
	cout<<endl<<"checkSameBST2 - "<<checkSameBST(a1,a2,0,0,na1,na2);
	return 0;
}


















