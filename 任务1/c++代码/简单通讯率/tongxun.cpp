#include <iostream>
#include"tongxun.h"
using namespace std;
info* cj(int n)
{
    info *pHead, //首节点指针
         *pRear, //尾节点指针
         *pNew; //新节点指针
    int i;
    for (i=0;i<n;i++)
    {
        pNew=new info;
        cout<<"编号： "<<endl;
        cin>>pNew->number;
        cout<<"姓名： "<<endl;
        cin>>pNew->name;
        cout<<"性别： "<<endl;
        cin>>pNew->sex;
        cout<<"年龄： "<<endl;
        cin>>pNew->age;
        cout<<"宅电： "<<endl;
        cin>>pNew->pho;
        cout<<"手机： "<<endl;
        cin>>pNew->tel;
        if (0 == i)
        {
            pRear = pHead = pNew;
        }
        else
        {
            pRear -> next = pNew;//新节点为尾节点
        }
        pNew -> next = NULL;//没有新结点
        pRear = pNew;//给尾结点赋空
    }
    return pHead;
}
info *addI(info *pHead,int nu)
{
    info *pDest, *pNew;
    pDest = pHead;
    while(pDest -> next != NULL && pDest -> number != nu)
    {
        pDest = pDest->next;
    }
    if(pDest -> number == nu)
    {
        pNew = new info;
        cout<<"请输入编号： "<<endl;
        cin>>pNew -> number;
        cout<<"请输入姓名： "<<endl;
        cin>>pNew -> name;
        cout<<"请输入性别： "<<endl;
        cin>>pNew -> sex;
        cout<<"请输入年龄： "<<endl;
        cin>>pNew -> age;
        cout<<"请输入宅电： "<<endl;
        cin>>pNew -> pho;
        cout<<"请输入手机： "<<endl;
        cin>>pNew -> tel;
        pNew -> next = pDest->next;
        pDest -> next = pNew;
        cout<<"添加完成！ "<<endl;
    }
    else
    {
        cout<<"未找到指定节点！ "<<endl;
    }
    return pHead;
}
info* chaxunN(info *pHead,string a)//姓名查询
{
    info *pDest = pHead;
    assert(pDest != NULL);
    while (pDest -> next != NULL && pDest -> name != a)
    {
        pDest = pDest -> next;
    }
    if (pDest -> name == a)
    {cout<<"查找成功，联系人信息为：编号"<<pDest -> number<<" 姓名 "<<pDest -> name<<" 性别 "<<pDest -> sex<<"  年龄 "<<pDest -> age<<" 宅电 "<<pDest -> pho<<" 手机 "<<pDest -> tel<<endl;
    return pDest;
    }
    else
    {
        cout<<"搜索失败，未找到找定拥有此名字的人！ ";
        return NULL;
    }
}
info* chaxunT(info *pHead,string b)//手机查询
{
    info *pDest = pHead;
    while (pDest -> next != NULL && pDest -> tel != b)
    {
        pDest = pDest->next;
    }
    if (pDest -> tel == b)
    {
        cout<<"查找成功，联系人信息为：编号"<<pDest -> number<<" 姓名 "<<pDest -> name<<" 性别 "<<pDest -> sex<<"  年龄 "<<pDest -> age<<" 宅电 "<<pDest -> pho<<" 手机 "<<pDest -> tel<<endl;
    return pDest;
    }
    else
    {
        cout<<"搜索失败，未找到此手机号的联系人！ ";
        return NULL;
    }
}
info* deleB(info *pHead,int nu)
{
    info *pDest, //要删除的节点
         *pBefore; //前一个节点
    pDest = pHead;
    while (pDest -> next != NULL && pDest -> number != nu)
    {
        pBefore = pDest;
        pDest = pDest -> next;
    }
    if (pDest -> number == nu)
    {
        if (pDest == pHead)
        {
            pHead = pDest -> next;
        }
        else
        {
            pBefore -> next = pDest -> next;
        }
        free(pDest);
       cout<<"该联系人已被删除！ "<<endl;
    }
    else
    {
        cout<<"未找到指定联系人，无法将其删除！ "<<endl;
    }
    return pHead;
}
info* deleN(info *pHead,string a)
{
    info *pDest, //要删除的节点
         *pBefore; //前一个节点
    pDest = pHead;
    while (pDest -> next != NULL && pDest -> name != a)
    {
        pBefore = pDest;
        pDest = pDest -> next;
    }
    if (pDest -> name == a)
    {
        if (pDest == pHead)
        {
            pHead = pDest -> next;
        }
        else
        {
            pBefore -> next = pDest -> next;
        }
        free(pDest);
       cout<<"该联系人已被删除！ "<<endl;
    }
    else
    {
        cout<<"未找到指定联系人，无法将其删除！ "<<endl;
    }
    return pHead;
}
void show(info *pHead)
{
    info *pTemp = pHead;
    while (pTemp != NULL)
    {
       cout<<"编号"<<pTemp -> number<<" 姓名 "<<pTemp -> name<<" 性别 "<<pTemp -> sex<<"  年龄 "<<pTemp -> age<<" 宅电 "<<pTemp -> pho<<" 手机 "<<pTemp -> tel<<endl;
        pTemp = pTemp -> next;
    }
}
info* change(info *pHead,string a)
{
     info *pDest = pHead;
     int k;
    while (pDest -> next != NULL && pDest -> name != a)
    {
        pDest = pDest -> next;
    }
    if (pDest -> name == a)
    {
        cout<<"想要修改联系人的哪项信息？ 1-编号 2-姓名 3-性别 4-年龄 5-宅电 6-手机（请选择）:"<<endl;
        cin>>k;
        cout<<"请输入要修改的信息："<<endl;
        switch(k)
        {
            case 1:cin>>pDest -> number;break;
            case 2:cin>>pDest -> name;break;
            case 3:cin>>pDest -> sex;break;
            case 4:cin>>pDest -> age;break;
            case 5:cin>>pDest -> pho;break;
            case 6:cin>>pDest -> tel;break;
        }
    return pDest;
    }
    else
    {
        cout<<"修改失败，未找到拥有此名字的人！ ";
        return NULL;
    }
}
void file_in(info *pHead)
{
    ifstream infile("通讯率.txt",ios::in);
    if(!infile)
    {
        cerr<<"open error!"<<endl;
    {
        infile>>pNew -> number>>pNew -> name>>pNew -> sex>>pNew -> age>>pNew -> pho>>pNew -> tel;
        pNew=pNew -> next;
    }
    cout<<"导入成功！"<<endl;
    infile.close();
}
        exit(1);
    }
    info *pNew = pHead;
    while(pNew)
void file_out(info *p)
{
    ofstream outfile("通讯率.txt",ios::out);
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    info *pNew = p;
    while(pNew)
    {
        outfile<<pNew -> number<<pNew -> name<<pNew -> sex<<pNew -> age<<pNew -> pho<<pNew -> tel;
        cout<<"编号"<<pNew -> number<<" 姓名 "<<pNew -> name<<" 性别 "<<pNew -> sex<<"  年龄 "<<pNew -> age<<" 宅电 "<<pNew -> pho<<" 手机 "<<pNew -> tel<<endl;
        pNew=pNew -> next;
    }
    cout<<"导出成功！"<<endl;
    outfile.close();
}

