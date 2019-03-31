#include <iostream>

using namespace std;

int c,k,w,t;

int main()
{
    cin>>t;
    while(t--){
        cin>>c>>k>>w;
        if(c*w<=k) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
