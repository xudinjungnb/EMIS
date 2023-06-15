//员工类
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "tools.h"

namespace emis{
class Employee
{
	int m_iId;//员工id
	int m_iAge;//年龄
	char m_strName[20];//姓名
	char m_cSex;//性别
public:
	Employee(const char* name="",char sex=' ',int age=0);
	// 设置属性
	void setId(int id);
	void setAge(int age);
	void setName(const char* name);
	void setSex(char sex);
	// 获得属性
	int getId(void);
	int getAge(void);
	char* getName(void);
	char getSex(void);
	// 输出运算符
	friend ostream& operator <<(ostream& os,const Employee& emp);
	// 输入运算符
	friend istream& operator >>(istream& is,Employee& emp);
};
ostream& operator <<(ostream& os,const Employee& emp);
istream& operator >>(istream& is,Employee& emp);
}

#endif//EMPLOYEE_H
