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
    double z;
    float y;
    //double z;
};

int main()
{
    A a(1.1,2.2,3.3);

    cout<<"x:"<<a.GetX()<<" "<<"y:"<<a.GetY()<<" "<<"z:"<<a.GetZ()<<endl;//OK
    cout<<"x��ַ:"<<a.GetX(1)<<" "<<"y��ַ:"<<a.GetY(1)<<" "<<"z��ַ:"<<a.GetZ(1)<<endl;//OK
    //cout<<a.x<<" "<<a.y<<" "<<a.z<<endl;//error

    cout<<endl;

    cout<<"����a�ĵ�ַ:"<<&a<<endl;

    getchar();
    getchar();
    return 0;
}