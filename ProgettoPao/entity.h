#ifndef ENTITY_H
#define ENTITY_H
#include <string>
using std::string;

class Entity{
public:
    Entity();
    Entity(string name, int power, bool state, int age);
    //virtual ~Entity();

    int seniority() const; 

    // Metodi virtuali


    // Metodi get
    string getName() const;
    int getPower() const;
    bool getState() const;
    int getAge() const;

    // Metodi set
    void setName(string);
    void setPower(int);
    void setState(bool);
    void setAge(int);
    
private:
    string name;
    int power;
    bool state;
    int age;
};

#endif // ENTITY_H
