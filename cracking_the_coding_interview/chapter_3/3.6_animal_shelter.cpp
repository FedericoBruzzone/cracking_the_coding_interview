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
    virtual ~Animal() = default;

    virtual std::string getClassName() = 0;

    void setOrder(int order) { _order = order; }
    int getOrder() { return _order; }
    void setType(std::string type) { _type = type; }
    inline std::string getType() { return _type; }

    // bool Compare(Animal* a) 
    // {
    //     return this->_order > a->getOrder(); 
    // }

    bool operator<(const Animal* b) const 
    {
        return this->_order < b->_order;
    }

protected:
    int _order;
private:
    std::string _type;
};

class Dog : public Animal 
{ 
public: 
    Dog(std::string name) : _name(name) {} 
    inline std::string getClassName() override { return "Dog"; }
    inline std::string getName() const { return _name; }
private:
    std::string _name;
};

class Cat : public Animal 
{ 
public: 
    Cat(std::string name) : _name(name) {} 
    inline std::string getClassName() override { return "Cat"; }
    inline std::string getName() const { return _name; }
private:
    std::string _name;
};

class AnimalQueue
{
public:
    std::list<Cat*> _cats = std::list<Cat*>();
    std::list<Dog*> _dogs = std::list<Dog*>();
    int _order;

    AnimalQueue() { _order = 0; }

    void enqueue(Animal* a)
    {
        a->setOrder(_order);
        _order++;

        if (a->getClassName() == "Dog") { _dogs.push_back( (Dog*)a ); }
        if (a->getClassName() == "Cat") { _cats.push_back( (Cat*)a ); }
    }

    Cat* dequeueCats() 
    { 
        Cat* cat = _cats.back();
        _cats.pop_back(); 
        return cat;
    }

    Dog* dequeueDogs() 
    { 
        Dog* dog = _dogs.back();
        _dogs.pop_back(); 
        return dog;
    }
    

    Animal* dequeueAny()
    {
        if (_cats.empty()) return (Animal*)dequeueDogs();
        if (_dogs.empty()) return (Animal*)dequeueCats();

        if ((Animal*)_cats.back() < (Animal*)_dogs.back()) 
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
    
    aq.enqueue(new Dog("d1"));
    aq.enqueue(new Cat("c1"));
    aq.enqueue(new Cat("c2"));
    aq.enqueue(new Dog("d2"));

    LOG("cats")
    for (auto i : aq._cats) { LOG(i->getName()) LOG(i->getOrder()) }
    LOG("dogs")
    for (auto i : aq._dogs) { LOG(i->getName()) LOG(i->getOrder()) }

    aq.dequeueAny();

    LOG("cats")
    for (auto i : aq._cats) { LOG(i->getName()) }
    LOG("dogs")
    for (auto i : aq._dogs) { LOG(i->getName()) }

    aq.dequeueAny();

    LOG("cats")
    for (auto i : aq._cats) { LOG(i->getName()) }
    LOG("dogs")
    for (auto i : aq._dogs) { LOG(i->getName()) }

}