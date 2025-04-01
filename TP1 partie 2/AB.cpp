/************************************************************************/
/* Auteur : GHABI Malek						*/
/* TP : Transformation d'un arbre binaire quelconque en arbre binaire	*/
/* de recherche								*/
/* Date dernière maj : 20/12/2024				*/
/************************************************************************/

#include <iostream>
#include "AB.h"

using namespace std;

/****************************************/
/* Objectif : Constructeur d'un noeud dont les fils sont NULL*/
/* Entrées : entier x*/
/* Complexité : 0(1)*/
/****************************************/
noeud::noeud(int x)
{
	cle = x;
	fg = fd = pere =  NULL;
}

/****************************************/
/* Objectif : Constructeur d'un noeud de fils donnés*/
/* Entrées : entier x, fg, fd */
/* Complexité : 0(1)*/
/****************************************/
noeud::noeud(int x, noeud* fg, noeud* fd)
{
	cle = x;
	this->fg = fg;
	this->fd = fd;
}

/****************************************/
/* Objectif : Destructeur d'un noeud*/
/****************************************/
noeud::~noeud()
{
	if(fg)
		delete(fg);
	if(fd)
		delete(fd);
}

/****************************************/
/* Objectif : Constructeur d'un AB*/
/****************************************/
AB::AB(noeud* x)
{
	r = x;	
}

/****************************************/
/* Objectif : Destructeur d'un AB*/
/****************************************/
AB::~AB()
{
	if(r)
		delete(r);
}

/****************************************/
/* Objectif : Accesseur à la racine r*/
/****************************************/
noeud* AB::root()
{
	return(r);
}

/****************************************/
/* Objectif : Parcours infixe*/
/****************************************/
void AB::AfficheT()
{
	n = N(r);
	cout << "T = ";
	
	for(int i = 0; i < n; i++)
		cout << T[i] << " ";
	
	cout << endl;
}


/****************************************/
/* Objectif : Parcours prefixe*/
/****************************************/
void AB::Prefixe(noeud* x)
{
	if(x){
		cout << " " << x->cle;
		Prefixe(x->fg);
		Prefixe(x->fd);
	}
}

/****************************************/
/* Objectif : Parcours postfixe*/
/****************************************/
void AB::Postfixe(noeud* x)
{
	if(x){
		Postfixe(x->fg);
		Postfixe(x->fd);
		cout << " " << x->cle;
	}
}

/****************************************/
/* Objectif : Parcours infixe*/
/****************************************/
void AB::Infixe(noeud* x)
{
	if(x){
		Infixe(x->fg);
		cout << " " << x->cle;
		Infixe(x->fd);
	}
}


/****************************************/
/* Objectif : Nombre d'éléments de l'arbre*/
/****************************************/
int AB::N(noeud* x)
{
	if (x == nullptr)
        return 0;
    return 1 + N(x->fg) + N(x->fd); // Nombre de nœuds dans fg + fd + le nœud actuel

}


/****************************************/
/* Objectif : Hauteur de l'arbre de racine x*/
/****************************************/
int AB::Hauteur(noeud* x)
{
	int res, resfg, resfd;

	res = resfg = resfd = -1;

	if(x){
		resfg = Hauteur(x->fg);
		resfd = Hauteur(x->fd);

		if(resfg > resfd)	
			res = resfg+1;
		else
			res = resfd+1;
	}

	return(res);
}
























/****************************************/
/* Objectif : Stocker dans T les valeurs */
/* de l'arbre triées en ordre croissant*/
/****************************************/

void AB::CollectValues(noeud* x, int T[], int& index) {
    if (x == nullptr) return; // Si le nœud est nul, on ne fait rien
    
    CollectValues(x->fg, T, index); // Parcours du sous-arbre gauche
    T[index++] = x->cle;            // Ajoute la valeur du nœud actuel dans le tableau
    CollectValues(x->fd, T, index); // Parcours du sous-arbre droit
}



void AB::Tri() {
    int index = 0;
    CollectValues(r, T, index); // Remplit le tableau T avec les valeurs de l'arbre
    n = index;                  // Met à jour le nombre de nœuds

    // Tri par sélection
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (T[j] < T[minIndex]) {
                minIndex = j;
            }
        }
        // Échange des éléments
        int temp = T[i];
        T[i] = T[minIndex];
        T[minIndex] = temp;
    }
}



















/****************************************/
/* Objectif : Transformation d'un arbre binaire de racine x*/
/* en un arbre binaire de recherche contenant les mêmes */
/* valeurs et ayant la même structure*/
/****************************************/


void AB::FillABR(noeud* x, int T[], int& index) {
    if (x == nullptr) return;  // Si le nœud est nul, on ne fait rien

    FillABR(x->fg, T, index);  // Remplir le sous-arbre gauche
    x->cle = T[index++];       // Assigner la valeur triée au nœud actuel
    FillABR(x->fd, T, index);  // Remplir le sous-arbre droit
}



void AB::ABtoABR(noeud* x) {
    int index = 0;
    FillABR(x, T, index); // Remplit l'arbre avec les valeurs triées
}
