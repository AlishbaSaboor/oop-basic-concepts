# OOP-Basic-Concepts
Object-Oriented Programming (OOP) is a programming paradigm that uses objects to design and structure software. C++ supports OOP by allowing developers to model real-world entities using classes and objects.
<h3>Key Features of OOP in C++:</h3>

**Encapsulation:**  
- Bundling data and functions inside a class.
- Protects data using private and public access specifiers.

**Abstraction:**  
- Hiding unnecessary implementation details from the user.
- Implemented using access modifiers (public, private, protected).

**Inheritance:**
- A mechanism where one class acquires properties of another.
- Allows code reusability (class Derived : public Base).

**Polymorphism:**  
- Ability to take multiple forms.
- Achieved through function overloading, operator overloading, and virtual functions.

**Classes & Objects:**  
- Class: A blueprint for creating objects.
- Object: An instance of a class.

**Syntax Example of OOP in C++:**  
```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    Car(string b) {
        brand = b;
    }
    void showBrand() {
        cout << "Car brand: " << brand << endl;
    }
};

int main() {
    Car myCar("Toyota");
    myCar.showBrand();
    return 0;
}
```

**Real-world Analogy:**  
Think of OOP as a car factory:  
Class → The blueprint of a car.  
Object → A specific car made from the blueprint.  
Encapsulation → The engine is hidden inside the hood (private data).  
Inheritance → A sports car inherits features from a general car.  
Polymorphism → A "drive" function works differently for a manual and automatic car.  

## Virtual & Pure Virtual functions
<h3>Virtual Functions:</h3> 
A virtual function is a function in a base class that you can override in a derived class. When calling a virtual function through a base class pointer, the derived class version is executed.  

**Key Points:**  
- Declared using the virtual keyword in the base class.
- Ensures correct function execution in an inheritance hierarchy.
- Enables runtime polymorphism.  

**Syntax:**
```cpp
virtual void print();
```

<h3>Pure Virtual Functions:</h3>
A pure virtual function is a function that has no implementation in the base class and must be overridden in derived classes. A class with at least one pure virtual function is called an abstract class.  

**Syntax:**
```cpp
virtual void show() = 0;
```

**Real-world example:**  
Think of a "Shape" class where different shapes (circle, square, triangle) must define their own way of calculating area.

## Virtual Classes
A virtual base class is used to prevent duplicate instances of a base class when using multiple inheritances.

**Key Points:**

- Declared using the virtual keyword in the base class.

- Helps solve the diamond problem in multiple inheritance.

**Syntax:**
```cpp
class A {
    // Base class
};
class B : virtual public A {
    // Virtual inheritance
};
class C : virtual public A {
    // Virtual inheritance
};
class D : public B, public C {
    // Avoids duplicate A
};
```

**Real-world example:**

Think of a grandfather (A), who has two children father (B) and uncle (C). The grandson (D) should inherit the grandfather only once, not twice.

## Friend Function
A function that is not a member of a class but can access its private and protected members.

**Key Points:**

- Declared using the friend keyword inside the class.

- Helps access private members from outside the class.

**Syntax:**

```cpp
class A {
    private:
        int value;
    public:
        friend void show(A obj); // Friend function declaration
};
```

## Friend Class
A class that has access to the private and protected members of another class.

**Syntax:**

```cpp
class A {
    friend class B; // B is a friend of A
};
```

**Real-world example:**

Think of a bank account class. A separate audit class may need to access the private balance for verification purposes.

## Operator Overloading
Operator overloading allows operators (like +, -, *) to be used with objects of a class.

Key Points:

Enables user-defined meaning for built-in operators.

Cannot overload ::, sizeof, .*, and ?:.

Syntax:

class A {
    public:
        A operator+(A obj); // Overloading + operator
};

Real-world example: Think of a money class where adding two money objects adds their values.
## Aggregation
A weak "has-a" relationship where an object contains another object but does not own it.

Syntax:

class Engine {};
class Car {
    Engine* engine; // Aggregation (Engine exists independently)
};
Real-world example:
A university has professors, but professors exist independently.
## Composition
A strong "has-a" relationship where an object contains another object and owns its lifecycle.

Syntax:

class Engine {};
class Car {
    Engine engine; // Composition (Engine is owned by Car)
};

Real-world example:
 A car has an engine, and if the car is destroyed, the engine is also destroyed.
## Template for variables & arrays
Templates allow writing generic code that works with any data type.

Key Points:

Allows the same code to work for multiple data types.

Reduces redundancy in code.

Syntax:

template <typename T>
T add(T a, T b) {
    return a + b;
}

Real-world example: Think of a calculator that can work with both integers and floating-point numbers without writing separate functions.
## Static members & functions
Static Data Members:

A class member shared by all objects of the class.

Syntax:

class A {
    static int count;
};

Static Functions:

A function that does not depend on any instance of the class.

Syntax:static void display();
## This pointer (this->)
A special pointer available in all non-static member functions pointing to the current object.

Syntax:

class A {
    void show() {
        cout << this->value;
    }
};
## Insertion&extraction operator overloading (With file handling)
Syntax:

ofstream file("data.txt");
file << obj; // Overloaded insertion operator
file.close();
## Insertion&extraction operator overloading (Without file handling)
Syntax:

ostream& operator<<(ostream& out, const A& obj);
istream& operator>>(istream& in, A& obj);
## insertion/extraction operator overloading(calling base class  from derived class to overload)
Syntax:

ostream& operator<<(ostream& out, const Derived& obj) {
    out << (Base)obj;
    return out;
}
## File Handling
File handling enables programs to read/write data from files.

Syntax:

#include <fstream>
ofstream file("data.txt");
file << "Hello!";
file.close();
## Exeption Handling
Exception handling deals with runtime errors to prevent crashes.

Key Points:

Uses try, catch, and throw.

Helps maintain program flow in case of errors.

Syntax:

try {
    throw "Error!";
} catch (const char* msg) {
    cout << msg;
}
## Dynamic Memory Allocation(for object)
Dynamic memory allocation allows allocating memory at runtime using new and deallocating using delete.

Key Points:

new operator allocates memory dynamically.

delete operator deallocates memory to prevent memory leaks.

Syntax:

A* obj = new A();
delete obj;