#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    vector<string> tab;
    tab.resize(4);
    for(string &element: tab){
        getline(cin, element);
    }
    cout<<endl;
    string str;
    cout<<"Entrer une autre valeur: ";
    getline(cin, str);
    tab.push_back(str);
    for(string element: tab){
        cout<<element<<", ";
    }
    cout<<endl;
    tab[1] = "2";
    for(string element: tab){
        cout<<element<<", ";
    }


    cout<<endl;

    return 0;
}