
//代码练习
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int t;
    FILE *fp=NULL;
    while(1)
    {
        cout<<"输入0对文件进行读取操作,输入1对文件进行默认改写操作,输入2对文件进行写入,输入3退出:";
        cin>>t;
        if(t==0)//读取数据
        {
            fp=fopen("D:\\VSCode\\MyCode\\WorkPlace2\\test2\\Mydate.txt","r");
            if(fp==NULL)
            {
                cout<<"文件打开失败"<<endl;
                cout<<"已退出"<<endl;
                return 0;
            }
            char str[100]={0};
            while(!feof(fp))
            {
                printf("%s\n",fgets(str,100,fp));
            }
            fclose(fp);
            getchar();
        }

        else if(t==1)//默认改写数据
        {
            fp=fopen("D:\\VSCode\\MyCode\\WorkPlace2\\test2\\Mydate.txt","w");

            if(fp==NULL)
            {
                cout<<"文件打开失败"<<endl;
                cout<<"已退出"<<endl;
                return 0;
            }
                cout<<"嘿嘿,你文件被我改写了"<<endl;

                fputs("苍茫茫的天涯是我的爱",fp);
            fclose(fp);
            getchar();
        }
        
        else if(t==2)//自定义改写数据
        {
            fp=fopen("D:\\VSCode\\MyCode\\WorkPlace2\\test2\\Mydate.txt","w");
            if(fp==NULL)
            {
                cout<<"文件打开失败"<<endl;
                cout<<"已退出"<<endl;
                return 0;
            }

            cout<<"要把文件内容改写为:"<<endl;
            char s[50];
            getchar();
            gets(s);
            char* sh=new char[strlen(s)+1];
            strcpy(sh,s);
            
            fputs(s,fp);
            delete sh;
            cout<<"自定义改写成功"<<endl;
            fclose(fp);
        }
        else if(t==3)
        {
            break;
        }
        cout<<endl;
    }
    return 0;
}