#include <iostream>
using namespace std;
struct  ListNode{
	int val;
	struct ListNode *next;
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
		while(val>currentNode->val){
			previousNode = currentNode;
			currentNode = currentNode->next;
			if(currentNode == NULL) break;
		}
		if(previousNode->next == NULL){
			//reached end
			//insert at end
			ListNode* newNode = createNode(val);
			newNode->next = NULL;
			previousNode->next = newNode;
		}else if(previousNode == *head){
			//insert at start
			ListNode* newNode = createNode(val);
			newNode->next = *head;
			*head = newNode;
		}else{
			//insert after previous node
			ListNode* newNode = createNode(val);
			newNode->next = previousNode->next;
			previousNode->next = newNode;
		}
	}
}

void printList(ListNode* head){
	cout<<"Printing List: [";
	while(head != NULL){
		cout<<", "<<head->val;
		head=head->next;
	}
	cout<<"]";
}

int main(){
	ListNode* head = NULL;
	addValue(&head,5);
	addValue(&head,10);
	addValue(&head,2);
	addValue(&head,2);
	addValue(&head,2);
	addValue(&head,20);
	addValue(&head,11);
	printList(head);
	return 0;
}
