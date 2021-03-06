#include <iostream>
#include <string>
#include "KNList.h"

// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ KNList
KNList :: KNList()
{
	// 該葬(Head) 喻萄
	m_pHead = new KNNode();
	memset(m_pHead, 0, sizeof(m_pHead));

	// 窒葬(Tail) /喻萄
	m_pTail = new KNNode();
	memset(m_pTail, 0, sizeof(m_pTail));

	m_pHead->next = m_pTail;
	m_pTail->next = m_pTail;	

	m_nCount = 0; // 識 喻萄 熱 0
	m_pCurrent = m_pHead;
}

// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ GetAt
// ⑷營 嬪纂蒂 奩�納挬�.
KNNode* KNList :: GetAt()
{
	return m_pCurrent;
}

// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ GoNext
// ⑷營 嬪纂縑憮 夥煎 棻擠 喻萄煎 檜翕и棻.
KNNode* KNList :: GoNext()
{
	// ⑷營 嬪纂陛 窒葬(Tail) 喻萄檣 唳辦
	if( m_pCurrent == m_pTail )
		return m_pTail;

	// ⑷營 嬪纂蒂 棻擠 喻萄蒂 陛葬霽
	m_pCurrent = m_pCurrent->next;
	return m_pCurrent;
}

// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ GoPrev
// ⑷營 嬪纂縑憮 夥煎 檜瞪 喻萄煎 檜翕
KNNode* KNList :: GoPrev()
{
	// ⑷營 嬪纂陛 該葬(Head) 喻萄檣 唳辦
	if( m_pCurrent == m_pHead )
		return m_pHead;

	// 檜瞪 喻萄 匐儀
	KNNode* temp_node = m_pHead; // 歜衛 喻萄
	while( temp_node->next == m_pCurrent )
	{
		temp_node = temp_node->next;
	}

	// ⑷營 嬪纂蒂 檜瞪 喻萄蒂 陛葬霽
	m_pCurrent = temp_node;
	return m_pCurrent;
}

// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ GoHead
// ⑷營 嬪纂蒂 該葬(Head) 喻萄煎 陛葬酈堅, 斜 嬪纂蒂 奩�納挬�.
KNNode* KNList ::GoHead()
{
	m_pCurrent = m_pHead;
	return m_pCurrent;
}

// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ GoTail
// ⑷營 嬪纂蒂 窒葬(Tail) 喻萄煎 陛葬酈堅, 斜 嬪纂蒂 奩�納挬�.
KNNode* KNList ::GoTail()
{
	m_pCurrent = m_pTail;
	return m_pCurrent;
}

// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ AddHead
// 葬蝶お 陛濰 擅縑 億煎遴 喻萄蒂 蹺陛и棻.
int KNList :: AddHead(KNNode* pNode)
{
	// 億煎遴 喻萄 蹺陛
	pNode->next = m_pHead->next;
	m_pHead->next = pNode;

	//⑷營 嬪纂蒂 億煎 蹺陛и 喻萄煎 陛葬霽
	m_pCurrent = pNode;

	++m_nCount; // 識 喻萄 熱 +1
	return GetCount();
}

// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ AddTail
// 葬蝶お 葆雖虞縑 億煎遴 喻萄蒂 蹺陛и棻.
int KNList :: AddTail(KNNode* pNode)
{
	// 窒葬(Tail) 喻萄 匐儀
	m_pCurrent = m_pHead;
	while( m_pCurrent->next != m_pTail )
	{
		m_pCurrent = m_pCurrent->next;
	}

	// 億煎遴 喻萄 蹺陛
	if( m_pCurrent->next == m_pTail )
	{
		pNode->next = m_pTail;
		m_pCurrent->next = pNode;
	}

	// ⑷營 嬪纂蒂 億煎 蹺陛и 喻萄煎 陛葬霽
	m_pCurrent = pNode;

	++m_nCount; // 識 喻萄 熱 +1
	return m_nCount;
}

// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ InsertAfter
// '⑷營 喻萄'諦 '棻擠 喻萄' 餌檜縑 億煎遴 喻萄蒂 儅撩и棻. 
int KNList :: InsertAfter(KNNode* pNode)
{
	if( m_pCurrent == m_pTail )
		GoHead(); // ⑷營 喻萄陛 窒葬(Tail)蒂 陛葬酈堅 氈朝 唳辦

	pNode->next = m_pCurrent->next;
	m_pCurrent->next = pNode;

	// ⑷營 嬪纂蒂 億煎 蹺陛и 喻萄煎 陛葬霽
	m_pCurrent = pNode;

	++m_nCount; // 識 喻萄 熱 +1
	return m_nCount;
}

// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ DeleteNode
// 喻萄蒂 匐儀ж罹 餉薯и棻.
int KNList :: DeleteNode(KNNode* pNode)
{
	if( pNode == m_pHead || pNode == m_pTail )
		return -1; // 螃盟1 : п渡 喻萄陛 ④萄(Head) 釭 窒葬(Tail)識歜

	// 餉薯й 喻萄 匐儀
	m_pCurrent = m_pHead;
	while( m_pCurrent->next != pNode )
	{
		if( m_pCurrent->next == m_pTail )
		{
			return -2; // 螃盟2 : п渡 喻萄陛 橈擠
		}
		m_pCurrent = m_pCurrent->next;
	} // while-end

	// 餉薯й 喻萄 瓊擠
	if( m_pCurrent->next  == pNode )
	{
		m_pCurrent->next = pNode->next;
		delete m_pCurrent;
	}
	m_nCount = m_nCount-1; // 識 喻萄 熱 -1
	return m_nCount;
}
// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ GetCount
// 識 喻萄 熱蒂 奩�納挬�.
int KNList :: GetCount()
{
	if(m_pHead->next == m_pTail)
	{
		return 0;
	}
	// 蘋遴お 喻萄 儅撩 : countNode
	KNNode* countNode = m_pHead->next;

	// 識 喻萄 熱 匐儀
	int nCount = 0;
	while( countNode != m_pTail )
	{
		++nCount;
		countNode = countNode->next;
	}
	return nCount;
}
// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ IsTail
// ⑷營 嬪纂(m_pCurrnet)陛 喻萄 窒葬(Tail)檣雖 �挫恉挬�.
bool KNList :: IsTail()
{
	return m_pCurrent == m_pTail;
}
// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ IsHead
// ⑷營 嬪纂(m_pCurrnet)陛 喻萄 該葬(Head)檣雖 �挫恉挬�.
bool KNList :: IsHead()
{
	return m_pCurrent == m_pHead;
}
// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ ModifyNode
// 億煎遴 喻萄蒂 竣橫噥錶憮 熱薑и棻.
void KNList :: ModifyNode(KNNode* pNode)
{
	// 竣橫噥選 喻萄 輿模蒂 盪濰й 歜衛 喻萄 儅撩
	KNNode* modify_node = m_pCurrent; 

	// 竣橫噥辦晦 濛機
	GoPrev();
	m_pCurrent->next = pNode;
	pNode->next = modify_node->next;
	delete modify_node;

	// ⑷營 嬪纂蒂 熱薑脹 喻萄蒂 陛葬霽
	m_pCurrent = pNode;
}
// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ DeleteLine
// 喻萄 牖憮廓�ㄧ� 匐儀ж罹 餉薯и棻.
int KNList :: DeleteLine(int lineNum)
{
	if( lineNum < 0 )
		return -1; // 螃盟1 : 廓�� 螃盟
	
	// 餉薯й 塭檣(喻萄) 瓊擠
	int line_count = 1;
	m_pCurrent = m_pHead->next;
	while( line_count != lineNum )
	{
		if( m_pCurrent == m_pTail )
		{
			return -2; // 螃盟2 : 廓�ㄟ� 識 喻萄 熱爾棻 躑
		}
		++line_count;
		m_pCurrent = m_pCurrent->next;
	}
	
	// 餉薯й 塭檣(喻萄) 檜瞪 喻萄 鬚儀
	KNNode* delete_node = m_pCurrent;
	m_pCurrent = m_pHead;
	while( m_pCurrent->next != delete_node )
	{
		m_pCurrent = m_pCurrent->next;
	}

	// 餉薯й 喻萄(delete_node)諦 檜瞪 喻萄(m_pCurrent) ん檣た 諫猿 塽 餉薯
	if( m_pCurrent->next  == delete_node )
	{
		m_pCurrent->next = delete_node->next;
		delete delete_node;
	}
}
// 收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收Ⅱ DeleteAll
// 喻萄 瞪羹蒂 餉薯и棻.
void KNList :: DeleteAll()
{
	// 釭該雖 賅萇 喻萄 餉薯
	while( m_pCurrent != m_pTail )
	{
		m_pCurrent = m_pHead->next;
		delete m_pCurrent;
	}

	// 該葬喻萄諦 窒葬喻萄 翱唸
	m_pHead->next = m_pTail;
	m_pTail->next = m_pTail;
}