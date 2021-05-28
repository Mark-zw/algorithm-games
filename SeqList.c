#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"

//��ʼ��
void SeqListInit(SL *ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("Failed to allocates memory blocks!\n");
		exit(-1);//���������е����˳�����
	}
	ps->size = 0;
	ps->capacity = 4;
}

//���ݼ��
void SeqListCheckCapacity(SL* ps)
{
	//���������Ҫ����
	if (ps->size == ps->capacity)
	{
		//Ϊ�˴ﵽ�õ������������٣��õĶ��������Ķ࣬һ������������
		//Ƶ�������ݴ���Խ��
		ps->capacity *= 2;
		ps->a = realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("Fail of dilatation!");
			exit(-1);
		}
	}
}

//β��βɾ
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}

//��ӡ
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

//βɾ
void SeqListPopBack(SL* ps)
{
	//ps->a[ps->size] = 0;//ΪʲôҪ�����һ�������0��������������
	//һ��ɾ�����ݲ�ɾ�������� ���ǽ�size--���� --- ��ʵ�������ݻָ�ģ��

	ps->size--;
}

//ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
	//ͷ����Ҫע������Ų���ķ����Ǵ�ǰ���󣬻��ǴӺ���ǰ��Ҫ��ʵ������
	//������Ҫ�Ӻ���ǰŲ������ֹ���ݱ�����

	//��Ҫ���ǲ������ݺ������Ƿ��㹻 
	//�����ݴ����װ����

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


//ͷɾ
void SeqListPopFront(SL* ps)
{
	//��Ų��λ��
	int start = 0;
	while (start <= (ps->size - 2))
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}

	//�ٽ�size--
	ps->size--;
}

//������λ�õĲ���ɾ��
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);