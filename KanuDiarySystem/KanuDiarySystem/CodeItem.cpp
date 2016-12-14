#include "CodeItem.h"
#include "KNFile.h"
#include "Util.h"
#include <string>
using namespace std;

Code::Code(void)
{

}
Code::Code(string strMainCode, string strSubCode , string strSubName)
{
	m_strMainCode = strMainCode; //���� ro ���
	m_strSubCode = strSubCode; //����Ű ������ ����Ѵ�.
	m_strSubName = strSubName; //��.
}

Code::~Code(void)
{


}

string Code::GetMainCode()
{
	return m_strMainCode;
}
string Code::GetSubCode()
{
	return m_strSubCode;
}
string Code::GetSubName()
{
	return m_strSubName;
}

string Code::ToString()
{
	char buff[1024] = {0};
	return m_strMainCode +","+ m_strSubCode +","+ m_strSubName ;
	//return CUtil::format("[%s][%s][%s]",m_strMainCode.c_str(),m_strSubCode.c_str(),m_strSubName.c_str());
}