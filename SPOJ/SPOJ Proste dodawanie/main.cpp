#include <iostream>

using namespace std;

int t,n,wynik,liczba;

int main()
{
    (cin>>t).get();
    for(int i=0;i<t;i++){wynik=0;
        (cin>>n).get();
        for(int j=0;j<n;j++){ (cin>>liczba).get(); wynik+=liczba;}
    cout<<wynik<<endl;}
    return 0;
}
