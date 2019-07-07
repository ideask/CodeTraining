#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){};
};

class solution{
	public:
		ListNode *reverseList(unsigned int m, unsigned int n, ListNode *head){
			unsigned int changelength = n - m + 1;
			ListNode *result = head;
			ListNode *pre_head = NULL;
			while(head != NULL && --m){
				pre_head = head;
				head = head->next;
			}
			ListNode *tail_modify = head;
			ListNode *newList = NULL;
			while(head && changelength){
				ListNode *next = head->next;
				head->next = newList;
				newList = head;
				head = next;
				changelength --;
			}
			tail_modify->next = head;
			if(pre_head){
				pre_head->next = newList;
			}
			else{
				result = newList;
			}
			return result;
		} 
};

void printResult(ListNode *head){
	if(head == NULL)
		return;
	while(head){
		cout << head->val << " ";
		head = head->next;
	} 
	cout << endl;
}

int main(){
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);
	
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	
	printResult(&a1);
	
	solution slover;
	ListNode *reverse = slover.reverseList(1,5, &a1);
	printResult(reverse);
	
	ListNode *reverse = slover.reverseList(1,5, &a1);
	printResult(reverse);
}
