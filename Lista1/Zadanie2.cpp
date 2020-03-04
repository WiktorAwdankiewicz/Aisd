#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double f(double x)
{
	return 2*x*x - 5;
}

void bisekcja(double a, double b)
{
    int i = 0;
    int maxI = 1000;
	double x0=a;

    /*if(f(a) * f(b) > 0)
    {
        cout<<"Funkcja nie ma roznych znakow na krancach przedzialu: "<<a<<" "<<b<<endl; //czyli nie przecina nigdzie osi X
        exit(1);
    }*/

	while(i < maxI)
    {
		x0=(a+b)/2;
		//cout<<"i = "<<i<<" | x0 = "<<x0<<endl;
		if(fabs(f(a-x0)) < 0.00000001)
        {
            cout<<"x0 = "<<x0<<endl;
            cout<<"Liczba iteracji = "<<i<<endl;
			break;
        }
        else if (fabs(f(x0)) < 0.00000001)
        {
            cout<<"x0 = "<<x0<<endl;
            cout<<"Liczba iteracji = "<<i<<endl;
			break;
        }
		else if (f(a) * f(x0) < 0)
			b=x0;
		else
			a=x0;
        i++;
	}
	if(i>=maxI)
        cout<<"Zapetlenie, liczba iteracji: "<<i<<endl;
}

int main()
{
    bisekcja(-5,-1);
    bisekcja(0,3);
    bisekcja(1,5);
    bisekcja(-2,6);
}
