#include <iostream>

using namespace std;

struct lnode
{
    int key;
    lnode *next;
    lnode(int n=0, lnode* l=NULL)
    :key(n), next(l)
    {}
};

void print(lnode* L)
{
    while(L != NULL)
    {
        cout<<L->key<<"  ";
        L = L->next;
    }
    cout<<endl;
}

void insertion_sort(lnode *&L)
{

    //sprawdza czy L istnieje i nie jest 1 argumentowa
    //jeden argument jest uporzadkowana lista
    if(L && L->next)
    {
        //tworzymy pusta liste pomocnicza
        lnode* sortedL = NULL;
        //by nie modyfikowaæ L w czasie rzeczywistym tworze liste z nieposortowanymi elementami
        lnode* unsortedL = L;
        //dopoki nieposortowana lista nie dotrze do swojego konca
        while(unsortedL)
        {
            //dodatkowa zmienna, pobiera aktualny unsorted
            lnode* value = unsortedL;
            //przeskakuje na nastepna wartosc
            unsortedL = unsortedL->next;
            //jesli moja lista jest pusta albo wartosc nieposortowanej jest mniejsza od klucza z posortowanej
            if(!sortedL || value->key <= sortedL->key)
            {
                //ustalam nieposortowany klucz na ten klucz listy value
                value->next = sortedL;
                //zapisuje miejsce w liscie
                sortedL = value;
            }
            else
            {
                //kolejna pomocniczna zmienna, dla pamieci porownywania liczb, tutaj rosnie wielkosc listy
                lnode* curSorted = sortedL;
                //dopoki nie dojdzie do konca
                while(curSorted)
                {
                    //jesli nastepny klucz obecnej zmiennej nie jest null albo liczba z value jest mniejsza od nastepnego currenta
                    if(!curSorted->next || value->key < curSorted->next->key)
                    {
                        //przypisanie do nastepnego value obecnego sorta
                        value->next = curSorted->next;
                        //zamiana miejsc
                        curSorted->next = value; //przypisanie do obecnego sorta = listy value
                        break; //unikniecie zapêtlenia
                    }
                    //przypisujemy curenta na nastepne miejsce
                    curSorted = curSorted->next;
                }
            }
        }
        //nadpisanie listy nowa
        L = sortedL;
    }
}

int main()
{
    lnode *L = NULL;
	L = new lnode(7, L);
	L = new lnode(5, L);
    L = new lnode(2, L);
	L = new lnode(3, L);
    L = new lnode(2, L);
	L = new lnode(1, L);
	L = new lnode(9, L);
    cout<<"Lista przed posortowaniem:"<<endl;
    print(L);
    insertion_sort(L);
    cout<<"Lista po posortowaniu:"<<endl;
    print(L);
}
