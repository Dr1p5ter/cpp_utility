#include <iostream>

#include "data_structure_h/queue.h"

using namespace std;

int main()
{

  Queue<int>* queue = new Queue<int>;
  int* myNum = new int[5];
  myNum[0] = 0;
  myNum[1] = 1;
  myNum[2] = 2;
  myNum[3] = 3;
  myNum[4] = 4;

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
    cout << "queue has been cleared; ending program..." << endl;
  }

  delete queue;
  queue = nullptr;
  delete[] myNum;
  myNum = nullptr;
  return 0;
} /* main() */

