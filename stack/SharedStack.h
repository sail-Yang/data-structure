#ifndef SHAREDSTACK_H
#define SHAREDSTACK_H
#include <iostream>

#define MaxSize 50
typedef ElemType int
typedef struct {
	ElemType data[MaxSize];
	int top0;
	int top1;
}SharedStack;

void InitSharedStack(SharedStack &S){
	S.top0 = -1;
	S.top1 = MaxSize;

}

bool EmptySharedStack1(SharedStack S){
	if(S.top0 == -1){
		return true;
	}
	return false;
}

bool EmptySharedStack2(SharedStack S){
	if(S.top1 == -1){
		return true;
	}
	return false;
}

bool PushStack1(SharedStack &S,ElemType x){
	if(S.top0 == S.top1-1){
		return false;
	}
	S.data[++S.top0] = x;
	return true;
}

bool PushStack2(SharedStack &S,ElemType x){
	if(S.top1 == S.top0+1){
		return false;
	}
	S.data[--S.top1] = x;
	return true;
}

bool PopStack1(SharedStack &S,ElemType &x){
	if(S.top0 == -1){
		return false;
	}
	x = S.data[S.top0--];
	return true;
}

bool PopStack2(SharedStack &S,ElemType &x){
	if(S.top1 == MaxSize){
		return false;
	}
	x = S.data[S.top1++];
	return true;
}

bool GetStack1Top(SharedStack S,ElemType &x){
	if(S.top0 == -1)
		return false;
	x = S.data[S.top0];
	return true;
}

bool GetStack1Top(SharedStack S,ElemType &x){
	if(S.top1 == MaxSize)
		return false;
	x = S.data[S.top1];
	return true;
}

#endif