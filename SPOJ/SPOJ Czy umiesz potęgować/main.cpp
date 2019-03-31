#include <iostream>

using namespace std;

int t;
long long int a,b;
int temp_a;
int tab_2[]={6,2,4,8};
int tab_3[]={1,3,9,7};
int tab_4[]={6,4};
int tab_7[]={1,7,9,3};
int tab_8[]={6,8,4,2};
int tab_9[]={1,9};
int main()
{
    cin>>t;
    while(t--){
        cin>>a>>b;
        temp_a=a%10;
        if(temp_a==0 || temp_a==1 || temp_a==5 || temp_a==6) cout<<temp_a<<endl;
        else if(temp_a==2) cout<<tab_2[b%4]<<endl;
        else if(temp_a==3) cout<<tab_3[b%4]<<endl;
        else if(temp_a==4) cout<<tab_4[b%2]<<endl;
        else if(temp_a==7) cout<<tab_7[b%4]<<endl;
        else if(temp_a==8) cout<<tab_8[b%4]<<endl;
        else if(temp_a==9) cout<<tab_9[b%2]<<endl;}

    return 0;
}
