#include <iostream>
#include <array>

/* This class is for node handeling and allows for the frame work of working
 * with multiple data structures. This is completely dynamic so nothing should
 * be changed inside of this class nore should it have any methods.
 */

template <typename T> class Node
{
  public:
    T* data;
    Node<T>* next;
}; /* Class :: Node */

/* This class is my implementation of a FIFO stack known as a queue. This can
 * be used with any data type and is currently being tested.
 */

template <typename T> class Queue
{
  private:
    Node<T>* head;
  public:
    void enqueue(T* dataToEnqueue);
    T* dequeue(void);
    bool isEmpty(void);
    int size(void);
    T* peek(void);

    // default constructor
    Queue()
    {
      this->head = nullptr;
    }
}; /* Class :: Queue */

/* This method will insert an item at the end of the queue and return a void
 * value once finished. If there is an error or the node is null, nothing will
 * happen.
 */

template <typename T> void Queue<T>::enqueue(T* dataToEnqueue)
{
  /* Allocates memory for data node */

  Node<T>* newNode = new Node<T>;
  if (!newNode)
  {
    std::cout << "Error: out of memory" << std::endl;
    exit(1);
  }
  else
  {
    newNode->data = dataToEnqueue;
    newNode->next = nullptr;
  }

  /* Enqueues the node into the queue */

  if (this->head == nullptr)
  {
    this->head = newNode;
  }
  else
  {
    Node<T>* findEnd = this->head;
    while (findEnd->next != nullptr) { findEnd = findEnd->next; }
    findEnd->next = newNode;
  }

  return;
} /* enqueue() */

/* This method will remove the item in front of the queue and return it. If the
 * queue is empty, nothing will be removed and the method will return null.
 */

template <typename T> T* Queue<T>::dequeue(void)
{
  if (!isEmpty())
  {
    T* info = this->head->data;

    /* Push up the queue after the dequeue */

    Node<T>* temp = this->head;
    if (temp->next == nullptr)
    {
      this->head = nullptr;
    }
    else
    {
      this->head = this->head->next;
    }
    delete temp;
    return info;
  }
  return nullptr;
} /* dequeue() */

/* This method will check whether the queue is empty or not by returning a
 * boolean equivalent. True for an empty queue; False for a non-empty queue.
 */

template <typename T> bool Queue<T>::isEmpty(void)
{
  return (this->head == nullptr);
} /* isEmpty() */

/* This method will traverse the entire queue and return the queue size. If the
 * queue is empty, a 0 will be returned.
 */

template <typename T> int Queue<T>::size(void)
{
  /* Check if there is anything inside of the queue */
  if (!isEmpty())
  {
    int n = 1;
    Node<T>* findEnd = this->head;
    while (findEnd->next != nullptr)
    {
      n += 1;
      findEnd = findEnd->next;
    }
    return n;
  }
  return 0;
} /* size() */

/* This method will peek at the first object in the queue and return it without
 * dequeueing the object. If the queue is empty, return null.
 */

template <typename T> T* Queue<T>::peek(void)
{
  if (this->head == nullptr)
  {
    return nullptr;
  }
  return this->head->data;
} /* peek() */

int main()
{
  Queue<int>* queue = new Queue<int>;
  int* myNum = new int[5];
  myNum[0] = 0;
  myNum[1] = 1;
  myNum[2] = 2;
  myNum[3] = 3;
  myNum[4] = 4;
  (*queue).enqueue(&myNum[0]);
  (*queue).enqueue(&myNum[1]);
  (*queue).enqueue(&myNum[2]);
  (*queue).enqueue(&myNum[3]);
  (*queue).enqueue(&myNum[4]);
  std::cout << "size of queue: " << (*queue).size() << std::endl;
  (*queue).dequeue();
  (*queue).dequeue();
  (*queue).dequeue();
  (*queue).dequeue();
  (*queue).dequeue();
  std::cout << "is queue empty: " << (*queue).isEmpty() << std::endl;
  delete queue;
  delete[] myNum;
  myNum = nullptr;
  return 0;
} /* main() */
