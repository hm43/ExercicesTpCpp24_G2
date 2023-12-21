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
};
int Livre::nbrexemplaires = 0;
int main(){
    Livre l1;
    Livre l2("un titre", "un auteur");
    Livre::afficherNombreExemplaires();
    return 0;
}