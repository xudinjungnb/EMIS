#include "manager_ctrl_impl.h"
#include "manager_mode_impl.h"
#include "tools.h"


emis::ManagerCtrlImpl::ManagerCtrlImpl(void)
{
	mgrMode = new ManagerModeImpl;
	mgrMode->load(mgrArr);
}

emis::ManagerCtrlImpl::~ManagerCtrlImpl(void)
{
	mgrMode->save(mgrArr);
	delete mgrMode;
}

bool emis::ManagerCtrlImpl::addMgr(Manager& mgr)
{
	int id = get_mgrid();
	if(-1 == id)	return false;
	
	mgr.setId(id);
	for(auto it=mgrArr.begin();it!=mgrArr.end();++it)
	{
		if(it->getId() == mgr.getId())//若存在相同的id，直接返回
		{
			return false;	
		}
	}
	mgrArr.push_back(mgr);
	return true;
}

bool emis::ManagerCtrlImpl::delMgr(int id)
{
	vector<Manager>::iterator it;
	for(it=mgrArr.begin(); it!=mgrArr.end(); ++it)
	{
		if(it->getId() == id)//id存在
		{
			mgrArr.erase(it);//删除
			return true;
		}
	}
	return false;
}

vector<emis::Manager>& emis::ManagerCtrlImpl::listMgr(void)
{
	return mgrArr;
}
