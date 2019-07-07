#include <iostream>
using namespace std;
 
struct ListNode{
	int val;
	ListNode *nextNode;
	ListNode(int x): val(x), nextNode(NULL){};
};
 
class solution{
public:
	ListNode *reverseList(ListNode *head){
		ListNode *new_head = NULL;
		while(head != NULL){
		ListNode *next = head->nextNode;
		head->nextNode = new_head;
		new_head = head;
		head = next;
		}
		return new_head;
	}; 
};
 
int main(){
	ListNode a1(1); 
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);
	a1.nextNode = &a2;
	a2.nextNode = &a3;
	a3.nextNode = &a4;
	a4.nextNode = &a5;
	
	ListNode *normalList = &a1;
	while(normalList){
		cout << normalList->val << " ";
		normalList = normalList->nextNode;
	} 
	cout << endl;
	
	normalList = &a1;
	solution slover;
	ListNode *reverseList = slover.reverseList(normalList);
	while(reverseList){
		cout << reverseList->val << " ";
		reverseList = reverseList->nextNode;
	}
	cout << endl;

}
 
