#ifndef SERVICE_CTRL_IMPL_H
#define SERVICE_CTRL_IMPL_H

#include "service_ctrl.h"
#include "service_mode.h"
#include "tools.h"

namespace emis{
class ServiceCtrlImpl:public ServiceCtrl
{
	ServiceMode* srcMode;//需要用到业务子系统中数据访问层的函数
	vector<Department> deptArr;//用于存储部门信息
public:
	ServiceCtrlImpl(void);
	~ServiceCtrlImpl(void);
	bool addDept(Department& dep);
	int delDept(int id);//根据部门id删除对应部门
	vector<Department>& listDept(void);//返回存储部门信息的vector
	bool modEmp(int id,Employee& emp);
	bool addEmp(int id,Employee& emp);//根据部门id，添加员工
	bool delEmp(int id);//根据员工id，删除对应员工
	Department* listEmp(int id);
	vector<Department>& listAllEmp();
};

}


#endif//SERVICE_CTRL_IMPL_H
