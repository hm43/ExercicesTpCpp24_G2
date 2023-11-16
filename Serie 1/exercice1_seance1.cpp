#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Point{
private:
    float x;
    float y;
public:
    Point(){
        cout<<"Constructeur par default."<<endl;
        x = 0;
        y = 0;
    }
    Point(float x, float y){
        cout<<"Constructeur d'initialisation."<<endl;
        this->x = x;
        this->y = y;
    }
    float getX(){
        return x;
    }
    void setX(float x){
        this->x = x;
    }
    float getY(){
        return y;
    }
    void setY(float y){
        this->y = y;
    }
    string coord(){
        string str = "("+to_string(x)+","+to_string(y)+")";
        return str;
    }
    float distance(Point p){
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
    
};


int main() {
    Point p1;
    Point p2(1, 9);
    cout<<"La distance entre "<<p1.coord()<<" et "<<p2.coord()<<" est: "<<p1.distance(p2)<<endl;
    return 0;
}
