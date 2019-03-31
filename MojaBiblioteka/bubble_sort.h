#include <iostream>

using namespace std;

void bubble_sort(int *table,int size_table)
{
    int temp;
    for(int i=0;i<size_table;i++)
    {
        for(int j=i;j<size_table;j++)
        {
            if(table[i]>table[j]) //growing
            //if(table[i]<table[j]) //desc
            {
                temp=table[i];
                table[i]=table[j];
                table[j]=temp;
            }
        }
    }
}
