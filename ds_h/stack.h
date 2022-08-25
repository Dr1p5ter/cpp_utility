#ifndef STACK_H
#define STACK_H

template <typename T> struct NodeStack
{

  public:
    T* _data;
    NodeStack<T>* _next;

}; /* Class :: NodeStack */

template <typename T> class Stack
{

  private:
    NodeStack<T>* _top;

  public:
    void push(T* dataToPush);
    T* pop(void);
    bool isEmpty(void);
    int size(void);
    T* peek(void);

    Stack();
    ~Stack();

}; /* Class :: Stack */

#include "../ds_cpp/stack.cpp"

#endif
