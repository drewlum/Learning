#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node* next = nullptr;
};

int main()
{

  Node *root;
  Node *passenger;
  Node *conductor;

  root = new Node;
  root->next = nullptr;
  root->data = 24;
  passenger  = root;
  
  passenger->next = new Node;
  passenger = passenger->next;
  passenger->data = 42;

  conductor = passenger; //this moves to the next Node
  conductor->next = new Node;
  conductor = conductor->next;
  conductor->next = nullptr;
  conductor->data = 54;

  conductor = root;
  while( conductor !=nullptr )
  {
    cout << conductor->data << std::endl;
    conductor = conductor->next;
  }
}
