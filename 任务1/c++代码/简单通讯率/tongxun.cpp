#include <iostream>
#include"tongxun.h"
using namespace std;
info* cj(int n)
{
    info *pHead, //�׽ڵ�ָ��
         *pRear, //β�ڵ�ָ��
         *pNew; //�½ڵ�ָ��
    int i;
    for (i=0;i<n;i++)
    {
        pNew=new info;
        cout<<"��ţ� "<<endl;
        cin>>pNew->number;
        cout<<"������ "<<endl;
        cin>>pNew->name;
        cout<<"�Ա� "<<endl;
        cin>>pNew->sex;
        cout<<"���䣺 "<<endl;
        cin>>pNew->age;
        cout<<"լ�磺 "<<endl;
        cin>>pNew->pho;
        cout<<"�ֻ��� "<<endl;
        cin>>pNew->tel;
        if (0 == i)
        {
            pRear = pHead = pNew;
        }
        else
        {
            pRear -> next = pNew;//�½ڵ�Ϊβ�ڵ�
        }
        pNew -> next = NULL;//û���½��
        pRear = pNew;//��β��㸳��
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
        cout<<"�������ţ� "<<endl;
        cin>>pNew -> number;
        cout<<"������������ "<<endl;
        cin>>pNew -> name;
        cout<<"�������Ա� "<<endl;
        cin>>pNew -> sex;
        cout<<"���������䣺 "<<endl;
        cin>>pNew -> age;
        cout<<"������լ�磺 "<<endl;
        cin>>pNew -> pho;
        cout<<"�������ֻ��� "<<endl;
        cin>>pNew -> tel;
        pNew -> next = pDest->next;
        pDest -> next = pNew;
        cout<<"�����ɣ� "<<endl;
    }
    else
    {
        cout<<"δ�ҵ�ָ���ڵ㣡 "<<endl;
    }
    return pHead;
}
info* chaxunN(info *pHead,string a)//������ѯ
{
    info *pDest = pHead;
    assert(pDest != NULL);
    while (pDest -> next != NULL && pDest -> name != a)
    {
        pDest = pDest -> next;
    }
    if (pDest -> name == a)
    {cout<<"���ҳɹ�����ϵ����ϢΪ�����"<<pDest -> number<<" ���� "<<pDest -> name<<" �Ա� "<<pDest -> sex<<"  ���� "<<pDest -> age<<" լ�� "<<pDest -> pho<<" �ֻ� "<<pDest -> tel<<endl;
    return pDest;
    }
    else
    {
        cout<<"����ʧ�ܣ�δ�ҵ��Ҷ�ӵ�д����ֵ��ˣ� ";
        return NULL;
    }
}
info* chaxunT(info *pHead,string b)//�ֻ���ѯ
{
    info *pDest = pHead;
    while (pDest -> next != NULL && pDest -> tel != b)
    {
        pDest = pDest->next;
    }
    if (pDest -> tel == b)
    {
        cout<<"���ҳɹ�����ϵ����ϢΪ�����"<<pDest -> number<<" ���� "<<pDest -> name<<" �Ա� "<<pDest -> sex<<"  ���� "<<pDest -> age<<" լ�� "<<pDest -> pho<<" �ֻ� "<<pDest -> tel<<endl;
    return pDest;
    }
    else
    {
        cout<<"����ʧ�ܣ�δ�ҵ����ֻ��ŵ���ϵ�ˣ� ";
        return NULL;
    }
}
info* deleB(info *pHead,int nu)
{
    info *pDest, //Ҫɾ���Ľڵ�
         *pBefore; //ǰһ���ڵ�
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
       cout<<"����ϵ���ѱ�ɾ���� "<<endl;
    }
    else
    {
        cout<<"δ�ҵ�ָ����ϵ�ˣ��޷�����ɾ���� "<<endl;
    }
    return pHead;
}
info* deleN(info *pHead,string a)
{
    info *pDest, //Ҫɾ���Ľڵ�
         *pBefore; //ǰһ���ڵ�
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
       cout<<"����ϵ���ѱ�ɾ���� "<<endl;
    }
    else
    {
        cout<<"δ�ҵ�ָ����ϵ�ˣ��޷�����ɾ���� "<<endl;
    }
    return pHead;
}
void show(info *pHead)
{
    info *pTemp = pHead;
    while (pTemp != NULL)
    {
       cout<<"���"<<pTemp -> number<<" ���� "<<pTemp -> name<<" �Ա� "<<pTemp -> sex<<"  ���� "<<pTemp -> age<<" լ�� "<<pTemp -> pho<<" �ֻ� "<<pTemp -> tel<<endl;
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
        cout<<"��Ҫ�޸���ϵ�˵�������Ϣ�� 1-��� 2-���� 3-�Ա� 4-���� 5-լ�� 6-�ֻ�����ѡ��:"<<endl;
        cin>>k;
        cout<<"������Ҫ�޸ĵ���Ϣ��"<<endl;
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
        cout<<"�޸�ʧ�ܣ�δ�ҵ�ӵ�д����ֵ��ˣ� ";
        return NULL;
    }
}
void file_in(info *pHead)
{
    ifstream infile("ͨѶ��.txt",ios::in);
    if(!infile)
    {
        cerr<<"open error!"<<endl;
    {
        infile>>pNew -> number>>pNew -> name>>pNew -> sex>>pNew -> age>>pNew -> pho>>pNew -> tel;
        pNew=pNew -> next;
    }
    cout<<"����ɹ���"<<endl;
    infile.close();
}
        exit(1);
    }
    info *pNew = pHead;
    while(pNew)
void file_out(info *p)
{
    ofstream outfile("ͨѶ��.txt",ios::out);
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    info *pNew = p;
    while(pNew)
    {
        outfile<<pNew -> number<<pNew -> name<<pNew -> sex<<pNew -> age<<pNew -> pho<<pNew -> tel;
        cout<<"���"<<pNew -> number<<" ���� "<<pNew -> name<<" �Ա� "<<pNew -> sex<<"  ���� "<<pNew -> age<<" լ�� "<<pNew -> pho<<" �ֻ� "<<pNew -> tel<<endl;
        pNew=pNew -> next;
    }
    cout<<"�����ɹ���"<<endl;
    outfile.close();
}

