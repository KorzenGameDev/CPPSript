#include <iostream>

using namespace std;
string wyraz;
int t;
int main()
{
    cin>>t;
    while(t--){
        wyraz.clear();
        (cin>>wyraz).get();
        for(int i=0;i<wyraz.size()/2;i++)   cout<<wyraz[i]; cout<<endl;}
    return 0;
}
