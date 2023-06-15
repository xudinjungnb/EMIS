#include "manager_view_impl.h"
#include "service_view_impl.h"
#include "manager_ctrl_impl.h"
#include "tools.h"

emis::ManagerViewImpl::ManagerViewImpl(void)
{
	mgrCtrl=new ManagerCtrlImpl;
	srcView=new ServiceViewImpl;
	
}
emis::ManagerViewImpl::~ManagerViewImpl(void)
{
	delete mgrCtrl;
	delete srcView;
}
//管理子系统登陆界面
void emis::ManagerViewImpl::loginManager(void)
{
	char id[10]={},pwd[20] = {};
	cout << "请输入超级用户ID:";
	emis::get_str(id,10);
	cout << "请输入超级用户密码:";
	emis::get_pass(pwd,20);
	
	if(!strcmp(id,"admin") && !strcmp(pwd,"1234"))
	{
		menuMgr();//跳转到超级管理员界面
	}
	else
	{
		cout << "用户名或密码有误,登录失败" << endl;
		emis::anykey_continue();
	}
}
//业务子系统登陆界面
void emis::ManagerViewImpl::loginService(void)
{
	int id = 0;
	cout << "请输入普通管理员ID:";
	cin >> id;
	char pwd[20] = {};
	cout << "请输入普通管理员密码:";
	emis::get_pass(pwd,20);
	
	//检查id与密码
	vector<Manager>& mgrArr = mgrCtrl->listMgr();
	for(auto it=mgrArr.begin();it!=mgrArr.end();++it)
	{
		if(it->getId() == id && 0 == strcmp(it->getPwd(),pwd))
		{
			srcView->menuSrc();//跳转到业务子系统
			return;
		}
		else
		{
			cout << "用户名或密码有误,登录失败" << endl;
			emis::anykey_continue();
		}
	}
}
//超级管理员功能列表
void emis::ManagerViewImpl::menuMgr(void)
{
	while(true)
	{
		system("clear");
		cout << "***欢迎进入管理子系统***" << endl;
		cout << "1、添加管理员" << endl;
		cout << "2、删除管理员" << endl;
		cout << "3、显示所有管理员" << endl;
		cout << "4、退出管理子系统" << endl;
		
		switch(emis::get_cmd('1','4'))
		{
			case '1': addMgr();break;
			case '2': delMgr();break;
			case '3': listMgr();break;
			case '4': return;		
		}
	}
	
}
//删除管理员
void emis::ManagerViewImpl::delMgr(void)
{
	int id = 0;
	cout << "请输入要删除的管理员id:";
	cin >> id;
	if(mgrCtrl->delMgr(id))
		cout << "删除管理员成功" << endl;
	else
		cout << "id有误,删除失败" << endl;
	emis::anykey_continue();
	
}
//添加管理员
void emis::ManagerViewImpl::addMgr(void)
{
	char name[20] = {},pwd[20] = {},repwd[20] = {};
	cout << "请输入新管理员用户名:";
	emis::get_str(name,20);
	cout << "请输入新管理员密码:";
	emis::get_pass(pwd,20);
	cout << "请再次输入新管理员密码:";
	emis::get_pass(repwd,20);
	if(strcmp(pwd,repwd))
	{
		cout << "两次输入的密码不相同，添加失败!" << endl;
		emis::anykey_continue();
		return;
	}
	
	Manager mgr(name,pwd);//创建新管理员
	if(mgrCtrl->addMgr(mgr))
		cout << "添加新管理员成功" << endl;
	else
		cout << "管理员id有误,添加失败" << endl;
	emis::anykey_continue();
}
//列出所有管理员
void emis::ManagerViewImpl::listMgr(void)
{
	vector<Manager>& mgrArr = mgrCtrl->listMgr();
	for(auto it=mgrArr.begin();it!=mgrArr.end();++it)
	{
		cout << *it << endl;	
	}
	emis::anykey_continue();
}
