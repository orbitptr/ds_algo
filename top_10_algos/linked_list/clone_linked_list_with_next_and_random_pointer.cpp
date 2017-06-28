//Clone_linked_list_with_next_and_random_pointer
#include <iostream>
using namespace std;
struct  ListNode{
	int val;
	ListNode *next;
	ListNode* arbit;
};

ListNode* createNode(int val){
	ListNode* newNode = (ListNode *) malloc(sizeof(ListNode));
	newNode->val = val;
	newNode->next = NULL;
	newNode->arbit = NULL;
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
	cout<<endl;
	cout<<"Printing List: [";
	while(head != NULL){
		cout<<", "<<head->val;
		if(head->arbit != NULL) cout<<"->"<<head->arbit->val;
		head=head->next;
	}
	cout<<"]";
}

void cloneList(ListNode **original,ListNode ** copy){
	ListNode* current = *original;
	while(current != NULL){
		ListNode* dup = createNode(current->val);
		//if(current->arbit != NULL) dup->arbit = current->arbit->next;
		dup->next = current->next;
		current->next = dup;
		current = dup->next;
	}

	current = *original;
	while(current != NULL){
		ListNode* dup = current->next;
		if(current->arbit != NULL) dup->arbit = current->arbit->next;
		current = dup->next;
	}


	printList(*original);
	current = *original;
	*copy = (*original)->next;
	while(current != NULL){
		ListNode* dup = current->next;
		if(dup != NULL){
			if(dup->next != NULL){
				current->next = dup->next;
				current = current->next;
				dup->next = dup->next->next;
			}
			else{
				current->next = NULL;
				current = NULL;

			}
		}
	}
}

int main(){
	ListNode* head = NULL;
	ListNode* copy = NULL;
	addValue(&head,5);
	addValue(&head,10);
	addValue(&head,2);
	addValue(&head,20);
	addValue(&head,11);
	head->arbit=head->next->next;
	head->next->arbit=head;
	head->next->next->arbit = head;
	printList(head);
	cloneList(&head,&copy);
	printList(head);
	printList(copy);
	return 0;
}
