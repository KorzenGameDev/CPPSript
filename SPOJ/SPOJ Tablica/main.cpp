#include <iostream>

using namespace std;

int tab[1000];
int i=0;

int main()
{
    while(cin>>tab[i++]);
    for(i=i-2;i>=0;i--) cout<<tab[i]<<" ";
    return 0;
}
