/************************************************* 
Copyright:bupt 
Author: chenyitong
Date:2016-09-15 
Description:  ��ͨѶ��
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
    friend  info* cj(int);//����
    info(){}
    info(int,string,string,int,string,string){}
    friend void show(info *);//��ʾ
    friend info* addI(info *,int);//���
   friend  info* chaxunT(info *,string);//�����ֻ���ѯ
   friend info* chaxunN(info *,string );//����������ѯ
   friend info* change(info*,string n);//���������޸�
    friend info* deleN(info*,string n);//��������ɾ��
   friend  info* deleB(info*,int n);//���ݱ��ɾ��
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
