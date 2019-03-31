#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>


using namespace std;
string napis,napis_tymczasowy,napis_koncowy;
string napis_szukaj;

int main()
{
    cout<<"Podaj napis: ";
    getline(cin,napis);                                                                 //pobieranie napisu z klawiatury ze spacjami

    cout<<endl<<"Laczenie napisow!"<<endl;
    cout<<endl<<"Podaj napis ktory ma byc dolaczony do poprzedniego napisu: ";
    getline(cin,napis_tymczasowy);
    napis_koncowy=napis+" "+napis_tymczasowy;                                           //³aczenie napisów w c++
    cout<<endl<<napis_koncowy<<endl;

    cout<<endl<<"Zamiana liter na duze//male"<<endl;                                    //zamiana liter na male i duze
    transform(napis.begin(),napis.end(),napis.begin(),::toupper);                       //zamiana na duze litery
    cout<<napis<<endl;
    transform(napis.begin(),napis.end(),napis.begin(),::tolower);                       //zamiana na male litery
    cout<<napis<<endl;

    cout<<"Znajdowanie frazy w stringu!"<<endl;
    cout<<"Podaj szukana fraze:";
    getline(cin,napis_szukaj);
    size_t pozycja=napis.find(napis_szukaj);                                            //znajdz w napisie tego wyrazu
    if(pozycja!=string::npos)                                                           //da prawde gdy znaleziono fraze
        cout<<endl<<"Znaleziono na pozycji "<<pozycja<<endl;
    else cout<<endl<<"Nie znaleziono!"<<endl;

    cout<<endl<<"Kasowanie znakow!"<<endl;
    napis.erase(1,1);                                                                   //dzialanie nazwa stringu.erase(od ktorej pozycji kasowac, ile znakow skasowac)
    cout<<napis<<endl;

    cout<<endl<<"Wstawianie znakow!"<<endl;
    napis.insert(1,"dodawane");                                                         //dzialanie nazwa stringu.insert(dodac na jakiej pozycji,"co dodac")
    cout<<napis<<endl;

    cout<<endl<<"Zastepowanie znakow!"<<endl;
    napis.replace(1,1,"zastapione");                                                    //dzialanie nazwa stringu.replace(na jakiej pozycji, ile znakow,"tekst ktory nalezy umiescic w zastepowanym fragmencie")
    cout<<napis<<endl;

    cout<<endl<<"Wyjmowanie ze stringu danej frazy!"<<endl;
    string napis_wyjmowanie=napis.substr(1,1);                                          //dzialanie nowy stringu=string.substr(od ktorej pozycji,ile znakow)
    cout<<napis_wyjmowanie<<endl;


    getchar();
    return 0;
}
