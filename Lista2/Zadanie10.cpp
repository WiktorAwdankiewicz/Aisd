#include <iostream>
using namespace std;

// Pesymistyczna zlozonosc czasowa: T(n) = O(h)

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

lnode* find(lnode* t, int key)
{
	while(t && t->key!=key)
	{
		if(key<t->key)
			t=t->left;
		else
			t=t->right;
	}
	return t;
}

void remove(lnode *&t, int key)
{
	lnode **t1=&t;
	while (*t1 && (*t1)->key!=key)
	{
		if(key<(*t1)->key)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	}
	if(*t1)
	{
		if((*t1)->right && (*t1)->left)
		{
			lnode **t2=&((*t1)->right);
			while ((*t2)->left)
				t2=&((*t2)->left);
			(*t1)->key=(*t2)->key;
			t1=t2;
		}
		if((*t1)->left==nullptr)
		{
			lnode *d=(*t1)->right;
			delete *t1;
			(*t1)=d;
		}
		else
		{
		    lnode *d=(*t1)->left;
			delete *t1;
			(*t1)=d;
		}
	}
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

int main()
{
	lnode *L1 = nullptr;

	for (int i=0;i<4;i++)
        insert(L1, i);

    display(L1);
    cout<<endl;
    cout<<"Szukamy 2: "<<find(L1,2)->key<<endl;
    display(L1);
    cout<<endl;
    cout<<"Usuwamy 3: ";
    remove(L1,3);
    display(L1);
}
