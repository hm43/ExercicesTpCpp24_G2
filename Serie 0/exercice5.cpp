#include<iostream>
using namespace std;
/*
Exercice 3:
-----------
Créer un programme qui:
1. Demande de l'utilisateur la taille du tableau des entiers moins de 10.
2. Donne la main à l'utilisateur d'entrer les valeurs du tableau.
3. Affiche la somme des valeurs du tableau à l'aide d'une fonction.
4. Affiche la moyenne du tableau à l'aide d'une fonction.

Exercice 5:
------------
Écrire une fonction qui permet de rechercher dans un tableau d’entiers tab une valeur A. 
void chercherVal (int tab[], int n, int A, int *pos, int *nb_occ); 
Dans pos, la fonction sauvegarde l’indice de la dernière apparition et -1 si la valeur n’a pas été trouvée. 
Dans nb_occ, elle sauvegarde le nombre d’occurence de A dans tab.
*/

// 3. Affiche la somme des valeurs du tableau à l'aide d'une fonction.
int somme(int *t, int taille){
    int s = 0;
    for(int i=0; i<taille; i++){
        s+=t[i];
    }
    return s;
}
// 4. Affiche la moyenne du tableau à l'aide d'une fonction.
float moyenne(int *t2, int taille2){
    int s = somme(t2, taille2);
    float m = s / taille2;
    return m;
}

// Exercice 5
void chercherVal (int tab[], int n, int A, int &pos, int &nb_occ){
    nb_occ = 0;
    pos = -1;
    for(int i=0; i < n; i++){
        if(A == tab[i]){
            pos = i;
            nb_occ++;
        }
    }
}

int main(){
    int taille;
    int *tab;
    int a, pos2, nb_occ2;
    // 1. Demande de l'utilisateur la taille du tableau des entiers moins de 10.
    do{
    cout<<"Donner la taille: ";
    cin>>taille;
    }while(taille > 10);

    //2. Donne la main à l'utilisateur d'entrer les valeurs du tableau.
    tab = new int[taille];

    for(int i = 0; i< taille; i++){
        cout<<"Entrer la valeur de "<<i+1<<": ";
        cin>>tab[i];
    }

    //3. Affiche la somme des valeurs du tableau à l'aide d'une fonction.
    cout<<"La somme est: "<<somme(tab, taille);
    //4. Affiche la moyenne du tableau à l'aide d'une fonction.
    cout<<"La moyenne est: "<<moyenne(tab, taille);

    // Exercice 5
    cout<<"Donner la valeur a chercher: ";
    cin>>a;
    chercherVal(tab, taille, a, pos2, nb_occ2);
    cout<<"Derniere position: "<<pos2<<endl;
    cout<<"Nmbre d'occ: "<<nb_occ2<<endl;



    
    return 0;
}