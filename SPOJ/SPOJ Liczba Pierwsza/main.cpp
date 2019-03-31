#include <iostream>
#include <cstdlib>

using namespace std;
int t, n,control;

int main()
{
	cin>>t;
	while(t--){ cin>>n; control=0;
        if(n<2) {cout<<"NIE"<<endl,control++;}
        for(int i=2;i*i<=n;i++){
            if(n%i==0 && control==0){cout<<"NIE"<<endl; control++;}}
        if(control==0) cout<<"TAK"<<endl;}
	return 0;
}
