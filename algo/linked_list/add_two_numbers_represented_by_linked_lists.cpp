//add_two_numbers_represented_by_linked_lists
#include <iostream>
using namespace std;
struct  ListNode{
	int val;
	ListNode *next;
};

ListNode* createNode(int val){
	ListNode* newNode = (ListNode *) malloc(sizeof(ListNode));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}
void addValue(ListNode ** head,int val){
	if(*head == NULL){
		*head=createNode(val);
	}else{
		ListNode* currentNode = *head;
		ListNode* previousNode = *head;
		while(currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		ListNode* newNode = createNode(val);
		currentNode->next = newNode;
	}
}

void printList(ListNode* head){
	cout<<endl;
	cout<<"Printing List: [";
	while(head != NULL){
		cout<<", "<<head->val;
		head=head->next;
	}
	cout<<"]";
}

ListNode* sumLinkedList(ListNode **num1,ListNode **num2){
	int num1Size = 0;
	int num2Size = 0;
	ListNode * currentNode = *num1;
	while(currentNode != NULL){
		num1Size++;
		currentNode=currentNode->next;
	}
	currentNode = *num2;
	while(currentNode != NULL){
		num2Size++;
		currentNode=currentNode->next;
	}
	cout<<endl<<"num1Size:"<<num1Size<<" num2Size:"<<num2Size;

	//reverse List
	currentNode = *num1;
	ListNode * previousNode = NULL;
	ListNode * tempNode = NULL;
	while(currentNode != NULL){
		*num1=currentNode;
		//cout<<endl<<"currentNode->val:"<<currentNode->val;
		tempNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode=tempNode;

	}
	currentNode = *num2;
	previousNode = NULL;
	tempNode = NULL;
	while(currentNode != NULL){
		*num2=currentNode;
		tempNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode=tempNode;
	}
	printList(*num1);
	printList(*num2);

	int carry = 0;
	int currentSum = 0;
	ListNode * bigList = NULL;
	ListNode * smallList = NULL;
	if(num1Size>num2Size){
		bigList = *num1;
		smallList = *num2;
	}else if(num1Size<num2Size){
		bigList = *num2;
		smallList = *num1;
	}else if(num1Size == num2Size){
		bigList = *num1;
		smallList = *num2;
	}
	ListNode* currentBigListNode = bigList;
	ListNode* currentSmallListNode = smallList;
	ListNode* sumList = NULL;
	ListNode* sumListCurrentNode = NULL;
	int val2 = 0;
	while(currentBigListNode != NULL){

		if(currentSmallListNode != NULL){
			val2 = currentSmallListNode->val;
		}else{
			val2 = 0;
		}
		currentSum = carry+currentBigListNode->val+val2;
		carry = currentSum/10;

		if(carry >0)
		currentSum%=10;
		cout<<endl<<"currentSum:"<<currentSum<<" carry:"<<carry<<" currentSum:"<<currentSum;
		cout<<endl<<"currentBigListNode->val:"<<currentBigListNode->val<<" val2:"<<val2<<endl;
		if(sumList==NULL){
			sumList = createNode(currentSum);
			sumListCurrentNode = sumList;
		}else{
			ListNode* newNode = createNode(currentSum);
			sumListCurrentNode->next = newNode;
			sumListCurrentNode = newNode;
		}
		currentBigListNode=currentBigListNode->next;
		if(currentSmallListNode != NULL)
		currentSmallListNode=currentSmallListNode->next;
	}
	if(carry>0){
		ListNode* newNode = createNode(currentSum);
		sumListCurrentNode->next = newNode;
		sumListCurrentNode = newNode;
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl<<"Biglist";
	printList(bigList);
	cout<<endl<<"Smalllist";
	printList(smallList);
	cout<<endl<<"Sumlist";
	printList(sumList);
	cout<<endl;
	cout<<endl;
	cout<<endl;

	//Reverse all the lists back
	currentNode = *num1;
	previousNode = NULL;
	tempNode = NULL;
	while(currentNode != NULL){
		*num1=currentNode;
		tempNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode=tempNode;
	}
	currentNode = *num2;
	previousNode = NULL;
	tempNode = NULL;
	while(currentNode != NULL){
		*num2=currentNode;
		tempNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode=tempNode;
	}
	currentNode = sumList;
	previousNode = NULL;
	tempNode = NULL;
	while(currentNode != NULL){
		sumList=currentNode;
		tempNode = currentNode->next;
		currentNode->next = previousNode;
		previousNode = currentNode;
		currentNode=tempNode;
	}
	return sumList;
}

int main(){
	ListNode* num1 = NULL;
	ListNode* num2 = NULL;
	ListNode* sumList = NULL;
	addValue(&num1,5);
	addValue(&num1,1);
	addValue(&num1,2);
	addValue(&num1,2);
	addValue(&num1,1);
	addValue(&num1,3);
	printList(num1);
	addValue(&num2,2);
	addValue(&num2,1);
	addValue(&num2,2);
	addValue(&num2,2);
	addValue(&num2,1);
	printList(num2);
	sumList = sumLinkedList(&num1,&num2);
	cout<<endl<<"Sumlist";
	printList(sumList);
	return 0;
}
