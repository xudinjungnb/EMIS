#include "service_view_impl.h"
#include "service_ctrl_impl.h"
#include "tools.h"

//构造函数
emis::ServiceViewImpl::ServiceViewImpl(void)
{
    srcCtrl=new ServiceCtrlImpl;//父类指针指向子类对象
}
//析构函数
emis::ServiceViewImpl::~ServiceViewImpl(void)
{
    delete srcCtrl;
}
//业务子系统界面
void emis::ServiceViewImpl::menuSrc(void)
{
    while(true)
    {
        system("clear");
        cout<<"*****欢迎进入业务子系统*****"<<endl;
        cout<<"1、添加部门"<<endl;
        cout<<"2、删除部门"<<endl;
        cout<<"3、显示所有部门"<<endl;
        cout<<"4、添加员工"<<endl;
        cout<<"5、删除员工"<<endl;
        cout<<"6、显示部门员工"<<endl;
        cout<<"7、显示所有员工"<<endl;
        cout<<"8、退出系统"<<endl;
        switch(get_cmd('1','8'))
        {
            case '1':addDept();break;
            case '2':delDept();break;
            case '3':listDept();break;
            case '4':addEmp();break;
            case '5':delEmp();break;
            case '6':listEmp();break;
            case '7':listAllEmp();break;
            case '8':return;
        }
    }
}
//部门相关
//添加部门
void emis::ServiceViewImpl::addDept(void)
{
	char name[20]={};
	cout<<"请输入新部门的名字：";
	get_str(name,20);
    // 部门名称不能相同
    vector<Department> deps=srcCtrl->listDept();
    for(auto it=deps.begin();it!=deps.end();++it)
    {
        if(0==strcmp(it->getName(),name))
        {
            cout<<"部门名字冲突"<<endl;
            anykey_continue();
         return;
        }
    }
    
    Department dep(name);
    if(srcCtrl->addDept(dep))
    	cout<<"部门添加成功"<<endl;    
    else
        cout<<"部门id有误，添加失败"<<endl;
}
//删除部门
void emis::ServiceViewImpl::delDept(void)
{
    int id=0;
    cout<<"请输入要删除的部门id:";
    cin>>id;
    if(srcCtrl->delDept(id))
        cout<<"部门删除成功"<<endl;
    else
        cout<<"部门id有误，删除失败"<<endl;
}
//列出所有部门
void emis::ServiceViewImpl::listDept(void)
{
    vector<Department>& deps=srcCtrl->listDept();
    for(auto it=deps.begin();it!=deps.end();++it)
    {
        cout<<*it<<endl;
    }
    anykey_continue();
}
//员工相关
//添加员工
void emis::ServiceViewImpl::addEmp(void)
{
    int age=0,dep_id=0;
    char name[20]={};
    char sex=' ';
    cout<<"请输入员工年龄:";
    cin>>age;
    cout<<endl;
    cout<<"请输入员工姓名:";
    get_str(name,20);
    cout<<"请输入员工性别:";
    cin>>sex;
    cout<<endl;
    cout<<"请输入部门id:"<<endl;
    cin>>dep_id;
    
    Employee emp(name,sex,age);
    if(srcCtrl->addEmp(dep_id,emp))
        cout<<"员工添加成功"<<endl;
    else
        cout<<"员工添加失败"<<endl;  
}
//删除员工
void emis::ServiceViewImpl::delEmp(void)
{
    int id=0;
    cout<<"请输入要删除的员工id:";
    cin>>id;
    if(srcCtrl->delEmp(id))
        cout<<"员工删除成功"<<endl;
    else
        cout<<"员工id有误，删除失败"<<endl;
}
//修改员工信息
void emis::ServiceViewImpl::modEmp(void)
{
    int id=0,age=0;
    char name[20]={};
    char sex=' ';
    cout<<"请输入需要修改信息的员工id";
    cin>>id;
    cout<<endl;
    cout<<"员工姓名:";
    get_str(name,20);
    cout<<"员工年龄:";
    cin>>age;
    cout<<endl;
    cout<<"员工性别:";
    cin>>sex;
    
    Employee emp(name,sex,age);
    if(srcCtrl->modEmp(id,emp))
        cout<<"员工信息修改成功"<<endl;
    else
        cout<<"员工id有误，修改失败"<<endl;
}
//列出部门员工
void emis::ServiceViewImpl::listEmp(void)
{
    int id;
    cout<<"请输入部门id";
    cin>>id;
    Department* depp=srcCtrl->listEmp(id);
    if(NULL==depp)
    {
        cout<<"部门id有误，操作失败"<<endl;
       	return;
    }
    for(auto it=(depp->empArr).begin();it!=(depp->empArr).end();++it)
    {
        cout<<*it<<endl;
    }
}
//列出所有员工
void emis::ServiceViewImpl::listAllEmp(void)
{
    vector<Department>& deps=srcCtrl->listAllEmp();
    for(auto it=deps.begin();it!=deps.end();++it)
    {
        cout<<*it<<endl;
        cout<<"员工信息:"<<endl;
        for(auto i=(it->empArr).begin();i!=(it->empArr).end();++i)
        {
            cout<<*i<<endl;
        }
    }
}
