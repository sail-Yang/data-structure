#ifndef SQQUEUE_H
#define SQQUEUE_H
#include <iostream>
using namespace std;

#define MaxSize 50

typedef int ElemType;

typedef struct queue{
	ElemType data[MaxSize];
	int front;
	int rear;
}*SqQueue;

void InitSqQueue(SqQueue &Q){
	Q->front = 0;
	Q->rear = 0;
}

bool IsEmptySqQueue(SqQueue Q){
	if(Q->front == Q->rear){
		return true;
	}
	return false;
}

bool IsFullSqQueue(SqQueue Q){
	if((Q->rear+1)%MaxSize == Q->front){
		return true;
	}
	return false;
}

bool EnQueue(SqQueue &Q,ElemType x){
	if(IsFullSqQueue(Q)){
		return false;
	}
	Q->rear = (Q->rear+1)%MaxSize;
	Q->data[Q->rear] = x;
	return true;
}

bool DeQueue(SqQueue &Q,ElemType &x){
	if(IsEmptySqQueue(Q)){
		return false;
	}
	Q->front = (Q->front+1)%MaxSize;
	x = Q->data[Q->front];
	return true;
}

void PrintQueue(SqQueue Q){
	int i = Q->rear;
	while(i%MaxSize!=Q->front){
		cout << Q->data[i] << " ";
		i = (i-1)%MaxSize;
	}
	cout << endl;
}
#endif