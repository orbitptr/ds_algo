//compare_two_strings_represented_as_linked_lists
#include <iostream>
using namespace std;
struct ListNode{
	char c;
	ListNode* next;
};

ListNode* createNode(char c){
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->next = NULL;
	newNode->c = c;
	return newNode;
}

void addNode(ListNode** head, char c){
	ListNode* newNode = createNode(c);
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
		cout<<", "<<currentNode->c;
		currentNode=currentNode->next;
	}
	cout<<"]"<<endl;
}

int lexographicCompare(ListNode* str1,ListNode* str2){
	while(str1 && str2 && str1->c == str2->c){
		str1=str1->next;
		str2=str2->next;
	}
	if(str1 && str2){
		return (str1->c > str2->c)?1:-1;
	}
	if(str1 && !str2){
		return 1;
	}
	if(str2 && !str1){
		return -1;
	}
	return 0;
}

int main(){
	ListNode* str1=NULL;
	ListNode* str2=NULL;
	addNode(&str1,'a');
	addNode(&str1,'b');
	addNode(&str1,'c');
	printList(str1);
	addNode(&str2,'a');
	addNode(&str2,'b');
	addNode(&str2,'c');
	printList(str2);
	cout<<endl<<"lexographic compare:"<<lexographicCompare(str1,str2);
}