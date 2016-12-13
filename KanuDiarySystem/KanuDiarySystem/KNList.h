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
	KNList(); // ���, ���� ��� �߰�
	~KNList()
	{
	};

public :
	void SetAt(int nPos); // ��ġ ����
	KNNode* GetAt(); // ���� ���
	KNNode* GetPrev(); // ���� ���
	KNNode* GetNext(); // ���� ���

	KNNode* GetHead(); // ��� ���� �̵�
	KNNode* GetTail(); // ���� ���� �̵�

	int GetCount(); // ��� �� ����

	KNNode* InsertNode(KNNode* pNode); // ���� ��ġ���� ��� �߰�
	KNNode* AddNode(KNNode* pNode); // ���� ���� ��� �߰�
	KNNode* DeleteNode(); //
	
	//void AddNode(); // �߰�
	//void DeleteNode(int deleteSeq); // ����
	//void PrintAll(); // ����Ʈ
};