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

void ajouterArticle(Minimarche &m)
{
    cin.ignore();
    article a;
    cout << "Donner l'id de l'article: ";
    getline(cin, a.id);
    cout << "Donner le nom de l'article: ";
    getline(cin, a.nom);
    cout << "Donner la description de l'article: ";
    getline(cin, a.desc);

    cout << "Donner la qte de l'article: ";
    cin >> a.qte;
    cout << "Donner le prix de l'article: ";
    cin >> a.prix;

    m.stock.push_back(a);
}

void majQte(Minimarche &m)
{
    cin.ignore();
    string id;
    cout << "Donner l'id de l'article: ";
    getline(cin, id);

    for (article &e : m.stock)
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
    cout << "le nom: " << m.nom << endl;

    for (article &e : m.stock)
    {
        cout << "Le nom de l'article: " << e.nom << endl
             << "La qte: " << e.qte << endl;
    }
}

int main()
{

    Minimarche *marche = new Minimarche;
    marche->nom = "My market";
menu:
    int choix;
    cout << "1. Ajouter article." << endl;
    cout << "2. Modifier un article." << endl;
    cout << "3. Afficher les articles." << endl;
    cout << "4. Quitter." << endl;
    cout << ">> ";
    cin >> choix;
    switch (choix)
    {
    case 1:
        ajouterArticle(*marche);
        goto menu;
        break;

    case 2:
        majQte(*marche);
        goto menu;
        break;

    case 3:
        afficher(*marche);
        goto menu;
        break;

    default:
        cout << "Au revoir." << endl;
    }

    return 0;
}