#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node* next = nullptr;
};

int findLinkedListSize(Node* mynode){
  int count = 1;
  while(mynode->next !=nullptr){
   mynode = mynode->next; 
   ++count;
  }
  return count;
}

Node* findNthNode(Node* mynode, int position){
  int myCount = findLinkedListSize(mynode);
  cout << "size of ll: " << myCount << endl;
  for( int i=1; i < myCount + 1; i++){
    if( i == position )
    {
      cout << "nth node number requested: " << i <<  " data: " << mynode->data << endl;
      return mynode;
    }
    mynode = mynode->next;
  }
  return nullptr;
}

int main(int argc, char* argv[])
{

  //Node *root;
  //Node *next;
  //Node *next2;

  Node* root = new Node;
  root->next = nullptr;
  root->data = 24;
  Node* node = root; //this moves to the next Node
  
  node->next = new Node;
  node = node->next;
  node->data = 42;
  
  Node* node2 = node;
  node2->next = new Node; 
  node2 = node2->next;
  node2->next = nullptr;
  node2->data = 54;
  node2 = root;

  while( node2 !=nullptr )
  {
    cout << node2->data << endl;
    node2 = node2->next;
  }
  
  //next2 = root;
  Node* nth = findNthNode(root, 3);
  cout << "nth node is: " << nth->data << endl;
}
