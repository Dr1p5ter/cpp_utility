#ifndef QUEUE_H
#define QUEUE_H

template <typename T> struct NodeQueue
{

  public:
    T* _data;
    NodeQueue<T>* _next;

}; /* Class :: NodeQueue */

template <typename T> class Queue
{

  private:
    NodeQueue<T>* _head;

  public:
    void enqueue(T* dataToEnqueue);
    T* dequeue(void);
    bool isEmpty(void);
    int size(void);
    T* peek(void);

    Queue();
    ~Queue();

}; /* Class :: Queue */

#endif
