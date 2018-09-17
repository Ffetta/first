#include <iostream>
#include <cmath>
#include <cstring>
#include <cmath>;
using namespace std;


int  convert(bool a[]){
    int mnogitel=1;
    int chislo=0;

    for (int i=0;i<=sizeof(a)*8-1;i++){
        chislo=chislo+a[i]*mnogitel;
        mnogitel=mnogitel*2;
       }
    cout<<endl<<"v desetichnoi "<<chislo;

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
void foo4(int c);
void foo1(int c);




void izmena(int* c){
    int a=0;
    bool b=0;
    cout<<" kakou bit?"<<endl;
    cin >>a;
    a=pow(2,a);

    cout<<" na cto(1 or 0)?"<<endl;
    cin>> b;



    if (b==0){
        *c = *c & ~(a);


    }
    else{
        *c=*c|(a);
    }
}



void foo3(int c){
    //cin>>c;
    bool m[sizeof(c)*16];
    for (int i=sizeof(c)*16-1;i>=0;i--){
        printf("%d",(c>>i)&1);
        m[i]=(c>>i)&1;
    }

}

void foo4(int c){
    bool m[sizeof(c)*8+1];
    for (int i=sizeof(c)*8-1;i>=0;i--){
        printf("%d",(c>>i)&1);
        m[i]=(c>>i)&1;
    }
    cout<<endl<<"znak "<< m[32]<<endl<<"poryadok ";
    for (int i=31;i>23;i--){
        cout<<m[i];
    }
    cout<<endl<<"mantisa";
    for (int i=23;i>=0;i--){
        cout<<m[i];
    }
    int d=0;
    cout<< endl<<"xotite izmenit?"<<endl<<"1 da"<<endl<<"0 net"<<endl;
    cin>>d;
    if (d==1){
        int *s=&c;
        izmena(s);
        foo4(c);
    }

}

void foo1(int c){

    bool m[sizeof(c)*8];
    for (int i=sizeof(c)*8-1;i>=0;i--){
        printf("%d",(c>>i)&1);
        m[i]=(c>>i)&1;


    }
    convert(m);
    int d=0;
    cout<< endl<<"xotite izmenit?"<<endl<<"1 da"<<endl<<"0 net"<<endl;
    cin>>d;
    if (d==1){
        int *s=&c;
        izmena(s);
        foo1(c);
    }

}






int perevod(int s, char chislo[]){
    int a=1;
    int result=0;
    for (int i=strlen(chislo)-1; i>=0;i--){
        if ((int)chislo[i]<58){
            result=result+((int)chislo[i]-48)*a;
        }

        else{
            if ((int)chislo[i]<91){
                result=result+((int)chislo[i]-55)*a;

            }
            else{
                result=result+((int)chislo[i]-61)*a;
            }
        }

        a=a*s;
    }
    cout<<result<<endl;
    return result;

}




int main()
{     
    cout << " 1. int (v liboy sisteme)" << endl<<
            "2. char"<<endl<<

            "3.  float" <<endl<<
            "4. double" << endl;
    int ab;
    cin>> ab;
    int s=0;
    switch (ab) {
    case 1:
    {char chislo[100];
        cout << " sistema scislenia " << endl;
        cin>> s;
        cout<<"Введите число"<<endl;
        cin>>chislo;
        int clislo_v_des =perevod(s,chislo);
        foo1(clislo_v_des);}
        break;
    case 2:
        foo2();
        break;
    case 3:
    { float *c;
        c = new float;
        cin>>*c;
        int *f;
        f=(int*)c;
        foo4(*f);}
        break;
    case 4:
        double *c;
        c= new double;
        cin>>*c;
        int *f;
        f=(int*)c;
        foo3(*f);
        break;
    default:
        main();
        break;
    }

    return 0;
}
