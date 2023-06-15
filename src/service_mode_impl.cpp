#include "service_mode_impl.h"
#include "tools.h"

void emis::ServiceModeImpl::load(vector<Department>& depArr)
{
    //打开存放部门信息的文件
    ifstream ifs(DATA_DEPT_PATH,ios::in|ios::binary);
    if(!ifs)	return;
    
    while(true)
    {
        Department dep;
        ifs.read((char*)&dep,sizeof(dep));
        if(ifs.fail()) break;
        depArr.push_back(dep);
    }
    ifs.close();
}

void emis::ServiceModeImpl::save(vector<Department>& depArr)
{
    //打开存放部门信息的文件
    ofstream ofs(DATA_DEPT_PATH,ios::out|ios::binary);
    if(!ofs)	return;
    
    for(auto it=depArr.begin();it!=depArr.end();++it)
    {
        ofs.write((char*)(&(*it)),sizeof(Department));
    }
    ofs.close();
}
