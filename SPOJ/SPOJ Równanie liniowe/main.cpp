#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>

float a, b, c;

using namespace std;

int main()
{
    cin>>a>>b>>c;
    if((c-b)==0 && a==0) cout<<"NWR";
    else if(((c-b)!=0) && a==0) cout<<"BR";
    else{   cout.setf(ios::fixed);
            cout<<fixed<<setprecision(2)<<(c-b)/a;}
    return 0;
}
