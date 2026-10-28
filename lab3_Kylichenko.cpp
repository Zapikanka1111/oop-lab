#include <iostream>
#include <cstring>
using namespace std;

class Employee{
    private:
    char* surname;
    char* position;
    double salary;

    public:
Employee() {
    surname = new char[1];
    surname[0] = '\0';
    position = new char[1];
    position[0] = '\0';
    salary = 0;
};


    ~Employee(){
        delete[] surname;
        delete[] position;
    };

    void inputSalary() {
    double s;
    cout << "Vvedit zarplatu: ";
    cin >> s;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw "Potribne chyslo";
    }
    if (s < 0) {
        throw "Nekorektna zarplata";
    }
    salary = s;
};

Employee(const char* s, const char* p, double sal) {
    if (sal < 0) {
        throw "Nekorektna zarplata";
    }
    surname = new char[strlen(s) + 1];
    strcpy(surname, s);
    position = new char[strlen(p) + 1];
    strcpy(position, p);
    salary = sal;
};

Employee& operator=(const Employee& other) {
    if (this == &other) return *this;

    delete[] surname;
    delete[] position;

    surname = new char[strlen(other.surname) + 1];
    strcpy(surname, other.surname);

    position = new char[strlen(other.position) + 1];
    strcpy(position, other.position);

    salary = other.salary;
    return *this;
};


Employee(const Employee& other) {
    surname = new char[strlen(other.surname) + 1];
    strcpy(surname, other.surname);

    position = new char[strlen(other.position) + 1];
    strcpy(position, other.position);

    salary = other.salary;
}

    Employee& operator+=(double bonus){
        if (bonus < 0){
            throw "Nekorektna suma";
        }
        salary += bonus;
        return *this;
    };


    double getSalary() const{
        return salary;
    };

     char* getSurname() const{
        return surname;
    };

    char* getPosition() const { 
        return position; 
    };

    void print() const{
        cout << surname << ", " << position << ", " << salary << endl;
    };
};



class Zarplata {
private:
    Employee* staff;
    int count;
public:
    Zarplata(){
        staff = nullptr;
        count = 0;
    };                            


    ~Zarplata(){
        delete[] staff;
    };                                 


    Zarplata(const Zarplata& other){
        count = other.count;
        staff = new Employee[count];

        for(int i = 0; i < count; i++){
            staff[i] = other.staff[i];
        };
        
    };            


    Zarplata& operator=(const Zarplata& other){
        if (this == &other) return *this;     
        delete[] staff;                        
        count = other.count;
        staff = new Employee[count];               
        for (int i = 0; i < count; i++) {
            staff[i] = other.staff[i];          
        }
        return *this;
    };   


    Zarplata operator+(const Employee& e) const{
        Zarplata result;                      
        result.count = count + 1;                  
        result.staff = new Employee[result.count];          
        for (int i = 0; i < count; i++) {      
           result.staff[i] = staff[i];
        }
        result.staff[result.count - 1] = e;                
        return result; 
        }; 


       Zarplata operator-(const char* surname) const {
    int index = -1;                              
    for (int i = 0; i < count; i++) {
        if (strcmp(staff[i].getSurname(), surname) == 0) {
            index = i;
        }
    }
    if (index == -1) {
        throw "Spivrobitnyka ne znaideno";
    }

    Zarplata result;
    result.count = count - 1;
    result.staff = new Employee[result.count];

    int j = 0;                                    // куди писати в новий масив
    for (int i = 0; i < count; i++) {
        if (i != index) {
            result.staff[j] = staff[i];
            j++;
        }
    }
    return result;
};

int find(const char* surname) const {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(staff[i].getSurname(), surname) == 0) {
            staff[i].print();
            found++;
        }
    }
    return found;
};


    int find(double from, double to) const{
        int found = 0;
        for (int i = 0; i < count; i++){
            if(staff[i].getSalary() >= from && staff[i].getSalary() <= to){
                staff[i].print();
                found ++;
            };
        };
        return found;
    };


    int find(const char* position, double minSalary) const{
        int found = 0;
        for(int i = 0; i < count; i++){
            if(strcmp(staff[i].getPosition(), position) == 0 && staff[i].getSalary() >= minSalary){
                staff[i].print();
                found ++;
            };
        };
        return found;
    };
     
     void print() const{
        for(int i = 0; i < count; i++){
                cout << i + 1 << ". ";
                staff[i].print();
        };
    };       
    
    
};


int main() {
    Zarplata z;
    z = z + Employee("Ivanenko", "Manager", 1000);
    z = z + Employee("Petrenko", "Clerk", 800);
    z.print();

    Zarplata z2 = z;     // перевірка копіювання
    z2.print();

    z = z - "Ivanenko";
    z.print();                         // лишився тільки Petrenko

    try { z = z - "Nobody"; }
    catch (const char* msg) { cout << "Pomylka: " << msg << endl; }

    z.find("Petrenko");
    z.find(500, 900);
    z.find("Clerk", 700);

    Employee e;
try {
    e.inputSalary();
    cout << "Zarplata: " << e.getSalary() << endl;
}
catch (const char* msg) {
    cout << "Pomylka: " << msg << endl;
}
}