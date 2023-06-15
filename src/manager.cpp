#include "manager.h"
#include "tools.h"
emis::Manager::Manager(const char* name,const char* pwd)
{
	strcpy(m_strName,name);
	strcpy(m_strPwd,pwd);
}
// 获取属性
int emis::Manager::getId(void)const
{
	return m_iId;
}
const char* emis::Manager::getName(void)const
{
	return m_strName;
}
const char* emis::Manager::getPwd(void)const
{
	return m_strPwd;
}
// 设置属性
void emis::Manager::setId(int id)
{
	m_iId=id;
}
void emis::Manager::setName(const char* name)
{
	strcpy(m_strName,name);
}
void emis::Manager::setPwd(const char* pwd)
{
	strcpy(m_strPwd,pwd);
}
// 输出运算符重载
ostream& emis::operator<<(ostream& os,const Manager& mgr)
{
	return os << mgr.m_iId << " " << mgr.m_strName << " " << mgr.m_strPwd;
}
// 输入运算符重载
istream& emis::operator>>(istream& is,Manager& mgr)
{
	return is >> mgr.m_iId >> mgr.m_strName >> mgr.m_strPwd;
}
