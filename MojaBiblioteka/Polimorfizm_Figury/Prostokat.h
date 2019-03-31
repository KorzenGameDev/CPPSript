#include "Figura.h"

class Prostokat :public Figura_niekulista
{
    float a,b;
public:
    Prostokat(float x=1, float y=1)
    {
        a=x;
        b=y;
    }
    virtual void wprowadz()
    {
        cout<<"Wprowadz poprawny wartosc pierwszego boku prostokata: ";
        cin>>a;
        while(a<=0)
        {
            cout<<"Bledna wartosc boku!"<<endl;
            Sleep(1500);
            system("cls");
            cout<<"Wprowadz poprawny wartosc pierwszego boku prostokata: ";
            cin>>a;
        }
        cout<<"Wprowadz poprawny wartosc drugiego boku prostokata: ";
        cin>>b;
        while(b<=0)
        {
            cout<<"Bledna wartos boku!"<<endl;
            Sleep(1500);
            system("cls");
            cout<<"Dlugosc pierwszego boku prostokata wynosi: "<<a<<endl;
            cout<<"Wprowadz poprawny wartosc drugiego boku prostokata: ";
            cin>>b;
        }
    }
    virtual float pole()
    {
        if(a<=0 || b<=0)
            exit(0);
        return a*b;
    }
    virtual float obwod()
    {
        if(a<=0 || b<=0)
            exit(0);
        return 2*a+2*b;
    }
    virtual int ile_wierzcholkow()
    {
        return 4;
    }
    virtual int ile_bokow()
    {
        return 4;
    }

};
