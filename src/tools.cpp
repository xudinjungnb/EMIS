#include "tools.h"

using namespace std;
//	从键盘获取指定长度的字符串
char* emis::get_str(char* str,size_t len)
{
	if(NULL==str||0==len) return NULL;
	stdin->_IO_read_ptr=stdin->_IO_read_end;//先清空输入缓冲区
	size_t index=0;
	while(index<len-1)
	{
		int ch=getch();
		if('\n'==ch) break;
		if(127==ch)
		{
			if(index)
			{
				--index;
				printf("\b \b");
				continue;
			}
		}
		str[index++]=ch;
		printf("%c",ch);
	}
	str[index]='\0';
	printf("\n");//回显输入的\n
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	return str;
}

//	输入指定长度密码
char* emis::get_pass(char* str,size_t len,bool is_show)
{
	if(NULL==str||0==len) return NULL;
	stdin->_IO_read_ptr=stdin->_IO_read_end;//先清空输入缓冲区
	size_t index=0;
	while(index<len-1)
	{
		int key=getch();
		if('\n'==key) break;
		if(127==key)
		{
			if(index)
			{
				--index;
				printf("\b \b");
				continue;
			}
		}
		str[index++]=key;
		if(is_show)
			printf("%c",key);	
		else
			printf("*");
	}
	str[index]='\0';
	printf("\n");//回显输入的\n
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	return str;
}

//	获取范围指令
int emis::get_cmd(char start,char end)
{
	printf("请输入指令：");
	int cmd;
	while(true)
	{
		cmd=getch();
		if(cmd>=start && cmd<=end)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
	
}

//	按任意键继续
void emis::anykey_continue(void)
{
	puts("请按任意键继续...");

	stdin->_IO_read_ptr = stdin->_IO_read_end;
	getch();
}

//	初始化id文件
void emis::init_id(void)
{
	// 先看看文件是否存在
	FILE* fp = fopen(DATA_ID_PATH,"r");//打开文件
	if(NULL != fp)	 return;//文件已经存在，不用再初始化，直接返回
	
	// 若不存在，则以只写权限重新打开，会自动创建新文件
	fp = fopen(DATA_ID_PATH,"w");
	if(NULL == fp)//返回NULL，说明没有创建文件的权限
	{
		printf("权限有误，id文件创建失败\n");
		return;
	}
	
	int ids[3] = {10,100,1000};
	fwrite(ids,sizeof(ids),1,fp);
	fclose(fp);
}

//	生成获取管理员id
int emis::get_mgrid(void)
{
	FILE* fp = fopen(DATA_ID_PATH,"r+");
	if(NULL == fp)
	{
		printf("未对id文件初始化\n");
		return -1;
	}	
	
	int id = 0;
	fread(&id,4,1,fp);//读四个字节出来
	++id;
	fseek(fp,0,SEEK_SET);//将文件读写指针移动到开头
	fwrite(&id,4,1,fp);//把++完的id重新写回去
	fclose(fp);
	return id;
}

//	生成获取部门id
int emis::get_deptid(void)
{
	FILE* fp=fopen(DATA_ID_PATH,"r+");
	if(NULL==fp)
	{
		printf("未对id文件初始化\n");
		return -1;
	}
	
	int id=0;
	fseek(fp,4,SEEK_SET);//偏移四字节
	fread(&id,4,1,fp);
	++id;
	fseek(fp,4,SEEK_SET);//覆盖更新
	fwrite(&id,4,1,fp);
	
	fclose(fp);
	return id;
}

//	生成获取员工id
int emis::get_empid(void)
{
	FILE* fp=fopen(DATA_ID_PATH,"r+");
	if(NULL==fp)
	{
		printf("未对id文件初始化\n");
		return -1;
	}
	
	int id=0;
	fseek(fp,8,SEEK_SET);//偏移8字节
	fread(&id,4,1,fp);
	++id;
	fseek(fp,8,SEEK_SET);//覆盖更新
	fwrite(&id,4,1,fp);
	
	fclose(fp);
	return id;
}
