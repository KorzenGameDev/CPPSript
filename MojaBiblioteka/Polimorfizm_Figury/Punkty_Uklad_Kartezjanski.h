#include "Library_Figura.h"

class Punkty_Uklad_Kartezjanski
{
    int ile_pkt;
    float *px=new float[ile_pkt];
    float *py=new float[ile_pkt];
public:
    Punkty_Uklad_Kartezjanski(int pkt=NB_2)
    {
        ile_pkt=pkt;
    }
    void wczytaj()
    {
        while(ile_pkt<NB_3)
        {
            Sleep(SHORT_SLEEP);
            system("cls");
            cout<<endl<<"Podaj liczbe wierzcholkow twojego wielokata: ";
            cin>>ile_pkt;
            if(ile_pkt<NB_3)
                cout<<endl<<"ERROR!"<<endl;
        }
        for(int i=NB_0;i<ile_pkt;i++)
        {
            cout<<"Podaj wpolrzedne X i Y "<<i+1<<" punktu: ";
            cin>>px[i]>>py[i];
            //cout<<*px++<<" "<<*py++<<endl;
        }
    }

    float pole_figury()
    {
        float suma=NB_0;
        for(int i=NB_0;i<ile_pkt-NB_1;i++)
            suma=suma+px[i]*py[i+NB_1]-px[i+NB_1]*py[i];

        suma=(suma+px[ile_pkt-NB_1]*py[NB_0]-px[NB_0]*py[ile_pkt-NB_1])/NB_2;
        if(suma<NB_0) suma=suma*(-NB_1);
        if(suma==NB_0)
        {
            cout<<endl<<"ERROR"<<endl;
            Sleep(LONG_SLEEP);
            exit(NB_0);
        }
        return suma;
    }
};
