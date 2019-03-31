#include <iostream>
#include <time.h>
#include <windows.h>
#include <stdio.h>

using namespace std;

int Moje_Typy[6], Los, Tablica_Losow[6],Pomocnicza_Los=0,Wynik=0,Tablica_Udanych_Trafien[6];
bool Losowanie_Ok;

int main()
{
    cout<<"Prosze podac twoje typy na losowanie(zakres 1-49)"<<endl;
    for(int i=0;i<6;i++)
    {
        cin>>Moje_Typy[i];
        if(Moje_Typy[i]<=0 || Moje_Typy[i]>49)
        {
            cout<<"Podano liczbe nienalezaca do zakresu"<<endl;
            i--;
        }
        else
        {
            for(int j=0;j<=(i-1);j++)
            {
                if(Moje_Typy[j]==Moje_Typy[i])
                {
                    cout<<"Podales juz wczesniej wybrana liczbe"<<endl;
                    i--;
                    break;
                }
            }
        }
    }

    srand(time(NULL));

    system("cls");

    cout<<"Twoje typy zapisane za 3 sekundy rozpoczynamy losowanie"<<endl;

    cout<<"3 sekundy\a"<<endl;
    Sleep(1000);
    cout<<"2 sekundy\a"<<endl;
    Sleep(1000);
    cout<<"1 sekundy\a"<<endl;
    Sleep(500);
    system("cls");
    Sleep(500);

    cout<<"Losowane liczby: "<<endl;

    for (int i=0; i<6; i++)
    {
		do
		{
            Los=rand()%49+1;
            Losowanie_Ok=true;

			for(int j=0; j<=Pomocnicza_Los; j++)
			{
				if(Los==Tablica_Losow[j])
                Losowanie_Ok=false;
			}

			if (Losowanie_Ok==true)
			{
				Tablica_Losow[Pomocnicza_Los]=Los;
				Pomocnicza_Los++;
			}
		} while(Losowanie_Ok!=true);

		Sleep(1000);
		cout<<Tablica_Losow[i]<<"\a ";
    }

    Sleep(500);
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(Tablica_Losow[i]==Moje_Typy[j])
                {
                    Tablica_Udanych_Trafien[Wynik]=Tablica_Losow[i];
                    Wynik++;
                }
        }
    }

    if(Wynik==1)
    {
        cout<<endl<<endl<<"Udalo Ci sie trafic "<<Wynik<<" liczbe!"<<endl;
        cout<<"Oto ona: "<<Tablica_Udanych_Trafien[0];
    }
    else
    {
        cout<<endl<<endl<<"Udalo Ci sie trafic "<<Wynik<<" liczb!"<<endl;
        cout<<"Oto one:";
        for(int i=0;i<Wynik;i++)
            cout<<" "<<Tablica_Udanych_Trafien[i];
    }

    getchar();
    return 0;
}
