// 单例模式实现企业类
#ifndef EMIS_H
#define EMIS_H

#include "manager_view.h"
#include "tools.h"

namespace emis{

class EMIS
{
	ManagerView* mgrView;
	static EMIS emis_obj;//饿汉模式
	
	EMIS(void);//禁用无参构造无参构造
	EMIS(const EMIS& that){};//禁用拷贝构造
public:
	~EMIS(void);
	static EMIS& get_instance(void);//获得对象
	void emis_start(void);//信息管理系统开启
};

}



#endif//EMIS_H
