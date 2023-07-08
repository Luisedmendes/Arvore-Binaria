#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

list<int> lista;

void showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it << " ";
    
}

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode *treenodeptr;

void tInsere(treenodeptr &p, float x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else // insere na subarvore direita
		tInsere(p->dir, x);
}

void emOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		lista.push_back(arvore->info);
		emOrdem(arvore->dir);
	}
}

void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

int main()
{
	treenode *arvore = NULL; //ponteiro para raiz da arvore
	int x;
	int n = 1;
	

	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
		n++;
	}
	
	// Criando uma lista
	emOrdem(arvore);
	
	lista.reverse();
	showlist(lista);

	tDestruir(arvore);

	return 0;
}
