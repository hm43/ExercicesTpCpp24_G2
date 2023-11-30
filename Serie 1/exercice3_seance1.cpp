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
    Minimarche(string nom): nom(nom){}
    void ajouterArticle(){
        string id,nom,desc;
        int qte;
        double prix;
        cout<<"Donner l'id: ";
        cin.ignore();
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
        cin.ignore();
        getline(cin, id);
        
        for(Article &e:stock){
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
        cout<<"Le nom est: "<<nom<<endl;
        for(Article &e: stock){
            cout<<"L'id : "<<e.getId()<<endl;
            cout<<"Le nom : "<<e.getNom()<<endl;
            cout<<"La description : "<<e.getDesc()<<endl;
            cout<<"Qte: "<<e.getQte()<<endl;
            cout<<"Prix: "<<e.getPrix()<<endl;
        }
    }
    
};
int main() {
    Minimarche m("M1");
    int choix;
menu:
    cout << "1. Ajouter article." << endl;
    cout << "2. Modifier un article." << endl;
    cout << "3. Afficher les articles." << endl;
    cout << "4. Quitter." << endl;
    cout << ">> ";
    cin >> choix;
    switch (choix)
    {
    case 1:
            m.ajouterArticle();
            goto menu;
            break;
    case 2:
            m.majQte();
            goto menu;
            break;

    case 3:
            m.afficher();
            goto menu;
            break;

    default:
        cout << "Au revoir." << endl;
    }
    return 0;
}
