#include <iostream>
#include <fstream>
using namespace std;

void ascii_counter(ifstream& plik)
{
    //pomijamy 32 pierwsze znaki ASCII poniewaz sa to znaki sterujace
	int ascii[128 - 32] = {};

    char singleChar;
    do
    {
        singleChar = plik.get();
        int numeric = singleChar - 32;
        ++ascii[numeric];

    } while(singleChar!= EOF); //EOF - end of file / koniec pliku

    for(int i=0;i<(128-32);++i)
        cout<<"Znak "<<(char)(i+32)<<" wystapil "<<ascii[i]<<endl; //(char)(liczba) - wypisuje znak ascii o podanej liczbie

	plik.close();
}

int main()
{
    ifstream file("ascii.txt");
	ascii_counter(file);
}
