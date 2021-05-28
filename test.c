#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"

void TestSeqList1()
{
	SeqList s = { 0 };
	SeqListInit(&s);//打个断点在这，直接按F5跳到这里
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);//越界了不一定会把错误报出来，酒驾模型,需要达到一定的临界值才能报出来
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPrint(&s);
	printf("\n");

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	printf("\n");

	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPrint(&s);
	printf("\n");

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	printf("\n");
}

int main()
{
	TestSeqList1();
	return 0;
}

