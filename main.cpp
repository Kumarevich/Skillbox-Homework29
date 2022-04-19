#include <iostream>

class Animal
{
protected:
    std::string type = "animal";
public:
    std::string getType()
    {
        return type;
    }

    virtual void voice(Animal* a) = 0;
};

class Dog : virtual public Animal
{
public:
    Dog(std::string _type)
    {
        type =  _type;
    }

    virtual void voice(Animal* a)
    {
        if (a->getType() == "dog") std::cout << "Woof ";
        else std::cout << "Bark ";
    }
};

class Cat : virtual public Animal
{
public:
    Cat(std::string _type)
    {
        type = _type;
    }

    virtual void voice(Animal* a)
    {
        if (a->getType() == "dog") std::cout << "Meow ";
        else std::cout << "Purr ";
    }
};

void meeting(Animal* a, Animal* b)
{
    std::cout << a->getType() << " + " << b->getType() << " -> ";
    a->voice(b);
    b->voice(a);
    std::cout << std::endl;
}

int main() {
    Animal* animals[4];
    animals[0] = new Cat("cat");
    animals[1] = new Cat("cat");
    animals[2] = new Dog("dog");
    animals[3] = new Dog("dog");
    meeting(animals[0], animals[1]);
    meeting(animals[2], animals[3]);
    meeting(animals[0], animals[2]);
    meeting(animals[3], animals[1]);
    return 0;
}
