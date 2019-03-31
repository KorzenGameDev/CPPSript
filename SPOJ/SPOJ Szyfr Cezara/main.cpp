#include <iostream>
#include <string>

using namespace std;

char cezar[200];

int main()
{
    while(cin.getline(cezar,200)){
    for(int i=0;i<200;i++){
        if(cezar[i]+3<='Z') cezar[i]=cezar[i]+3;
        else cezar[i]=cezar[i]-23;}
    cout<<cezar<<endl;}

    return 0;
}
