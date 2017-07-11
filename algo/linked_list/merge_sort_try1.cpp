#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;	
};

ListNode* createNode(int val);
void addNode(ListNode** head,int newVal);
void printList(ListNode* head);


ListNode* createNode(int val){
	ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

void addNode(ListNode** head,int newVal){
	ListNode* newNode = createNode(newVal);
	//ListEmpty
	if(*head == NULL){
		*head = newNode;
		return;
	}
	//list Not empty
	else{
		//find the last node
		ListNode* currentNode = *head;
		while(currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		//now the currentNode points to the last node
		currentNode->next = newNode;
		return;
	}
}

void printList(ListNode* head){
	cout<<endl<<"Printing List [";
	//traverse through the list once
	while(head!=NULL){
		cout<<", "<<head->val;
		head= head->next;
	}
	cout<<"]"<<endl;
}

void splitLists(ListNode** inputList,ListNode** firstList,ListNode** secondList){
	if(*inputList == NULL){
		return;
	}
	ListNode* fast = (*inputList)->next;
	ListNode* slow= (*inputList);
	while(fast!=NULL){
		fast=fast->next;
		if(fast!= NULL){
			fast=fast->next;
			slow=slow->next;
		}
	}
	(*firstList) = *inputList;
	(*secondList) = slow->next;
	if(slow != NULL){
		slow->next=NULL;
	}
}

ListNode* mergeSortedList(ListNode* firstList,ListNode* secondList){
	if(firstList == NULL){
		return secondList;
	}
	if(secondList == NULL){
		return firstList;
	}
	ListNode* result = NULL;
	if(firstList->val <= secondList->val){
		result = firstList;
		result->next=mergeSortedList(firstList->next,secondList);
	}else{
		result = secondList;
		result->next=mergeSortedList(firstList,secondList->next);
	}
	return result;
}

void mergeSort(ListNode** inputList){
	if((*inputList) == NULL || (*inputList)->next == NULL){
		return;
	}
	ListNode* firstList = NULL;
	ListNode* secondList = NULL;
	splitLists(inputList,&firstList,&secondList);
	mergeSort(&firstList);
	mergeSort(&secondList);
	*inputList=mergeSortedList(firstList,secondList);
}

int main(){
	ListNode* list1 = NULL;
	addNode(&list1,5);
	addNode(&list1,6);
	addNode(&list1,1);
	printList(list1);
	mergeSort(&list1);
	printList(list1);
	return 0;
}