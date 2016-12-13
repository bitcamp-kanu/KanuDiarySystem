#pragma once

#include "KNNode.h"

class KNList
{
private :
	int m_nCount;
	int m_nCurrent;

private :
	KNNode* head;
	KNNode* tail;

public :
	KNList(); // 헤드, 테일 노드 추가
	~KNList()
	{
	};

public :
	void SetAt(int nPos); // 위치 설정
	KNNode* GetAt(); // 현재 노드
	KNNode* GetPrev(); // 이전 노드
	KNNode* GetNext(); // 다음 노드

	KNNode* GetHead(); // 헤드 노드로 이동
	KNNode* GetTail(); // 테일 노드로 이동

	int GetCount(); // 노드 총 숫자

	KNNode* InsertNode(KNNode* pNode); // 현재 위치에서 노드 추가
	KNNode* AddNode(KNNode* pNode); // 테일 이전 노드 추가
	KNNode* DeleteNode(); //
	
	//void AddNode(); // 추가
	//void DeleteNode(int deleteSeq); // 삭제
	//void PrintAll(); // 프린트
};