
//������ϰ
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int t;
    FILE *fp=NULL;
    while(1)
    {
        cout<<"����0���ļ����ж�ȡ����,����1���ļ�����Ĭ�ϸ�д����,����2���ļ�����д��,����3�˳�:";
        cin>>t;
        if(t==0)//��ȡ����
        {
            fp=fopen("D:\\VSCode\\MyCode\\WorkPlace2\\test2\\Mydate.txt","r");
            if(fp==NULL)
            {
                cout<<"�ļ���ʧ��"<<endl;
                cout<<"���˳�"<<endl;
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

        else if(t==1)//Ĭ�ϸ�д����
        {
            fp=fopen("D:\\VSCode\\MyCode\\WorkPlace2\\test2\\Mydate.txt","w");

            if(fp==NULL)
            {
                cout<<"�ļ���ʧ��"<<endl;
                cout<<"���˳�"<<endl;
                return 0;
            }
                cout<<"�ٺ�,���ļ����Ҹ�д��"<<endl;

                fputs("��ãã���������ҵİ�",fp);
            fclose(fp);
            getchar();
        }
        
        else if(t==2)//�Զ����д����
        {
            fp=fopen("D:\\VSCode\\MyCode\\WorkPlace2\\test2\\Mydate.txt","w");
            if(fp==NULL)
            {
                cout<<"�ļ���ʧ��"<<endl;
                cout<<"���˳�"<<endl;
                return 0;
            }

            cout<<"Ҫ���ļ����ݸ�дΪ:"<<endl;
            char s[50];
            getchar();
            gets(s);
            char* sh=new char[strlen(s)+1];
            strcpy(sh,s);
            
            fputs(s,fp);
            delete sh;
            cout<<"�Զ����д�ɹ�"<<endl;
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