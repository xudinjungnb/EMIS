#ifndef MANAGER_CTRL_IMPL_H
#define MANAGER_CTRL_IMPL_H

#include "manager_ctrl.h"
#include "manager_mode.h"
#include "tools.h"

namespace emis{
class ManagerCtrlImpl:public ManagerCtrl
{
	vector<Manager> mgrArr;// 用于存放管理员的向量
	ManagerMode* mgrMode;// 业务逻辑中需要调用数据访问层的方法进行数据存取
public:
	ManagerCtrlImpl(void);
	// 必须实现以下函数
	~ManagerCtrlImpl(void);
	bool addMgr(Manager& mgr);//添加管理员
	bool delMgr(int id);//删除管理员
	vector<Manager>& listMgr(void);//列出所有管理员
};
}

#endif//MANAGER_CTRL_IMPL_H
