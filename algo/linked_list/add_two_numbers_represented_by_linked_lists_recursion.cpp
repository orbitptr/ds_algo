//add_two_numbers_represented_by_linked_lists_recursion
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

void addNode(ListNode ** head,int val){
	ListNode* newNode = createNode(val);
	if(*head == NULL){
		*head = newNode;
		return;
	}else{
		ListNode* currentNode = *head;
		while(currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
}

void printList(ListNode* head){
	cout<<endl<<"PrintList [";
	while(head != NULL){
		cout<<", "<<head->val;
		head=head->next;
	}
	cout<<"]"<<endl;
}

int recursiveSum(ListNode** sumList,  ListNode* num1,ListNode* num2){
	if(num1->next == NULL && num2->next == NULL){
		int sum = num1->val+num2->val;
		int carry = sum/10;
		sum%=10;
		ListNode* sumNode = createNode(sum);
		sumNode->next = *sumList;
		*sumList = sumNode;
		return carry;
	}else{
		int carry =  recursiveSum(sumList,num1->next,num2->next);
		int sum = num1->val+num2->val+carry;
		carry = sum/10;
		sum%=10;
		ListNode* sumNode = createNode(sum);
		sumNode->next = *sumList;		
		*sumList = sumNode;
		return carry;
	}
}

int recursiveAdd(ListNode** sumList,ListNode* bigList,int carry,int depth){
	depth--;
	if(depth<=0){
		int sum = bigList->val;
		int carry = sum/10;
		sum%=10;
		ListNode* sumNode = createNode(sum);
		sumNode->next = *sumList;
		*sumList = sumNode;
		return carry;
	}else{
		int carry = recursiveAdd(sumList,bigList,carry,depth);
		int sum = bigList->val+carry;
		carry = sum/10;
		sum%=10;
		ListNode* sumNode = createNode(sum);
		sumNode->next = *sumList;
		*sumList = sumNode;
		return carry;
	}
}

ListNode* sumLinkedList(ListNode** num1,ListNode** num2){
	ListNode* sumList = NULL;
	if(*num1 == NULL && *num2 == NULL){
		return sumList;
	}else{
		int num1Size = 0;
		int num2Size = 0;
		ListNode* currentNode = *num1;
		while(currentNode != NULL){
			num1Size++;
			currentNode=currentNode->next;
		}
		currentNode = *num2;
		while(currentNode != NULL){
			num2Size++;
			currentNode=currentNode->next;
		}

		int diff = num1Size - num2Size;
		if(diff < 0) diff*=-1;
		ListNode* bigList = NULL;
		ListNode* bigListOriginal = NULL;
		ListNode* smallList = NULL;
		if(num1Size>num2Size){
			bigList = *num1;
			bigListOriginal = *num1;
			smallList = *num2;
		}else if(num2Size>num1Size){
			bigList = *num2;
			bigListOriginal = *num2;
			smallList = *num1;
		}else{
			bigList = *num1;
			bigListOriginal = *num1;
			smallList = *num2;
		}
		for(int i=0;i<diff;i++){
			bigList = bigList->next;
		}

		int carry = recursiveSum(&sumList,bigList,smallList);
		if(diff>0){
			cout<<endl<<" diff:"<<diff;
			carry = recursiveAdd(&sumList,bigListOriginal,carry,diff);
			if(carry>0){
				ListNode* newNode = createNode(carry);
				newNode->next= sumList;
				sumList = newNode;
			}
		}
	}
	return sumList;
}

int main(){
	ListNode* num1 = NULL;
	ListNode* num2 = NULL;
	
	addNode(&num1,5);
	addNode(&num1,2);
	addNode(&num1,3);
	addNode(&num1,4);
	addNode(&num1,5);

	addNode(&num2,1);
	addNode(&num2,2);
	addNode(&num2,0);
	addNode(&num2,3);
	addNode(&num2,5);
	addNode(&num2,6);
	printList(num1);
	printList(num2);

	ListNode* sumList = sumLinkedList(&num1,&num2);
	cout<<endl<<"Printing sumList"<<endl;
	printList(sumList);
	return 0;
}