#include <iostream>
using namespace std;

struct lnode
{
    int key;
    lnode *left;
    lnode *right;
    lnode(int key0, lnode* l=nullptr, lnode* r=nullptr)
    :key(key0), left(l), right(r)
    {}
};

void insert(lnode*& t, int key)
{
    lnode **t1 = &t;
    while(*t1)
		if(key<(*t1)->key)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
    *t1 = new lnode(key);
}

void display(lnode *t, char z1 = ' ', char z2 = ' ')
{
    if (t)
    {
        cout<<z1;
        display(t->left,'(',')');
        cout<<t->key;
        display(t->right,'[',']');
        cout<<z2;
    }
}

void reverse(lnode*& L)
{
    if (L) //dopoki s¹ elementy tablicy
    {
        lnode* current = L; //current staje sie nasza lista przekazana przez L
        lnode* left = NULL;
        lnode* right = NULL;

        while (current != NULL)
        {
            right = current -> right; //pod right zostaje przypisany wskaznik na nastepny element listy.
            current -> right = left; //odwrocenie wskaznika ustawiajac go na left
            left = current; //poprzedni = terazniejszy
            current = right; //przechodzimy do nastepnego elementu: terazniejszy = nastepny
        }
        L = left; //odwrocenie wskaznika na nowy element ktory jest pierwszy
    }
}

int main()
{
	lnode *L1 = nullptr;

	for (int i=0;i<4;i++)
        insert(L1, i);

    display(L1);
    reverse(L1);
    display(L1);
}
