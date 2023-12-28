#include <iostream>
#include <string>

using namespace std;

class Transaction;

class Cryptomonnaie{
private:
    string nom;
    double valeur;
public:
    Cryptomonnaie(string n, double v):  nom(n), valeur(v){}
    void setNom(string n){
        nom = n;
    }
    void setValeur(double v){
        valeur = v;
    }
    friend class Transaction;
};
class Portefeuille {
    double solde;
    string propritaire;
public:
    Portefeuille(double s, string p): solde(s), propritaire(p){}
    void afficherSolde(){
        cout<<"Le solde de: "<<propritaire<<" est: "<<solde<<endl;
    }
    friend class Transaction;
};
class Transaction{
public:
    void effectuerTransaction(Portefeuille &p1, Portefeuille &p2, double montant,const Cryptomonnaie &c){
        if(p1.solde < montant){
            cout<<"Solde insufisant de premier portefeuille "<<p1.solde<<"!"<<endl;
        }else{
            p1.solde -= montant;
            p2.solde += montant * c.valeur;
            cout<<"Transaction de: "<<montant<<" de "<<p1.propritaire<<" a "
            <<p2.propritaire<<" Effectuer avec succes (valeur de change pour "<<c.nom<<")"<<endl;
        }
    }
};

int main(){
    Portefeuille p1(10000, "A1"); // USD
    Portefeuille p2(12000, "A2"); // MAD
    Cryptomonnaie USD_to_MAD("USD_to_MAD", 10);
    
    Transaction t;
    t.effectuerTransaction(p1, p2, 20000, USD_to_MAD);
    t.effectuerTransaction(p1, p2, 2000, USD_to_MAD);
    cout<<"Solde de p1: ";
    p1.afficherSolde();
    cout<<"Solde de p2: ";
    p2.afficherSolde();
    
    return 0;
}
