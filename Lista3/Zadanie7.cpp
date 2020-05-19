#include<iostream>

using namespace std;

struct node
{
	int x;
	node* left;
	node* right;

	node(int x0, node* l=nullptr, node* r=nullptr)
    :x(x0), left(l), right(r)
	{}
};

void insert(node* &t, int x)
{
	node **t1=&t;
	while(*t1)
    {
		if(x<(*t1)->x)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
    }
	*t1=new node(x);
}

int poziom(node *&t,int key)
{
	node *n=t;
	int level=1; // wyznacznik poziomu

	while(n != nullptr && n->x != key)
    {
		level++;
		if(key < n->x)
			n = n->left;
		else
            n = n->right;
	}
	return n!=nullptr ? level : 0; // jesli n nie jest nullem to zwroc level, jesli jest nullem zwroc 0. | a ? b : c == if(a) b; else c;
}

int main()
{
    node* t=nullptr;
    insert(t,3);
    insert(t,4);
    insert(t,1);
    insert(t,7);
    insert(t,-4);
    insert(t,9);
    insert(t,2);

    cout<<"Podaj jaki klucz chcesz znalezc: ";
    int klucz;
    cin>>klucz;

    switch(poziom(t, klucz))
    {
    case 0:
        cout<<"Klucza "<<klucz<<" nie ma w drzewie."<<endl;
        break;
    case 1:
        cout<<"Klucz "<<klucz<<" jest w korzeniu."<<endl;
        break;
    case 2:
        cout<<"Klucz "<<klucz<<" jest w dziecku korzenia."<<endl;
        break;
    default:
        cout<<"Klucz "<<klucz<<" jest na poziomie: "<<poziom(t, klucz)<<endl;
        break;
    }
}

