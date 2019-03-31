#include <iostream>
#include <cstdlib>

using namespace std;

int m,n;

int main()
{
    cin>>m>>n;
    int tab[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>tab[i][j];}
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            cout<<tab[i][j]; if(i+1<m) cout<<" ";}
        cout<<endl;}
    return 0;
}
