#ifndef ENTITY_H
#define ENTITY_H
#include <string>
using std::string;

class Entity {
public:
    Entity();
    Entity(string name, int power, unsigned age);
    Entity(string serialized);

    int seniority() const;
    virtual Entity* clone() const = 0;

    // Metodi virtuali
    virtual ~Entity() = 0;
    virtual string asString();
    static Entity* fromString(const string);

    // Metodi get
    string getName() const;
    int getPower() const;
    unsigned getAge() const;

    // Metodi set
    void setName(string);
    void setPower(int);
    void setAge(unsigned);
    
private:
    string name;
    int power;
    unsigned age;
};

#endif // ENTITY_H
