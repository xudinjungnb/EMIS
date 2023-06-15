#ifndef MANAGER_CTRL_H
#define MANAGER_CTRL_H

#include "manager.h"
#include "tools.h"

namespace emis{
class ManagerCtrl
{
public:
	virtual ~ManagerCtrl(void){}
	virtual bool addMgr(Manager&)=0;// 添加管理员
	virtual bool delMgr(int)=0;// 删除管理员
	virtual vector<Manager>& listMgr(void)=0;// 列出所有管理员
};

}

#endif//MANAGER_CTRL_H
