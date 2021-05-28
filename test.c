#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"

void TestSeqList1()
{
	SeqList s = { 0 };
	SeqListInit(&s);//����ϵ����⣬ֱ�Ӱ�F5��������
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);//Խ���˲�һ����Ѵ��󱨳������Ƽ�ģ��,��Ҫ�ﵽһ�����ٽ�ֵ���ܱ�����
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

