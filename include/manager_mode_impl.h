#ifndef MANAGER_MODE_IMPL_H
#define MANAGER_MODE_IMPL_H

#include "manager_mode.h"//ManagerMode类
#include "tools.h"

namespace emis{
class ManagerModeImpl : public ManagerMode
{
public:
	// 必须实现以下函数
	~ManagerModeImpl(void){}
	void load(vector<Manager>& mgrArr);//加载管理员信息
	void save(const vector<Manager>& mgrArr);//保存管理员信息
};

}

#endif//MANAGER_MODE_IMPL_H
