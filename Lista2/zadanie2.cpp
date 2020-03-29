#include <iostream>
using namespace std;

int maks(int t[], int n)
{
    int x=t[--n];
    while(n--)
        if(t[n] > x)
            x = t[n];
    return x;
}

int max_r(int t[], int n)
{
    if(n==1)
        return t[0];

    int x = max_r(t, n-1);

    if(t[n-1] > x)
        return t[n-1];

    return x;
}

int max_r2(int t[], int n, int lewy, int prawy)
{
    if(n < 1)
        return -1;
    if(n == 1)
        return t[0];

    int x;

    if(n == 2)
    {
        x = t[lewy];
        if(t[prawy] > x)
            x = t[prawy];

        return x;
    }

    int srodek = (lewy+prawy)/2;
    int max1 = max_r2(t,n/2,lewy,srodek);
    int max2 = max_r2(t,n/2,srodek + 1,prawy);

    if(max1 > max2)
        x = max1;
    else
        x = max2;
    return x;
}

int main()
{
    int tab[] = {2,5,6,64,32,93,-3,202,-10,302};

    cout<<"Maks1 = "<<maks(tab,10)<<endl;
    cout<<"Maks2 = "<<max_r(tab,10)<<endl;
    cout<<"Maks3 = "<<max_r2(tab,10,0,9)<<endl;
}
