#include "Figura.h"

class Kolo :public Figura_kulista
{
    float r;
public:
    Kolo(float x=1)
    {
        r=x;
    }

    virtual void wprowadz()
    {
        cout<<"Wprowadz poprawny wartosc promien kola: ";
        cin>>r;
        while(r<=0)
        {
            cout<<"Bledna wartos promienia!"<<endl;
            Sleep(1500);
            system("cls");
            cout<<"Wprowadz poprawny wartosc promien kola: ";
            cin>>r;
        }
    }

    virtual float obwod()
    {
        if(r<=0)
            exit(0);

        return 2*r*M_PI;
    }
    virtual float pole()
    {
        if(r<=0)
            exit(0);

        return r*r*M_PI;
    }
    virtual float srednica()
    {
        if(r<=0)
            exit(0);
        return 2*r;
    }
};
