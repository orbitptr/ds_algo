//delete_a_given_node_in_Linked_List_under_given_constraints
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

void deleteNode(ListNode** head,ListNode* nodeToDelete){
	if(nodeToDelete == NULL){
		cout<<endl<<"Node to delete is empty";
		return;
	}
	if(*head == NULL){
		cout<<endl<<"List is empty nothing to delete";
		return;
	}else{
		ListNode* currentNode = *head;
		ListNode* previousNode = currentNode;
		while(currentNode != nodeToDelete){
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
		if(currentNode != NULL){
			//delete here
			if(currentNode == *head){
				*head = currentNode->next;
				free(currentNode);
			}else{
				previousNode->next = currentNode->next;
				free(currentNode);
			}
		}else{
			cout<<endl<<"List is empty nothing to delete";
		}
	}
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
	deleteNode(&head,head);
	printList(head);
	deleteNode(&head,head->next->next->next);
	printList(head);
	return 0;
}
