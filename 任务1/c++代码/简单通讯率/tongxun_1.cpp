# include "tongxun.h"
void start()
{
    int n,cho;
    info*p;
    int num,t;
    while(num != 9)
    {
    cout<<"�������������Ŀ��"<<endl;
    cout<<"1.����"<<endl;
    cout<<"2.���"<<endl;
    cout<<"3.��ѯ"<<endl;
    cout<<"4.�޸�"<<endl;
    cout<<"5.ɾ��"<<endl;
    cout<<"6.��ʾ"<<endl;
    cout<<"7.�ļ�����"<<endl;
    cout<<"8.�ļ�����"<<endl;
    cout<<"9.�˳�"<<endl;
    string w;
    cin>>num;
    switch(num)
    {
    case 1:{cout<<"�����Ҫ��������Ϣ������"<<endl;cin>>n;p = cj(n);}break;
    case 2:{cout<<"�������Ҫ��ӵ�λ��ǰһ��λ����ϵ�˵ı�ţ�"<<endl;cin>>t;addI(p,t);}break;
    case 3:
    {
        cout<<"�����ѯ��ʽ��1.������ѯ 2.�ֻ���ѯ"<<endl;
        cin>>cho;
        string n;
        if(cho == 1)
        {
         cout<<"���Ҫ��ѯ��������Ϣ��"<<endl;
         cin>>n;
         p=chaxunN(p,n);
        }
        else
        {
            cout<<"���Ҫ��ѯ���ֻ���Ϣ��"<<endl;
            cin>>n;
            p=chaxunT(p,n);
        }
    }break;
    case 4 :{string y;cout<<"���Ҫ�޸ĵ���ϵ������"<<endl;cin>>y;change(p,y);}break;
    case 5:
    {
        cout<<"���ɾ����ʽ��1.����ɾ�� 2.���ɾ��"<<endl;
        cin>>cho;
        string n;
        int g;
        if(cho == 1)
        {
         cout<<"���Ҫɾ����������Ϣ��"<<endl;
         cin>>n;
         p=deleN(p,n);
        }
        else
        {
            cout<<"���Ҫɾ���ı����Ϣ��"<<endl;
            cin>>g;
            p=deleB(p,g);
        }
    }break;
    case 6:show(p);break;
    case 7:file_in(p);break;
    case 8:file_out(p);break;
    case 9:break;
    }
    }
}

int main()
{
    start();
    return 0;
}
