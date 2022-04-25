#include <iostream>

class Animal
{
public:
    virtual void voice(Animal* a) = 0;
};

class Dog : virtual public Animal
{
public:
    Dog(){};

    virtual void voice(Animal* a)
    {
        if (typeid(*a) == typeid(*this)) std::cout << "Woof ";
        else std::cout << "Bark ";
    }
};

class Cat : virtual public Animal
{
public:
    Cat(){};

    virtual void voice(Animal* a)
    {
        if (typeid(*a) == typeid(*this)) std::cout << "Purr ";
        else std::cout << "Meow ";
    }
};

void getType(Animal* a)
{
    if (typeid(*a) == typeid(Dog)) std::cout << "dog";
    else if (typeid(*a) == typeid(Cat)) std::cout << "cat";
}

void meeting(Animal* a, Animal* b)
{
    getType(a);
    std::cout << " + ";
    getType(b);
    std::cout << " -> ";
    a->voice(b);
    b->voice(a);
    std::cout << std::endl;
}

int main() {
    Animal* animals[4];
    animals[0] = new Cat();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Dog();
    meeting(animals[0], animals[1]);
    meeting(animals[2], animals[3]);
    meeting(animals[0], animals[2]);
    meeting(animals[3], animals[1]);
    return 0;
}
