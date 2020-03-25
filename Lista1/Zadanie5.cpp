#include <iostream>
using namespace std;

struct para
{
    int min;
    int max;
};

void maxmin(int tab[], int n)
{
    para wynik;
    int i;

    if (n%2 == 0)
    {
        if (tab[0] > tab[1])
        {
            wynik.max = tab[0];
            wynik.min = tab[1];
        }
        else
        {
            wynik.max = tab[1];
            wynik.min = tab[0];
        }
        i=2;
    }
    else
    {
        wynik.min = tab[0];
        wynik.max = tab[0];
        i=1;
    }

    while(i < n-1)
    {
        if (tab[i] > tab[i+1])
        {
            if(tab[i] > wynik.max)
                wynik.max = tab[i];

            if(tab[i+1] < wynik.min)
                wynik.min = tab[i+1];
        }
        else
        {
            if (tab[i+1] > wynik.max)
                wynik.max = tab[i+1];

            if (tab[i] < wynik.min)
                wynik.min = tab[i];
        }
        i+=2;
    }
    cout <<"min: "<<wynik.min<<" max: "<<wynik.max<<endl;
}

int main()
{
    int tab[] = {99,51,-22,0,1,74,254,-5};
    maxmin(tab,8);
}
