#include <iostream>
#include <cmath>
using namespace std;

void countingSort(int t[], int n, int c)
{
    int max=t[0];
    int min=t[0];

    for(int i=0;i<n;i++)
    {
        if(t[i]>max)
            max=t[i];
        if(t[i]<min)
            min=t[i];
    }

    cout<<"Min = "<<min<<", max = "<<max<<endl;

    int range = max - min + 1;
    int licznik[range] = {0};
    int output[n];

    int i;
    int out[n];
    c = pow(10, c);

    for(i=0;i<n;i++)
        ++licznik[(t[i]/c)%10];

    for(i=1;i<range;i++)
        licznik[i]+=licznik[i-1];

    for(i=n-1;i>=0;i--)
    {
        out[licznik[(t[i]/c)%10]-1]=t[i];
        --licznik[(t[i]/c)%10];
    }

    for(i=0;i<n;i++)
        t[i]=out[i];
}

void wypisz(int t[],int n)
{
    for(int i=0;i<n;i++)
        cout<<t[i]<<"  ";
    cout<<endl;
    cout<<endl;
}

int main()
{
    int tab[10] = {645,2,1,23,17,5,12,99,202,44};
    wypisz(tab,10);
    countingSort(tab, 10, 0);
    wypisz(tab,10);
    countingSort(tab, 10, 1);
    wypisz(tab,10);
    countingSort(tab, 10, 2);
    wypisz(tab,10);
}
