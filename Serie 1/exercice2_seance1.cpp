#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PileInt{
private:
    int max;
    int sommet;
    int *pile;
public:
    PileInt(){
        max = 50;
        sommet = 0;
        pile = new int[max];
    }
    PileInt(int max){
        this->max = max;
        sommet = 0;
        pile = new int[max];
    }
    ~PileInt(){
        delete [] pile;
    }
    void empiler(int v){
        if(max > sommet){
            pile[sommet] = v;
            sommet++;
        }else{
            cout<<"Pile plein"<<endl;
        }
    }
    void depiler(){
        if(sommet > 0){
            sommet--;
        }
    }
    int taille(){
        return max;
    }
    int compter(){
        return sommet;
    }
    void afficher(){
        cout<<"[";
        for(int i = 0; i< sommet; i++){
            cout<<pile[i];
            if(i < sommet - 1)
                cout<<",";
        }
        cout<<"]"<<endl;
    }
};
int main() {
    PileInt p(5);
    p.empiler(1);
    p.empiler(2);
    p.depiler();
    p.empiler(3);
    cout<<"Taille: "<<p.taille()<<" Nbr d'elements: "<<p.compter()<<endl;
    p.afficher();
    
    return 0;
}
