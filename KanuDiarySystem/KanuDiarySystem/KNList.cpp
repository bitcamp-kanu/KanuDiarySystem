#include <iostream>
#include <string>
#include "KNList.h"

// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º KNList
KNList :: KNList()
{
	// ¸Ó¸®(Head) ³ëµå
	m_pHead = new KNNode();
	memset(m_pHead, 0, sizeof(m_pHead));

	// ²¿¸®(Tail) /³ëµå
	m_pTail = new KNNode();
	memset(m_pTail, 0, sizeof(m_pTail));

	m_pHead->next = m_pTail;
	m_pTail->next = m_pTail;	

	m_nCount = 0; // ÃÑ ³ëµå ¼ö 0
	m_pCurrent = m_pHead;
}

// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º GetAt
// ÇöÀç À§Ä¡¸¦ ¹ÝÈ¯ÇÑ´Ù.
KNNode* KNList :: GetAt()
{
	return m_pCurrent;
}

// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º GoNext
// ÇöÀç À§Ä¡¿¡¼­ ¹Ù·Î ´ÙÀ½ ³ëµå·Î ÀÌµ¿ÇÑ´Ù.
KNNode* KNList :: GoNext()
{
	// ÇöÀç À§Ä¡°¡ ²¿¸®(Tail) ³ëµåÀÎ °æ¿ì
	if( m_pCurrent == m_pTail )
		return m_pTail;

	// ÇöÀç À§Ä¡¸¦ ´ÙÀ½ ³ëµå¸¦ °¡¸®Å´
	m_pCurrent = m_pCurrent->next;
	return m_pCurrent;
}

// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º GoPrev
// ÇöÀç À§Ä¡¿¡¼­ ¹Ù·Î ÀÌÀü ³ëµå·Î ÀÌµ¿
KNNode* KNList :: GoPrev()
{
	// ÇöÀç À§Ä¡°¡ ¸Ó¸®(Head) ³ëµåÀÎ °æ¿ì
	if( m_pCurrent == m_pHead )
		return m_pHead;

	// ÀÌÀü ³ëµå °Ë»ö
	KNNode* temp_node = m_pHead; // ÀÓ½Ã ³ëµå
	while( temp_node->next == m_pCurrent )
	{
		temp_node = temp_node->next;
	}

	// ÇöÀç À§Ä¡¸¦ ÀÌÀü ³ëµå¸¦ °¡¸®Å´
	m_pCurrent = temp_node;
	return m_pCurrent;
}

// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º GoHead
// ÇöÀç À§Ä¡¸¦ ¸Ó¸®(Head) ³ëµå·Î °¡¸®Å°°í, ±× À§Ä¡¸¦ ¹ÝÈ¯ÇÑ´Ù.
KNNode* KNList ::GoHead()
{
	m_pCurrent = m_pHead;
	return m_pCurrent;
}

// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º GoTail
// ÇöÀç À§Ä¡¸¦ ²¿¸®(Tail) ³ëµå·Î °¡¸®Å°°í, ±× À§Ä¡¸¦ ¹ÝÈ¯ÇÑ´Ù.
KNNode* KNList ::GoTail()
{
	m_pCurrent = m_pTail;
	return m_pCurrent;
}

// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º AddHead
// ¸®½ºÆ® °¡Àå ¾Õ¿¡ »õ·Î¿î ³ëµå¸¦ Ãß°¡ÇÑ´Ù.
int KNList :: AddHead(KNNode* pNode)
{
	// »õ·Î¿î ³ëµå Ãß°¡
	pNode->next = m_pHead->next;
	m_pHead->next = pNode;

	//ÇöÀç À§Ä¡¸¦ »õ·Î Ãß°¡ÇÑ ³ëµå·Î °¡¸®Å´
	m_pCurrent = pNode;

	++m_nCount; // ÃÑ ³ëµå ¼ö +1
	return GetCount();
}

// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º AddTail
// ¸®½ºÆ® ¸¶Áö¸·¿¡ »õ·Î¿î ³ëµå¸¦ Ãß°¡ÇÑ´Ù.
int KNList :: AddTail(KNNode* pNode)
{
	// ²¿¸®(Tail) ³ëµå °Ë»ö
	m_pCurrent = m_pHead;
	while( m_pCurrent->next != m_pTail )
	{
		m_pCurrent = m_pCurrent->next;
	}

	// »õ·Î¿î ³ëµå Ãß°¡
	if( m_pCurrent->next == m_pTail )
	{
		pNode->next = m_pTail;
		m_pCurrent->next = pNode;
	}

	// ÇöÀç À§Ä¡¸¦ »õ·Î Ãß°¡ÇÑ ³ëµå·Î °¡¸®Å´
	m_pCurrent = pNode;

	++m_nCount; // ÃÑ ³ëµå ¼ö +1
	return m_nCount;
}

// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º InsertAfter
// 'ÇöÀç ³ëµå'¿Í '´ÙÀ½ ³ëµå' »çÀÌ¿¡ »õ·Î¿î ³ëµå¸¦ »ý¼ºÇÑ´Ù. 
int KNList :: InsertAfter(KNNode* pNode)
{
	if( m_pCurrent == m_pTail )
		GoHead(); // ÇöÀç ³ëµå°¡ ²¿¸®(Tail)¸¦ °¡¸®Å°°í ÀÖ´Â °æ¿ì

	pNode->next = m_pCurrent->next;
	m_pCurrent->next = pNode;

	// ÇöÀç À§Ä¡¸¦ »õ·Î Ãß°¡ÇÑ ³ëµå·Î °¡¸®Å´
	m_pCurrent = pNode;

	++m_nCount; // ÃÑ ³ëµå ¼ö +1
	return m_nCount;
}

// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º DeleteNode
// ³ëµå¸¦ °Ë»öÇÏ¿© »èÁ¦ÇÑ´Ù.
int KNList :: DeleteNode(KNNode* pNode)
{
	if( pNode == m_pHead || pNode == m_pTail )
		return -1; // ¿À·ù1 : ÇØ´ç ³ëµå°¡ Çìµå(Head) ³ª ²¿¸®(Tail)ÃÑÀÓ

	// »èÁ¦ÇÒ ³ëµå °Ë»ö
	m_pCurrent = m_pHead;
	while( m_pCurrent->next != pNode )
	{
		if( m_pCurrent->next == m_pTail )
		{
			return -2; // ¿À·ù2 : ÇØ´ç ³ëµå°¡ ¾øÀ½
		}
		m_pCurrent = m_pCurrent->next;
	} // while-end

	// »èÁ¦ÇÒ ³ëµå Ã£À½
	if( m_pCurrent->next  == pNode )
	{
		m_pCurrent->next = pNode->next;
		delete m_pCurrent;
	}
	m_nCount = m_nCount-1; // ÃÑ ³ëµå ¼ö -1
	return m_nCount;
}
// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º GetCount
// ÃÑ ³ëµå ¼ö¸¦ ¹ÝÈ¯ÇÑ´Ù.
int KNList :: GetCount()
{
	if(m_pHead->next == m_pTail)
	{
		return 0;
	}
	// Ä«¿îÆ® ³ëµå »ý¼º : countNode
	KNNode* countNode = m_pHead->next;

	// ÃÑ ³ëµå ¼ö °Ë»ö
	int nCount = 0;
	while( countNode != m_pTail )
	{
		++nCount;
		countNode = countNode->next;
	}
	return nCount;
}
// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º IsTail
// ÇöÀç À§Ä¡(m_pCurrnet)°¡ ³ëµå ²¿¸®(Tail)ÀÎÁö È®ÀÎÇÑ´Ù.
bool KNList :: IsTail()
{
	return m_pCurrent == m_pTail;
}
// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º IsHead
// ÇöÀç À§Ä¡(m_pCurrnet)°¡ ³ëµå ¸Ó¸®(Head)ÀÎÁö È®ÀÎÇÑ´Ù.
bool KNList :: IsHead()
{
	return m_pCurrent == m_pHead;
}
// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º ModifyNode
// »õ·Î¿î ³ëµå¸¦ µ¤¾î¾º¿ö¼­ ¼öÁ¤ÇÑ´Ù.
void KNList :: ModifyNode(KNNode* pNode)
{
	// µ¤¾î¾º¿ï ³ëµå ÁÖ¼Ò¸¦ ÀúÀåÇÒ ÀÓ½Ã ³ëµå »ý¼º
	KNNode* modify_node = m_pCurrent; 

	// µ¤¾î¾º¿ì±â ÀÛ¾÷
	GoPrev();
	m_pCurrent->next = pNode;
	pNode->next = modify_node->next;
	delete modify_node;

	// ÇöÀç À§Ä¡¸¦ ¼öÁ¤µÈ ³ëµå¸¦ °¡¸®Å´
	m_pCurrent = pNode;
}
// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º DeleteLine
// ³ëµå ¼ø¼­¹øÈ£¸¦ °Ë»öÇÏ¿© »èÁ¦ÇÑ´Ù.
int KNList :: DeleteLine(int lineNum)
{
	if( lineNum < 0 )
		return -1; // ¿À·ù1 : ¹øÈ£ ¿À·ù
	
	// »èÁ¦ÇÒ ¶óÀÎ(³ëµå) Ã£À½
	int line_count = 1;
	m_pCurrent = m_pHead->next;
	while( line_count != lineNum )
	{
		if( m_pCurrent == m_pTail )
		{
			return -2; // ¿À·ù2 : ¹øÈ£°¡ ÃÑ ³ëµå ¼öº¸´Ù Å­
		}
		++line_count;
		m_pCurrent = m_pCurrent->next;
	}
	
	// »èÁ¦ÇÒ ¶óÀÎ(³ëµå) ÀÌÀü ³ëµå Å½»ö
	KNNode* delete_node = m_pCurrent;
	m_pCurrent = m_pHead;
	while( m_pCurrent->next != delete_node )
	{
		m_pCurrent = m_pCurrent->next;
	}

	// »èÁ¦ÇÒ ³ëµå(delete_node)¿Í ÀÌÀü ³ëµå(m_pCurrent) Æ÷ÀÎÆÃ ¿Ï·á ¹× »èÁ¦
	if( m_pCurrent->next  == delete_node )
	{
		m_pCurrent->next = delete_node->next;
		delete delete_node;
	}
}
// ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¢º DeleteAll
// ³ëµå ÀüÃ¼¸¦ »èÁ¦ÇÑ´Ù.
void KNList :: DeleteAll()
{
	// ³ª¸ÓÁö ¸ðµç ³ëµå »èÁ¦
	while( m_pCurrent != m_pTail )
	{
		m_pCurrent = m_pHead->next;
		delete m_pCurrent;
	}

	// ¸Ó¸®³ëµå¿Í ²¿¸®³ëµå ¿¬°á
	m_pHead->next = m_pTail;
	m_pTail->next = m_pTail;
}