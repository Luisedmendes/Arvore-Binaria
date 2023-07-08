#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

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
		emOrdem(arvore->dir);
		cout << arvore->info << " ";
		emOrdem(arvore->esq);
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

treenodeptr tPesq(treenodeptr p, int x)
{
	if (p == NULL)
		return NULL;
	else
		if ( x == p-> info)
			return p;
		else
			if ( x < p->info)
				return tPesq(p->esq,x);
			else
				return tPesq(p->dir,x);
}

int main()
{
	treenode *arvore = NULL; //ponteiro para raiz da arvore
	int n;
	int x;
	int encontra;

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		tInsere(arvore, x);
	}

	cin >> encontra;

	if(tPesq(arvore, encontra) == NULL){
		cout << "Nao encontrado" << endl;
	} else {
		cout << "Encontrado"<< endl;
	}

	tDestruir(arvore);

	return 0;
}