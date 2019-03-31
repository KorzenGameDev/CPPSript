#include <iostream>

using namespace std;

int t,n;
int main()
{
    cin>>t;
    while(t--){
        cin>>n; int tab[n];
        for(int i=0;i<n;i++) cin>>tab[i];
        for(int i=n-1;i>=0;i--) cout<<tab[i]<<" ";
        cout<<endl;
    }
    return 0;
}
