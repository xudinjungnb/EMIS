#include "department.h"
#include "tools.h"

emis::Department::Department(const char* name)
{
	strcpy(m_strName,name);
}
emis::Department::~Department(void)
{
}
//	设置属性
void emis::Department::setId(int id)
{
	m_iId=id;
}
void emis::Department::setName(char* name)
{
	strcpy(m_strName,name);
}
//  获得属性
int emis::Department::getId(void)
{
	return m_iId;
}
char* emis::Department::getName(void)
{
	return m_strName;
}
// 输出运算符
ostream& emis::operator <<(ostream& os,const emis::Department& dep)
{
	return os<<dep.m_iId<<" "<<dep.m_strName;
}
// 输入运算符
istream& emis::operator >>(istream& is,emis::Department& dep)
{
	return is>>dep.m_iId>>dep.m_strName;//输入时以空格间隔
}
