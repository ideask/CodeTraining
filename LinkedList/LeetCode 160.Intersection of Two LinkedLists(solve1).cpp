#include <iostream>
#include <set>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){};
};

class solution{
	public:
		ListNode * cross_point(ListNode *headA, ListNode *headB){
			set<ListNode *>test_set;
			while(headA){
				test_set.insert(headA);
				headA = headA->next;
			}
			while(headB){
				if(test_set.find(headB) != test_set.end()){
					return headB;
				}
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
	
	ListNode *crossPoint = slover.cross_point(&a1, &b1);
	cout << crossPoint->val << endl;
}
