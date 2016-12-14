#include "CodeList.h"
#include "KNFile.h"
#include "Util.h"
#include <string>
#include "CodeItem.h"
using namespace std;

CodeListMgr::CodeListMgr()
{
	m_strFilePath = "ListImte.DB";
}
CodeListMgr::~CodeListMgr()
{
	RemoveAllItem();
}

int CodeListMgr::LoadData()
{
	KNFile knFile;
	int nCnt = 0;
	if(knFile.Open(m_strFilePath,"r"))
	{
		while(!knFile.IsEOF())
		{
			string str;
			knFile.ReadLine(str);
			vector<string> rgStr;
			CUtil::Tokenize(str,rgStr,",");
			if(rgStr.size() == 3)
			{
				Code* p = new Code(rgStr[0],rgStr[1],rgStr[2]);
				cout << rgStr[0] << rgStr[1] << rgStr[2];
				//cout << p->ToString();
				m_rgCodes.push_back(p );
			}
		}
	}
	return nCnt;
}
int CodeListMgr::RemoveAllItem()
{
	int cnt = m_rgCodes.size();
	list<Code*>::iterator iter;
	//for (iter = m_rgCodes.begin(); iter != m_rgCodes.end(); ++iter)
	for (iter = m_rgCodes.begin(); iter != m_rgCodes.end();)
	{
		delete (*iter);
		iter = m_rgCodes.erase(iter); //이넘이 ++을 대신 한다. 삭제 하면 다음 위치로 자동 이동 된다.
	}
	return cnt;
}
void CodeListMgr::Display()
{
	list<Code*>::iterator iter;
	for (iter = m_rgCodes.begin(); iter != m_rgCodes.end(); ++iter)
	{
		cout << (*iter)->ToString() << endl;
		//CLog::Instance()->WriteLog((*iter)->ToString(),__FILE__,__LINE__);
		
	}
}


int CodeListMgr::GetCodeData(string mainCode, vector<Code*>& vec)
{
	list<Code*>::iterator iter;
	for (iter = m_rgCodes.begin(); iter != m_rgCodes.end(); ++iter)
	{
		if((*iter)->GetMainCode() == mainCode)
		{
			vec.push_back((*iter));
		}
	}
	return vec.size();
}
