
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Employee{
    string id;
    string nom;
    double salaire;
    static int employeeCount;
    static double bonusPourcentage;
public:
    Employee(): nom(""), salaire(0.0){
        employeeCount++;
        id = to_string(employeeCount);
    }
    Employee(string nom, double salaire ): nom(nom), salaire(salaire){
        employeeCount++;
        id = to_string(employeeCount);
    }
    Employee(const Employee &e){
        employeeCount++;
        this->id = to_string(employeeCount);
        this->nom = e.nom;
        this->salaire = e.salaire;
    }
    ~Employee(){
        employeeCount--;
    }
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
    
    double getSalaire(){
        return salaire;
    }
    void setSalaire(double salaire){
        this->salaire = salaire;
    }
    double operator+(const Employee &e){
        return salaire + e.salaire;
    }
    friend ostream& operator<<(ostream& o, const Employee &e){
        o<<e.id<<endl;
        o<<e.nom<<endl;
        o<<e.salaire<<endl;
        return o;
    }
    void promoter(double montant){
        salaire += montant;
    }
    static double averageSalary(vector<Employee> es){
        double somme = 0;
        for(Employee &e: es){
            somme += e.salaire;
        }
        return somme / es.size();
    }
    static void setBonusPercentage(double bonus){
        bonusPourcentage = bonus;
    }
    void awardBonus(){
        salaire = salaire + salaire * bonusPourcentage;
    }
};
int Employee::employeeCount = 0;
double Employee::bonusPourcentage = 0;
int main(){
    vector<Employee> employees;
        Employee::setBonusPercentage(10.0); // 10% bonus
        Employee emp1("Alice", 50000.0);
        Employee emp2("Bob", 60000.0);
        Employee emp3("Charlie", 70000.0);
        employees.push_back(emp1);
        employees.push_back(emp2);
        employees.push_back(emp3);
        cout << "Somme des employees 1 et 2: " << emp1 + emp2 << endl;
        emp3.promoter(5000.0);
        cout << "Employee apres promotion: " << emp3 << endl;
        cout << "Salaire moyenne: " << Employee::averageSalary(employees) << endl;
        for (auto& emp : employees) {
            emp.awardBonus();
        }
        cout << "Employees apres bonus:"<<endl;
        for (const auto& emp : employees) {
            cout << emp << endl;
        }



    return 0;
}
