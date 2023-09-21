#include <iostream>
#include <set>
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

void doStuff(const std::shared_ptr<Base> &ptr) {
    
    const std::string tname = std::string(typeid(*ptr).name());
    std::cout << "tname = " << tname << std::endl;
    const std::set<std::string> types_with_extradata = {"8Derived1", "8Derived2"};
    
    if (types_with_extradata.find(tname) == types_with_extradata.end()) {
        std::cout << "not a class with extra data!" << std::endl;
        std::cout << "data: " << ptr->getData() << std::endl;
        return;
    }
    
    if (tname == "8Derived1"){
        auto derived1Ptr = std::dynamic_pointer_cast<Derived1>(ptr);
        std::cout << "data: " << derived1Ptr->getData() << ", extra data: " << derived1Ptr->getExtraData() << std::endl;
    }
    
    if (tname == "8Derived2"){
        auto derived2Ptr = std::dynamic_pointer_cast<Derived2>(ptr);
        std::cout << "data: " << derived2Ptr->getData() << ", extra data: " << derived2Ptr->getExtraData() << std::endl;
    }
    return;
}


int main() {
    std::shared_ptr<Base> basePtr;

    // Create objects
    basePtr = std::make_shared<Derived1>(10, 5);
    doStuff(basePtr);

    // Create another object
    basePtr = std::make_shared<Derived2>(20, 3.14);
    doStuff(basePtr);

    // Create another object
    basePtr = std::make_shared<Derived3>(30);
    doStuff(basePtr);

    return 0;
}
