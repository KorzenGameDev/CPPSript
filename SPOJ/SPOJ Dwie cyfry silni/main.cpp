#include <iostream>

using namespace std;
int D,n;
int silnia[]={1,1,2,6,24,20,20,40,20,80,00};
int main()
{
    cin>>D;
    while(D--){
    cin >> n;
    if(n>10) n=10;
    cout<<silnia[n]/10<<" "<<silnia[n]%10<<endl;}
    return 0;
}
