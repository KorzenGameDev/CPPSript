#include <iostream>


using namespace std;

int stos[10];
char znaki[1];
int i=0;
bool prawda=true;

int main()
{
    while(cin>>znaki){
    if(znaki[0]=='+') {cin>>stos[i]; prawda=true;
        for(int j=0;j<i;j++){
            if(stos[j]==stos[i]) {cout<<":("<<endl; prawda=false; break;}}
        if(prawda!=false) {cout<<":)"<<endl; i++;}}
    else if(znaki[0]=='-'){
        if(i>0) cout<<stos[--i]<<endl;
        else cout<<":("<<endl;
    }}
    return 0;
}
