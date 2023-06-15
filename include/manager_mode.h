#ifndef MANAGER_MODE_H
#define MANAGER_MODE_H

#include "manager.h"
#include "tools.h"

namespace emis{
class ManagerMode
{
public:
	virtual ~ManagerMode(void){}
	virtual void load(vector<Manager>& mgrArr)=0;//加载管理员信息
	virtual void save(const vector<Manager>& mgrArr)=0;//保存管理员信息
};

}

#endif//MANAGER_MODE_H
