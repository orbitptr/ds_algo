//reverse_a_Linked_List_in_groups_of_given_size_recursion
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
ListNode* reverse(ListNode* currentStartNode,int k){
	if(currentStartNode == NULL){
		return NULL;
	}
	ListNode* currentNode = currentStartNode;
	ListNode* prev = NULL;
	ListNode* next = NULL;
	int c =0;
	while(currentNode != NULL &&  c<k){
		next=currentNode->next; //Backup the next
		currentNode->next = prev; //set current->next as prev ====> real code that does the job
		//Move current and previous
		//prev becomes current
		//current becomes the next which is in backup
		prev=currentNode; 
		currentNode=next;
		c++;
	}
	//reverse k nodes
	if(next != NULL)
	currentStartNode->next = reverse(next,k);
	return  prev;
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
	addValue(&num1,10);
	addValue(&num1,11);
	addValue(&num1,12);
	printList(num1);
	num1 = reverse(num1,3);
	printList(num1);
	return 0;
}
