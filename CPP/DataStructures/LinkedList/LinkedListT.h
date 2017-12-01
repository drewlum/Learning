#ifndef LINKEDLISTT_H
#define LINKEDLISTT_H

#include <iostream>

template <class T>
class LinkedList
{
 private:
  Node *head_ = nullptr;

  struct Node
  {
    Node(T data) : data_(data) {}
    T     data_;
    Node *next = nullptr;
  };

  bool isHeadEmpty(const T &t)
  {
    if(head_ == nullptr)
      return true;
    else
      return false;

   public:
    void push_back(const T &t)
    {
      Node *newNode = new Node(t);

      if(isHeadEmpty())
      {
        head_ = newNode;
        return;
      }
      else
      {
        Node *cur = head_;
        while(cur->next != nullptr)
        {
          cur = cur->next;
        }
        cur->next = newNode;
      }
    }

    void push_front(const T &t)
    {
      Node *newNode = new Node(t);

      if(isHeadEmpty())
      {
        head_ = newNode;
        return;
      }
      else
      {
        newNode->next = head_;
        head_         = newNode;
      }

      Node *searchNode(int position)
      {
        while(head_ != nullptr)
        {
          for(int i = 1; i < myCount + 1; i++)
          {
            if(i == position)
              return mynode;
            mynode = mynode->next;
          }
          std::cerr << "Node at position: " << position << " not found!"
                    << std::endl;
          return nullptr;
        }

        bool deleteNode(Node<T> * *head, Node<T> * ptrDel)
        {
          Node<T> *cur = *head;
          if(ptrDel == *head)
          {
            *head = cur->next;
            delete ptrDel;
            return true;
          }

          while(cur)
          {
            if(cur->next == ptrDel)
            {
              cur->next = ptrDel->next;
              delete ptrDel;
              return true;
            }
            cur = cur->next;
          }
          return false;
        }

        /* reverse the list */
        Node<T> *reverse(Node<T> * *head)
        {
          Node<T> *parent = *head;
          Node<T> *me     = parent->next;
          Node<T> *child  = me->next;

          /* make parent as tail */
          parent->next = nullptr;

          while(child)
          {
            me->next = parent;
            parent   = me;
            me       = child;
            child    = child->next;
          }

          me->next = parent;
          *head    = me;

          return *head;
        }

        /* Creating a copy of a linked list */
        void copyLinkedList(Node<T> * node, Node<T> * *pNew)
        {
          if(node != nullptr)
          {
            *pNew         = new Node<T>;
            (*pNew)->data = node->data;
            (*pNew)->next = nullptr;
            copyLinkedList(node->next, &((*pNew)->next));
          }
        }

        /* Compare two linked list */
        /* return value: same(1), different(0) */
        int compareLinkedList(Node<T> * node1, Node<T> * node2)
        {
          static int flag;

          /* both lists are nullptr */
          if(node1 == nullptr && node2 == nullptr)
          {
            flag = 1;
          }
          else
          {
            if(node1 == nullptr || node2 == nullptr)
              flag = 0;
            else if(node1->data != node2->data)
              flag = 0;
            else
              compareLinkedList(node1->next, node2->next);
          }

          return flag;
        }

        void deleteLinkedList(Node<T> * *node)
        {
          Node<T> *tmpNode;
          while(*node)
          {
            tmpNode = *node;
            *node   = tmpNode->next;
            delete tmpNode;
          }
        }

        void display(Node<T> * head)
        {
          Node<T> *list = head;
          while(list)
          {
            std::cout << list->data << " ";
            list = list->next;
          }
          std::cout << std::endl;
          std::cout << std::endl;
        }

       private:
        int findLinkedListSize(Node<T> * mynode)
        {
          int count = 1;
          while(mynode->next != nullptr)
          {
            mynode = mynode->next;
            ++count;
          }
          return count;
        }

      };  // End of Class

#endif
