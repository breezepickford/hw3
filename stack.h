#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// BREEZE REMEMBER FOR STUDYING THIS IS GOOD EXAMPLE OF WHAT DIFFERENT CONST PLACEMENTS DO!!!!!

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> // private inheritance bc a stack doesnt want to do all the things a vector does, so some of its methods should be inaccessible
{
public:
    Stack();
    ~Stack();
    bool empty() const; // const at the end means it will not modify member vars of this class. good for things that are only supposed to check the state of smth but not modify it (empty, size, top)
    size_t size() const;
    void push(const T &item);
    //^takes in param of const reference (const T &) so that it push method doesnt modify the item being pushed onto stack, and also avoids unnesseary copying (reference moves the real var 'by address' and not a copy of the var)
    void pop();           // throws std::underflow_error if empty
    const T &top() const; // throws std::underflow_error if empty
    //^ return type is const reference (Const T &)  so that caller of method cannot modify the ele returned by top
    // const at the end makes it so it doesnt modify mem vars of this class
    // Add other members only if necessary
};

#endif