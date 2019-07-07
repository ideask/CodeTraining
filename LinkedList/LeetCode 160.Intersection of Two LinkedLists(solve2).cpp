#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){};
};

class solution{
	public:
		unsigned int returnListLength(ListNode *head){
			unsigned int count = 0;
			while(head){
				count ++;
				head = head->next;
			}
			return count;
		}
		ListNode *forwardLongList(ListNode *head, unsigned int offset){
			while(head && offset){
				offset --;
				head = head->next;
			}
			return head;
		}
		ListNode *getCrossPointNode(ListNode *headA, ListNode *headB){
			unsigned int offset = 0;
			unsigned int headAlength = returnListLength(headA);
			unsigned int headBlength = returnListLength(headB);
			if(headAlength > headBlength){
				offset = headAlength - headBlength;
				headA = forwardLongList(headA, offset);
			}
			else{
				offset = headBlength - headAlength;
				headB = forwardLongList(headB, offset);
			}
			while(headA && headB){
				if(headA == headB){
					return headB;
				}
				headA = headA->next;
				headB = headB->next;
			}
			return NULL;
		}
		
};

int main(){
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);
	ListNode b1(1);
	ListNode b2(2);
	ListNode b3(3);
	ListNode c1(100);
	ListNode c2(200);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = &c1;
	c1.next = &c2;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &c1;
	
	solution slover;
	
	ListNode *crossPoint = slover.getCrossPointNode(&a1, &b1);
	cout << crossPoint->val << endl;
}
