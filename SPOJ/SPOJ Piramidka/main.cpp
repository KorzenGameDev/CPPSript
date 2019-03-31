#include <iostream>

using namespace std;

string S;
int N=30,j=0;
int main()
{
    while((N<1 || N>29) || N%2==0){cin>>N;}
    while(S.size()>N || S.size()<N){cin>>S;}
    for(int i=0;i<=(N/2);i++){
        for(j=0;j<(N/2)-i;j++) cout<<".";
        for(int k=0;k<=2*i;k++) cout<<S[k+j];
        for(j=0;j<(N/2)-i;j++) cout<<".";
        cout<<endl;}
    return 0;
}
