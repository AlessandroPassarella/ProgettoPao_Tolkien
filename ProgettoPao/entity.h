#ifndef ENTITY_H
#define ENTITY_H
#include <string>
using std::string;

class Entity {
public:
    Entity();
    Entity(string name, int power, int age);
    Entity(string serialized);

    int seniority() const; 

    // Metodi virtuali
    virtual ~Entity() = 0;
    virtual string asString();
    static Entity* fromString(const string);

    // Metodi get
    string getName() const;
    int getPower() const;
    int getAge() const;

    // Metodi set
    void setName(string);
    void setPower(int);
    void setAge(int);
    
private:
    string name;
    int power;
    int age;
};

#endif // ENTITY_H
