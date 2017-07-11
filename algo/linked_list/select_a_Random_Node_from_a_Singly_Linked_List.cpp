//select_a_Random_Node_from_a_Singly_Linked_List
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

ListNode* createNode(int val){
	ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

ListNode* addVal(ListNode** head,int newVal){
	ListNode* newNode = createNode(newVal);
	if(*head == NULL){
		*head = newNode;
		return newNode;
	}else{
		ListNode* currentNode = *head;
		while(currentNode->next != NULL){
			currentNode =currentNode->next;
		}
		currentNode->next = newNode;
		return newNode;
	}
}

void printList(ListNode* head){
	cout<<endl<<"PrintingList:[";
	while(head != NULL){
		cout<<" ,"<<head->val;
		head=head->next;
	}
	cout<<"]"<<endl;
}

void pickRandomNode(ListNode* head){
	ListNode* result = head;
	int n =2,j;
	ListNode* currentNode = head->next;
	srand((unsigned)time(NULL));
	while(currentNode!= NULL){
		j= (rand()%(n-1));
		if(j==0){
			result = currentNode;
		}
		n++;
		currentNode=currentNode->next;
	}
	cout<<endl<<"RandomNode:"<<(result->val);
}

int main(){
	ListNode* list1 = NULL;
	addVal(&list1,1);
	addVal(&list1,2);
	addVal(&list1,3);
	addVal(&list1,4);
	addVal(&list1,5);
	addVal(&list1,6);
	addVal(&list1,7);
	printList(list1);
	pickRandomNode(list1);
	return 0;
}