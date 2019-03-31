#include <iostream>
#include "Quicksort.h"

using namespace std;

int tablica[]={10,11,2,33,45,65,45,75,48,98,45,12,10,1};

int main()
{
    quicksort(tablica,0,13);
    cout<<tablica[1]<<endl;
    return 0;
}
