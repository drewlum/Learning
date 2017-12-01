#include <iostream>
#include <stdexcept>


using namespace std;

class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int intValue) :
        intValue_(intValue),
        next_(nullptr)
    {
    }
};


// returns the node with value 4 (the 2nd to last node)
LinkedListNode* kthToLastNode(size_t k, LinkedListNode* head)
{
   if( k < 1)
   {
      throw std::invalid_argument(" k is less than the first node: " + std::to_string(k)); 
   }
   
   size_t listLength = 1;
   LinkedListNode* currentNode = head;
   
   cout << "counting the length of the list" << endl; 
   while(currentNode->next_)
   {
     cout << currentNode->intValue_ << endl;
     currentNode = currentNode->next_;
     ++listLength;
   }
   
   if( k > listLength)
   {
      throw std::invalid_argument(" k is larger than the linkedlist: " + std::to_string(k)); 
   }
 
   size_t howFarToGo = listLength - k; 
   
   cout << "how far to go: " << howFarToGo << endl; 
   currentNode = head; 
   for(int i=0; i< howFarToGo; ++i)
   {
     cout << currentNode->intValue_ << endl;
     currentNode = currentNode->next_;
   }
   
   return currentNode;  
   
}

int main()
{

	LinkedListNode* a = new LinkedListNode(1);
	LinkedListNode* b = new LinkedListNode(2);
	LinkedListNode* c = new LinkedListNode(3);
	LinkedListNode* d = new LinkedListNode(4);
	LinkedListNode* e = new LinkedListNode(5);

	a->next_ = b;
	b->next_ = c;

	c->next_ = d;
	d->next_ = e;
  
  LinkedListNode* result = kthToLastNode(2, a);
  std::cout << "result is node with value of: " << result->intValue_ << std::endl;
}
