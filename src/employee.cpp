#include "employee.h"
#include "tools.h"
emis::Employee::Employee(const char* name,char sex,int age):	m_cSex(sex),m_iAge(age)
{
	strcpy(m_strName,name);
}
// 设置属性
void emis::Employee::setId(int id)
{
	m_iId=id;
}
void emis::Employee::setAge(int age)
{
	m_iAge=age;
}
void emis::Employee::setName(const char* name)
{
	strcpy(m_strName,name);
}
void emis::Employee::setSex(char sex)
{
	m_cSex=sex;
}
// 获得属性
int emis::Employee::getId(void)
{
	return m_iId;
}
int emis::Employee::getAge(void)
{
	return m_iAge;
}
char* emis::Employee::getName(void)
{
	return m_strName;
}
char emis::Employee::getSex(void)
{
	return m_cSex;
}
// 输出运算符
ostream& emis::operator <<(ostream& os,const Employee& emp)
{
	return os<<emp.m_iId<<" "<<emp.m_strName<<" "<<emp.m_cSex<<" "<<emp.m_iAge;
}
// 输入运算符
istream& emis::operator >>(istream& is,Employee& emp)
{
	return is>>emp.m_iId>>emp.m_strName>>emp.m_cSex>>emp.m_iAge;
}

