#include "manager_mode_impl.h"
#include "tools.h"

void emis::ManagerModeImpl::load(vector<emis::Manager>& mgrArr)
{
	ifstream ifs(DATA_MGR_PATH,ios::in|ios::binary);
	if(!ifs)	return;//打开失败，直接返回
	
	while(true)
	{
		Manager mgr;
		ifs.read((char*)&mgr,sizeof(mgr));
		if(ifs.fail())	break;
		mgrArr.push_back(mgr);
	}
	ifs.close();
}

void emis::ManagerModeImpl::save(const vector<emis::Manager>& mgrArr)
{
	ofstream ofs(DATA_MGR_PATH,ios::out|ios::binary);
	if(!ofs)	return;
	
	for(auto it=mgrArr.begin();it!=mgrArr.end();++it)
	{
		ofs.write((char*)(&(*it)),sizeof(Manager));
	}
	
	ofs.close();
}
