#include "emis.h"
#include "manager_view_impl.h"
#include "tools.h"

emis::EMIS emis::EMIS::emis_obj;

emis::EMIS::EMIS(void)
{
	mgrView = new ManagerViewImpl;
	emis::init_id();//初始化id文件
}

emis::EMIS::~EMIS(void)
{
	delete mgrView;
}

emis::EMIS& emis::EMIS::get_instance(void)
{
	return emis_obj;
}

void emis::EMIS::emis_start(void)
{
	while(true)
	{
		system("clear");
		cout << "******欢迎使用在线企业管理系统******" << endl;
		cout << "1、登录管理子系统" << endl;
		cout << "2、登录业务子系统" << endl;
		cout << "3、退出系统" << endl;
		switch(emis::get_cmd('1','3'))
		{
		case '1':mgrView->loginManager();break;
		case '2':mgrView->loginService();break;
		case '3':return;
		}
	}
}
