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

void splitList(ListNode** inputHead,ListNode** firstList,ListNode** secondList){
	if(*inputHead==NULL) {
		*firstList = NULL;
		*secondList = NULL;
	}
	ListNode* fast = (*inputHead)->next;
	ListNode* slow = (*inputHead);
	while(fast!= NULL){
		fast = fast->next;
		if(fast != NULL){
			fast=fast->next;
			slow=slow->next;
		}
	}
	*firstList = *inputHead;
	*secondList = slow->next;
	slow->next = NULL;
}

ListNode* mergeListBySorting(ListNode* firstList,ListNode* secondList){
	if(firstList == NULL){
		return secondList;
	}
	if(secondList == NULL){
		return firstList;
	}

	ListNode* result = NULL;
	if(firstList->val<=secondList->val){
		result = firstList;
		result->next = mergeListBySorting(firstList->next,secondList);
	}else{
		result = secondList;
		result->next = mergeListBySorting(firstList,secondList->next);
	}
	return result;
}

void mergeSort(ListNode** inputHead){
	if((*inputHead) == NULL || (*inputHead)->next==NULL){
		return;
	}
	ListNode* firstList = NULL;
	ListNode* secondList = NULL;
	splitList(inputHead,&firstList,&secondList);

	mergeSort(&firstList);
	mergeSort(&secondList);
	*inputHead = mergeListBySorting(firstList,secondList);
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

ListNode* getIntersect(ListNode* num1,ListNode* num2){
	ListNode* result = NULL;
	
	if(num1==NULL || num2 == NULL){
		cout<<"case5";
		return NULL;
	}else{
		cout<<endl<<"getIntersect:Num1->val:"<<num1->val<<" Num2->val:"<<num2->val;
		cout<<"case1";
		if(num1->val == num2->val){
			cout<<"case2";
			cout<<"<<equal";
			result = createNode(num1->val);
			result->next = getIntersect(num1,num2->next);
		}else{
			if(num1->val<num2->val){
				cout<<"case4";
				result = getIntersect(num1->next,num2);
			}else{
				cout<<"case5";
				result = getIntersect(num1,num2->next);
			}
		}

	}
	cout<<endl<<"returning result "<<result;
	return result;
}

ListNode* getUnion(ListNode* num1,ListNode* num2){
	ListNode* result = NULL;
	ListNode* resulttail = NULL;
	ListNode* newNode = NULL;
	while(num1 != NULL || num2 != NULL){
		if(num1 == NULL && num2 != NULL ){
			cout<<endl<<"case1";
			newNode = createNode(num2->val);
			num2=num2->next;
		}else if(num1 != NULL && num2 == NULL){
			cout<<endl<<"case2";
			newNode = createNode(num1->val);
			num1=num1->next;
		}else{
			cout<<endl<<"case3"<<" ["<<num1->val<<","<<num2->val<<"] ";
			printList(result);
			//both have value
			if(num1->val>num2->val){
				if(resulttail==NULL || resulttail->val != num2->val){
					newNode = createNode(num2->val);
				}
				num2=num2->next;
			}else if(num2->val>num1->val){
				if(resulttail==NULL || resulttail->val != num1->val){
					newNode = createNode(num1->val);
				}
				num1=num1->next;
			}else{
				//equal
				if(resulttail==NULL || resulttail->val != num1->val){
					newNode = createNode(num1->val);
				}
				num1=num1->next;
				// num2=num2->next;
			}
		}
		if(newNode != NULL){
			if(result == NULL){
				result = newNode;
				resulttail = newNode;
			}else{
				resulttail->next = newNode;
				resulttail = newNode;
			}
			newNode = NULL;
		}
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

	addValue(&num2,3);
	addValue(&num2,3);
	addValue(&num2,3);
	addValue(&num2,10);
	
	printList(num1);
	printList(num2);
	mergeSort(&num1);
	mergeSort(&num2);
	printList(num1);
	printList(num2);
	cout<<endl<<"List sorted";

	ListNode* unionList =  getUnion(num1,num2);
	ListNode* intersectList =  getIntersect(num1,num2);
	cout<<endl;
	cout<<endl;
	cout<<"union";
	printList(unionList);
	printList(intersectList);
	return 0;
}
