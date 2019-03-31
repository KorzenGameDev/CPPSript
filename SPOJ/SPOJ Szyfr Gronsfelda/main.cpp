#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int k,j=0;
string szyfr,zamiana;

int main()
{
    cout<<"SZYFRUJ"<<endl;
    cin>>k;
    cin>>szyfr;
    stringstream ss;
    ss << k;
    string liczba = ss.str();
    int tab_k[liczba.size()];
    for(int i=0;i<liczba.size();i++) tab_k[i]=(liczba[i]-48);
    for(int i=0;i<szyfr.size();i++){
        if(j>=liczba.size()) j=0;
        if(szyfr[i]+tab_k[j]<='Z') szyfr[i]=szyfr[i]+tab_k[j];
        else szyfr[i]=szyfr[i]+tab_k[j]-26;
        j++;}
    cout<<szyfr<<endl;
        j=0;
    cout<<"DESZYFRUJ"<<endl;
    cin>>k;
    cin>>szyfr;
    ss << k;
    liczba = ss.str();
    for(int i=0;i<szyfr.size();i++){
        if(j>=liczba.size()) j=0;
        if(szyfr[i]-tab_k[j]>='A') szyfr[i]=szyfr[i]-tab_k[j];
        else szyfr[i]=szyfr[i]-tab_k[j]+26;
        j++;}
    cout<<szyfr<<endl;
    return 0;
}
