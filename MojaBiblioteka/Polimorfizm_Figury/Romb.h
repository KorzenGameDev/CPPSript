#include "Figura.h"

class Rowneleglobok :public Figura_niekulista
{
    float a,h;
public:
    Rownoleglobok(float x=1, float y=1)
    {
        a=x;
        h=y;
    }
    virtual void wprowadz()
    {
        cout<<"Wprowadz poprawny wartosc podstawy rownolegloboku : ";
        cin>>a;
        while(a<=0)
        {
            cout<<"Bledna wartosc podstawy!"<<endl;
            Sleep(1500);
            system("cls");
            cout<<"Wprowadz poprawna wartosc podstawy rownolegloboku: ";
            cin>>a;
        }
        cout<<"Wprowadz poprawna wartosc wysokosci rownelegloboku opuszczona na podana podstawe: ";
        cin>>h;
        while(h<=0)
        {
            cout<<"Bledna wartosc wysokosci!"<<endl;
            Sleep(1500);
            system("cls");
            cout<<"Dlugosc podstawy rownelegloboku wynosi: "<<a<<endl;
            cout<<"Wprowadz poprawna wartosc wysokosci rownelegloboku opuszczona na podana podstawe: ";
            cin>>h;
        }
    }
    virtual float pole()
    {
        if(a<=0 || h<=0)
            exit(0);
        return a*h;
    }
    virtual float obwod()
    {
        if(a<=0 || b<=0)
            exit(0);
        return 2*a+2*;
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
