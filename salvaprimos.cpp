#include <iostream>
#include <iomanip>
#include <list>
#include <math.h>
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

bool isPrimo(int n)
{

	if(n < 5 || n % 2 == 0 || n % 3 == 0)
		return (n == 2 || n == 3);

	int maxP = sqrt(n) + 2;
	for(int p = 5; p < maxP; p += 6)
		if(n % p == 0 || n % (p + 2) == 0)
			return false;

	return true;
}

int soma = 0;

int contaPrimos (treenodeptr arvore)
{

	if (arvore != NULL)
	{
		contaPrimos(arvore->esq);
		if(arvore->info % 2 != 0)
		{
			soma++;
		}
		contaPrimos(arvore->dir);
	}
	return soma;
	
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

	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}

	cout << contaPrimos(arvore) << " numeros primos";


	tDestruir(arvore);

	return 0;
}
