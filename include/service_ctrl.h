#ifndef SERVICE_CTRL_H
#define SERVICE_CTRL_H

#include "department.h"
#include "tools.h"

namespace emis{
class ServiceCtrl
{
public:
	 virtual ~ServiceCtrl(void){}
	 virtual bool addDept(Department&)=0;// 添加部门
	 virtual int delDept(int)=0;// 删除部门
	 virtual vector<Department>& listDept(void)=0;// 列出所有部门
	 virtual bool addEmp(int,Employee&)=0;// 添加员工
	 virtual bool delEmp(int)=0;// 删除员工
	 virtual bool modEmp(int,Employee&)=0;//修改员工信息
	 virtual Department* listEmp(int)=0;// 列出所有部门
	 virtual vector<Department>& listAllEmp()=0;// 列出所有员工
};

}

#endif//SERVICE_CTRL_H
