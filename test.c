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
	//找链表最后一个节点
	assert(s);
	PNode pNewNode = BuySListNode(data);
	if (s->_pHead == NULL) {//链表没有节点的情况
		s->_pHead = pNewNode;
	}
	else {
		PNode pCur = s->_pHead;
		while (pCur->_PNext) {
			pCur = pCur->_PNext;
		}
		//让最后一个节点指向新节点
		pCur->_PNext = pNewNode;
	}
}

void SListPopBack(SList* s) {
	assert(s);
	if (s->_pHead == NULL) {//链表中没有节点
		return;
	}
	else if (s->_pHead->_PNext == NULL) {//只有一个节点
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else {                           //多个节点
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
	if (s->_pHead == NULL) {//链表为空
		s->_pHead = pNewNode;
	}
	else {
		pNewNode->_PNext = s->_pHead;
		s->_pHead = pNewNode;
	}
}

void SListPopFront(SList* s) {
	assert(s);
	if (s->_pHead == NULL) {//链表为空
		return;
	}
	else if (s->_pHead->_PNext == NULL) {//只有一个节点
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