#include <iostream>

using namespace std;

int t,n,temp;

int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        int tab[n];
        for(int i=0;i<n;i++) cin>>tab[i];
        temp=tab[0];
        for(int j=1;j<n;j++)cout<<tab[j]<<" ";
        cout<<temp<<endl;}
    return 0;
}
