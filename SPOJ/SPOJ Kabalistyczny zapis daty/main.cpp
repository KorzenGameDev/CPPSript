#include <iostream>

using namespace std;

string data;
int data_l=0;

int main()
{
    (cin>>data).get();
    while(data.size()<1 || data.size()>25) (cin>>data).get();
    for(int i=0;i<data.size();i++){
        if(data[i]>='a' && data[i]<'j') data_l+=data[i]-96;
        else if(data[i]>='k' && data[i]<='t') data_l+=(data[i]-106)*10;
        else if(data[i]>='x' && data[i]<='z') data_l+=(data[i]-117)*100;
        else if(data[i]=='v') data_l+=200;}
    cout <<data_l<< endl;
    return 0;
}
