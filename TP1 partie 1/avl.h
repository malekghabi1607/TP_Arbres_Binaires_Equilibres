/************************************************************************/
/* GHABI Malek						*/
/* TP1 Algorithmique Avancée : Arbres Binaires Équilibrés	*/
			
/************************************************************************/
#ifndef AVL_H
#define AVL_H



#include <iostream>
#include <fstream>
#include <string> 
class noeud {
public:
    int cle; // Clé du noeud
    int N;    // Nombre de noeuds dans le sous-arbre
    int d;    // Différence de hauteur
    int h;    // Hauteur du noeud
    noeud* fg; // Fils gauche
    noeud* fd; // Fils droit
    noeud* pere; // Père du noeud

    noeud(int x); // Constructeur
    ~noeud(); // Destructeur
    void affiche(); // Affiche les informations du noeud
};

class AVL {
private:
    noeud* r; // Racine de l'arbre

public:
    AVL(const char* filename, bool option); // Constructeur à partir d'un fichier
    ~AVL(); // Destructeur
    void prefixe(noeud* x); // Affichage préfixe
    void insertionFeuille(noeud*& x, noeud* y); // Insertion en feuille
    void insertionRacine(noeud*& x, noeud* y); // Insertion en racine
    void mettreAJour(noeud* x); // Mettre à jour N, d et h
    void equilibre(noeud*& x); // Équilibrer l'arbre
    void rotationDroite(noeud*& x); // Rotation droite
    void rotationGauche(noeud*& x); // Rotation gauche
    noeud*& root(); // Retourner la racine de l'arbre




    // Ajout des méthodes noeds et desequilibres si nécessaire
    void noeds(noeud* x); // Méthode pour compter les noeuds
    void desequilibres(noeud* x); // Méthode pour afficher les déséquilibres





    
};

#endif // AVL_H
