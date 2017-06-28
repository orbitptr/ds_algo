//detect_and_Remove_Loop_in_a_Linked_List
//union_and_Intersection_of_two_Linked_Lists_merge_sort
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
ListNode* addValue(ListNode ** head,int val){
	ListNode* newNode = createNode(val);
	if(*head == NULL){
		*head=newNode;
	}else{
		ListNode* currentNode = *head;
		ListNode* previousNode = *head;
		while(currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
	return newNode;
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

void detectAndRemoveLoop(ListNode* head){
	ListNode* slow = head;
	ListNode* fast = head;
	int count = 0;
	while(fast != NULL){
		count++;
		fast=fast->next;
		
		if(fast != NULL){
			fast=fast->next;
			slow=slow->next;
		}
		cout<<endl<<(slow->val)<<":"<<(fast->val);
		if(fast == slow){
			cout<<endl<<"Loop Node detected:"<<(slow->val)<<" loop count:"<<count;
			return;
		}
	}
}

int main(){
	ListNode* num1 = NULL;
	addValue(&num1,1);
	addValue(&num1,2);
	addValue(&num1,3);
	addValue(&num1,4);
	addValue(&num1,5);
	addValue(&num1,6);
	addValue(&num1,7);
	addValue(&num1,8);
	addValue(&num1,9);
	ListNode* loopstart= addValue(&num1,10);
	addValue(&num1,11);
	addValue(&num1,12);
	addValue(&num1,13);
	addValue(&num1,14);
	addValue(&num1,15);
	ListNode* loopend = addValue(&num1,16);
	loopend->next = loopstart;
	//printList(num1);
	detectAndRemoveLoop(num1);
	return 0;
}
