#pragma once
#include "KNNode.h"

class KNList
{
private :
	int m_nCount; // 총 노드 수
	KNNode* m_pCurrent; // 현재 노드 포인터

private :
	KNNode* m_pHead; // 머리(Head) 노드
	KNNode* m_pTail; // 꼬리(Tail)  노드

public :
	KNList();
	~KNList()
	{
	};

public :
	KNNode* GetAt(); // 현재 노드
	KNNode* GoNext(); // 다음 노드
	KNNode* GoPrev(); // 이전 노드 
	KNNode* GoHead(); // 머리 노드
	KNNode* GoTail(); // 꼬리 노드
	int AddHead(KNNode* pNode); // 머리 노드 뒤에 생성
	int AddTail(KNNode* pNode); // 꼬리 노드 전에 생성
	int InsertAfter(KNNode* pNode); // 현재 위치 뒤에 생성
	int DeleteNode(KNNode* pNode); // 해당 노드 삭제
	int GetCount(); // 전체 노드 수 카운트
	bool IsTail(); // 현재 위치가 꼬리인지
	bool IsHead(); // 현재 위치가 머리인지
	void ModifyNode(KNNode* pNode); // 수정
	int KNList :: DeleteLine(int lineNum);
	void KNList :: DeleteAll();
};