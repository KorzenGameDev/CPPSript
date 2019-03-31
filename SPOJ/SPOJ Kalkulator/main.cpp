#include <iostream>

using namespace std;

char znak;
int a,b;

int main()
{
    while((cin>>znak>>a>>b)){
        switch(znak){
            case '+': cout<<a+b<<endl; break;
            case '-': cout<<a-b<<endl; break;
            case '*': cout<<a*b<<endl; break;
            case '/': cout<<a/b<<endl; break;
            case '%': cout<<a%b<<endl; break;
            default: break;}}
    return 0;
}
