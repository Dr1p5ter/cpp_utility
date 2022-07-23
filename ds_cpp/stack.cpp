#include <iostream>

#include "..ds_h/stack.h"

/* This is the constructor for the Stack class. This will provide the necessary
 * set up for the rest of the implementation.
 */

template <typename T> Stack<T>::Stack(void)
{
  this->top = nullptr;
} /* Stack() */

/* This method will insert the data at the top of the stack and then will
 * return void.
 */

template <typename T> void Stack<T>::push(T* dataToPush)
{
  // TODO : finish implementation
} /* push() */

/* This method will remove the data at the top of the stack and then return the
 * pointer to the data.
 */

template <typename T> T* Stack<T>::pop(void)
{
  // TODO : finish implementation
  return nullptr;
} /* pop() */

/* This method will check the top of the stack to see if there is a null
 * pointer. If there is a null pointer, return T; else return F.
 */

template <typename T> bool Stack<T>::isEmpty(void)
{
  return (this->top == nullptr);
} /* isEmpty() */

/* This method will return the size of the stack as an int after traversing the
 * length of the stack. Returns 0 if empty.
 */

template <typename T> int Stack<T>::size(void)
{
  if (!isEmpty())
  {
    int n = 1;
    NodeStack<T>* findEnd = this->top;
    while (findEnd->next != nullptr)
    {
      n += 1;
      findEnd = findEnd->next;
    }
    return n;
  }
  return 0;
} /* size() */

/* This method will return the data at the top of the stack without removing it
 * so that order is kept.
 */

template <typename T> T* Stack<T>::peek(void)
{
  return this->top->data;
} /* peek() */

