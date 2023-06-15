#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include <vector>
#include <fstream>

using namespace std;

namespace emis{
#define DATA_ID_PATH "../data/id.dat"
#define DATA_MGR_PATH "../data/managers.dat"
#define DATA_DEPT_PATH "../data/departments.dat"

//	从键盘获取指定长度的字符串
char* get_str(char* str,size_t len);

//	输入指定长度密码
char* get_pass(char* str,size_t len,bool is_show=false);

//	获取范围指令
int get_cmd(char start,char end);

//	按任意键继续
void anykey_continue(void);

//	初始化id文件
void init_id(void);

//	生成获取管理员id
int get_mgrid(void);

//	生成获取部门id
int get_deptid(void);

//	生成获取员工id
int get_empid(void);

}
#endif//TOOLS_H
