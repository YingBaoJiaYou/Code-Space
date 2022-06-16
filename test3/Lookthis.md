由于已知在同一一类对象下，同种数据类型的存储地址具有连续性，且先后存储顺序与数据成员的声明顺序有关。  
故此次专门对同一类对象下的不同数据类型的存储地址是否也具有连续性进行测试  
  
在此系统下，int占4个字节，float占4个字节，double占8个字节  


关于测试的代码模板以及情况展示  

**测试一：关于int和double**  

代码部分  
~~~
#include <iostream>
using namespace std;

class A
{
public:
    A(int x,double y,int z):x(x),y(y),z(z){}
    ~A(){}
    int GetX(){return x;}
    double GetY(){return y;}
    int GetZ(){return z;}

    int* GetX(int t){return &x;}
    double* GetY(int t){return &y;}
    int* GetZ(int t){return &z;}
private:
    int x;
    //int z;
    double y;
    int z;
};

int main()
{
    A a(1,2.0,3);

    cout<<"x:"<<a.GetX()<<" "<<"y:"<<a.GetY()<<" "<<"z:"<<a.GetZ()<<endl;//OK
    cout<<"x地址:"<<a.GetX(1)<<" "<<"y地址:"<<a.GetY(1)<<" "<<"z地址:"<<a.GetZ(1)<<endl;//OK
    //cout<<a.x<<" "<<a.y<<" "<<a.z<<endl;//error

    cout<<endl;

    cout<<"对象a的地址:"<<&a<<endl;

    getchar();
    getchar();
    return 0;
}

~~~  
关于声明1  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3ae8p2ij3j304402mdfv.jpg "")  

关于结果1  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3aebhgt3pj30hh0bzabt.jpg "") 

声明2  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3aeiw04tnj303f02oq2z.jpg "")  

结果2  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3aejvoi3ij30hh098abv.jpg "")  
  


此例发现，不int和double之间，其存储地址是不连续的  

但是有个规律  
无论int类的数据变量于double类的数据变量或先或后声明  
都有：  
int类数据与double类数据的存储地址均相差4个字节。  
  
**测试二：关于int和float**  
~~~
#include <iostream>
using namespace std;

class A
{
public:
    A(int x,float y,int z):x(x),y(y),z(z){}
    ~A(){}
    int GetX(){return x;}
    float GetY(){return y;}
    int GetZ(){return z;}

    int* GetX(int t){return &x;}
    float* GetY(int t){return &y;}
    int* GetZ(int t){return &z;}
private:
    int x;
    //int z;
    float y;
    int z;
};

int main()
{
    A a(1,2.5,3);

    cout<<"x:"<<a.GetX()<<" "<<"y:"<<a.GetY()<<" "<<"z:"<<a.GetZ()<<endl;//OK
    cout<<"x地址:"<<a.GetX(1)<<" "<<"y地址:"<<a.GetY(1)<<" "<<"z地址:"<<a.GetZ(1)<<endl;//OK
    //cout<<a.x<<" "<<a.y<<" "<<a.z<<endl;//error

    cout<<endl;

    cout<<"对象a的地址:"<<&a<<endl;

    getchar();
    getchar();
    return 0;
}

~~~  
 关于声明1  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3afcys4mbj304402ljre.jpg "")  

关于结果1  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3aff0joejj30hh098765.jpg "") 

声明2  
![](http://tva1.sinaimg.cn/large/008tz3FNgy1h3afhpu1ngj304s02qmx7.jpg "")  

结果2  
![](http://tva1.sinaimg.cn/large/008tz3FNgy1h3afh8ohssj30hh098q4v.jpg "")  
  
  
以上，int与float的存储地址非连续  
而且发现int和float存储地址的特性与int和double存储地址的特性是一致的  

**测试三：关于int和char**  
代码部分  
~~~
#include <iostream>
using namespace std;

class A
{
public:
    A(int x,char y,int z):x(x),y(y),z(z){}
    ~A(){}
    int GetX(){return x;}
    char GetY(){return y;}
    int GetZ(){return z;}

    int* GetX(int t){return &x;}
    char* GetY(int t){return &y;}
    int* GetZ(int t){return &z;}
private:
    int x;
    //int z;
    char y;
    int z;
};

int main()
{
    A a(1,'A',3);

    cout<<"x:"<<a.GetX()<<" "<<"y:"<<a.GetY()<<" "<<"z:"<<a.GetZ()<<endl;//OK
    cout<<"x地址:"<<a.GetX(1)<<" "<<"y地址:"<<a.GetY(1)<<" "<<"z地址:"<<a.GetZ(1)<<endl;//OK
    //cout<<a.x<<" "<<a.y<<" "<<a.z<<endl;//error

    cout<<endl;

    cout<<"对象a的地址:"<<&a<<endl;

    getchar();
    getchar();
    return 0;
}
~~~
关于声明1  
![](http://tva1.sinaimg.cn/large/008tz3FNgy1h3ag2mg9arj305502umx6.jpg "")  

关于结果1  
![](http://tva1.sinaimg.cn/large/008tz3FNgy1h3ag32oqw2j30hh098q4k.jpg "") 

声明2  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3ag8kzsz3j303t02k3yj.jpg "")  

结果2  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3ag7y8yqwj30hh098dhi.jpg "")  

声明3  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3ag5msds6j304t028dfs.jpg "")  

结果3  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3ag4pnpoaj30hh098abq.jpg "")  

  
int与char类存储地址非连续  
3个结果中，char数据类型的地址表现十分奇怪,  
推测可能char的存储形式比较特殊的原因。  
  
但结果1和2中，即时x和z相差一个数据类型，但是二者
的存储地址却只相差4个字节，非常有趣，
与前面两种测试情况有相通之处；  

结果3尝试把char最先声明，但依旧改变不了char
存储地址的问题，
但是发现对象a的首地址与第二个声明的x也是相差
4个字节，而后呈现同数据类型存储地址连续性的情况。

**测试四：关于float和double**  
  
代码部分  
~~~
#include <iostream>
using namespace std;

class A
{
public:
    A(double x,float y,double z):x(x),y(y),z(z){}
    ~A(){}
    double GetX(){return x;}
    float GetY(){return y;}
    double GetZ(){return z;}

    double* GetX(double t){return &x;}
    float* GetY(double t){return &y;}
    double* GetZ(double t){return &z;}
private:
    double x;
    //double z;
    float y;
    double z;
};

int main()
{
    A a(1.1,2.2,3.3);

    cout<<"x:"<<a.GetX()<<" "<<"y:"<<a.GetY()<<" "<<"z:"<<a.GetZ()<<endl;//OK
    cout<<"x地址:"<<a.GetX(1)<<" "<<"y地址:"<<a.GetY(1)<<" "<<"z地址:"<<a.GetZ(1)<<endl;//OK
    //cout<<a.x<<" "<<a.y<<" "<<a.z<<endl;//error

    cout<<endl;

    cout<<"对象a的地址:"<<&a<<endl;

    getchar();
    getchar();
    return 0;
}
~~~
关于声明1  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3agjg65vxj304f02m0su.jpg "")  

关于结果1  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3agjtwrz4j30hh098abx.jpg "") 

声明2  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3agmx6cmjj304602m0su.jpg "")  

结果2  
![](http://tva1.sinaimg.cn/large/008tz3FNly1h3agmcy5u1j30hh09840d.jpg "")  


就目前来看，double和float前后交换的话也并不是全都连续的，主要存在两种情况：  
当double在float先，则存储地址连续；
而float在double前，则存储地址有4个字节是断开状态。  

以上，此次测试并结合之前测试发现：  
在同一类对象下，同一数据类类型数据成员（private）的存储地址是连续的，  
而不同数据类型数据成员的存储地址并不满足连续性，但存在连续的情况（上述）。
