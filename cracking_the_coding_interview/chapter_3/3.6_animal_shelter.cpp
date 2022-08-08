#include "../../ALL_H_FILES.h"

// =============================================================

// template<typename Base, typename T>
// inline bool instanceof(const T *ptr) 
// {
//    return dynamic_cast<const Base*>(ptr) != nullptr;
// }


class Animal
{
public:
    Animal() = default;
    
    virtual std::string getClassName() = 0;

    void setOrder(int order) { order = order; }
    inline int getOrder() { return order; }
    void setOrder(std::string type) { type = type; }
    inline std::string getType() { return type; }

    bool Compare(Animal* a) 
    {
        return this->order > a->getOrder(); 
    }

protected:
    std::string type;

private:
    int order;
};

class Dog : public Animal 
{ 
public: 
    Dog(std::string name) : name(name) {} 
    inline std::string getClassName() { return "Dog"; }
    inline std::string getName() { return name; }
private:
    std::string name;
};

class Cat : public Animal 
{ 
public: 
    Cat(std::string name) : name(name) {} 
    inline std::string getClassName() { return "Cat"; }
    inline std::string getName() { return name; }
private:
    std::string name;
};

class AnimalQueue
{
public:
    std::list<Cat*> cats = std::list<Cat*>();
    std::list<Dog*> dogs = std::list<Dog*>();
    int order = 0;

    void enqueue(Animal* a)
    {
        a->setOrder(order);
        order++;

        if ( typeid(*a) == typeid(Dog) ) { LOG("OK") dogs.push_back( (Dog*)a ); }
        if ( typeid(&a) == typeid(Cat) ) { LOG("OK") cats.push_back( (Cat*)a ); }
    }

    Cat* dequeueCats() 
    { 
        Cat* cat = cats.back();
        cats.pop_back(); 
        return cat;
    }

    Dog* dequeueDogs() 
    { 
        Dog* dog = dogs.back();
        dogs.pop_back(); 
        return dog;
    }
    

    Animal* dequeueAny()
    {
        if (cats.empty()) return (Animal*)dequeueDogs();
        if (dogs.empty()) return (Animal*)dequeueCats();

        if (dogs.back()->isOlderThen(*(cats.back()))) 
        { 
            return (Animal*)dequeueDogs();
        }
        else 
        { 
           return (Animal*)dequeueCats();
        }

    }
};

// =============================================================

int main()
{
    AnimalQueue aq;
    
    Dog* d1 = new Dog("d1");
    Dog* d2 = new Dog("d2");

    Cat* c1 = new Cat("d1");
    Cat* c2 = new Cat("d2");

    aq.enqueue(d1);
    aq.enqueue(d2);

    aq.enqueue(c1);
    aq.enqueue(c2);

    for (auto i : aq.cats) 
    { 
        LOG(i->name)
    }

    for (auto i : aq.dogs) 
    { 
        LOG(i->name)
    }

    aq.dequeueAny();

    for (auto i : aq.cats) { std::cout << i->name << std::endl; }
    for (auto i : aq.dogs) { std::cout << i->name << std::endl; }

}