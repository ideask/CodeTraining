#include <iostream>
#include <set>
using namespace std;

struct LinkNode{
	int val;
	LinkNode *next;
	LinkNode(int x): val(x), next(NULL){};
};

class solution{
	public:
		LinkNode *detectCycle(LinkNode *head){
			set<LinkNode *>LinkSet;
			while(head){
				if(LinkSet.find(head) != LinkSet.end()){
					return head;
				}
				LinkSet.insert(head);
				head = head->next;
			}
			return NULL;
		}
};

int main(){
	LinkNode a(1);
	LinkNode b(2);
	LinkNode c(3);
	LinkNode d(4);
	LinkNode e(5);
	LinkNode f(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &c;
	solution solve;
	LinkNode *node = solve.detectCycle(&a);
	if (node){
		printf("%d\n", node->val);
	}
	else{
		printf("NULL\n");
	}
	return 0;
}

