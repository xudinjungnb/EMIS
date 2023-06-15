//管理员类
#ifndef MANAGER_H
#define MANAGER_H

#include "tools.h"

namespace emis{
class Manager
{
	int m_iId;//id号
	char m_strName[20];//姓名
	char m_strPwd[20];//密码
public:
	Manager(const char* name="",const char* pwd="");
	// 获取属性
	int getId(void)const;
	const char* getName(void)const;
	const char* getPwd(void)const;
	// 设置属性
	void setId(int id);
	void setName(const char* name);
	void setPwd(const char* pwd);
	// 输出运算符重载
	friend ostream& operator<<(ostream& os,const Manager& mgr);
	// 输入运算符重载
	friend istream& operator>>(istream& is,Manager& mgr);
};
ostream& operator<<(ostream& os,const Manager& mgr);
istream& operator>>(istream& is,Manager& mgr);
}
#endif//MANAGER_H
