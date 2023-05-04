#ifndef SQLIST_H
#define SQLIST_H
#include <iostream>
using namespace std;

const int MAXSIZE = 100;
typedef int ElemType;

typedef struct SqList{
	ElemType data[MAXSIZE];
	int length = 0;
} SqList ;


/*默认初始化List*/
void InitList(SqList &L){
	int arr[12] = {1,2,2,2,4,5,5,6,7,8,9,10};
	for(int i=1;i<=12;i++){
		L.data[i-1] = arr[i-1];
		L.length++;
	}
}

/*
	在序号为i的位置(从1开始)插入e
	实际存储位置为L.data[i-1]
*/
bool ListInsert(SqList &L,int i,ElemType e){
	//i从1开始，必须>=1；i最大为L.length
	if(i<1 || i>=L.length+1)
		return false;
	if(L.length>=MAXSIZE)
		return false;
	for(int j=L.length;j>=i;j--)
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;
	L.length++;
	return true;
}

/*
	删除位于i位置的元素，并把值传给e
	实际删除位置为L.data[i-1]
*/
bool ListDelete(SqList &L,int i,ElemType &e){
	if(i<1||i>=L.length+1)
		return false;
	if(L.length<=0)
		return false;
	e = L.data[i-1];
	for(int j=i;j<L.length;j++)
		L.data[j-1] = L.data[j];
	L.length--;
	return true;
}

/*
	顺序查找，寻找第一个==e的元素，并返回其坐标值
	若未找到，返回0
*/
bool LocateElem(SqList L,ElemType e){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==e)
			return i+1;
	}
	return 0;
}


/*打印数组*/
void PrintList(SqList L){
	for(int i=0;i<L.length;i++){
		cout << L.data[i] << "  ";
	}
	cout << endl;
}

/*==算法题练习==*/
/*
	删除最小元素（假设唯一）并返回该值
	空出的位置由最后一个元素填补
	若顺序表为空，则显示出错信息并退出运行
*/
bool Del_Min(SqList &L,ElemType &e){
	if(L.length <= 0)
		return false;
	int pos = 0,minValue = L.data[0];
	for(int i=1;i<L.length;i++){
		if(L.data[i] < minValue){
			minValue = L.data[i];
			pos = i;
		}
	}
	e = L.data[pos];
	L.data[pos] = L.data[L.length-1];
	return true;
}

/*
	逆置所有元素，空间复杂度为O(1)
*/
bool Reverse(SqList &L){
	int p=0,q=L.length-1;
	while(p<q){
		int n = L.data[p];
		L.data[p] = L.data[q];
		L.data[q] = n;
		p++;
		q--;
	}
	return true;
}

/*
	删除值为x的元素，要求时间复杂度为n，空间复杂度为1
*/
bool Del_Value(SqList &L,ElemType e){
	int k = 0;
	for(int i=0;i<L.length;i++){
		if(L.data[i] != e){
			L.data[k++] = L.data[i];
		}
	}
	L.length = k;
	return true;
}

/*
	与上题类似，只是要求删除区间[s,t]内的值，
	区间不合理或者顺序表为空，要求显示出错信息并退出运行
*/
bool Del_Interval(SqList &L,ElemType s,ElemType t){
	if(s >= t | L.length <=0)
		return false;
	int k=0;
	for(int i=0;i<L.length;i++){
		if(L.data[i] < s || L.data[i] > t){
			L.data[k++] = L.data[i];
		}
	}
	L.length = k;
	return true;
}

/*
	删除有序表中重复的元素
*/
bool Del_Repeat_Order(SqList &L){
	int pos = 0;
	for(int i=1;i<L.length;i++){
		if(L.data[i] != L.data[pos]){
			L.data[++pos] = L.data[i];			
		}
	}
	L.length = pos + 1;
	return true;
}

/*
	删除无序表中重复的元素，使用散列表
*/
bool Del_Repeat_DisOrder(SqList &L){
	return true;
}


/*合并两个有序顺序表为一个*/
SqList Merge(SqList &L1,SqList &L2){
	SqList L;
	int i = 0,j = 0;
	while(i<L1.length && j <L2.length){
		if(L1.data[i]<L2.data[j]){
			L.data[L.length++] = L1.data[i++];
		}else{
			L.data[L.length++] = L1.data[j++];
		}
	}
	while(i<L1.length){
		L.data[L.length++] = L1.data[i++];
	}

	while(j<L2.length){
		L.data[L.length++] = L2.data[j++];
	}
	return L;
}

/*
将序列循环左移p个位置
Reverse(L,0,p-1);
Reverse(L,p,n-1);
Reverse(L,0,n-1);
*/
bool RMove_Left(SqList &L,int p ){
	if(p<0 || p>=L.length){
		return false;
	}
	
	return true;
}

#endif