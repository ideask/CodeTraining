#include <iostream>
using namespace std;

struct LinkNode{
	int val;
	LinkNode *next;
	LinkNode(int x): val(x), next(NULL){};
};

class solution{
	public:
		LinkNode *partition(LinkNode *head, int x){
			LinkNode LessLink(0);
			LinkNode MoreLink(0);
			LinkNode *Lessprt = &LessLink;
			LinkNode *Moreprt = &MoreLink;
			while(head){
				if(head->val >= x)
				{
					Moreprt->next = head;
					Moreprt = head;
				}
				else
				{
					Lessprt->next = head;
					Lessprt = head;
				}
				head = head->next;
			}
			Lessprt->next = MoreLink.next; 
			Moreprt->next = NULL;
			return LessLink.next;
		}
};

int main(){
	LinkNode a(1);
	LinkNode b(4);
	LinkNode c(3);
	LinkNode d(2);
	LinkNode e(5);
	LinkNode f(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;	
	solution solve;
	LinkNode *head = solve.partition(&a, 3);	
	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}
	return 0;
}
