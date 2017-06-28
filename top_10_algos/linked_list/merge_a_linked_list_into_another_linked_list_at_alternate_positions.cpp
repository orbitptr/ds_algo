//merge_a_linked_list_into_another_linked_list_at_alternate_positions
#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
};

ListNode* createNode(int val){
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->next = NULL;
	newNode->val = val;
	return newNode;
}

void addNode(ListNode** head, int val){
	ListNode* newNode = createNode(val);
	if(*head == NULL){
		*head = newNode;
		return;
	}else{
		ListNode* currentNode = *head;
		if(currentNode!= NULL && currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
		return;
	}
}
void printList(ListNode* head){
	ListNode* currentNode = head;
	cout<<endl<<"Printing List [";
	while(currentNode!= NULL){
		cout<<", "<<currentNode->val;
		currentNode=currentNode->next;
	}
	cout<<"]"<<endl;
}

void mergeAtAlternatePositions(ListNode** list1,ListNode** list2){
	if(*list1 == NULL){
		*list1 = *list2;
		return;
	}else{
		ListNode* currentNodeList1 = *list1;
		ListNode* currentNodeList2 = *list2;
		ListNode* temp=NULL;
		while(currentNodeList2  != NULL){			
			temp=currentNodeList2->next;
			currentNodeList2->next = currentNodeList1->next;
			currentNodeList1->next = currentNodeList2;
			currentNodeList1=currentNodeList2;
			currentNodeList2=temp;
			if(currentNodeList1 && currentNodeList1->next != NULL){
				currentNodeList1=currentNodeList1->next;
			}			
		}
		*list2=NULL;
	}
}

int main(){
	ListNode* list1=NULL;
	ListNode* list2=NULL;
	addNode(&list1,'a');
	addNode(&list1,'b');
	addNode(&list1,'c');
	printList(list1);
	addNode(&list2,'d');
	addNode(&list2,'e');
	addNode(&list2,'f');
	printList(list2);
	mergeAtAlternatePositions(&list1,&list2);
	printList(list1);
	printList(list2);
}