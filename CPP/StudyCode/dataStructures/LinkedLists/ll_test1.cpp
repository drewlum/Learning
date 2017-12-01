#include <iostream>

using namespace std;

struct Node
{
  int data = 0;
  Node* next = nullptr;
};

int getListSize(struct Node* root)
{
  int cnt = 0;
  while ( root->next !=nullptr )
  {
    ++cnt;
    root->next = root;
  }
  return cnt;
}

int main()
{
  Node* root = new Node;
  root->data = 5;
  root->next = new Node;
  Node* node = root->next;
  node->data = 42;
  node->next = new Node;
  Node* node2 = node->next;
  node2->data = 54;
  node2->next = nullptr;
  node2 = root;
  cout << "size is: " << getListSize(root) << endl;
}
