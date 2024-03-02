#include "stack.h"
//lowkey not sure if i was supposed ot put this in a seperate file 
//or put it in the bottom of the ehader file the instructions were vague asf
//but thats how i did it so we shall see if it passes tests like this


// contuctor
template <typename T>
Stack<T>::Stack() : std::vector<T>() {}

// destructor
template <typename T>
Stack<T>::~Stack() {}

// empty function
template <typename T>
bool Stack<T>::empty() const
{
    return std::vector<T>::empty();
}

// size function
template <typename T>
size_t Stack<T>::size() const
{
    return std::vector<T>::size();
}

// pop function
template <typename T>
void Stack<t>::pop()
{
    if (this->empty())
    {
        throw std::underflow_error("Stack underflow");
    }
    std::vector<T>::pop_back();
}

// push function
template <typename T>
void Stack<T>::push(const T &item)
{ // const bc dont wanna change item when adding it
    std::vector<T>::push_back(item);
}

// top function
template <typename T>
const T &Stack<T>::top() const
{
    if (this->empty())
    {
        throw std::underflow_error("Stack underflow");
    }
    return std::vector<T>::back();
}