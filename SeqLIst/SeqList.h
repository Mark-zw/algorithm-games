#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma once
typedef int SLDataType;

//��̬�洢
typedef struct SeqList
{
	SLDataType* a;//ָ��̬���������ָ��
	int size;//��Ч���ݵĸ���
	int capacity;//���ݴ洢������
}SL,SeqList;

//��ʼ��
void SeqListInit(SL *ps);

//��ӡ
void SeqListPrint(SL* ps);

//���ݼ��
void SeqListCheckCapacity(SL* ps);

//β��
void SeqListPushBack(SL* ps, SLDataType x);

//βɾ
void SeqListPopBack(SL* ps);

//ͷ��
void SeqListPushFront(SL* ps, SLDataType x);

//ͷɾ
void SeqListPopFront(SL* ps);

//������λ�õĲ���ɾ��
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

////˳�����Ч�����������б�����������
////��̬�洢
//struct SeqList
//{
//	int arr[10];
//	int size;
//};