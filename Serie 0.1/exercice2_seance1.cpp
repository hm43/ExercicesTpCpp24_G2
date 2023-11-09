#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct article
{
    string id;
    string nom;
    string desc;
    int qte;
    float prix;
} article;

typedef struct Minimarche
{
    string nom;
    vector<article> stock;
} Minimarche;

void ajouterArticle(vector<article> &stock)
{
    article a;
    cout << "Donner l'id: ";
    getline(cin, a.id);

    cout << "Donner le nom: ";
    getline(cin, a.nom);

    cout << "Donner la description: ";
    getline(cin, a.desc);

    cout << "Donner la qte: ";
    cin >> a.qte;

    cout << "Donner le prix: ";
    cin >> a.prix;

    stock.push_back(a);
}

void majQte(vector<article> &stock)
{
    string id;
    cout << "Donner l'id: ";
    getline(cin, id);

    for (article &e : stock)
    {
        if (e.id.compare(id) == 0)
        {
            cout << "L'ancienne qte: " << e.qte << endl;
            cout << "Donner la nouvelle qte: ";
            cin >> e.qte;
        }
    }
}
void afficher(Minimarche &m)
{
    cout << endl
         << m.nom << endl;

    cout << "Les articles: " << endl;
    for (article &e : m.stock)
    {
        cout << "Le nom: " << e.nom << "; qte: " << e.qte << endl;
    }
}

int main()
{

    Minimarche *m = new Minimarche;
    m->nom = "Mon mini marche";
    ajouterArticle(m->stock);
    int c;
    do{
        cout<<"1. ajouter article."<<endl;
        cout<<"2. MAJ un article."<<endl;
        cout<<"3. Afficher les articles."<<endl;
        cout<<"4. Quitter."<<endl;
        cin>>c;
        switch(c){
            case 1:
                ajouterArticle(m->stock);
                break;
            case 2:
                majQte(m->stock);
                break;
            case 3:
                afficher(*m);
                break;
            default:
                cout<<"Quitter"<<endl;
                break;
        }
    }while( c != 4);
    
    return 0;
}