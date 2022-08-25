#ifndef QUEUE_H
#define QUEUE_H

template <typename T> struct NodeQueue
{

  public:
    T* data;
    NodeQueue<T>* next;

}; /* Class :: NodeQueue */

template <typename T> class Queue
{

  private:
    NodeQueue<T>* head;

  public:
    void enqueue(T* dataToEnqueue);
    T* dequeue(void);
    bool isEmpty(void);
    int size(void);
    T* peek(void);

    Queue();

}; /* Class :: Queue */

#include "../ds_cpp/queue.cpp"

#endif
