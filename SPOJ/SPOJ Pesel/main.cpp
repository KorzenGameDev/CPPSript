#include <iostream>

using namespace std;

long long int pesel;
int t;
int liczba;

int main()
{
    cin>>t;
    while(t--){
        cin>>pesel;
        liczba=(pesel%10*1)+(((pesel%10*10^1)/10)*3)+(((pesel%10*10^2)/(10*10^1))*1)+(((pesel%10*10^3)/(10*10^2))*9)+(((pesel%10*10^4)/(10*10^3))*7)+(((pesel%10*10^5)/(10*10^4))*3)+(((pesel%10*10^6)/(10*10^5))*1)+(((pesel%10*10^7)/(10*10^6))*9)+(((pesel%10*10^8)/(10*10^7))*7)+(((pesel%10*10^9)/(10*10^8))*3)+(((pesel%10*10^10)/(10*10^9))*1);
        if(liczba%10==0) cout<<"D"<<endl;
        else cout<<"N"<<endl;
    }

    return 0;
}
