#include <iostream>

using namespace std;

int t=0,control;
int main()
{
    while(t<1 || t>10) {cin>>t;}
    long int tab_a[t];
    long int tab_b[t];
    for(int i=0;i<t;i++) {tab_a[i]=0; tab_b[i]=0;}
    for(int i=0;i<t;i++){
        control=1;
        while(tab_a[i]<1 || tab_a[i]>1000000000) {cin>>tab_a[i];}
        while(tab_b[i]<1 || tab_b[i]>1000000000) {cin>>tab_b[i];}
        while(control){
            if(tab_a[i]>tab_b[i] && tab_a[i]-tab_b[i]>0) tab_a[i]=tab_a[i]-tab_b[i];
            else if(tab_a[i]<tab_b[i] && tab_b[i]-tab_a[i]>0) tab_b[i]=tab_b[i]-tab_a[i];
            else {control--; cout<<tab_a[i]+tab_b[i]<<endl;}}}
    return 0;
}
