#include <iostream>

using namespace std;

int t,n,x,y;
int i;

int main()
{
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        i=0;
        while(i<n){
            if(i%x==0 && i%y!=0) {cout<<i<<" "; i+=x;}
            else if(i%x==0 && i%y==0) i+=x;
            else i++;}
    cout<<endl;}
    return 0;
}
