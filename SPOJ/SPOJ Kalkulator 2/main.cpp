#include <iostream>
#include <cstdlib>

using namespace std;

char c;
int tab[]={0,0,0,0,0,0,0,0,0,0};
int a,b;

int main()
{
    while(cin>>c>>a>>b){
        switch(c){
            case 'z': tab[a]=b;break;
            case '+': cout<<tab[a]+tab[b]<<endl; break;
            case '-': cout<<tab[a]-tab[b]<<endl; break;
            case '*': cout<<tab[a]*tab[b]<<endl; break;
            case '/': cout<<tab[a]/tab[b]<<endl; break;
            case '%': cout<<tab[a]%tab[b]<<endl; break;
            default: break;}

    }
    return 0;
}
