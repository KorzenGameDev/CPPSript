#include "Figura.h"

class Czworokat :public Figura_niekulista :public Punkty_Uklad_Kartezjanski
{
    string name;
    float a,b,c,d;
    float
    int choice_1,choice_2;
    float kat;
public:
    Czworokat(string n="Zamknij",float x1=NB_0, float x2=NB_0, float x3=NB_0, float x4=NB_0,int c1=NB_0,int c2=NB_0,float k=NB_0)
    {
        name=n;
        a=x1;
        b=x2;
        c=x3;
        d=x4;
        choice_1=c1;
        choice_2=c2;
        kat=k;
    }

    virtual void wprowadz()
    {
        while(choice_1<=NB_0 || choice_1>NB_9)
        {
            cout<<"------------------------------------"<<endl;
            cout<<"O jaki czworokat ci chodzi?"<<endl;
            cout<<"------------------------------------"<<endl;
            cout<<"1.Kwadrat"<<endl;
            cout<<"2.Prostokat"<<endl;
            cout<<"3.Romb"<<endl;
            cout<<"4.Rownoleglobok"<<endl;
            cout<<"5.Trapez"<<endl;
            cout<<"6.Deltoid"<<endl;
            cout<<"7.Dowolny czworokat wpisany w okrag"<<endl;
            cout<<"8.Dowolny czworokat"<<endl;
            cout<<"9.Zamknij"<<endl<<endl;
            cout<<"WYBOR: "; cin>>choice;
            if(choice_1<=NB_0 || choice>NB_9)
            {
                cout<<"ERROR!"<<endl;
                Sleep(MEDIUM_SLEEP);
                system("cls");
            }
        }

        switch(choice_1)
        { //poczatek switch_1
        case NB_1:  name="kwadrat";
            while(choice_2<=NB_0 ||choice_2>NB_6)
            {
                Sleep(SHORT_SLEEP);
                system("cls");
                cout<<"---------------------------------"<<endl;
                cout<<"KWADRAT"<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<"Podaj metode obliczenia pola:"<<endl;
                cout<<"1.Oblicz za pomoca dlugosci boku"<<endl;
                cout<<"2.Oblicz za pomoca dlugosci przekatnej"<<endl;
                cout<<"3.Oblicz za pomoca siatki kartezjanskiej"<<endl;
                cout<<"4.Oblicz za pomoca promienia okregu wpisanego w ten kwadrat"<<endl;
                cout<<"5.Oblicz za pomoca promienia okregu opisanego na tym kwadracie"<<endl;
                cout<<"6.Zamknij"<<endl;
                cin>>choice_2;
                if(choice_2<=NB_0 || choice_2>NB_6)
                    cout<<endl<<"ERROR!"<<endl;
            }

            switch(choice_2)
            { //poczatek switch_2
            case 1:
                while(a<=NB_0)
                {
                    Sleep(SHORT_SLEEP);
                    system("cls");
                    cout<<"----------------------------------"<<endl;
                    cout<<"KWADRAT"<<endl;
                    cout<<"Metoda liczenia pola: DLUGOSC BOKU"<<endl;
                    cout<<"----------------------------------"<<endl;
                    cout<<"Podaj dlugosc boku: "<<endl;
                    cin>>a;
                    if(a<=NB_0)
                        cout<<endl<<"ERROR!"<endl;
                }
                break;
            case 2:
                while(a<=NB_0)
                {
                    Sleep(SHORT_SLEEP);
                    system("cls");
                    cout<<"----------------------------------"<<endl;
                    cout<<"KWADRAT"<<endl;
                    cout<<"Metoda liczenia pola: DLUGOSC PRZEKATNEJ"<<endl;
                    cout<<"----------------------------------"<<endl;
                    cout<<"Podaj dlugosc przekatnej: "<<endl;
                    cin>>a;
                    if(a<=NB_0)
                        cout<<endl<<"ERROR!"<endl;
                }
            break;
             case 3:
                while(a<=NB_0)
                {
                    Sleep(SHORT_SLEEP);
                    system("cls");
                    cout<<"----------------------------------"<<endl;
                    cout<<"KWADRAT"<<endl;
                    cout<<"Metoda liczenia pola: SIATKA KARTEZJANSKA"<<endl;
                    cout<<"----------------------------------"<<endl;
                    cout<<"Podaj wspolrzedne wierzcholkow A,B,C i D:"<<endl;
                    cout<<"Zacznij od pkt wysunietego najdalej na lewo!"<<endl;
                    cout<<"Nastepne pkt wypisuj zgodnie z ruchem wskazowek zegara:"<<endl;
                    Punkty_Uklad_Kartezjanski p(4);
                    p.wczytaj();
                }
            break;

             case 4:
                while(a<=NB_0)
                {
                    Sleep(SHORT_SLEEP);
                    system("cls");
                    cout<<"----------------------------------"<<endl;
                    cout<<"KWADRAT"<<endl;
                    cout<<"Metoda liczenia pola: DLUGOSC PROMIENIA OKREGU WPISANEGO"<<endl;
                    cout<<"----------------------------------"<<endl;
                    cout<<"Podaj dlugosc promienia: "<<endl;
                    cin>>a;
                    if(a<=NB_0)
                        cout<<endl<<"ERROR!"<endl;
                }
            break;

             case 5:
                while(a<=NB_0)
                {
                    Sleep(SHORT_SLEEP);
                    system("cls");
                    cout<<"----------------------------------"<<endl;
                    cout<<"KWADRAT"<<endl;
                    cout<<"Metoda liczenia pola: DLUGOSC PROMIENIA OKREGU OPISANEGO"<<endl;
                    cout<<"----------------------------------"<<endl;
                    cout<<"Podaj dlugosc promienia: "<<endl;
                    cin>>a;
                    if(a<=NB_0)
                        cout<<endl<<"ERROR!"<endl;
                }
            break;

             case 6:
                system("cls");
                cout<<endl<<"ZAMYKAM PROGRAM..."<<endl;
                Sleep(LONG_SLEEP);
                exit(NB_0);
            break;

            default: break;
            //koniec switch_2
        }

        case NB_2:
            while(a<=NB_0)
            {
                Sleep(SHORT_SLEEP);
                system("cls");
                cout<<"---------------------------------"<<endl;
                cout<<"PROSTOKAT"<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<"Podaj dlugosc pierwszego boku prostokata: ";
                cin>>a;
            }
            break;
        default: break;
        //koniec switch_1
        }
    }
    virtual float pole()
    {

    }
    virtual float obwod()
    {

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
