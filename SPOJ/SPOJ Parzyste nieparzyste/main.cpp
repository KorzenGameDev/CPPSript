#include <iostream>

using namespace std;

int t,n,i;

int main()
{
    cin>>t;
    while(t--){
        cin>>n; i=0;
        int tab[n];
        while(i<n) cin>>tab[i++];
        for(int k=1;k<n;k+=2) cout<<tab[k]<<" ";
        for(int k=0;k<n;k+=2) cout<<tab[k]<<" ";
    cout<<endl;}
    return 0;
}
