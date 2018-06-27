# include "tongxun.h"
void start()
{
    int n,cho;
    info*p;
    int num,t;
    while(num != 9)
    {
    cout<<"请输入下面的项目："<<endl;
    cout<<"1.创建"<<endl;
    cout<<"2.添加"<<endl;
    cout<<"3.查询"<<endl;
    cout<<"4.修改"<<endl;
    cout<<"5.删除"<<endl;
    cout<<"6.显示"<<endl;
    cout<<"7.文件导入"<<endl;
    cout<<"8.文件导出"<<endl;
    cout<<"9.退出"<<endl;
    string w;
    cin>>num;
    switch(num)
    {
    case 1:{cout<<"输出想要创建的信息组数："<<endl;cin>>n;p = cj(n);}break;
    case 2:{cout<<"输出你想要添加的位置前一个位置联系人的编号："<<endl;cin>>t;addI(p,t);}break;
    case 3:
    {
        cout<<"输出查询方式：1.姓名查询 2.手机查询"<<endl;
        cin>>cho;
        string n;
        if(cho == 1)
        {
         cout<<"输出要查询的姓名信息："<<endl;
         cin>>n;
         p=chaxunN(p,n);
        }
        else
        {
            cout<<"输出要查询的手机信息："<<endl;
            cin>>n;
            p=chaxunT(p,n);
        }
    }break;
    case 4 :{string y;cout<<"输出要修改的联系人姓名"<<endl;cin>>y;change(p,y);}break;
    case 5:
    {
        cout<<"输出删除方式：1.姓名删除 2.编号删除"<<endl;
        cin>>cho;
        string n;
        int g;
        if(cho == 1)
        {
         cout<<"输出要删除的姓名信息："<<endl;
         cin>>n;
         p=deleN(p,n);
        }
        else
        {
            cout<<"输出要删除的编号信息："<<endl;
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
