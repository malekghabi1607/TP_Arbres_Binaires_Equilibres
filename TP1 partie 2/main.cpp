#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include "AB.h"

using namespace std;


int main(int argc, char** argv)
{
	int T[9] = {15, 32, 36, 10, 7, 3, 9, 8, 13};

	AB ab(new noeud(T[0],new noeud(T[1],new noeud(T[2],new noeud(T[5]), 
				new noeud(T[6],new noeud(T[7]), new noeud(T[8]))), 
				new noeud(T[3])), 
				new noeud(T[4])));

	cout << endl << "--------------------------------------------" << endl;
	cout << "Affichage infixe AB :\t";
	ab.Infixe(ab.root());	
	cout << endl << "--------------------------------------------" << endl;
	cout << "Affichage Prefixe AB :\t";
	ab.Prefixe(ab.root());
	cout << endl << "--------------------------------------------" << endl;
	cout << "Affichage Postfixe AB :\t";
	ab.Postfixe(ab.root());
	cout << endl << "--------------------------------------------" << endl;
	cout << "Hauteur AB = \t" << ab.Hauteur(ab.root());
	cout << endl << "--------------------------------------------" << endl;
	cout << "Tri :\t";
	ab.Tri();
	ab.AfficheT();
	cout << endl << "--------------------------------------------" << endl;
	cout << "AB to ABR :\t";
	ab.ABtoABR(ab.root());
	cout << endl << "--------------------------------------------" << endl;
	cout << "Affichage infixe ABR :\t";
	ab.Infixe(ab.root());	
	cout << endl << "--------------------------------------------" << endl;
	cout << "Affichage Prefixe ABR :\t";
	ab.Prefixe(ab.root());
	cout << endl << "--------------------------------------------" << endl;
	cout << "Affichage Postfixe ABR :\t";
	ab.Postfixe(ab.root());
	cout << endl << "--------------------------------------------" << endl;
	cout << "Hauteur ABR = \t" << ab.Hauteur(ab.root());
	cout << endl << "--------------------------------------------" << endl;

	return 0;
}


/*

Soit A un arbre binaire, par exemple celui ci :
 
 [racine]---- | 
              |----- [fils gauche]
              |----- [fils droite]



 [15]---- | 
          |----- [32]---- | 
					      |----- [36] ---- |
					                       |----- [3]
					                       |----- [9] ---- |
										                   |----- [8]
										                   |----- [13]
					      |----- [10]
						 

          |----- [7]


On suppose que A n'est pas un arbre binaire de recherche (ABR). On souhaite écrire une méthode transformant A en un ABR tout en gardant sa "structure". C'est à dire la façon dont les noeuds sont liés entre eux. Sur l'exemple ci-dessus la méthode doit donner comme résultat.



 [racine]---- | 
              |----- [fils gauche]
              |----- [fils droite]


  
 [32]---- | 
          |----- [13]|----- 
		                   |----- [7] ----- |
						                    |----- [3]
									        |----- [9] ----- |
											                 |----- [8]
															 |----- [10]
						   |----- [15]
		     
          |----- [36]
		

qui contient les mêmes éléments mais dont la structure n'est pas la même que celle d'origine.

La méthode ne doit pas créer de nouveaux noeuds mais transformer l'existant à l'aide d'un tableau (T) qui est donné en argument de la classe AB fournie. Pour s'en assurer, il est interdit d'utiliser le mot clef "new" dans votre code. Le système vérifiera l'existence ou non de ce mot dans vote fichier source.

"T" contiendra les valeurs triées, en ordre croissant, de A. Pour cela une méthode "tri()" devra être codée. Elle rangera les valeurs de A dans le tableau T. Vous pouvez rajouter, dans AB.h, toute méthode que vous pensez utile pour réaliser cela. Par contre, conservez ce qui vous est déjà donné.

La méthode "ABtoABR" exploite le contenu de T pour effectuer la transformation voulue.

Pour vérifier que vous avez bien un ABR, de la même structure que l'arbre initial, les affichages "infixe", "prefixe", "postfixe" sont appelées. De même ,la hauteur de l'arbre est calculée avant et après. Tous ces résultats doivent être les mêmes que ceux calculés par le code solution.



		  

  








*/