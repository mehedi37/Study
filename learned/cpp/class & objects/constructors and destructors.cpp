// Copyright [2022] Meek_0
// Learning Started 11/02/22 | 11.00 a.m
// Constructor and destructors

#include <iostream>
#include <string>

class player {
 private:
    std::string name;
    int health;
    int xp;
 public:
    void set_name(std::string name) {this->name = name;}    // "this" is a pointer to the object
    // void set_name(std::string name_input) {name = name_input;}


    // member methods with same name as class is called constructor
    // constructors with overloads



// Data is assigened to the object after creating it
    // not the best practice
    player() {
        name = "Def_Player";
        health = 100;
        xp = 0;
        std::cout << "No argument constructor is called" << std::endl;
    }




// Delegating constructor

    // Best way is to initialize the values in the constructor when object is created
    // just works on constructor initializer
    // the idea is to call another constructor (same name as the class) to initialize the object
    player(std::string name_val)    // use unique names
    : player {name_val, 100, 0} {
        std::cout << "String constructor created ! for " << name << std::endl;
    }




    // not assigning them after the object is created like upper example

// New way
    player(std::string name, int health, int xp)
    : name {name}, health {health}, xp {xp} {
        std::cout << "Three argument constructor called! for " << name << std::endl;
    }


    // Destructor
    ~player() {std::cout << "Destructor called! for " << name << std::endl;}
};

int main() {
    // they are separated by scopes "{}"
    // when class is out of scope then destructor is called
    {
        player meek;
        meek.set_name("Meek");
    }
    {
        player Mj;
        Mj.set_name("Mj");
        player hero;
        hero.set_name("Hero");
        player kim;
        kim.set_name("Kim");
        // destructor is called in reverse order of the constructors
    }
    {
    player *enemy = new player;
    enemy -> set_name("Enemy");
    delete enemy;
    player *boss = new player("Boss", 100, 1000);
    boss -> set_name("Boss");
    delete boss;
    }
    return 0;
}