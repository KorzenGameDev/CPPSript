#include <iostream>
#include <cstdlib>

using namespace std;

int a,b,t;
int main()
{
    cin>>t;
    for(int i=0;i<t;i++){
    cin >> a;
    cin >> b;
    do{ if(a>b) a=a-b;
        else b=b-a;}    while(a!=b);
    cout<<a<<endl;}
    return 0;
}
