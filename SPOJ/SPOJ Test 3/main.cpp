#include <iostream>
#include <cstdlib>

using namespace std;

int liczba,control=0,temp=42;

int main()
{
    while(cin>>liczba){
        if(liczba==42 && liczba!=temp){
            control++;
            if(control==3) {cout<<liczba<<endl; exit(0);}}
        cout<<liczba<<endl;
        temp=liczba;}

    return 0;
}
