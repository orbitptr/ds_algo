//merge_sort_linked_list_practice_1.cpp
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

ListNode* createNode(int val){
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->val = val;
	//initialize all the remaining pointers and data to default value very important
	newNode->next=NULL;
	return newNode;
}

void addNode(ListNode** list,int newVal){
	ListNode* newNode = createNode(newVal);
	if(*list == NULL){
		//empty List
		*list = newNode;
	}else{
		ListNode* currentNode = *list;
		while(currentNode->next !=NULL){
			currentNode=currentNode->next;
		}
		//now the currentNode is pointing to the last node
		currentNode->next = newNode;
	}
}

void printList(ListNode* input){
	cout<<endl<<"Printing List [";
	while(input != NULL){
		cout<<", "<<input->val;
		input=input->next;
	}
	cout<<"]"<<endl;
}

void splitAndStore(ListNode* sourceListHead, ListNode** firstList,ListNode** secondList){
	// if(sourceListHead == NULL){
	// 	return;
	// }
	ListNode* fast = sourceListHead->next;
	ListNode*  slow = sourceListHead;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
	}
	*firstList = sourceListHead;
	*secondList=slow->next;
	slow->next=NULL;
}



ListNode* sortAndMergeRecursively(ListNode* firstList,ListNode* secondList){
	if(firstList == NULL){
		return secondList;
	}
	if(secondList == NULL){
		return firstList;
	}
	ListNode* currentNodeResult = NULL;
	if(firstList->val<=secondList->val){
		currentNodeResult = firstList;
		currentNodeResult->next = sortAndMergeRecursively(firstList->next,secondList);
	}else{
		currentNodeResult = secondList;
		currentNodeResult->next = sortAndMergeRecursively(firstList,secondList->next);
	}
	return currentNodeResult;
}


ListNode* mergeSort(ListNode* input){
	//checking the basic cases
	if(input == NULL || input->next == NULL){
		return input;
	}
	ListNode* firstList = NULL;
	ListNode* secondList = NULL;
	splitAndStore(input,&firstList,&secondList);

	firstList = mergeSort(firstList);
	secondList = mergeSort(secondList);
	
	return sortAndMergeRecursively(firstList,secondList);
}

int main(){
	ListNode* list1 = NULL;
	addNode(&list1,4);
	addNode(&list1,2);
	addNode(&list1,3);
	addNode(&list1,1);
	addNode(&list1,4);
	printList(list1);
	list1=mergeSort(list1);
	printList(list1);
	return 0;
}