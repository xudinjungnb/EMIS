#ifndef SERVICE_VIEW_IMPL_H
#define SERVICE_VIEW_IMPL_H

#include "service_view.h"
#include "service_ctrl.h"
#include "tools.h"

namespace emis{
class ServiceViewImpl:public ServiceView
{
	ServiceCtrl* srcCtrl;//需要使用业务子系统的业务逻辑层函数
public:
    ServiceViewImpl(void);
    //必须要实现以下函数
    ~ServiceViewImpl(void);//析构函数
    void menuSrc(void);//业务子系统界面,在登录函数中调用
    //部门相关
    void addDept(void);//添加部门
    void delDept(void);//删除部门
    void listDept(void);//列出所有部门
    //员工相关
    void addEmp(void);//添加员工
    void delEmp(void);//删除员工
    void modEmp(void);//修改员工信息
    void listEmp(void);//列出部门员工
    void listAllEmp(void);//列出所有员工
};
}

#endif//SERVICE_VIEW_IMPL_H
