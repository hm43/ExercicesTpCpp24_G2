#include<iostream>
using namespace std;
typedef struct {
    float valeur;
    float coeff;
    char module[20];
}note;
typedef struct{
    char nom[20];
    char mat[20];
    note *notes = new note[3];
}etudiant;

float moyenne(etudiant e, int taille = 3){
    float s = 0;
    float s2 = 0;
    for(int i=0; i<taille; i++){
        s += e.notes[i].valeur * e.notes[i].coeff;
        s2 += e.notes[i].coeff;
    }
    return s / s2;
}

int main(){
    etudiant *etudiants = new etudiant[3];
    for(int i=0; i<3; i++){
        cout<<"Donner le nom "<<i+1<<": ";
        cin>>etudiants[i].nom;
        //cout<<"Donner le matricule: ";
        //cin>>etudiants[i].mat;
        for(int j=0; j<3; j++){
            cout<<"Donner le valeur de la note "<<j+1<<" : ";
            cin>>etudiants[i].notes[j].valeur;
            cout<<"Donner le coefficient de la note: ";
            cin>>etudiants[i].notes[j].coeff;
            //cout<<"Donner le nom du module de la note: ";
            //cin>>etudiants[i].notes[j].module;
        }
    }

    for(int i=0; i<3 ; i++){
        cout<<"Le nom: "<<etudiants[i].nom<<" La moyenne est: "<<moyenne(etudiants[i])<<endl;
    }
    return 0;
}