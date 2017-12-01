#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

class SimpleLinkedList
{
  Node *head, *tail;

public:
  SimpleLinkedList()
  {
    head = nullptr;
    tail = nullptr;
  }

  void addNode(int data)
  {
    Node *tmp = new Node;
    tmp->data = data;
    tmp->next = nullptr;

    if(head == nullptr)
    {
      head = tmp;
      tail = tmp;
    }
    else
    {
      tail->next = tmp;
      tail = tail->next;
    }
  }

  Node *getHead()
  {
    return head;
  }
  
  /*
   * Watch out for the movement of the size and initial
   * count to 1 otherwise we'll iterate too far and
   * seg fault
   */
  Node* findNthNode(Node *node, int pos)
  {
    int myCount = getListSize(node);
    for(int i=1; i<myCount+1; i++)
    {
      if(i == pos)
      {
        cout << "found nth: " << pos << " node->data: " << node->data << endl;
        return node;
      }
      node = node->next;
    }
    return nullptr;
  }
  
  int getListSize(Node *node)
  {
    int cnt = 1;
    while(node->next !=nullptr)
    {
      node = node->next;
      ++cnt;
    }
    return cnt;
  }

  void display(Node* head)
  {
    if(head != nullptr)
    {
      cout << head->data << endl;
      display(head->next);
    }
  }
};

int main(int argc, char* argv[])
{
  int position = atoi(argv[1]);
  cout << "position found: " << position << endl;
  SimpleLinkedList sll;
  sll.addNode(24);
  sll.addNode(42);
  sll.addNode(54);
  sll.display(sll.getHead());
  cout << "list size is: " << sll.getListSize(sll.getHead()) << endl;
  cout << "node data is: " << sll.findNthNode(sll.getHead(), position)->data << endl;

  return 0;
}

