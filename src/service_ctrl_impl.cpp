#include "service_ctrl_impl.h"
#include "service_mode_impl.h"
#include "tools.h"

emis::ServiceCtrlImpl::ServiceCtrlImpl(void)
{
    srcMode=new ServiceModeImpl;
    srcMode->load(deptArr);
}

emis::ServiceCtrlImpl::~ServiceCtrlImpl(void)
{
    srcMode->save(deptArr);
    delete srcMode;
}
//部门相关
//添加部门
bool emis::ServiceCtrlImpl::addDept(emis::Department& dep)
{
    int id=get_deptid();
    if(-1==id) return false;
    
    dep.setId(id);
    for(auto it=deptArr.begin();it!=deptArr.end();++it)
    {
        if(it->getId()==dep.getId())
        {
            return false;
        }
    }
    deptArr.push_back(dep);
    return true;
}
//根据部门id删除对应部门
int emis::ServiceCtrlImpl::delDept(int id)
{
    for(auto it=deptArr.begin();it!=deptArr.end();++it)
    {
        if(it->getId()==id)
        {
            deptArr.erase(it);
            return true;
        }
    }
    return false;
}
//返回存储部门信息的vector
vector<emis::Department>& emis::ServiceCtrlImpl::listDept(void)
{
    return deptArr;
}
//员工相关
//根据部门id，添加员工
bool emis::ServiceCtrlImpl::addEmp(int id,Employee& emp)
{
    int emp_id=get_empid();
    if(-1==emp_id) return false;
    
    emp.setId(emp_id);
    //先找到部门
    for(auto it=deptArr.begin();it!=deptArr.end();++it)
    {
        if(it->getId()==id)//找到了
        {
            (it->empArr).push_back(emp);
            return true;
        }
    }
    //没找到
    return false;
}
//根据员工id，删除对应员工
bool emis::ServiceCtrlImpl::delEmp(int id)
{
    //需要遍历所有员工
    for(auto it=deptArr.begin();it!=deptArr.end();++it)//遍历所有部门
    {
        for(auto i=(it->empArr).begin();i!=(it->empArr).end();++i)//遍历部门里的员工
        {
            if(i->getId()==id)//找到了
            {
                (it->empArr).erase(i);//删除该员工
                return true;
            }
        }
    }
    //没找到
    return false;
}
//根据员工id，修改对应员工信息
bool emis::ServiceCtrlImpl::modEmp(int id,Employee& emp)
{
	//需要遍历所有员工
    for(auto it=deptArr.begin();it!=deptArr.end();++it)//遍历所有部门
    {
        for(auto i=(it->empArr).begin();i!=(it->empArr).end();++i)//遍历部门里的员工
        {
            if(i->getId()==id)//找到了
            {
                (it->empArr).erase(i);//删除该员工
                (it->empArr).push_back(emp);//添加
                return true;
            }
        }
    }
    //没找到
    return false;
}
//根据提供的部门id，返回对应部门信息
emis::Department* emis::ServiceCtrlImpl::listEmp(int id)
{
    for(auto it=deptArr.begin();it!=deptArr.end();++it)
    {
        if(it->getId()==id)//找到部门
        {
            return &(*it);
        }
    }
    //没找到
    return NULL;
}
//返回所有所有部门信息
vector<emis::Department>& emis::ServiceCtrlImpl::listAllEmp()
{
    return deptArr;
}
