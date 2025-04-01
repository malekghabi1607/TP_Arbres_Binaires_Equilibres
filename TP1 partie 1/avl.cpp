/************************************************************************/
/* GHABI Malek						*/
/* TP1 Algorithmique Avancée : Arbres Binaires Équilibrés	*/
			
/************************************************************************/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string> 
#include "avl.h"

using namespace std;

// Constructeur de noeud
noeud::noeud(int x) : cle(x), N(1), d(0), h(1), fg(nullptr), fd(nullptr), pere(nullptr) {}

// Destructeur de noeud
noeud::~noeud() {
    delete fg;
    delete fd;
}

// Méthode pour afficher les informations du noeud
void noeud::affiche() {
    cout << "Clé: " << cle << ", N: " << N << ", d: " << d << ", h: " << h << endl;
}

// Constructeur de l'arbre AVL
AVL::AVL(const char* filename, bool option) : r(nullptr) {
    ifstream file(filename);
    if (!file) {
        cerr << "Erreur d'ouverture du fichier" << endl;
        exit(EXIT_FAILURE);
    }

    int valeur;
    while (file >> valeur) {
        noeud* nouveau = new noeud(valeur);
        if (option) {
            insertionFeuille(r, nouveau); // Insertion en feuille
        } else {
            insertionRacine(r, nouveau); // Insertion en racine
        }
    }
    mettreAJour(r); // Mettre à jour N et d après l'insertion
    file.close();
}

// Destructeur de l'arbre AVL
AVL::~AVL() {
    delete r; // Le destructeur de noeud va gérer la libération de mémoire
}

// Affichage préfixe de l'arbre
void AVL::prefixe(noeud* x) {
    if (x != nullptr) {
        x->affiche(); // Afficher le noeud
        prefixe(x->fg); // Afficher le sous-arbre gauche
        prefixe(x->fd); // Afficher le sous-arbre droit
    }
}

// Insertion d'un noeud en feuille
void AVL::insertionFeuille(noeud*& x, noeud* y) {
    if (x == nullptr) {
        x = y; // Si le noeud est vide, insérer le nouveau noeud
    } else if (y->cle < x->cle) {
        insertionFeuille(x->fg, y); // Insérer dans le sous-arbre gauche
        x->fg->pere = x; // Mettre à jour le père du noeud
    } else {
        insertionFeuille(x->fd, y); // Insérer dans le sous-arbre droit
        x->fd->pere = x; // Mettre à jour le père du noeud
    }
    mettreAJour(x); // Mettre à jour N, d et h après l'insertion
}

// Insertion d'un noeud en racine
void AVL::insertionRacine(noeud*& x, noeud* y) {
    if (x == nullptr) {
        x = y; // Si le noeud est vide, insérer le nouveau noeud
    } else {
        // Insérer dans le sous-arbre approprié
        if (y->cle < x->cle) {
            insertionRacine(x->fg, y); // Insérer dans le sous-arbre gauche
            x->fg->pere = x; // Mettre à jour le père
        } else {
            insertionRacine(x->fd, y); // Insérer dans le sous-arbre droit
            x->fd->pere = x; // Mettre à jour le père
        }
    }
    mettreAJour(x); // Mettre à jour N, d et h après l'insertion
}

// Mettre à jour N, d et h du noeud
void AVL::mettreAJour(noeud* x) {
    if (x != nullptr) {
        x->N = 1; // Initialiser N à 1 (pour lui-même)
        x->h = 1; // Initialiser h à 1 (pour lui-même)
        // Mettre à jour les N et h des enfants
        if (x->fg != nullptr) {
            mettreAJour(x->fg);
            x->N += x->fg->N; // Ajouter le nombre de noeuds du sous-arbre gauche
            x->h = max(x->h, x->fg->h + 1); // Mettre à jour la hauteur
        }
        if (x->fd != nullptr) {
            mettreAJour(x->fd);
            x->N += x->fd->N; // Ajouter le nombre de noeuds du sous-arbre droit
            x->h = max(x->h, x->fd->h + 1); // Mettre à jour la hauteur
        }
        // Mettre à jour la différence de hauteur
        x->d = (x->fg ? x->fg->h : 0) - (x->fd ? x->fd->h : 0);
    }
}

// Équilibrer l'arbre
void AVL::equilibre(noeud*& x) {
    if (x->d > 1) {
        // Si le sous-arbre gauche est plus haut
        if (x->fg->d < 0) {
            rotationGauche(x->fg); // Rotation gauche
        }
        rotationDroite(x); // Rotation droite
    } else if (x->d < -1) {
        // Si le sous-arbre droit est plus haut
        if (x->fd->d > 0) {
            rotationDroite(x->fd); // Rotation droite
        }
        rotationGauche(x); // Rotation gauche
    }
}

// Rotation droite
void AVL::rotationDroite(noeud*& x) {
    noeud* y = x->fg; // Nouveau racine sera le fils gauche
    x->fg = y->fd; // Le sous-arbre droit de y devient le fils gauche de x
    if (y->fd != nullptr) {
        y->fd->pere = x; // Mettre à jour le père
    }
    y->fd = x; // x devient le fils droit de y
    x->pere = y; // Mettre à jour le père
    x = y; // Changer la racine
    mettreAJour(x); // Mettre à jour N, d et h
}

// Rotation gauche

void AVL::rotationGauche(noeud*& x) {
    noeud* y = x->fd; // Nouveau racine sera le fils droit
    x->fd = y->fg; // Le sous-arbre gauche de y devient le fils droit de x
    if (y->fg != nullptr) {
        y->fg->pere = x; // Mettre à jour le père
    }
    y->fg = x; // x devient le fils gauche de y
    x->pere = y; // Mettre à jour le père
    x = y; // Changer la racine
    mettreAJour(x); // Mettre à jour N, d et h
}

// Retourner la racine de l'arbre
noeud*& AVL::root() {
    return r; // Retourner la racine




