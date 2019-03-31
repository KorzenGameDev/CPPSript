#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int n;
    string zmienna;

	cin>>n;
	cin>>zmienna;
	cout<<zmienna.length();
	if((zmienna.length())<=n)
        cout<<zmienna<<endl;
    else
    {
        for(int i=(zmienna.length())-1;i>=0;i--)
        {
            if((zmienna[i]<='a' && zmienna[i]>='z') || (zmienna[i]<='A' && zmienna[i]>='Z') || (zmienna[i]<=0 && zmienna[i]>=9))
                zmienna.erase(i,1);
        }
        cout<<zmienna<<endl;
    }
	return 0;
}
