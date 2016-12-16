#include <iostream>
#include <string>
#include "KNList.h"

// �������������������������������������������������������������������� KNList
KNList :: KNList()
{
	// �Ӹ�(Head) ���
	m_pHead = new KNNode();
	memset(m_pHead, 0, sizeof(m_pHead));

	// ����(Tail) /���
	m_pTail = new KNNode();
	memset(m_pTail, 0, sizeof(m_pTail));

	m_pHead->next = m_pTail;
	m_pTail->next = m_pTail;	

	m_nCount = 0; // �� ��� �� 0
	m_pCurrent = m_pHead;
}

// �������������������������������������������������������������������� GetAt
// ���� ��ġ�� ��ȯ�Ѵ�.
KNNode* KNList :: GetAt()
{
	return m_pCurrent;
}

// �������������������������������������������������������������������� GoNext
// ���� ��ġ���� �ٷ� ���� ���� �̵��Ѵ�.
KNNode* KNList :: GoNext()
{
	// ���� ��ġ�� ����(Tail) ����� ���
	if( m_pCurrent == m_pTail )
		return m_pTail;

	// ���� ��ġ�� ���� ��带 ����Ŵ
	m_pCurrent = m_pCurrent->next;
	return m_pCurrent;
}

// �������������������������������������������������������������������� GoPrev
// ���� ��ġ���� �ٷ� ���� ���� �̵�
KNNode* KNList :: GoPrev()
{
	// ���� ��ġ�� �Ӹ�(Head) ����� ���
	if( m_pCurrent == m_pHead )
		return m_pHead;

	// ���� ��� �˻�
	KNNode* temp_node = m_pHead; // �ӽ� ���
	while( temp_node->next == m_pCurrent )
	{
		temp_node = temp_node->next;
	}

	// ���� ��ġ�� ���� ��带 ����Ŵ
	m_pCurrent = temp_node;
	return m_pCurrent;
}

// �������������������������������������������������������������������� GoHead
// ���� ��ġ�� �Ӹ�(Head) ���� ����Ű��, �� ��ġ�� ��ȯ�Ѵ�.
KNNode* KNList ::GoHead()
{
	m_pCurrent = m_pHead;
	return m_pCurrent;
}

// �������������������������������������������������������������������� GoTail
// ���� ��ġ�� ����(Tail) ���� ����Ű��, �� ��ġ�� ��ȯ�Ѵ�.
KNNode* KNList ::GoTail()
{
	m_pCurrent = m_pTail;
	return m_pCurrent;
}

// �������������������������������������������������������������������� AddHead
// ����Ʈ ���� �տ� ���ο� ��带 �߰��Ѵ�.
int KNList :: AddHead(KNNode* pNode)
{
	// ���ο� ��� �߰�
	pNode->next = m_pHead->next;
	m_pHead->next = pNode;

	//���� ��ġ�� ���� �߰��� ���� ����Ŵ
	m_pCurrent = pNode;

	++m_nCount; // �� ��� �� +1
	return GetCount();
}

// �������������������������������������������������������������������� AddTail
// ����Ʈ �������� ���ο� ��带 �߰��Ѵ�.
int KNList :: AddTail(KNNode* pNode)
{
	// ����(Tail) ��� �˻�
	m_pCurrent = m_pHead;
	while( m_pCurrent->next != m_pTail )
	{
		m_pCurrent = m_pCurrent->next;
	}

	// ���ο� ��� �߰�
	if( m_pCurrent->next == m_pTail )
	{
		pNode->next = m_pTail;
		m_pCurrent->next = pNode;
	}

	// ���� ��ġ�� ���� �߰��� ���� ����Ŵ
	m_pCurrent = pNode;

	++m_nCount; // �� ��� �� +1
	return m_nCount;
}

// �������������������������������������������������������������������� InsertAfter
// '���� ���'�� '���� ���' ���̿� ���ο� ��带 �����Ѵ�. 
int KNList :: InsertAfter(KNNode* pNode)
{
	if( m_pCurrent == m_pTail )
		GoHead(); // ���� ��尡 ����(Tail)�� ����Ű�� �ִ� ���

	pNode->next = m_pCurrent->next;
	m_pCurrent->next = pNode;

	// ���� ��ġ�� ���� �߰��� ���� ����Ŵ
	m_pCurrent = pNode;

	++m_nCount; // �� ��� �� +1
	return m_nCount;
}

// �������������������������������������������������������������������� DeleteNode
// ��带 �˻��Ͽ� �����Ѵ�.
int KNList :: DeleteNode(KNNode* pNode)
{
	if( pNode == m_pHead || pNode == m_pTail )
		return -1; // ����1 : �ش� ��尡 ���(Head) �� ����(Tail)����

	// ������ ��� �˻�
	m_pCurrent = m_pHead;
	while( m_pCurrent->next != pNode )
	{
		if( m_pCurrent->next == m_pTail )
		{
			return -2; // ����2 : �ش� ��尡 ����
		}
		m_pCurrent = m_pCurrent->next;
	} // while-end

	// ������ ��� ã��
	if( m_pCurrent->next  == pNode )
	{
		m_pCurrent->next = pNode->next;
		delete m_pCurrent;
	}
	m_nCount = m_nCount-1; // �� ��� �� -1
	return m_nCount;
}
// �������������������������������������������������������������������� GetCount
// �� ��� ���� ��ȯ�Ѵ�.
int KNList :: GetCount()
{
	if(m_pHead->next == m_pTail)
	{
		return 0;
	}
	// ī��Ʈ ��� ���� : countNode
	KNNode* countNode = m_pHead->next;

	// �� ��� �� �˻�
	int nCount = 0;
	while( countNode != m_pTail )
	{
		++nCount;
		countNode = countNode->next;
	}
	return nCount;
}
// �������������������������������������������������������������������� IsTail
// ���� ��ġ(m_pCurrnet)�� ��� ����(Tail)���� Ȯ���Ѵ�.
bool KNList :: IsTail()
{
	return m_pCurrent == m_pTail;
}
// �������������������������������������������������������������������� IsHead
// ���� ��ġ(m_pCurrnet)�� ��� �Ӹ�(Head)���� Ȯ���Ѵ�.
bool KNList :: IsHead()
{
	return m_pCurrent == m_pHead;
}
// �������������������������������������������������������������������� ModifyNode
// ���ο� ��带 ������� �����Ѵ�.
void KNList :: ModifyNode(KNNode* pNode)
{
	// ����� ��� �ּҸ� ������ �ӽ� ��� ����
	KNNode* modify_node = m_pCurrent; 

	// ������ �۾�
	GoPrev();
	m_pCurrent->next = pNode;
	pNode->next = modify_node->next;
	delete modify_node;

	// ���� ��ġ�� ������ ��带 ����Ŵ
	m_pCurrent = pNode;
}
// �������������������������������������������������������������������� DeleteLine
// ��� ������ȣ�� �˻��Ͽ� �����Ѵ�.
int KNList :: DeleteLine(int lineNum)
{
	if( lineNum < 0 )
		return -1; // ����1 : ��ȣ ����
	
	// ������ ����(���) ã��
	int line_count = 1;
	m_pCurrent = m_pHead->next;
	while( line_count != lineNum )
	{
		if( m_pCurrent == m_pTail )
		{
			return -2; // ����2 : ��ȣ�� �� ��� ������ ŭ
		}
		++line_count;
		m_pCurrent = m_pCurrent->next;
	}
	
	// ������ ����(���) ���� ��� Ž��
	KNNode* delete_node = m_pCurrent;
	m_pCurrent = m_pHead;
	while( m_pCurrent->next != delete_node )
	{
		m_pCurrent = m_pCurrent->next;
	}

	// ������ ���(delete_node)�� ���� ���(m_pCurrent) ������ �Ϸ� �� ����
	if( m_pCurrent->next  == delete_node )
	{
		m_pCurrent->next = delete_node->next;
		delete delete_node;
	}
}
// �������������������������������������������������������������������� DeleteAll
// ��� ��ü�� �����Ѵ�.
void KNList :: DeleteAll()
{
	// ������ ��� ��� ����
	while( m_pCurrent != m_pTail )
	{
		m_pCurrent = m_pHead->next;
		delete m_pCurrent;
	}

	// �Ӹ����� ������� ����
	m_pHead->next = m_pTail;
	m_pTail->next = m_pTail;
}