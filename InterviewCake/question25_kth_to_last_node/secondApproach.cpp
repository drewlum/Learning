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
LinkedListNode * kthToLastNode(size_t k, LinkedListNode* head)
{

    if (k < 1) {
        throw invalid_argument(
                "Impossible to find less than first to last node: "
                + to_string(k));
    }

    LinkedListNode* leftNode  = head;
    LinkedListNode* rightNode = head;

    // move rightNode to the kth node
    for (size_t i = 0; i < k - 1; ++i) {

        // but along the way, if a rightNode doesn't have a next,
        // then k is greater than the length of the list and there
        // can't be a kth-to-last node! we'll raise an error
        if (!rightNode->next_) {
            throw invalid_argument(
                    "k is larger than the length of the linked list: "
                    + to_string(k));
        }

        rightNode = rightNode->next_;
    }

    // starting with leftNode on the head,
    // move leftNode and rightNode down the list,
    // maintaining a distance of k between them,
    // until rightNode hits the end of the list
    while (rightNode->next_) {
        leftNode  = leftNode->next_;
        rightNode = rightNode->next_;
    }

    // since leftNode is k nodes behind rightNode,
    // leftNode is now the kth to last node!
    return leftNode;
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
  cout << "result is node with value of: " << result->intValue_ << endl;
}
