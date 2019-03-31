#include <iostream>

using namespace std;

int t,a,b,cukierki;

int main()
{
    cin>>t;
    while(t--){
        cin>>a>>b;
        cukierki=a*b;
        while(a!=b){
            if(a>b) a=a-b;
            else b=b-a;}
        cout<<cukierki/a<<endl;}
    return 0;
}
