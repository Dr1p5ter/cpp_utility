#ifndef STACK_H
#define STACK_H

template <typename T> class NodeStack
{

  public:
    T* data;
    NodeStack<T>* next;

}; /* Class :: NodeStack */

template <typename T> class Stack
{

  private:
    NodeStack<T>* top;

  public:
    void push(T* dataToPush);
    T* pop(void);
    bool isEmpty(void);
    int size(void);
    T* peek(void);

    Stack();

}; /* Class :: Stack */

#include "../ds_cpp/stack.cpp"

#endif
