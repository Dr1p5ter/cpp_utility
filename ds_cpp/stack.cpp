#include <iostream>
#include "../ds_h/stack.h"

/* This is the constructor for the Stack class. This will provide the necessary
 * set up for the rest of the implementation.
 */

template <typename T>
Stack<T>::Stack( void )
{
  this->_top = nullptr;
} /* Stack() */

/* This is the deconstructor for the Stack class. This will provide the steps
 * needed for removing the object.
 */

template <typename T>
Stack<T>::~Stack( void )
{
  while ( !isEmpty() )
  {
    NodeStack<T> * delNode = this->_top;
    T * delData = delNode->_data;
    this->_top = this->_top->_next;
    delete delNode;
    delete delData;
  }
} /* ~Stack() */

/* This method will insert the data at the top of the stack and then will
 * return void.
 */

template <typename T>
void Stack<T>::push( T * dataToPush )
{
  /* Allocates memory for data node */

  NodeStack<T> * newNode = new NodeStack<T>;
  if ( !newNode )
  {
    std::cout << "Error: out of memory" << std::endl;
    exit(1);
  }
  else
  {
    newNode->_data = dataToPush;
    newNode->_next = nullptr;
  }

  /* pushes the node into the queue */

  if ( this->_top == nullptr )
  {
    this->_top = newNode;
  }
  else
  {
    newNode->_next = this->_top;
    this->_top = newNode;
  }
} /* push() */

/* This method will remove the data at the top of the stack and then return the
 * pointer to the data.
 */

template <typename T>
T * Stack<T>::pop( void )
{
  if ( !isEmpty() )
  {
    T * info = this->_top->_data;
    NodeStack<T> * temp = this->_top;
    if ( this->_top->_next == nullptr )
    {
      this->_top = nullptr;
    }
    else
    {
      this->_top = this->_top->_next;
    }

    /* Removes node dynamically & return info */

    delete temp;
    temp = nullptr;
    return info;
  }
  return nullptr;
} /* pop() */

/* This method will check the top of the stack to see if there is a null
 * pointer. If there is a null pointer, return T; else return F.
 */

template <typename T>
bool Stack<T>::isEmpty( void )
{
  return this->_top == nullptr;
} /* isEmpty() */

/* This method will return the size of the stack as an int after traversing the
 * length of the stack. Returns 0 if empty.
 */

template <typename T>
int Stack<T>::size( void )
{
  if ( !isEmpty() )
  {
    int n = 1;
    NodeStack<T> * findEnd = this->_top;
    while ( findEnd->_next != nullptr )
    {
      n += 1;
      findEnd = findEnd->_next;
    }
    return n;
  }
  return 0;
} /* size() */

/* This method will return the data at the top of the stack without removing it
 * so that order is kept.
 */

template <typename T>
T * Stack<T>::peek(void)
{
  return this->_top->_data;
} /* peek() */

