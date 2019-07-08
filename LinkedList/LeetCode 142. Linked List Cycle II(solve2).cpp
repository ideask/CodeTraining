#include <iostream>
using namespace std;

struct LinkNode{
	int val;
	LinkNode *next;
	LinkNode(int x): val(x), next(NULL){};
};

class solution{
	public:
		LinkNode *detectCycle(LinkNode *head){
			LinkNode *SlowHead = head;
		 	LinkNode *FastHead = head;
		 	LinkNode *MeetHead = NULL;
		 	while(FastHead){
	 			SlowHead = SlowHead->next;
	 			FastHead = FastHead->next;
	 			if(FastHead == NULL){
			 		return NULL;
			 	}
			 	FastHead = FastHead->next;
			 	if(FastHead == SlowHead){
	 				MeetHead = FastHead;
	 				break;
	 			}
	 		}
	 		if(MeetHead == NULL){
		 		return NULL;
		 	}
		 	while(MeetHead && head){
	 			if(MeetHead == head){
			 		return MeetHead;
			 	}
			 	MeetHead = MeetHead->next;
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
	LinkNode g(7);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &c;
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
