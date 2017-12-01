#include <iostream>

/*
 * LRU has to make sure that old values get deleted. Basically
 * a priority queue. Anything that has been accessed will get
 * sent to the end of the queue as the last accessed. The oldest
 * or first in the queue must be deleted.
 *
 * Hint use two containers linked_list backed with a vector 
 */

class LRUCache(int aSz)
{

  /*
   * gets added to the end of the list
   */
  void put(int key, int value);

  /*
   * takes a key and returns a value
   * must move any element that has been accessed
   * to the end of the list as last accessed
   */
  int get(int key);
  
};

int main()
{

}

