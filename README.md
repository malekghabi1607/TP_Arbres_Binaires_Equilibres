# TP1 - Arbres Binaires Équilibrés (AVL)

🎓 **Module :** Algorithmique Avancée  
🏫 **Filière :** Licence 2 Informatique – Semestre 3  
🧠 **Objectif :** Implémenter des arbres binaires équilibrés (AVL) en C++, avec insertion, équilibrage et affichage.

---

## 🧩 Structure du TP

Ce TP est divisé en deux parties :

### 🔹 Partie 1 – Implémentation d’un arbre AVL

📁 Dossier : `TP1 partie 1`  
📄 Sujet : présent dans `sujet.pdf`

### Objectifs :
- Déclaration des classes `noeud` et `AVL`
- Insertion des données à partir d’un fichier (`donnees.txt`)
- Insertion en **feuille** ou en **racine**
- Calcul du nombre de nœuds (`N`), hauteur (`h`) et déséquilibre (`d`)
- Affichage en parcours préfixe
- Équilibrage de l’arbre via la méthode "diviser pour régner"

### Fichiers :
- `avl.h` : déclaration des classes
- `avl.cpp` : implémentation des méthodes AVL
- `main.cpp` : programme principal
- `donnees.txt` : fichier d'entrée
- `avl.exe` : exécutable compilé

---

### 🔹 Partie 2 – TP “AB to ABR” sur Caspienne

📁 Dossier : `TP1 partie 2`  
📄 Sujet réalisé directement sur la plateforme Caspienne

### Objectifs :
- Conversion d’un arbre binaire quelconque en arbre binaire de recherche (ABR)
- Compréhension du parcours et de la transformation d’arbres

### Fichiers :
- `AB.h`, `AB.cpp` : gestion d’un arbre binaire
- `main.cpp` : test du programme
- `programme_execut…` : sortie d’exécution (log ou résultat)
- `a.out` : exécutable généré localement

---

## 🛠️ Compilation

Pour compiler les deux parties (exemple pour g++) :

```bash
# Partie 1 (AVL)
g++ main.cpp avl.cpp -o avl.exe

# Partie 2 (AB to ABR)
g++ main.cpp AB.cpp -o ab.exe
