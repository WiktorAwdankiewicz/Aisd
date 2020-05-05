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

int height(lnode* t)
{
    if (t == nullptr)
        return 0;

    int left = height(t->left);
    int right = height(t->right);

    if (left > right)
        return 1 + left;
    else
        return 1 + right;
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

	for (int i=0;i<5;i++)
        insert(L1, i);

    display(L1);
    cout<<endl;
    cout<<"Wysokosc: "<<height(L1)<<endl;
}
