#include "Punkty_Uklad_Kartezjanski.h"

class Kwadrat :public Punkty_Uklad_Kartezjanski
{
    float a;
public:
    Kwadrat(float x=NB_0)
    {
        a=x;
    }
    void wczytaj()
    {
        int choice=NB_0;
        while(choice<=NB_0 || choice>NB_6)
        {
            Sleep(SHORT_SLEEP);
            system("cls");
            cout<<endl<<"KWADRAT"<<endl;
            cout<<"KTORE Z SPOSOBOW WYKORZYSTAC DO POLICZENIA POLA I OBWODU"<<endl<<endl;
            cout<<"1.BOK"<<endl;
            cout<<"2.PRZEKATNA"<<endl;
            cout<<"3.WSPOLRZEDNE WIERZCHOLKOW"<<endl;
            cout<<"4.KOLO OPISANE"<<endl;
            cout<<"5.KOLO WPISANE"<<endl;
            cout<<"6.ZAMKNIJ"<<endl;
            cout<<endl<<"WYBOR: "<<endl;
            cin>>choice;
            if(choice<=NB_0 || choice>NB_6)
                cout<<endl<<"ERROR!"<<endl;
        }

        switch(choice)
        {
        case NB_1:
            while(a<=0)
            {
                Sleep(SHORT_SLEEP);
                system("cls");
                cout<<endl<<"PODAJ POPRAWNA DLUGOSC BOKU: ";
                cin>>a;
                if(a<=0)
                   cout<<endl<<"ERROR!"<<endl;
            }
        break;

        case NB_2:
            while(a<=0)
            {
                Sleep(SHORT_SLEEP);
                system("cls");
                cout<<endl<<"PODAJ POPRAWNA DLUGOSC PRZEKATNEJ: ";
                cin>>a;
                if(a<=0)
                   cout<<endl<<"ERROR!"<<endl;
            }
        break;

        case NB_3:
            Punkty_Uklad_Kartezjanski::wczytaj();

        break;
        }
    }
    float pole()
    {

    }
    float obwod()
    {
    }
    int ile_wierzcholkow()
    {
        return 4;
    }
    int ile_bokow()
    {
        return 4;
    }

};
