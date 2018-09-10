#include <iostream>
#include <cmath>
using namespace std;
int  convert(bool a[]){
    int mnogitel=1;
    int chislo=0;

    for (int i=0;i<=sizeof(a)*8-1;i++){
        chislo=chislo+a[i]*mnogitel;
        mnogitel=mnogitel*2;


    }
  cout<<endl<<chislo;


}

uint64_t normalize(double value)
{
    int64_t  m_integral=static_cast<int64_t>(floor(value));
            uint64_t m_fractional=static_cast<int64_t>(floor((value - m_integral) * 1e+18 + 0.5));
            int64_t tail = m_fractional % (1000);
    if (tail)
    {
        if (tail > 103/2)
            m_fractional += 1e+3 - tail;
        else
            m_fractional -= tail;

    }
    return m_fractional;
}

void foo2(){
    char c;
    cin>>c;
    bool m[sizeof(c)*8];
    for (char i=sizeof(c)*8-1;i>=0;i--){
        printf("%d",(c>>i)&1);
        m[i]=(c>>i)&1;



    }
    convert(m);


}
void foo3(){
    bool c;
    cin>>c;
    for (char i=sizeof(c)*8-1;i>=0;i--)
        printf("%d",(c>>i)&1);


}

void foo4(){
    double c;
    cin>>c;
    int64_t  m_integral=static_cast<int64_t>(floor(c));
  // uint64_t m_fractional=  normalize(c);
  uint64_t m_fractional=static_cast<int64_t>(floor((c- m_integral) * 1e+18 + 0.5));
    for (char i=sizeof(m_integral)*8-1;i>=0;i--)
        printf("%d",(m_integral>>i)&1);
    cout<<".";
    for (char i=sizeof(m_fractional)*8-1;i>=0;i--)
        printf("%d",(m_fractional>>i)&1);


}

void foo1(){

    int c;
    cin>>c;
    bool m[sizeof(c)*8];
    for (int i=sizeof(c)*8-1;i>=0;i--){
        printf("%d",(c>>i)&1);
        m[i]=(c>>i)&1;



    }
    convert(m);

}



//class decimal
//{
//    …
//private:
//    int64_t  m_integral;
//    uint64_t m_fractional;
//};

//decimal::decimal(double value)
//   :    m_integral(static_cast<int64_t>(std::floor(value))
//        m_fractional(static_cast<int64_t>(std::floor((value - m_integral) * 1e+18 + 0.5))
//{
//    normalize();
//}

//uint64_t normalize(double value)
//{
//    int64_t  m_integral=static_cast<int64_t>(floor(value));
//            uint64_t m_fractional=static_cast<int64_t>(floor((value - m_integral) * 1e+18 + 0.5));
//            int64_t tail = m_fractional % (1000);
//    if (tail)
//    {
//        if (tail > 103/2)
//            m_fractional += 1e+3 - tail;
//        else
//            m_fractional -= tail;

//    }
//    return m_fractional;
//}

int main()
{
    cout << " 1. int" << endl<<
            "2. char"<<endl<<

            "3. bool" <<endl<<
            "4. float" << endl;
    int a;
    cin>> a;
    switch (a) {
    case 1:
        foo1();
        break;
    case 2:
        foo2();
        break;
    case 3:
        foo3();
        break;
    case 4:
        foo4();
        break;
    default:
        main();
        break;
    }

    return 0;
}
