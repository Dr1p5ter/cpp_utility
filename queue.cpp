#include <iostream>
#include <string>

/* This class will be the container used for the rest of the implementation
 * of the Queue class. Until I have an idea of how to make the nodes universal,
 * it will remain here as a placeholder.
 *
 * TODO : Remove when universal object has been implemented.
 *
 */

class Node
{
  private:
    Node* nextNode;
    std::string* name;
    int age;
  public:
    Node(std::string* name, int age)
    {
      this.nextNode = nullptr;
      this.name = nullptr;
      this.age = age;
    };
    void setNextNode(Node* newNextNode) { this.nextNode = newNextNode; };
    void setName(std::string* newName) { this.name = newName; };
    void setAge(int newAge) { this.age = newAge; };
    Node* getNextNode(void) { return this.nextNode; };
    std::string* getName(void) { return this.name; };
    int getAge(void) { return this.age; };
}; /* Class :: Node */

/* This class is my implementation of a FIFO stack known as a queue. Current
 * universal use is not available so use the Node class provided above for
 * now.
 *
 * TODO : Update once a universal object keyward has been found.
 *
 */

class Queue
{
  private:
    Node* head;
  public:
    void enqueue(Node* newNode);
    Node* dequeue(void);
    bool isEmpty(void);
    int size(void);
    Node* peek(void);
}; /* Class :: Queue */

/* This method will insert an item at the end of the queue and return a void
 * value once finished. If there is an error or the node is null, nothing will
 * happen.
 */

void Queue::enqueue(Node* newNode)
{
  // TODO : implement this method
  std::cout << "enqueue() is used" << std::endl;
  return void;
} /* enqueue() */

/* This method will remove the item in front of the queue and return it. If the
 * queue is empty, nothing will be removed and the method will return null.
 */

Node* Queue::dequeue(void)
{
  // TODO : implement this method
  std::cout << "dequeue() is used" << std::endl;
  return nullptr;
} /* dequeue() */

/* This method will check whether the queue is empty or not by returning a
 * boolean equivalent. True for an empty queue; False for a non-empty queue.
 */

bool Queue::isEmpty(void)
{
  // TODO : implement this method
  std::cout << "isEmpty() is used" << std::endl;
  return false;
} /* isEmpty() */

/* This method will traverse the entire queue and return the queue size. If the
 * queue is empty, a 0 will be returned and a memory error will return -1.
 */

int Queue::size(void)
{
  // TODO : implement this method
  std::cout << "size() is used" << std::endl;
  return -1;
} /* size() */

/* This method will peek at the first object in the queue and return it without
 * dequeueing the object. If the queue is empty, return null.
 */

Node* Queue::peek(void)
{
  // TODO : implement this method
  std::cout << "peek() is used" << std::endl;
  return nullptr;
} /* peek() */

int main()
{
  Queue queue;
  Node node = Node(nullptr, 0);
  queue.enqueue(nullptr);
  queue.dequeue();
  queue.isEmpty();
  queue.size();
  queue.peek();
  return 0;
} /* main() */
