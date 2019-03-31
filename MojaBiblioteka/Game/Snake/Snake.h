#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

const int DOgraniczenie=5;
const int GOgraniczenie=35;

struct obiekty{
    int xPos=0,yPos=0;
    bool jest=false;
}jedzenie, waz;


class Snake
{
  private:
      int szerokosc,wysokosc,predkosc;
      int gora, dol, prawo, lewo, key;
      int punkty;
      char **plansza;


  public:
    Snake()
    {
        szerokosc=wysokosc=predkosc=gora=dol=prawo=lewo=key=punkty=0;
        srand(time(NULL));
    }
    ~Snake()
    {
        for(int i=0;i<wysokosc;i++)
            delete[] plansza[i];
        delete[] *plansza;
    }
    void sterowanie(int &klawisz)
    {
        klawisz=getch();
        if(klawisz==224) klawisz+=getch();
        else if(klawisz==0) klawisz-=getch();
    }
    void wczytaj()
    {
        cout<<"WCZYTYWANIE"<<endl;
        while(szerokosc<=DOgraniczenie || szerokosc>GOgraniczenie)
        {
            cout<<"Podaj szerokosc planszy: ";
            cin>>szerokosc;
        }
        while(wysokosc<=DOgraniczenie || wysokosc>GOgraniczenie)
        {
            cout<<"Podaj wysokosc planszy: ";
            cin>>wysokosc;
        }
        cout<<"Podaj predkosc weza(1-10): ";
        cin>>predkosc;
        if(predkosc<=0) predkosc=1;
        else if(predkosc>10) predkosc=10;
        plansza=new char*[wysokosc];
        for(int i=0;i<wysokosc;i++)
        {
            plansza[i]=new char[szerokosc];
        }

        cout<<endl<<"STEROWANIE"<<endl;
        cout<<"GORA"<<endl;
        sterowanie(gora);
        cout<<"DOL"<<endl;
        sterowanie(dol);
        cout<<"PRAWO"<<endl;
        sterowanie(prawo);
        cout<<"LEWO"<<endl;
        sterowanie(lewo);
    }

    void rysuj()
    {
        for(int i=0; i<wysokosc; i++)
        {
            for(int j=0; j<szerokosc; j++)
            {
                //bazowa plansza
                if(i==0 && j==0) plansza[i][j]=201;
                else if(i==wysokosc-1 && j==0) plansza[i][j]=200;
                else if(i==0 && j==szerokosc-1) plansza[i][j]=187;
                else if(i==wysokosc-1 && j==szerokosc-1) plansza[i][j]=188;
                else if(j==0 || j==szerokosc-1 && (i!=0 && i!=wysokosc-1)) plansza[i][j]=186;
                else if(i==0 || i==wysokosc-1 &&(j!=0 && j!=szerokosc-1)) plansza[i][j]=205;
                //koniec rysowania obramowan
                else if(i==jedzenie.yPos && j==jedzenie.xPos) plansza[i][j]=178;
                else if(i==waz.yPos && j==waz.xPos) plansza[i][j]=219;
                else plansza[i][j]=32;
                if(j>0 && j<szerokosc-1)
                    cout<<plansza[i][j]<<plansza[i][j];
                cout<<plansza[i][j];
            }
            cout<<endl;
        }
    }

    void graObiekty()
    {
        if(waz.xPos==jedzenie.xPos && waz.yPos==jedzenie.yPos)
        {
            plansza[jedzenie.yPos][jedzenie.xPos]=32;
            jedzenie.jest=false;
            punkty+=10;
        }

        if(jedzenie.jest==false)
        {
            jedzenie.jest=true;
            jedzenie.xPos=rand()%(szerokosc-1);
            if(jedzenie.xPos==0) jedzenie.xPos=1;
            jedzenie.yPos=rand()%(wysokosc-1);
            if(jedzenie.yPos==0) jedzenie.yPos=1;
        }

        if(waz.jest==false)
        {
            waz.jest=true;
            waz.xPos=rand()%(szerokosc-1);
            if(waz.xPos==0) waz.xPos=1;
            waz.yPos=rand()%(wysokosc-1);
            if(waz.yPos==0) waz.yPos=1;
        }
    }

    void koniecGry()
    {
        Sleep(500);
        system("cls");
        cout<<"============="<<endl;
        cout<<"====WYNIK===="<<endl;
        cout<<"============="<<endl;
        cout<<"=PUNKTY: "<<punkty<<endl;
        cout<<"============="<<endl;
        getch();
        exit(0);
    }

    void kolizjaSciany()
    {
        if(waz.xPos==szerokosc-1 || waz.xPos==0 || waz.yPos==0 || waz.yPos==wysokosc-1)
            koniecGry();
    }

    void brakKolizji()
    {
        if(waz.xPos==szerokosc-1)
            waz.xPos=1;
        else if(waz.xPos==0)
            waz.xPos=szerokosc-2;
        else if(waz.yPos==0)
            waz.yPos=wysokosc-2;
        else if(waz.yPos==wysokosc-1)
            waz.yPos=1;

    }

    void poruszanie(int &klawisz)
    {

        if(klawisz==gora)
            waz.yPos--;
        else if(klawisz==lewo)
            waz.xPos--;
        else if(klawisz==dol)
            waz.yPos++;
        else if(klawisz==prawo)
            waz.xPos++;
        else
            waz.xPos++;
        kolizjaSciany();
        //brakKolizji();
    }

    void graGlowna()
    {
        wczytaj();
        system("cls");
        while(true)
        {
           graObiekty();
           rysuj();
           if(kbhit())
                sterowanie(key);
           poruszanie(key);


           Sleep(1500/predkosc);
           system("cls");
        }
    }
};
