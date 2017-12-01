//
//  main.cpp
//  LinkedLists
//
//  Created by Drew Lum on 5/13/13.
//  Copyright (c) 2013 Drew Lum. All rights reserved.
//

#include <iostream>
#include "LinkedListT.h"

int main() {
  LinkedList<int> theList;
  struct Node<int> *head = new Node<int>;
  struct Node<int> *newHead = new Node<int>;

  theList.initNode(head, 10);
  theList.display(head);

  theList.addNode(head, 20);
  theList.display(head);

  theList.addNode(head, 30);
  theList.display(head);

  theList.addNode(head, 35);
  theList.display(head);

  theList.addNode(head, 40);
  theList.display(head);

  theList.insertFront(&head, 5);
  theList.display(head);

  int numDel = 5;

  Node<int> *ptrDelete = theList.searchNode(head, numDel);

  if (theList.deleteNode(&head, ptrDelete))
    std::cout << "Node " << numDel << " deleted!\n";
  theList.display(head);

  std::cout << "The list is reversed\n";
  theList.reverse(&head);
  theList.display(head);

  std::cout << "The list is copied\n";
  theList.copyLinkedList(head, &newHead);
  theList.display(newHead);

  std::cout << "Comparing the two lists...\n";
  std::cout << "Are the two lists same?\n";
  if (theList.compareLinkedList(head, newHead))
    std::cout << "Yes, they are same!\n";
  else
    std::cout << "No, they are different!\n";

  ptrDelete = theList.searchNode(newHead, numDel);
  if (theList.deleteNode(&newHead, ptrDelete)) {
    std::cout << "Node " << numDel << " deleted!\n";
    std::cout << "The new list after the delete is\n";
    theList.display(newHead);
  }
  std::cout << "Comparing the two lists again...\n";
  std::cout << "Are the two lists same?\n";
  if (theList.compareLinkedList(head, newHead))
    std::cout << "Yes, they are same!\n";
  else
    std::cout << "No, they are different!\n";

  std::cout << std::endl;
  std::cout << "Deleting the copied list\n";
  theList.deleteLinkedList(&newHead);
  theList.display(newHead);

  return 0;
}
