#include <iostream>

using namespace std;

string szyfr;
int control=1,l=0,temp;
int main()
{
    while(control){
        control=0; (cin>>szyfr).get();
        for(int i=0;i<szyfr.size();i++){ if(szyfr[i]<'A' || szyfr[i]>'Z') control++;}}
    char rozw[szyfr.size()/2];
    for(int i=0;i<szyfr.size()/2;i++){
        temp=szyfr[i*2]+szyfr[i*2+1];
        cout<<temp<<endl;
        if(szyfr[i*2+1]=='\0') rozw[l++]=szyfr[i*2];
        else if(temp>'Z') rozw[l++]=temp-26;
        else rozw[l++]=temp;}
    cout<<rozw<<endl;
    return 0;
}
