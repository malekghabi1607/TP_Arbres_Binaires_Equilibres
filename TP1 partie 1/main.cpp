/************************************************************************/
/* GHABI Malek						*/
/* TP1 Algorithmique Avancée : Arbres Binaires Équilibrés	*/
			
/************************************************************************/
#include <iostream>
#include "avl.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Utilisation: " << argv[0] << " donnees.txt" << endl;
        return 1;
    }

    // Demande à l'utilisateur de choisir l'option d'insertion
    cout << "Choisissez l'option d'insertion : 1 pour insertion en feuille, 0 pour insertion en racine : ";
    bool option;
    cin >> option;

    // Créer un arbre AVL à partir du fichier
    AVL arbre(argv[1], option);

    cout << "Affichage préfixe avant équilibrage :" << endl;
    arbre.prefixe(arbre.root()); // Afficher l'arbre

    // Équilibrer l'arbre
    arbre.equilibre(arbre.root());

    cout << "Affichage préfixe après équilibrage :" << endl;
    arbre.prefixe(arbre.root()); // Afficher l'arbre après équilibrage







    return 0;
}
