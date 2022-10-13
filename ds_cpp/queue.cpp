#include <iostream>
#include "../ds_h/queue.h"

/* This is the constructor for the Queue class. This will do nothing other than
 * initialize the head pointer to a null pointer so the methods can do the all
 * the work.
 */

template <typename T>
Queue<T>::Queue( void )
{
  this->head = nullptr;
} /* Queue() */

/* This is the deconstructor for the Queue class. This will do remove everything and delete any
 * memory made from the object.
 */

template <typename T>
Queue<T>::~Queue( void )
{
  while ( !isEmpty() )
  {
    NodeQueue<T> * delNode = this->_head;
    T * delData = this->_head->_data;
    this->_head = this->_head->_next;
    delete delNode;
    delete delData;
  }
} /* ~Queue() */

/* This method will insert an item at the end of the queue and return a void
 * value once finished. If there is an error or the node is null, nothing will
 * happen.
 */

template <typename T>
void Queue<T>::enqueue( T * dataToEnqueue )
{
  /* Allocates memory for data node */

  NodeQueue<T> * newNode = new NodeQueue<T>;
  if ( !newNode )
  {
    std::cout << "Error: out of memory" << std::endl;
    exit(1);
  }
  else
  {
    newNode->_data = dataToEnqueue;
    newNode->_next = nullptr;
  }

  /* Enqueues the node into the queue */

  if ( this->_head == nullptr )
  {
    this->_head = newNode;
  }
  else
  {
    NodeQueue<T> * findEnd = this->_head;
    while ( findEnd->_next != nullptr ) { findEnd = findEnd->_next; }
    findEnd->_next = newNode;
  }
} /* enqueue() */

/* This method will remove the item in front of the queue and return it. If the
 * queue is empty, nothing will be removed and the method will return null.
 */

template <typename T>
T * Queue<T>::dequeue( void )
{
  if ( !isEmpty() )
  {
    /* Push up the queue after the dequeue */

    T * info = this->_head->_data;
    NodeQueue<T> * temp = this->_head;
    if ( temp->_next == nullptr )
    {
      this->_head = nullptr;
    }
    else
    {
      this->_head = this->_head->_next;
    }

    /* Removes node dynamically & return info */

    delete temp;
    temp = nullptr;
    return info;
  }
  return nullptr;
} /* dequeue() */

/* This method will check whether the queue is empty or not by returning a
 * boolean equivalent. True for an empty queue; False for a non-empty queue.
 */

template <typename T>
bool Queue<T>::isEmpty( void )
{
  return ( this->_head == nullptr );
} /* isEmpty() */

/* This method will traverse the entire queue and return the queue size. If the
 * queue is empty, a 0 will be returned.
 */

template <typename T>
int Queue<T>::size( void )
{
  /* Check if there is anything inside of the queue */
  if ( !isEmpty() )
  {
    int n = 1;
    NodeQueue<T> * findEnd = this->_head;
    while ( findEnd->_next != nullptr )
    {
      n += 1;
      findEnd = findEnd->_next;
    }
    return n;
  }
  return 0;
} /* size() */

/* This method will peek at the first object in the queue and return it without
 * dequeueing the object. If the queue is empty, return null.
 */

template <typename T>
T * Queue<T>::peek( void )
{
  if ( this->_head == nullptr )
  {
    return nullptr;
  }
  return this->_head->_data;
} /* peek() */

