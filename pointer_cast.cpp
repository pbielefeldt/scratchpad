#include <iostream>
#include <memory>

class Base {
public:
    Base(int data) : data_(data) {}

    int getData() const {
        return data_;
    }

    virtual ~Base() = default;

private:
    int data_;
};

class Derived1 : public Base {
public:
    Derived1(int data, int extraData) : Base(data), extraData_(extraData) {}

    void printName() {
        std::cout << "I am derived 1 (int data, int extraData)" << std::endl;
    }


    int getExtraData() const {
        return extraData_;
    }

private:
    int extraData_;
};

class Derived2 : public Base {
public:
    Derived2(int data, double extraData) : Base(data), extraData_(extraData) {}

    void printName() {
        std::cout << "I am derived 2 (int data, double extraData)" << std::endl;
    }

    double getExtraData() const {
        return extraData_;
    }

private:
    int extraData_;
};

class Derived3 : public Base {
public:
    Derived3(int data) : Base(data) {}
    
    void printName() {
        std::cout << "I am derived 3 (int data)" << std::endl;
    }
};

int main() {
    std::shared_ptr<Base> basePtr;

    // Create objects
    basePtr = std::make_shared<Derived1>(10, 5);

    // Check if it's a Derived1 object
    if (auto derived1Ptr = std::dynamic_pointer_cast<Derived1>(basePtr)) {
        derived1Ptr->printName();
        std::cout << "Derived1 data: " << derived1Ptr->getData() << ", Extra data: " << derived1Ptr->getExtraData() << std::endl;
    } else {
        std::cout << "It's not a Derived1 object." << std::endl;
    }

    // Create another object
    basePtr = std::make_shared<Derived2>(20, 3.14);

    // Check if it's a Derived2 object
    if (auto derived2Ptr = std::dynamic_pointer_cast<Derived2>(basePtr)) {
        derived2Ptr->printName();
        std::cout << "Derived2 data: " << derived2Ptr->getData() << ", More data: " << derived2Ptr->getExtraData() << std::endl;
    } else {
        std::cout << "It's not a Derived2 object." << std::endl;
    }

    // Create another object
    basePtr = std::make_shared<Derived3>(30);

    // Check if it's a Derived3 object
    if (auto derived3Ptr = std::dynamic_pointer_cast<Derived3>(basePtr)) {
        derived3Ptr->printName();
        std::cout << "Derived3 data: " << derived3Ptr->getData() << " -- no extra data" << std::endl;
    } else {
        std::cout << "It's not a Derived3 object." << std::endl;
    }

    return 0;
}
