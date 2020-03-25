#include <iostream>
using namespace std;

void sito_erastotenesa(int n)
{
    bool prime[n];

    for(int i=0;i<=n;i++)
        prime[i] = true;

    for(int p=2;p*p<=n;p++)
        if(prime[p] == true)
            for(int i=p*p;i<=n;i+=p)
                prime[i] = false;

    for(int i=2;i<=n;i++)
        if(prime[i]) //jesli prime[i] == true
            cout<<i<<endl;
}

int main()
{
    sito_erastotenesa(12);
}
