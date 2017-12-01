//
//  LinkedListT.h
//
//  Created by Drew Lum on 5/13/13.
//  Copyright (c) 2013 Drew Lum. All rights reserved.
//

#ifndef LINKEDlISTS_LINKEDlIST_H
#define LINKEDlISTS_LINKEDlIST_H

#include <iostream>

template <class ValueT>
struct Node {
    ValueT data;
    Node *next;
};

template <class T>
class LinkedList {
   public:
    // only for the 1st Node
    void initNode(Node<T> *head, T t) {
        head->data = t;
        head->next = nullptr;
    }

    // apending
    void addNode(Node<T> *head, T t) {
        Node<T> *newNode = new Node<T>;
        newNode->data = t;
        newNode->next = nullptr;

        Node<T> *cur = head;
        while (cur) {
            if (cur->next == nullptr) {
                cur->next = newNode;
                return;
            }
            cur = cur->next;
        }
    }

    void insertFront(Node<T> **head, T t) {
        Node<T> *newNode = new Node<T>;
        newNode->data = t;
        newNode->next = *head;
        *head = newNode;
    }

    //Node<T> *searchNode(Node<T> *head, int n) {
    //    Node<T> *cur = head;
    //    while (cur) {
    //        if (cur->data == n) return cur;
    //        cur = cur->next;
    //    }
    //    std::cout << "No Node " << n << " in list.\n";
    //    return nullptr;
    //}

   Node<T> *searchNode(Node<T> *mynode, int position) {
      int myCount = findLinkedListSize(mynode);
      for( int i=1; i < myCount + 1; i++){
        if( i == position )
          return mynode;
        mynode = mynode->next;
      }
      std::cerr << "Node at position: " << position << " not found!" << std::endl;
      return nullptr;
   }

    bool deleteNode(Node<T> **head, Node<T> *ptrDel) {
        Node<T> *cur = *head;
        if (ptrDel == *head) {
            *head = cur->next;
            delete ptrDel;
            return true;
        }

        while (cur) {
            if (cur->next == ptrDel) {
                cur->next = ptrDel->next;
                delete ptrDel;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    /* reverse the list */
    Node<T> *reverse(Node<T> **head) {
        Node<T> *parent = *head;
        Node<T> *me = parent->next;
        Node<T> *child = me->next;

        /* make parent as tail */
        parent->next = nullptr;

        while (child) {
            me->next = parent;
            parent = me;
            me = child;
            child = child->next;
        }

        me->next = parent;
        *head = me;

        return *head;
    }

    /* Creating a copy of a linked list */
    void copyLinkedList(Node<T> *node, Node<T> **pNew) {
        if (node != nullptr) {
            *pNew = new Node<T>;
            (*pNew)->data = node->data;
            (*pNew)->next = nullptr;
            copyLinkedList(node->next, &((*pNew)->next));
        }
    }

    /* Compare two linked list */
    /* return value: same(1), different(0) */
    int compareLinkedList(Node<T> *node1, Node<T> *node2) {
        static int flag;

        /* both lists are nullptr */
        if (node1 == nullptr && node2 == nullptr) {
            flag = 1;
        } else {
            if (node1 == nullptr || node2 == nullptr)
                flag = 0;
            else if (node1->data != node2->data)
                flag = 0;
            else
                compareLinkedList(node1->next, node2->next);
        }

        return flag;
    }

    void deleteLinkedList(Node<T> **node) {
        Node<T> *tmpNode;
        while (*node) {
            tmpNode = *node;
            *node = tmpNode->next;
            delete tmpNode;
        }
    }

    void display(Node<T> *head) {
        Node<T> *list = head;
        while (list) {
            std::cout << list->data << " ";
            list = list->next;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

private:

   int findLinkedListSize(Node<T>* mynode){
     int count = 1;
     while(mynode->next !=nullptr){
        mynode = mynode->next; 
        ++count;
     }
     return count;
   }

};  // End of Class

#endif
