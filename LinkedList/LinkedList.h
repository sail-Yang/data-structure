#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct LNode {
	ElementType data;
	struct LNode *next;
}LNode,*LinkedList;

/*****************************
 * 基础操作
*****************************/
LinkedList HeadInsert(LinkedList &L){
	LNode *s;int x;
	L = (LinkedList)malloc(sizeof(LNode));
	L->next = NULL;
	cin>>x;
	while(x != 9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}

LinkedList TailInsert(LinkedList &L){
	LNode *s,*list;int x;
	L = (LinkedList)malloc(sizeof(LNode));
	L->next = NULL;
	list = L;
	cin>>x;
	while(x != 9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = list->next;
		list->next = s;
		list = s;
		cin >> x;
	}
	return L;
}

LNode *GetElem(LinkedList L,int i){
	int j = 1;
	LNode *p = L->next;
	if(i==0){
		return L;
	}
	if(i < 1)
		return NULL;
	while(p!=NULL&&j<i){
		p = p->next;
		j++;
	}
	return p;
}

/*[1,len]*/
bool InsertBeforeElem(LinkedList &L,int i,int x){
	LNode *p = GetElem(L,i-1);
	if(p==NULL){
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
	return true;
}

bool InsertAfterElem(LinkedList &L,int i,int x){
	LNode *p = GetElem(L,i);
	if(p==NULL){
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = x;
	s->next = p->next;
	p->next = s;
	return true;
}

bool DelElem(LinkedList &L,int i,int &value){
	LNode *s = GetElem(L,i-1);
	if(s==NULL){
		return false;
	}
	LNode *p = s->next;
	s->next = p->next;
	value = p->data;
	free(p);
	return true;

}

void PrintList(LinkedList L){
	LNode *p = L->next;
	while(p!=NULL){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

/*****************************
 * 链表相关算法
*****************************/

/*递归算法，删除不带头结点的单链表L中所有值为x的结点*/
void R_DelNode(LinkedList &L,int x){
	if(L==NULL){
		return;
	}
	if(L->data == x){
		LNode *p = L;
		L=L->next;
		free(p);
		R_DelNode(L,x);
	}else{
		R_DelNode(L->next,x);
	}

}

/*就地逆置链表*/
void Reverse(LinkedList &L){
	LNode *p = L->next;
	L->next = NULL;
	while(p!= NULL){
		LNode *q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}

}

/*单链表排序：使用插入排序*/
void SortByInsert(LinkedList &L){
	LNode *p = L->next;
	if(p==NULL){
		return;
	}
	LNode *q = p->next;
	p->next = NULL;
	while(q!= NULL){
		LNode *r = q->next;
		LNode *pre = L;
		while(pre->next!= NULL && pre->next->data < q->data ){
			pre = pre->next;
		}
		q->next = pre->next;
		pre->next = q;
		q = r;
	}
}

/*给定两个单链表，然后找到公共结点*/
LNode *GetSimilarNode(LinkedList L1,LinkedList L2){
	LNode *p = L1;
	int L1Len = 0,L2Len = 0,dist=0;
	LinkedList longList,shortList;
	/*求L1的长度*/
	while(p!=NULL){
		L1Len++;
		p = p->next;
	}
	p = L2;
	/*求L2的长度*/
	while(p!=NULL){
		L2Len++;
		p = p->next;
	}

	if(L1Len > L2Len){
		longList = L1;
		shortList = L2;
		dist = L1Len - L2Len;
	}else{
		longList = L2;
		shortList = L1;
		dist = L2Len - L1Len;
	}

	while(dist--){
		longList = longList->next;
	}

	while(longList != NULL){
		if(longList == shortList)
			return longList;
		else{
			longList = longList->next;
			shortList = shortList->next;
		}
	}
	return NULL;
}

/*判断单链表是否有环*/
bool isLoop(LinkedList L){
	LNode *fast=L,*slow=L;
	while(fast!= NULL && fast->next!= NULL&&fast->next->next!=NULL ){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow){
			return true;
		}
	}
	return false;

	}

LNode* deleteDuplicates(LNode* head) {
        
        LNode *slow = head,*fast = head;
        
        while(fast != NULL && fast->next!=NULL){
            if(fast->next->next == NULL || fast->next->data != fast->next->next->data){
                slow = slow->next;
                fast = fast->next;
            }else{
                int value = fast->next->data;
                LNode *p = fast->next;
                while( p!= NULL && p->data == value ){
                    LNode *q = p->next;
                    fast->next = q;
                    free(p);
                    p = q;
                }
            }
        }
        return head;
    }
#endif