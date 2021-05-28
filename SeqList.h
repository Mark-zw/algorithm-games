#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma once
typedef int SLDataType;

//动态存储
typedef struct SeqList
{
	SLDataType* a;//指向动态开辟数组的指针
	int size;//有效数据的个数
	int capacity;//数据存储的容量
}SL,SeqList;

//初始化
void SeqListInit(SL *ps);

//打印
void SeqListPrint(SL* ps);

//扩容检查
void SeqListCheckCapacity(SL* ps);

//尾插
void SeqListPushBack(SL* ps, SLDataType x);

//尾删
void SeqListPopBack(SL* ps);

//头插
void SeqListPushFront(SL* ps, SLDataType x);

//头删
void SeqListPopFront(SL* ps);

//在任意位置的插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);

////顺序表，有效数组再数组中必须是连续的
////静态存储
//struct SeqList
//{
//	int arr[10];
//	int size;
//};