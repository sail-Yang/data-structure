#include "SqQueue.h"
int main(int argc, char const *argv[])
{
	SqQueue Q = (SqQueue)malloc(sizeof(queue));
	ElemType e;
	InitSqQueue(Q);
	EnQueue(Q,1);
	EnQueue(Q,2);
	EnQueue(Q,3);
	EnQueue(Q,4);
	EnQueue(Q,5);
	EnQueue(Q,6);
	DeQueue(Q,e);
	PrintQueue(Q);
	cout << "Deleted e : " << e << endl;
	DeQueue(Q,e);
	PrintQueue(Q);
	cout << "Deleted e : " << e << endl;
	DeQueue(Q,e);
	PrintQueue(Q);
	cout << "Deleted e : " << e << endl;
	return 0;
}
