// 部门类
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "tools.h"
#include "employee.h"

 namespace emis{
class Department
{
	int m_iId;//部门id号
	char m_strName[20];//部门名
public:
	vector<Employee> empArr;//部门员工列表
public:
	Department(const char* name="");
	~Department(void);
	//	设置属性
	void setId(int id);
	void setName(char* name);
	//  获得属性
	int getId(void);
	char* getName(void);
	// 输出运算符
	friend ostream& operator <<(ostream& os,const Department& dep);
	// 输入运算符
	friend istream& operator >>(istream& is,Department& dep);
};
ostream& operator <<(ostream& os,const Department& dep);
istream& operator >>(istream& is,Department& dep);
}
#endif//DEPARTMENT_H
