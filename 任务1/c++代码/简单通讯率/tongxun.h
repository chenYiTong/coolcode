/************************************************* 
Copyright:bupt 
Author: chenyitong
Date:2016-09-15 
Description:  简单通讯率
**************************************************/  
#ifndef TONGXUN_H_INCLUDED
#define TONGXUN_H_INCLUDED
#include <iostream>
#include<fstream>
#include <string>
using namespace std;
class info
{
    public:
    friend  info* cj(int);//创建
    info(){}
    info(int,string,string,int,string,string){}
    friend void show(info *);//显示
    friend info* addI(info *,int);//添加
   friend  info* chaxunT(info *,string);//依据手机查询
   friend info* chaxunN(info *,string );//依据姓名查询
   friend info* change(info*,string n);//依据姓名修改
    friend info* deleN(info*,string n);//依据姓名删除
   friend  info* deleB(info*,int n);//依据编号删除
   friend void file_in(info *);
    friend void file_out(info *);
   info *next;
  private:
   int number;
   string name;
   string sex;
   int age;
   string pho;
   string tel;
};
#include"tongxun.cpp"
#endif // TONGXUN_H_INCLUDED
