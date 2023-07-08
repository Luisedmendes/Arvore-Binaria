#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

struct treenode{
    
	int info;
    treenode *esq;
    treenode *dir;
};

typedef treenode* treenodeptr;

//funcao para inserir os elementos da arvore
void tInsere(treenodeptr &p, int x){
    
	//insere na raiz
    if(p == NULL){
        
		p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    
	//insere na subarvore esquerda
    else if(x < p->info)
        tInsere(p->esq, x);
	
//insere na subarvore direita
    else 
        tInsere(p->dir, x);
}

//funcao para procurar um elemento especifico
treenodeptr tPesq(treenodeptr p, int x){
	
	//elemento nao encontrado
	if(p == NULL)
		return NULL;
	
	//elemento encontrado na raiz
	else if(x == p->info)
		return p;
	
	//procura na subarvore esquerda
	else if(x < p->info)
		return tPesq(p->esq, x);
	
	//procura na subarvore direita
	else 
		return tPesq(p->dir, x);
	
}

void contaPreOrdem(treenodeptr arvore, int &N){
    
	if(arvore != NULL){
        
		N++;
        contaPreOrdem(arvore->esq, N);
        contaPreOrdem(arvore->dir, N);
    }
}

//funcao para mostrar quantos nos a arvore tem
int contaNos(treenodeptr arvore){
    
	int N = 0; //numero de nos da arvore
    
	contaPreOrdem(arvore, N);
    
	return N;
}

//funcao para mostrar quantas folhas a arvore tem
int contaFolhas(treenodeptr arvore){
    
    int N = 0; //numero de folhas da arvore
    
    if(arvore == NULL)
    	return 0;
    
    else if(arvore->esq == NULL && arvore->dir == NULL)
    	N++;
    
    else 
    	N += contaFolhas(arvore->esq) + contaFolhas(arvore->dir);
    
	return N;
}

//encontra o menor elemento do lado direito da arvore
treenodeptr tMenor(treenodeptr &raiz){
    
	treenodeptr t;
    
    t = raiz;
    
    //encontrou o menor valor
    if(t->esq == NULL){
		
		raiz = raiz->dir;
		return t;
	}
    
    //continua a busca na subarvore esquerda
    else 
    	return tMenor(raiz->esq);
}

//encontra o maior elemento da arvore
treenodeptr tMaior(treenodeptr &raiz){
    
	treenodeptr t;
    
    t = raiz;
    
    //encontrou o menor valor
    if(t->dir == NULL){
		
		raiz = raiz->dir;
		return t;
	}
    
    //continua a busca na subarvore esquerda
    else 
    	return tMaior(raiz->dir);
}

//funcao para mostrar o percurso pre-ordem
void preOrdem(treenodeptr arvore){
    
	if(arvore != NULL){
        
		cout << arvore->info << endl;
        preOrdem(arvore->esq);
        preOrdem(arvore->dir);
    }
}

//funcao para mostrar o percurso em-ordem (serve para ordenar de forma crescente)
void emOrdem(treenodeptr arvore){
    
	if(arvore != NULL){
        
		emOrdem(arvore->esq);
        cout << arvore->info << " ";
        emOrdem(arvore->dir);
    }
}

//funcao para mostrar o percurso em-ordem (serve para ordenar de forma decrescente)
void emOrdemDecres(treenodeptr arvore){
    
	if(arvore != NULL){
        
		emOrdemDecres(arvore->dir);
        cout << arvore->info << " ";
        emOrdemDecres(arvore->esq);
    }
}

//funcao para mostrar o percurso pos-ordem
void posOrdem(treenodeptr arvore){
    
	if(arvore != NULL){
        
		posOrdem(arvore->esq);
        posOrdem(arvore->dir);
        cout << arvore->info << endl;
    }
}

//realiza um percurso em nivel na arvore
void emNivel(treenodeptr t){
	
	treenodeptr n;
	list <treenodeptr> q;
	
	if(t != NULL){
		
		q.push_back(t);
		
		while(!q.empty()){
			
			n = *q.begin();
			q.pop_front();
			
			if(n->esq != NULL)
				q.push_back(n->esq);
			
			if(n->dir != NULL)
				q.push_back(n->dir);
			
			cout << n->info << " ";
		}
		cout << endl;
	}
}

//funcao para remover cada no
int tRemove(treenodeptr &raiz, int x){
	
	treenodeptr p;
	
	//arvore ja ta vazia
	if(raiz == NULL)
		return 1;
	
	if(x == raiz->info){
		
		p = raiz;
		
		//a raiz nao tem filho esquerdo
		if(raiz->esq == NULL)
			raiz = raiz->dir;
		
		//a raiz nao tem filho direito
		else if(raiz->dir == NULL)
			raiz = raiz->esq;
		
		//a raiz tem ambos os filhos
		else{
			
			p = tMenor(raiz ->dir);
			raiz->info = p->info;
		}
		
		delete p;
		return 0;
	}
	
	else if(x < raiz->info)
		return tRemove(raiz->esq, x);
	
	else 
		return tRemove(raiz->dir, x);
}

//funcao pra destruir a arvore
void tDestruir(treenodeptr &arvore){
	
	if(arvore != NULL){
		
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	
	arvore = NULL;
}

int main(){
    
	treenodeptr arvore = NULL; //ponteiro para a raiz
    int n;
    
	//inserindo os elementos na arvore
    cin >> n;
    
	while(n != -1){
        
		tInsere(arvore, n);
        cin >> n;
    }
    
	//saida de dados
	emNivel(arvore);
    
    //liberacao da memoria utilizada
    tDestruir(arvore);
    
	
	return 0;
}