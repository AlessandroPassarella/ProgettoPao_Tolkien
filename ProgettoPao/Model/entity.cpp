#include "entity.h"

Entity::Entity() {}
Entity::~Entity() = default;

Entity::Entity(string name, int power, unsigned age):
name(name), power(power), age(age){}

int Entity::seniority() const{
    return (getPower()*2) + getAge();
}

// Metodi get
string Entity::getName() const{
    return name;
}
int Entity::getPower() const{
    return power;
}
unsigned Entity::getAge() const{
    return age;
}

// Metodi set
void Entity::setName(string name){
    this->name = name;
}
void Entity::setPower(int power){
    this->power = power;
}
void Entity::setAge(unsigned age){
    this->age = age;
}
