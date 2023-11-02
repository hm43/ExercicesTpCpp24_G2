#include<iostream>
using namespace std;

int somme(int *t, int taille){
    int s = 0;
    for(int i=0; i<taille; i++){
        s+=t[i];
    }
    return s;
}

float moyenne(int *t2, int taille2){
    int s = somme(t2, taille2);
    float m = s / taille2;
    return m;
}

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
    do{
    cout<<"Donner la taille: ";
    cin>>taille;
    }while(taille > 10);
    tab = new int[taille];

    for(int i = 0; i< taille; i++){
        cout<<"Entrer la valeur de "<<i+1<<": ";
        cin>>tab[i];
    }
    cout<<"La somme est: "<<somme(tab, taille);
    cout<<"La moyenne est: "<<moyenne(tab, taille);

    cout<<"Donner la valeur a chercher: ";
    cin>>a;
    chercherVal(tab, taille, a, pos2, nb_occ2);
    cout<<"Derniere position: "<<pos2<<endl;
    cout<<"Nmbre d'occ: "<<nb_occ2<<endl;


    
    return 0;
}