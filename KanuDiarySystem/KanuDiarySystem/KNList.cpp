#include <iostream>
#include "KNList.h"
#include "KNNode.h"

/* ──────────────────────────────────────── KNList 생성자 */
KNList :: KNList()
{
	head = new KNNode();
	memset(head, 0, sizeof(head)); // Head 노드 생성 완료
	tail = new KNNode();
	memset(tail, 0, sizeof(tail)); // Tail 노드 생성완료
	head->next = tail;
	tail->next = tail;	
	this->m_nCount = 0;
	this->m_nCurrent = 0;
}

/* ──────────────────────────────────────── SetAt */
// (현재 위치) 카운트 설정
void KNList :: SetAt(int nPos)
{
	m_nCurrent = nPos;
}

/* ──────────────────────────────────────── GetAt */
// 현재 위치 반환
KNNode* KNList :: GetAt()
{
	KNNode* np = head->next;
	if( m_nCurrent = -1 )
	{
		//printf("현재 위치가 정확히 설정되지 않았습니다.\n");
		return NULL;
	}
	if( np->next == tail )
	{
		//printf("저장된 노드가 하나도 없습니다.\n");
		return NULL;
	}
	for(int index=0; index<m_nCurrent; index++)
	{
		np = np->next;
	}
	return np;
}

/* ──────────────────────────────────────── GetPrev */
// 이전 위치로 이동 및 노드 반환
KNNode* KNList :: GetPrev()
{
	--m_nCurrent;
	return GetAt();
}

/* ──────────────────────────────────────── GetNext */
// 다음 위치로 이동 및 노드 반환
KNNode* KNList :: GetNext()
{
	++m_nCurrent;
	return GetAt();
}

/* ──────────────────────────────────────── InsertNode */
// 현재 노드 다음으로 새로운 노드 추가
KNNode* KNList :: InsertNode(KNNode* pNode)
{
	KNNode* newNode = new KNNode();
	memset(newNode, 0, sizeof(newNode));
	newNode->next = GetAt()->next;
	GetAt()->next = newNode;
	++m_nCount;
	++m_nCurrent;
	return newNode;
}

/* ──────────────────────────────────────── DeleteNode */
// 현재 위치를 지운다.
KNNode* KNList :: DeleteNode()
{
	// 이전 노드
	// 현재 노드
	// 다음 노드
	return NULL;
}

/* ──────────────────────────────────────── AddNode */
// 리스트 끝에 노드 추가
KNNode* KNList :: AddNode(KNNode* pNode)
{
	KNNode* np = head; // 임시 노드
	// 노드 검색
	while( np->next != tail )
	{
		np = np->next;
	}
	// 노드 추가
	if( np->next == tail ) 
	{
		KNNode* newNode = new KNNode(); // 새로운 노드 생성
		memset(newNode, 0, sizeof(newNode)); // 새로운 노드 초기화
		newNode->next = tail; // new → tail
		np->next = newNode; // prev → new
	}
	return NULL;
}

/* ──────────────────────────────────────── GetHead */
// Head 노드 반환
KNNode* KNList :: GetHead()
{
	return head;
}

/* ──────────────────────────────────────── GetTail */
// Tail 노드 반환
KNNode* KNList :: GetTail()
{
	return tail;
}

/*──────────────────────────────────────── GetCount */
// 총 노드 수를 저장하는 변수
int KNList :: GetCount()
{
	KNNode* np = head->next; // 임시 노드

	// 추가된 노드가 하나도 없으면 0 반환
	if( np == tail )
	{
		printf("저장된 노드가 하나도 없습니다.\n");
		return 0;
	}
	
	// 노드 수 카운트
	while( np != tail )
	{
		++m_nCount;
		np = np->next;
	}

	// 총 노드 수 반환
	return m_nCount;
}