#ifndef MANAGER_VIEW_H
#define MANAGER_VIEW_H

#include "tools.h"

namespace emis{
class ManagerView
{
public:
	virtual ~ManagerView(void){}
	virtual void loginManager(void)=0;//管理子系统登陆界面
	virtual void loginService(void)=0;//业务子系统登陆界面
	virtual void menuMgr(void)=0;//超级管理员功能列表
	virtual void addMgr(void)=0;//删除管理员
	virtual void delMgr(void)=0;//添加管理员
	virtual void listMgr(void)=0;//列出所有管理员
};

}

#endif//MANAGER_VIEW_H
