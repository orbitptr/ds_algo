//union_and_Intersection_of_two_Linked_Lists
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
int isPresent(ListNode* head,int val){
	while(head!=NULL){
		if(head->val == val) return 1;
		head=head->next;
	}
	return 0;
}

ListNode* getUnion(ListNode* num1,ListNode* num2){
	ListNode* result = NULL;
	while(num1 != NULL){
		if(!isPresent(result,num1->val)){
			addValue(&result,num1->val);
		}
		num1=num1->next;
	}
	while(num2 != NULL){
		if(!isPresent(result,num2->val)){
			addValue(&result,num2->val);
		}
		num2=num2->next;
	}
	return result;
}

ListNode* getIntersect(ListNode* num1,ListNode* num2){
	ListNode* result = NULL;
	while(num1 != NULL){
		if(isPresent(num2,num1->val)){
			addValue(&result,num1->val);
		}
		num1=num1->next;
	}
	return result;
}

int main(){
	ListNode* num1 = NULL;
	ListNode* num2= NULL;
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
	addValue(&num2,4);
	addValue(&num2,2);
	addValue(&num2,3);
	addValue(&num2,20);
	printList(num2);
	ListNode* unionList = getUnion(num1,num2);
	ListNode* intersectList = getIntersect(num1,num2);
	cout<<endl<<endl<<"unionList";printList(unionList);
	cout<<endl<<endl<<"intersectList";printList(intersectList);
	return 0;
}
