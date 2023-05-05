#include "entity.h"

Entity::Entity(){}

Entity::Entity(string name, int power, int age):
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
int Entity::getAge() const{
    return age;
}

// Metodi set
void Entity::setName(string name){
    this->name = name;
}
void Entity::setPower(int power){
    this->power = power;
}
void Entity::setAge(int age){
    this->age = age;
}
