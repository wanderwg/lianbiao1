#pragma once

typedef int SDataType;
//����Ľڵ�
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _PNext;
}Node,*PNode;

typedef struct SList
{
	PNode _pHead;//ָ�������һ���ڵ�
}SList;

void SListInit(SList*s);//����ĳ�ʼ��

//������s���һ���ڵ�����һ��ֵΪdata�Ľڵ�
void SListPushBack(SList* s, SDataType data);

//ɾ������s���һ���ڵ�
void SListPopBack(SList* s);

//������s��һ���ڵ�ǰ����ֵΪdata�Ľڵ�
void SListPushFront(SList* s, SDataType data);

//ɾ������s�ĵ�һ���ڵ�
void SListPopFront(SList* s);

//�������posλ�ú����ֵΪdata�Ľڵ�
void SListInsert(PNode pos, SDataType data);

//ɾ������s��posλ�õĽڵ�
void SListErase(SList* s, PNode pos);

// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻�NULL 
PNode SListFind(SList* s, SDataType data);

// ��ȡ��������Ч�ڵ�ĸ��� 
//size_t SListSize(SList* s);

// ��������Ƿ�Ϊ�� 
int SListEmpty(SList* s);

// ����������Ч�ڵ���� 
void SListClear(SList* s);

// �������� 
void SListDestroy(SList* s);
void SListPrint(SList* s);
