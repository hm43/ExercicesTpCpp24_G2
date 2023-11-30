#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Article{
private:
    string id;
    string nom;
    string desc;
    int qte;
    double prix;
public:
    Article(){
        id = "";
        nom = "";
        desc = "";
        qte = 0;
        prix = 0;
    }
    Article(string id, string nom, string desc, int qte, double prix):
    id(id), nom(nom), desc(desc), qte(qte), prix(prix){}
    string getId(){
        return id;
    }
    void setId(string id){
        this->id = id;
    }
    string getNom(){
        return nom;
    }
    void setNom(string nom){
        this->nom = nom;
    }
    string getDesc(){
        return nom;
    }
    void setDesc(string desc){
        this->desc = desc;
    }
    int getQte(){
        return qte;
    }
    void setQte(int qte){
        this->qte = qte;
    }
    double getPrix(){
        return prix;
    }
    void setPrix(double prix){
        this->prix = prix;
    }
};
class Minimarche{
private:
    string nom;
    vector <Article> stock;
public:
    Minimarche(){
        nom = "";
    }
    Minimarche(string nom){
        this->nom = nom;
    }
    Minimarche(Minimarche const &m){
        nom = m.nom;
        stock = m.stock;
    }
    void ajouterArticle(){
        string id;
        string nom;
        string desc;
        int qte;
        double prix;
        cout<<"Donner l'id: ";
        getline(cin, id);
        cout<<"Donner le nom: ";
        getline(cin, nom);
        cout<<"Donner la description: ";
        getline(cin, desc);
        cout<<"Donner la qte: ";
        cin>>qte;
        cout<<"Donner le prix: ";
        cin>>prix;

        Article a(id, nom, desc, qte, prix);
        
        stock.push_back(a);
    }

    void majQte(){
        string id;
        cout<<"Donner l'id de l'article a modifier: ";
        getline(cin, id);

        for(Article &e : stock){
            if(e.getId().compare(id) == 0){

                int qte;
                cout<<"Donner la nouvelle qte: ";
                cin>>qte;
                e.setQte(qte);
                break;
            }
        }
    }

    void afficher(){
        cout<<"Le nom: "<<nom<<endl;
        for(Article &e: stock){
            cout<<"L'id : "<<e.getId()<<endl;
            cout<<"Le nom : "<<e.getNom()<<endl;
            cout<<"La description : "<<e.getDesc()<<endl;
            cout<<"Qte: "<<e.getQte()<<endl;
            cout<<"Prix: "<<e.getPrix()<<endl;
        }
    }
};

int main(){
    Minimarche m("mini");
    
    return 0;
}