#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;
int l=1001,control_upper;
int najw[l],najm[l];
string wyraz;

int main()
{
    while(l>=1000 || l<1){cin>>l;}
    for(int j=0;j<l;j++){
    wyraz.clear();
    while((wyraz.size()<=2 || wyraz.size()>1000) && control_upper==0) {
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); (cin>>wyraz);
        control_upper=0;
        for(int i=0;i<wyraz.size();i++){
            if(wyraz[i]<='A' && wyraz[i]>='Z') control_upper++;}}
        najw[l]=wyraz[0]; najm[l]=wyraz[0];
        for(int i=0;i<wyraz.size();i++){
            if(wyraz[i]>najw[l]) najw[l]=wyraz[i];
            else if(wyraz[i]<najm[l]) najm[l]=wyraz[i];}}
    for(int i=0;i<l;i++) cout<<najw[l]-najm[l]<<endl;
    return 0;
}
