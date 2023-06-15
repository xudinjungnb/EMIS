#ifndef MANAGER_VIEW_IMPL_H
#define MANAGER_VIEW_IMPL_H

#include "manager_view.h"
#include "manager_ctrl.h"
#include "service_view.h"
#include "tools.h"

namespace emis{
class ManagerViewImpl:public ManagerView
{
	ManagerCtrl* mgrCtrl;//需要调用管理子系统中业务逻辑层的函数
	ServiceView* srcView;//需要调用业务子系统中的用户接口层函数
public:
	ManagerViewImpl(void);
	// 必须实现一下函数，否则无法实例化类
	~ManagerViewImpl(void);//析构函数，可以不用与父类析构同名
	void loginManager(void);//管理子系统登陆界面
	void loginService(void);//业务子系统登陆界面
	void menuMgr(void);//超级管理员功能列表
	void delMgr(void);//删除管理员
	void addMgr(void);//添加管理员
	void listMgr(void);//列出所有管理员
};
}

#endif//MANAGER_VIEW_IMPL_H
