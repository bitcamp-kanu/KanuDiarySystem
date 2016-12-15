#pragma once
#include "KNNode.h"

class KNList
{
private :
	int m_nCount; // �� ��� ��
	KNNode* m_pCurrent; // ���� ��� ������

private :
	KNNode* m_pHead; // �Ӹ�(Head) ���
	KNNode* m_pTail; // ����(Tail)  ���

public :
	KNList();
	~KNList()
	{
	};

public :
	KNNode* GetAt(); // ���� ���
	KNNode* GoNext(); // ���� ���
	KNNode* GoPrev(); // ���� ��� 
	KNNode* GoHead(); // �Ӹ� ���
	KNNode* GoTail(); // ���� ���
	int AddHead(KNNode* pNode); // �Ӹ� ��� �ڿ� ����
	int AddTail(KNNode* pNode); // ���� ��� ���� ����
	int InsertAfter(KNNode* pNode); // ���� ��ġ �ڿ� ����
	int DeleteNode(KNNode* pNode); // �ش� ��� ����
	int GetCount(); // ��ü ��� �� ī��Ʈ
	bool IsTail(); // ���� ��ġ�� ��������
	bool IsHead(); // ���� ��ġ�� �Ӹ�����
	void ModifyNode(KNNode* pNode); // ����
	int KNList :: DeleteLine(int lineNum);
	void KNList :: DeleteAll();
};