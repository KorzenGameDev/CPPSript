#include <iostream>

using namespace std;

int N,M,t,C,ciastka;
int doba=24*3600;
int main()
{
    cin>>t;
    while(t--){
        cin>>N>>M;
        ciastka=0;
        for(int i=0;i<N;i++) {cin>>C; ciastka+=doba/C;}
        if(ciastka%M==0) cout<<ciastka/M<<endl;
        else cout<<ciastka/M+1<<endl;
    }
    return 0;
}
