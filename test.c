#include <stdio.h>
#include "Slist.h"
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>

void SListInit(SList*s) {
	assert(s);
	s->_pHead = NULL;
}

PNode BuySListNode(SDataType data) {
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (pNewNode == NULL) {
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_PNext = NULL;
	return pNewNode;
}

void SListPushBack(SList* s, SDataType data) {
	//���������һ���ڵ�
	assert(s);
	PNode pNewNode = BuySListNode(data);
	if (s->_pHead == NULL) {//����û�нڵ�����
		s->_pHead = pNewNode;
	}
	else {
		PNode pCur = s->_pHead;
		while (pCur->_PNext) {
			pCur = pCur->_PNext;
		}
		//�����һ���ڵ�ָ���½ڵ�
		pCur->_PNext = pNewNode;
	}
}

void SListPopBack(SList* s) {
	assert(s);
	if (s->_pHead == NULL) {//������û�нڵ�
		return;
	}
	else if (s->_pHead->_PNext == NULL) {//ֻ��һ���ڵ�
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else {                           //����ڵ�
		PNode pCur = s->_pHead;
		PNode pPre = NULL;
		while (pCur->_PNext) {
			pPre = pCur;
			pCur = pCur->_PNext;
		}
		free(pCur);
		pPre->_PNext = NULL;
	}
}

void SListPushFront(SList* s, SDataType data) {
	assert(s);
	PNode pNewNode = BuySListNode(data);
	if (s->_pHead == NULL) {//����Ϊ��
		s->_pHead = pNewNode;
	}
	else {
		pNewNode->_PNext = s->_pHead;
		s->_pHead = pNewNode;
	}
}

void SListPopFront(SList* s) {
	assert(s);
	if (s->_pHead == NULL) {//����Ϊ��
		return;
	}
	else if (s->_pHead->_PNext == NULL) {//ֻ��һ���ڵ�
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else {
		PNode pCur = s->_pHead;
		s->_pHead = pCur->_PNext;
		free(pCur);
	}
}

void SListInsert(PNode pos, SDataType data) {

}

void SListPrint(SList* s) {
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur) {
		printf("%d--->", pCur->_data);
		pCur = pCur->_PNext;
	}
	printf("\n");
}
void main() {
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPrint(&s);
	SListPopFront(&s);
	SListPrint(&s);


	system("pause");
	return;
}