//merge_sort_linked_list
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

void splitListAndStore(ListNode* inputListHead,ListNode** firstList,ListNode** secondList){
	if(inputListHead == NULL){
		return;
	}
	ListNode* fast = inputListHead;
	ListNode* slow=inputListHead;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
	}
	*firstList = inputListHead;
	if(slow->next == NULL){
		//only 2 elements in the list
		*secondList=slow;
		(*firstList)->next=NULL;
	}else{
		*secondList = slow->next;
		slow->next=NULL;
	}
	
	
	
	return;
}

ListNode* mergeTwoSortedLinkedList(ListNode* firstList,ListNode* secondList){
	if(firstList == NULL){
		return secondList;
	}
	if(secondList == NULL){
		return firstList;
	}

	ListNode* result = NULL;
	if(firstList->val<=secondList->val){
		result = firstList;
		result->next = mergeTwoSortedLinkedList(result->next,secondList);
	}else{
		result = secondList;
		result->next=mergeTwoSortedLinkedList(firstList,result->next);
	}
	return result;
}

ListNode* mergeSortLinkedList(ListNode* inputList){
	cout<<endl<<"InputList";printList(inputList);
	//checking basic test cases
	if(inputList == NULL || inputList->next == NULL){
		return inputList;
	}
	ListNode* firstList=NULL;
	ListNode* secondList=NULL;
	splitListAndStore(inputList,&firstList,&secondList);
	cout<<endl<<"firstList";printList(firstList);
	cout<<endl<<"secondList";printList(secondList);

	firstList = mergeSortLinkedList(firstList);
	secondList = mergeSortLinkedList(secondList);
	return mergeTwoSortedLinkedList(firstList,secondList);
}

int main(){
	ListNode* num1 = NULL;
	addValue(&num1,5);
	addValue(&num1,5);
	addValue(&num1,5);
	addValue(&num1,21);
	addValue(&num1,5);
	addValue(&num1,5);
	addValue(&num1,5);
	addValue(&num1,4);
	addValue(&num1,3);
	addValue(&num1,2);
	addValue(&num1,1);
	printList(num1);
	num1 = mergeSortLinkedList(num1);
	printList(num1);
	return 0;
}
