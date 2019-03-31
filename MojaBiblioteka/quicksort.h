#include <iostream>

using namespace std;

void quicksort(int *table, int left, int right) //lewy element najbardziej wysuniety na lewo(pierwszy element tablicy) , prawy ostatni element tablicy
{
    int v=table[(left+right)/2];
    int i,j,x;
    i=left;
    j=right;
    do{
        while (table[i]<v) i++;
        while (table[j]>v) j--;
        if (i<=j)
        {
            x=table[i];
            table[i]=table[j];
            table[j]=x;
            i++; j--;
        }
    } while (i<=j);
    if (j>left)     quicksort(table, left, j);
    if (i<right)    quicksort(table, i, right);
}
