#include <iostream>
#include <cstring>
using namespace std;

class Kafedra{
    private: 
    char* surenameHead;
    int Worker;

    public:

    Kafedra(){
        surenameHead = nullptr;
        Worker = 0;
    }

    ~Kafedra(){
        delete[] surenameHead;
    }

    void setSurenameHead(const char* n){
        delete[] surenameHead;
        surenameHead = new char[strlen(n) + 1];
        strcpy(surenameHead, n);
    }

    char* getSurenameHead() const{
        return surenameHead;
    }

    void setWorker(int w){
        Worker = w;
    }

    int getWorker() const{
        return Worker;
    }

    void input(){
        char buffer[100];
        int k;
        cout << "Wwedit surenameHead: ";
        cin >> buffer;
        setSurenameHead(buffer);
        cout << "Wwedit worker: ";
        cin >> k;
        setWorker(k);
    }

    void print() const{
        cout << "Surenamehead: " << getSurenameHead() << " Worker: " << getWorker() << endl;
    }

};


class Institute{

    private:
    char* SurenameDirector;
    Kafedra* kafedry;
    int kafedraCount;

    public:
    Institute(){
        SurenameDirector = nullptr;
        kafedry = nullptr;
        kafedraCount = 0;
    }

    ~Institute(){
        delete[] SurenameDirector; 
        delete[] kafedry;
    }

    void setSurenameDirector(const char* n){
        delete[] SurenameDirector;
        SurenameDirector = new char[strlen(n) + 1];
        strcpy(SurenameDirector, n);
    }

    char* getSurenameDirector() const{
        return SurenameDirector;
    }

    void input(){
        char buffer[100];
        cout << "SurenameDirector: " << endl;
        cin >> buffer;
        setSurenameDirector(buffer);
        cout << "\nKil kafedry: ";
        cin >> kafedraCount;
        kafedry = new Kafedra[kafedraCount];
        for(int i = 0; i < kafedraCount; i++){
            kafedry[i].input();
        }
    }

    void print() const{
        cout << "SurenameDirector: " << getSurenameDirector() << endl;
        for(int i = 0; i < kafedraCount; i++){
            kafedry[i].print();
        }
    }

    int getTotalWorkers() const {
        int sum = 0;
        for (int i = 0; i < kafedraCount; i++) {
            sum += kafedry[i].getWorker();
        }
        return sum;
}
};

class Universiti{

    private: 
    char* Surenamerector;
    Institute* instytuty;
    int institutCount;

    public:
    Universiti(){
        Surenamerector = nullptr;
        instytuty = nullptr;
        institutCount = 0;
    }

    ~Universiti(){
        delete[] Surenamerector;
        delete[] instytuty;
    }

    void setSurenamerector(const char* n){
        delete[] Surenamerector;
        Surenamerector = new char[strlen(n) + 1];
        strcpy(Surenamerector, n);    
    }

    char* getSurenamerector() const{
        return Surenamerector;
    }

    void input(){
        char buffer[100];
        cout << "Surenamerector: " << endl;
        cin >> buffer;
        setSurenamerector(buffer);
        cout << "\nKil Institute: ";
        cin >> institutCount;
        instytuty = new Institute[institutCount];
        for(int i = 0; i < institutCount; i++){
            instytuty[i].input();
        }
    }

    void print() const{
        cout << "Surenamerector: " << getSurenamerector() << endl;
        for(int i = 0; i < institutCount; i++){
            instytuty[i].print();
        }
    }


    int getTotalTotalWorker() const{
        int sum = 0;
        for (int i = 0; i < institutCount; i++) {
            sum += instytuty[i].getTotalWorkers();
        }
        return sum;
    }
};

int main(){
    Universiti u;
    u.input();
    u.print();
    cout << u.getTotalTotalWorker();
};