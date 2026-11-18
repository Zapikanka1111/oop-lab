#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Osoba{
    protected:
    char* surname;
    int age;

    public:
    Osoba(const char* s, int a){
        surname = new char[strlen(s) + 1];
        strcpy(surname, s);
        age = a;
    }

    ~Osoba(){
        delete[] surname;
    }

    void setSurname(const char* s){
        delete[] surname;
        surname = new char[strlen(s) + 1];
        strcpy(surname, s);
    }

    char* getSurname() const{
        return surname;
    }

    void setAge(int a){
        age = a;
    }

    int getAge() const{
        return age;
    }

    void printOwn(ostream& out) const{
        out << "Prizvyshche: " << getSurname() << endl;
        out << "Vik: " << getAge() << endl;
    }

    void print(ostream& out) const{
        out << "--- Osoba ---" << endl;
        printOwn(out);
    }
};


class Sportsman : virtual public Osoba{
    protected:
    char* sport;
    char* rank;

    public:
    Sportsman(const char* s, int a, const char* sp, const char* r) : Osoba(s, a){
        sport = new char[strlen(sp) + 1];
        strcpy(sport, sp);
        rank = new char[strlen(r) + 1];
        strcpy(rank, r);
    }

    ~Sportsman(){
        delete[] sport;
        delete[] rank;
    }

    void setSport(const char* sp){
        delete[] sport;
        sport = new char[strlen(sp) + 1];
        strcpy(sport, sp);
    }

    char* getSport() const{
        return sport;
    }

    void setRank(const char* r){
        delete[] rank;
        rank = new char[strlen(r) + 1];
        strcpy(rank, r);
    }

    char* getRank() const{
        return rank;
    }

    void printOwn(ostream& out) const{
        out << "Vyd sportu: " << getSport() << endl;
        out << "Rozriad: " << getRank() << endl;
    }

    void print(ostream& out) const{
        out << "--- Sportsman ---" << endl;
        Osoba::printOwn(out);
        printOwn(out);
    }
};


class Vykladach : virtual public Osoba{
    protected:
    char* subject;
    int experience;

    public:
    Vykladach(const char* s, int a, const char* subj, int exp) : Osoba(s, a){
        subject = new char[strlen(subj) + 1];
        strcpy(subject, subj);
        experience = exp;
    }

    ~Vykladach(){
        delete[] subject;
    }

    void setSubject(const char* subj){
        delete[] subject;
        subject = new char[strlen(subj) + 1];
        strcpy(subject, subj);
    }

    char* getSubject() const{
        return subject;
    }

    void setExperience(int exp){
        experience = exp;
    }

    int getExperience() const{
        return experience;
    }

    void printOwn(ostream& out) const{
        out << "Predmet: " << getSubject() << endl;
        out << "Stazh (rokiv): " << getExperience() << endl;
    }

    void print(ostream& out) const{
        out << "--- Vykladach ---" << endl;
        Osoba::printOwn(out);
        printOwn(out);
    }
};


class Trener : public Sportsman, public Vykladach{
    private:
    char* team;
    int athletes;

    public:
    Trener(const char* s, int a, const char* sp, const char* r, const char* subj, int exp, const char* t, int n) : Osoba(s, a), Sportsman(s, a, sp, r), Vykladach(s, a, subj, exp){
        team = new char[strlen(t) + 1];
        strcpy(team, t);
        athletes = n;
    }

    ~Trener(){
        delete[] team;
    }

    void setTeam(const char* t){
        delete[] team;
        team = new char[strlen(t) + 1];
        strcpy(team, t);
    }

    char* getTeam() const{
        return team;
    }

    void setAthletes(int n){
        athletes = n;
    }

    int getAthletes() const{
        return athletes;
    }

    void print(ostream& out) const{
        out << "--- Trener ---" << endl;
        Osoba::printOwn(out);
        Sportsman::printOwn(out);
        Vykladach::printOwn(out);
        out << "Komanda: " << getTeam() << endl;
        out << "Sportsmeniv u hrupi: " << getAthletes() << endl;
    }
};


bool saveToFile(const char* filename, ios::openmode mode, const Sportsman& sp, const Vykladach& vy, const Trener& tr){
    ofstream fout(filename, mode);
    if(!fout.is_open()){
        cout << "Ne vdalosia vidkryty fail " << filename << endl;
        return false;
    }
    sp.print(fout);
    fout << endl;
    vy.print(fout);
    fout << endl;
    tr.print(fout);
    fout << "==========" << endl;
    fout.close();
    return true;
}

void showFile(const char* filename){
    ifstream fin(filename);
    if(!fin.is_open()){
        cout << "Ne vdalosia vidkryty fail " << filename << endl;
        return;
    }
    char line[200];
    while(fin.getline(line, 200)){
        cout << line << endl;
    }
    fin.close();
}


int main(){
    const char* fileName = "lab4_output.txt";

    cout << "===== Komplekt danykh 1 =====" << endl;
    {
        cout << "Stvoriuiemo obiekty:" << endl;
        Sportsman sp("Kovalenko", 22, "Plavannia", "KMS");
        Vykladach vy("Melnyk", 45, "Fizyka", 20);
        Trener tr("Shevchenko", 38, "Futbol", "MS", "Fizychne vykhovannia", 12, "Dynamo-2", 25);

        cout << "\nVyvid na ekran:" << endl;
        sp.print(cout);
        cout << endl;
        vy.print(cout);
        cout << endl;
        tr.print(cout);

        cout << "\nUspadkovani metody Trener: prizvyshche = " << tr.getSurname() << ", vik = " << tr.getAge() << endl;

        if(saveToFile(fileName, ios::out | ios::trunc, sp, vy, tr)){
            cout << "\nDani komplektu 1 zapysano u fail " << fileName << endl;
        }
        cout << "\nZnyshchuiemo obiekty:" << endl;
    }

    cout << "\n===== Komplekt danykh 2 =====" << endl;
    {
        cout << "Stvoriuiemo obiekty:" << endl;
        Sportsman sp("Bondarenko", 19, "Tenis", "I rozriad");
        Vykladach vy("Tkachenko", 52, "Anatomiia", 28);
        Trener tr("Lysenko", 41, "Basketbol", "KMS", "Teoriia sportu", 15, "Lviv-Basket", 18);

        cout << "\nVyvid na ekran:" << endl;
        tr.print(cout);

        if(saveToFile(fileName, ios::out | ios::app, sp, vy, tr)){
            cout << "\nDani komplektu 2 dopysano u kinets failu " << fileName << endl;
        }
        cout << "\nZnyshchuiemo obiekty:" << endl;
    }

    cout << "\n===== Vmist failu " << fileName << " =====" << endl;
    showFile(fileName);
}