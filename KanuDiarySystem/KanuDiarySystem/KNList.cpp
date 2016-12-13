#include <iostream>
#include "KNList.h"
#include "KNNode.h"

/* �������������������������������������������������������������������������������� KNList ������ */
KNList :: KNList()
{
	head = new KNNode();
	memset(head, 0, sizeof(head)); // Head ��� ���� �Ϸ�
	tail = new KNNode();
	memset(tail, 0, sizeof(tail)); // Tail ��� �����Ϸ�
	head->next = tail;
	tail->next = tail;	
	this->m_nCount = 0;
	this->m_nCurrent = 0;
}

/* �������������������������������������������������������������������������������� SetAt */
// (���� ��ġ) ī��Ʈ ����
void KNList :: SetAt(int nPos)
{
	m_nCurrent = nPos;
}

/* �������������������������������������������������������������������������������� GetAt */
// ���� ��ġ ��ȯ
KNNode* KNList :: GetAt()
{
	KNNode* np = head->next;
	if( m_nCurrent = -1 )
	{
		//printf("���� ��ġ�� ��Ȯ�� �������� �ʾҽ��ϴ�.\n");
		return NULL;
	}
	if( np->next == tail )
	{
		//printf("����� ��尡 �ϳ��� �����ϴ�.\n");
		return NULL;
	}
	for(int index=0; index<m_nCurrent; index++)
	{
		np = np->next;
	}
	return np;
}

/* �������������������������������������������������������������������������������� GetPrev */
// ���� ��ġ�� �̵� �� ��� ��ȯ
KNNode* KNList :: GetPrev()
{
	--m_nCurrent;
	return GetAt();
}

/* �������������������������������������������������������������������������������� GetNext */
// ���� ��ġ�� �̵� �� ��� ��ȯ
KNNode* KNList :: GetNext()
{
	++m_nCurrent;
	return GetAt();
}

/* �������������������������������������������������������������������������������� InsertNode */
// ���� ��� �������� ���ο� ��� �߰�
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

/* �������������������������������������������������������������������������������� DeleteNode */
// ���� ��ġ�� �����.
KNNode* KNList :: DeleteNode()
{
	// ���� ���
	// ���� ���
	// ���� ���
	return NULL;
}

/* �������������������������������������������������������������������������������� AddNode */
// ����Ʈ ���� ��� �߰�
KNNode* KNList :: AddNode(KNNode* pNode)
{
	KNNode* np = head; // �ӽ� ���
	// ��� �˻�
	while( np->next != tail )
	{
		np = np->next;
	}
	// ��� �߰�
	if( np->next == tail ) 
	{
		KNNode* newNode = new KNNode(); // ���ο� ��� ����
		memset(newNode, 0, sizeof(newNode)); // ���ο� ��� �ʱ�ȭ
		newNode->next = tail; // new �� tail
		np->next = newNode; // prev �� new
	}
	return NULL;
}

/* �������������������������������������������������������������������������������� GetHead */
// Head ��� ��ȯ
KNNode* KNList :: GetHead()
{
	return head;
}

/* �������������������������������������������������������������������������������� GetTail */
// Tail ��� ��ȯ
KNNode* KNList :: GetTail()
{
	return tail;
}

/*�������������������������������������������������������������������������������� GetCount */
// �� ��� ���� �����ϴ� ����
int KNList :: GetCount()
{
	KNNode* np = head->next; // �ӽ� ���

	// �߰��� ��尡 �ϳ��� ������ 0 ��ȯ
	if( np == tail )
	{
		printf("����� ��尡 �ϳ��� �����ϴ�.\n");
		return 0;
	}
	
	// ��� �� ī��Ʈ
	while( np != tail )
	{
		++m_nCount;
		np = np->next;
	}

	// �� ��� �� ��ȯ
	return m_nCount;
}