#include <iostream>
#include <list>

class B {
public:
    virtual void doSomething() {
        std::cout << "I am a B." << std::endl;
    }
};

class A : public B {
public:
    void doSomething() override {
        std::cout << "I am an A." << std::endl;
    }
};

int main() {
    std::list<B*> myList;

    // Populate the list
    myList.push_back(new B());
    myList.push_back(new A());
    myList.push_back(new B());
    myList.push_back(new A());

    // Iterate over the list and count the number of elements of type A/B
    int countA(0);
    int countB(0);
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        if (dynamic_cast<A*>(*it) != nullptr) {
            countA++;
        }
        if (dynamic_cast<B*>(*it) != nullptr) {
            countB++;
        }
    }

    std::cout << "There are " << countA << " elements of type A and " 
              << countB << " elements of type B in the list." << std::endl;

    // Clean up memory
    for (auto ptr : myList) {
        delete ptr;
    }

    return 0;
}
