#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int n,temp=0;
string napis;

int main()
{
    cin>>n;
    cin>>napis;

    if(napis.size()<=n) cout<<napis<<endl;
    else{
        for(int i=(napis.size()-1);i>=0;i--)
        {   if(napis.size()>n && napis[i]=='_') napis.erase(i,1);
            else if(napis.size()<=n) {cout<<napis<<endl; exit(0);}}
        for(int i=(napis.size()-1);i>=0;i--)
        {   if(napis.size()>n && (napis[i]>=0 || napis[i]<=9)) napis.erase(i,1);
            else if(napis.size()<=n) {cout<<napis<<endl; exit(0);}}
        for(int i=0;i>=napis.size()-1;i--)
        {   if(napis[i] == 'a' || napis[i] == 'o' || napis[i] == 'i' || napis[i] == 'u' || napis[i] == 'y' || napis[i] == 'e') temp++;
            else if(napis.size()>n && temp!=0 && (napis[i] == 'a' || napis[i] == 'o' || napis[i] == 'i' || napis[i] == 'u' || napis[i] == 'y' || napis[i] == 'e')) {napis.erase(i,1); temp++;}
            else if(napis.size()<=n) {cout<<napis<<endl; exit(0);}}
        napis.erase(napis.size()-(napis.size()-n)-1,napis.size()-n); cout<<napis<<endl;}
    return 0;
}
