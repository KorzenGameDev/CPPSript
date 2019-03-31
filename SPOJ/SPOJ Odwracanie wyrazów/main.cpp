#include <iostream>
#include <string>

using namespace std;

string wyraz;
int main()
{
    cin>>wyraz;
    string wspak[wyraz.size()];
    for(int i=0;i<wyraz.size();i++) wspak[i]=wyraz[wyraz.size()-1-i];
    cout<<wspak<<endl;

    return 0;
}
