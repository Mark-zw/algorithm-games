#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"

//初始化
void SeqListInit(SL *ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("Failed to allocates memory blocks!\n");
		exit(-1);//非正常运行导致退出程序
	}
	ps->size = 0;
	ps->capacity = 4;
}

//扩容检查
void SeqListCheckCapacity(SL* ps)
{
	//如果满了需要增容
	if (ps->size == ps->capacity)
	{
		//为了达到用的少增容增的少，用的多增容增的多，一般增容增二倍
		//频繁的增容代价越大
		ps->capacity *= 2;
		ps->a = realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("Fail of dilatation!");
			exit(-1);
		}
	}
}

//尾插尾删
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}

//打印
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

//尾删
void SeqListPopBack(SL* ps)
{
	//ps->a[ps->size] = 0;//为什么要将最后一个数变成0？这句代码无意义
	//一般删除数据不删除真数据 而是将size--即可 --- 现实电脑数据恢复模型

	ps->size--;
}

//头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	//头插需要注意数据挪动的方向，是从前往后，还是从后往前需要看实际需求
	//这里需要从后往前挪动，防止数据被覆盖

	//需要考虑插入数据后容量是否足够 
	//将扩容代码封装起来

	SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}


//头删
void SeqListPopFront(SL* ps)
{
	//先挪动位置
	int start = 0;
	while (start <= (ps->size - 2))
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}

	//再将size--
	ps->size--;
}

//在任意位置的插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);