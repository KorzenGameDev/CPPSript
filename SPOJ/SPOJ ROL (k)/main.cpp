#include <iostream>

using namespace std;

int n,k,i=0;

int main()
{
    cin>>n>>k;
    int tab[n];
    while(cin>>tab[i++] && i<n);
    for(i=0;i<n;i++){
        if(k+i>=n) cout<<tab[k+i-n]<<" ";
        else cout<<tab[i+k]<<" ";}
    cout<<endl;
    return 0;
}
