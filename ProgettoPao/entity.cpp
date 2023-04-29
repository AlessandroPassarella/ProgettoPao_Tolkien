#include "entity.h"

Entity::Entity(){}

Entity::Entity(string name, int power, bool state, int age): 
name(name), power(power), state(state), age(age){}

// Metodi get
string Entity::getName() const{
    return name;
}
int Entity::getPower() const{
    return power;
}
bool Entity::getState() const{
    return state;
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
void Entity::setState(bool state){
    this->state = state;
}
void Entity::setAge(int age){
    this->age = age;
}