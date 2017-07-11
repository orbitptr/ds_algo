//reverse_a_Linked_List_in_groups_of_given_size
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
void addElemAtBegining(ListNode** tempListHead,ListNode** tempListTail, ListNode* temp){
	if(*tempListHead == NULL && *tempListTail == NULL){
		*tempListHead = temp;
		*tempListTail = temp;
		temp->next = NULL;
	}else{
		temp->next = *tempListHead;
		*tempListHead = temp;
	}
}
void mergeTempList(ListNode* tempListHead,ListNode* tempListTail,ListNode* lastTailNode,ListNode* currentNode,ListNode** mainList){
	if(lastTailNode == NULL){
		//firsttime
		*mainList = tempListHead;
		tempListTail->next=currentNode;
	}else{
		lastTailNode->next = tempListHead;
		tempListTail->next = currentNode;
	}
}
void reverseListByGroup(ListNode** mainList,int k){
	ListNode* currentNode = *mainList;
	if(currentNode == NULL || k ==0 || k==1){
		return;
	}else{
		int c=0;
		ListNode* tempListHead=NULL,*tempListTail=NULL;
		ListNode* lastTailNode=NULL;
		ListNode* nextNode=NULL;
		while(currentNode != NULL){
			nextNode=currentNode->next;			
			if(c<k){
				addElemAtBegining(&tempListHead,&tempListTail,currentNode);
				c++;
			}
			cout<<endl<<endl<<"Printing tempList:";
			printList(tempListHead);
			if(c>=k){
				mergeTempList(tempListHead,tempListTail,lastTailNode,nextNode,mainList);
				lastTailNode = tempListTail;
				tempListHead=NULL;
				tempListTail=NULL;
				c=0;
				cout<<endl<<"Printing MainList:";
				printList(*mainList);
			}
			currentNode=nextNode;
		}
		if(c>0){
			mergeTempList(tempListHead,tempListTail,lastTailNode,NULL,mainList);
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
	addValue(&num1,10);
	addValue(&num1,11);
	addValue(&num1,12);
	printList(num1);
	reverseListByGroup(&num1,3);
	printList(num1);
	return 0;
}
