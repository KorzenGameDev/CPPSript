#include <iostream>
#include <cstdlib>

using namespace std;

int t;
int tab[6];
int main()
{
    cin>>t;
    while(t--){
        for(int i=0;i<6;i++) cin>>tab[i];
        if(tab[2]-tab[0]!=0 && tab[4]-tab[0]!=0 && (tab[3]-tab[1])/(tab[2]-tab[0])==(tab[5]-tab[1])/(tab[4]-tab[0]))
            cout<<"TAK"<<endl;
        else if(tab[2]-tab[0]==0 && tab[4]-tab[0]==0)
            cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;}
    return 0;
}
