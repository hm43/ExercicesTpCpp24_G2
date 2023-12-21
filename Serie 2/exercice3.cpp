
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Livre{
    private:
    string titre;
    string auteur;
    static int nbrexemplaires;
    public:
    static int exemplairesLoues;
    Livre(){
        titre = "";
        auteur = "";
        nbrexemplaires++;
    }
    Livre(string titre, string auteur){
        this->titre = titre;
        this->auteur = auteur;
        nbrexemplaires++;
    }
    static void afficherNombreExemplaires(){
        cout<<"Le nombre total est: "<<nbrexemplaires<<endl;
    }
    static void afficherExemplairesLoues(){
        cout<<"le nombre total d'exemplaires actuellement loués: "<<exemplairesLoues<<endl;
    }
    friend ostream& operator<<(ostream &o, const Livre &l){
        o<<"Titre: "<<l.titre<<endl;
        o<<"l'auteur: "<<l.auteur<<endl;
        o<<nbrexemplaires<<endl;
        o<<exemplairesLoues<<endl;
        return o;
    }
    friend istream& operator>>(istream &, Livre &);
};
istream& operator>>(istream &i, Livre &l){
    cout<<"Titre: ";
    getline(i, l.titre);
    cout<<"Auteur: ";
    getline(i, l.auteur);
    return i;
}
int Livre::nbrexemplaires = 0;
int Livre::exemplairesLoues = 0;
int main(){
    Livre livre1("Les Misérables", "Victor Hugo");
    Livre livre2("1984", "George Orwell");
    cout << "Informations initiales du livre 1 :"<<endl << livre1;
    Livre::exemplairesLoues++;
    cout << "Simulation de la location d'un exemplaire: "<<endl;
    Livre::afficherNombreExemplaires();
    Livre::afficherExemplairesLoues();
    cout << "livre 1 :" <<endl<< livre1;
    Livre livre3("Le Petit Prince", "Antoine de Saint-Exupéry");
    cout << "Nouveau livre ajouté :"<<endl << livre3;
    
    return 0;
}
