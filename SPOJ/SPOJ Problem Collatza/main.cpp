#include <iostream>

using namespace std;

int t,s,ktory;

int main()
{
    cin>>t;
    while(t--){ ktory=0;
        cin>>s;
        while(s!=1){
            if(s%2==0) s=s/2;
            else s=s*3+1;
            ktory++;}
        cout<<ktory<<endl;}
    return 0;
}
