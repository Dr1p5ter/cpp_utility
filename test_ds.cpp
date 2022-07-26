#include <iostream>

#include "ds_h/queue.h"
#include "ds_h/stack.h"

using namespace std;

int main()
{

  /* allocating memory for testing */

  Queue<int>* queue = new Queue<int>;
  Stack<int>* stack = new Stack<int>;
  int* myNum = new int[5];
  myNum[0] = 0;
  myNum[1] = 1;
  myNum[2] = 2;
  myNum[3] = 3;
  myNum[4] = 4;

  /* testing the Queue class and methods */

  {
    if ((*queue).isEmpty())
    {
      cout << "queue is empty" << endl;
    }
    for (int i = 0; i < 5; i += 1)
    {
      cout << "element being enqueued : " << myNum[i] << endl;
      (*queue).enqueue(&myNum[i]);
    }
    if (!(*queue).isEmpty())
    {
      cout << "queue is not empty; contains : " << (*queue).size() << endl;
    }
    for (int i = 0; i < 5; i += 1)
    {
      cout << "element being dequeued : " << *((*queue).peek()) << endl;
      (*queue).dequeue();
    }
    if ((*queue).isEmpty())
    {
      cout << "queue has been cleared" << endl;
    }
  }

  /* testing the Stack class and methods */

  {
    if ((*stack).isEmpty())
    {
      cout << "stack is empty" << endl;
    }
    for (int i = 0; i < 5; i += 1)
    {
      cout << "element being pushed : " << myNum[i] << endl;
      (*stack).push(&myNum[i]);
    }
    if (!(*stack).isEmpty())
    {
      cout << "stack is not empty; contains : " << (*stack).size() << endl;
    }
    for (int i = 0; i < 5; i += 1)
    {
      cout << "element being popped : " << *((*stack).peek()) << endl;
      (*stack).pop();
    }
    if ((*stack).isEmpty())
    {
      cout << "stack has been cleared" << endl;
    }
  }

  /* deallocating memory for testing */

  cout << "ending testing" << endl;
  delete queue;
  queue = nullptr;
  delete stack;
  stack = nullptr;
  delete[] myNum;
  myNum = nullptr;
  return 0;
} /* main() */

