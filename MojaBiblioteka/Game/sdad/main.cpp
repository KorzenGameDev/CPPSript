#include <iostream>

using namespace std;

int main()
{
    int num;
    //do
    //{
     //   cin.clear();
      //  cin.sync();
       // cin>>num;
    //}while(cin.fail());

    while(cin.good()==false)
    {
        cin>>num;
    }
    return 0;
}
