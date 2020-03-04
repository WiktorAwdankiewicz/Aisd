#include<iostream>
using namespace std;

long iteracyjnie(long a, long n)
{
	long long wynik = 1;

	while(n>0)
	{
		if (n%2 == 1)
			wynik *= a;

		a*= a;
		n/=2;
	}
	return wynik;
}

long rekurencyjnie(long a, long n)
{
	if(n==0)
		return 1;

	if(n%2 == 1)
		return a * rekurencyjnie(a, n - 1);

	long long wynik = rekurencyjnie(a, n/2);
	return wynik * wynik;
}

int main()
{
	long x;
	long n;

	cout<<"Podaj podstawe: ";
	cin>>x;
	cout<<"Podaj wykladnik: ";
	cin>>n;

	cout<<"Iteracyjnie: "<<x<<" do potegi "<<n<<" wynosi "<<iteracyjnie(x, n)<<endl;
	cout<<"Rekurencyjnie: "<<x<<" do potegi "<<n<<" wynosi "<<rekurencyjnie(x, n)<<endl;
}
