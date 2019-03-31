#include <iostream>
#include <cstdio>

using namespace std;
int tab[4];
int i=0,msc=0;
int main()
{
    while(cin>>tab[i++] && getchar()!='\0' && i<4){}
    for(i=0;i<2;i++) msc+=tab[2*i]*tab[(2*i)+1];
    cout<<msc<<endl;
    return 0;
}
