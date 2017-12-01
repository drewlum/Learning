#include "BinaryTree.h"

int main(int argc, char **argv)
{
	char ch, ch1, ch2;
	Tree *found;
	Tree *succ;
	Tree *pred;
	Tree *ancestor;
	char charArr[9] = {'A','B','C','D','E','F','G','H','I'};

	Tree *root = newTreeNode('F');
	insertTreeNode(root,'B');
	insertTreeNode(root,'A');
	insertTreeNode(root,'D');
	insertTreeNode(root,'C');  
	insertTreeNode(root,'E');
	insertTreeNode(root,'G');
	insertTreeNode(root,'I');
	insertTreeNode(root,'H');

	/* is the tree BST? */
	isBST(root);

	/* size of tree */
	cout << "size = " << treeSize(root) << endl;

	/* max depth */
	cout << "max depth = " << maxDepth(root) << endl;

	/* min depth */
	cout << "min depth = " << minDepth(root) << endl;

	/* balanced tree? */
	if(isBalanced(root))
	    cout << "This tree is balanced!\n";
	else
	    cout << "This tree is not balanced!\n";

	/* min value of the tree*/
	if(root) 
	    cout << "Min value = " << minTree(root)->data << endl;

	/* max value of the tree*/
	if(root) 
	    cout << "Max value = " << maxTree(root)->data << endl;

	/* get the level of a data: root level = 0 */
	cout << "Node B is at level: " << getLevel(root, 'B', 0) << endl;
	cout << "Node H is at level: " << getLevel(root, 'H', 0) << endl;
	cout << "Node F is at level: " << getLevel(root, 'F', 0) << endl;

        /* separate even/odd level elements */
        level_even_odd(root);

	ch = 'B';
	found = lookUp(root,ch);
	if(found) {
	    cout << "Min value of subtree " << ch << " as a root is "
			 << minTree(found)->data << endl;
	    cout << "Max value of subtree " << ch << " as a root is "
			 << maxTree(found)->data << endl;
	}

	ch = 'B';
	found = lookUp(root,ch);
	if(found) {
	    succ = succesorInOrder(found);
	    if(succ)
		cout << "In Order Successor of " << ch << " is "
		     << succesorInOrder(found)->data << endl;
	    else 
		cout << "In Order Successor of " << ch << " is None\n";
	}

	ch = 'E';
	found = lookUp(root,ch);
	if(found) {
	    succ = succesorInOrder(found);
	    if(succ)
		cout << "In Order Successor of " << ch << " is "
			 << succesorInOrder(found)->data << endl;
	    else 
		cout << "In Order Successor of " << ch << " is None\n";
	}

	ch = 'I';
	found = lookUp(root,ch);
	if(found) {
	    succ = succesorInOrder(found);
	    if(succ)
		cout << "In Order Successor of " << ch << " is "
			 << succesorInOrder(found)->data << endl;
	    else 
		cout << "In Order Successor of " << ch << " is None\n";
	}

	ch = 'B';
	found = lookUp(root,ch);
	if(found) {
	    pred = predecessorInOrder(found);
	    if(pred)
		cout << "In Order Predecessor of " << ch << " is "
			 << predecessorInOrder(found)->data << endl;
	    else 
		cout << "In Order Predecessor of " << ch << " is None\n";
	}

	ch = 'E';
	found = lookUp(root,ch);
	if(found) {
	    pred = predecessorInOrder(found);
	    if(pred)
		cout << "In Order Predecessor of " << ch << " is "
			 << predecessorInOrder(found)->data << endl;
	    else 
		cout << "In Order Predecessor of " << ch << " is None\n";
	}

	ch = 'I';
	found = lookUp(root,ch);
	if(found) {
	    pred = predecessorInOrder(found);
	    if(pred)
		cout << "In Order Predecessor of " << ch << " is "
			 << predecessorInOrder(found)->data << endl;
	    else 
		cout << "In Order Predecessor of " << ch << " is None\n";
	}

	/* Lowest Common Ancestor */
	ch1 = 'A';
	ch2 = 'C';
	ancestor = 
	    lowestCommonAncestor(root, 
			lookUp(root,ch1), lookUp(root,ch2));
	if(ancestor) 
	    cout << "The lowest common ancestor of " << ch1 << " and "
		<< ch2 << " is " << ancestor->data << endl;

	ch1 = 'E';
	ch2 = 'H';
	ancestor = 
	    lowestCommonAncestor(root, 
			lookUp(root,ch1), lookUp(root,ch2));
	if(ancestor) 
	    cout << "The lowest common ancestor of " << ch1 << " and "
		<< ch2 << " is " << ancestor->data << endl;

	ch1 = 'D';
	ch2 = 'E';
	ancestor = 
	    lowestCommonAncestor(root, 
			lookUp(root,ch1), lookUp(root,ch2));
	if(ancestor) 
	    cout << "The lowest common ancestor of " << ch1 << " and "
		<< ch2 << " is " << ancestor->data << endl;

	ch1 = 'G';
	ch2 = 'I';
	ancestor = 
	    lowestCommonAncestor(root, 
			lookUp(root,ch1), lookUp(root,ch2));
	if(ancestor) 
	    cout << "The lowest common ancestor of " << ch1 << " and "
		<< ch2 << " is " << ancestor->data << endl;

	ch1 = 'H';
	ch2 = 'I';
	ancestor = 
	    lowestCommonAncestor(root, 
			lookUp(root,ch1), lookUp(root,ch2));
	if(ancestor) 
	    cout << "The lowest common ancestor of " << ch1 << " and "
		<< ch2 << " is " << ancestor->data << endl;

	/* print tree in order */
	cout << "increasing sort order\n";
	printTreeInOrder(root);
	cout << endl;

	/* print tree in postorder*/
	cout << "post order \n";
	printTreePostOrder(root);
	cout << endl;

	/* print tree in preorder*/
	cout << "pre order \n";
	printTreePreOrder(root);
	cout << endl;

	/* print tree in reverse order*/
	cout << "reverse order \n";
	printTreeReverseOrder(root);
	cout << endl;

	/* lookUp */
	ch = 'D';
	found = lookUp(root,ch);
	if(found) 
	    cout << found->data << " is in the tree\n";
	else
	    cout << ch << " is not in the tree\n";

	/* lookUp */
	ch = 'M';
	found = lookUp(root,ch);
	if(found) 
	    cout << found->data << " is in the tree\n";
	else
	    cout << ch << " is not in the tree\n";

	/* printing all paths :
	Given a binary tree, print out all of its root-to-leaf 
	paths, one per line. Uses a recursive helper to do the work. */
	cout << "printing paths ..." << endl;
	int path[10];
	pathFinder(root, path, 0);

	/* find n-th maximum node */
	NthMax(root);

	/* Traversing level-order. 
	We visit every node on a level before going to a lower level. 
	This is also called Breadth-first traversal.*/
	cout << "printing with Breadth-first traversal" << endl;
	BreadthFirstTraversal(root);

	/* Prints all element at the same depth (level) */
	int row = maxDepth(root);
	vector<vector<int> > levVec(row+1);
	BreadthFirst_LevelElement_Print(root, levVec);
	for(int m = 0; m < levVec.size(); m++) {
	    cout << "Level at " << m << ": ";
	    for(int n = 0; n < levVec[m].size(); n++) 
		cout << (char)levVec[m][n] << " ";
	    cout << endl;
	}

	/* levelPrint()
	prints nodes at the same level
	This is simpler than the BreadthFirstTraversal(root) above
	It takes 2D vector (elm) with the same size of level (= MaxDepth+1)
	and fills elements as we traverse (preOrder) */
	vector<vector<char> > elm;
	int mxDepth = maxDepth(root);
	elm.resize(mxDepth+1);
	int level = 0;
	levelPrint(root, elm, level);
	cout << "levelPrint() " << endl;
	for(int i = 0; i <= mxDepth; i++) {
	    cout << "level " << i << ": " ;
	    for(int j = 0; j < elm[i].size(); j++) 
		cout << elm[i][j] << " ";
	    cout << endl;
	}

	/* convert the tree into an array */
	int treeSz = treeSize(root);
	int *array = new int[treeSz];
	TreeToArray(root,array);
	cout << "New array: ";
	for (int i = 0; i < treeSz; i++)
	    cout << (char)array[i] << ' ';
	cout << endl;
	delete [] array;

	/* subtree */
	Tree *root2 = newTreeNode('D');
	insertTreeNode(root2,'C');  
	insertTreeNode(root2,'E');
	cout << "1-2 subtree: " << isSubTree(root, root2) << endl;

	Tree *root3 = newTreeNode('B');
	insertTreeNode(root3,'A');  
	insertTreeNode(root3,'D');
	insertTreeNode(root3,'C');  
	insertTreeNode(root3,'E');
	cout << "1-3 subtree: " << isSubTree(root, root3) << endl;

	Tree *root4 = newTreeNode('B'); 
	insertTreeNode(root4,'D');
	insertTreeNode(root4,'C');  
	insertTreeNode(root4,'E');
	cout << "1-4 subtree: " << isSubTree(root, root4) << endl;

	cout << "2-3 subtree: " << isSubTree(root2, root3) << endl;
	cout << "3-2 subtree: " << isSubTree(root3, root2) << endl;

	/* swap left and right */
	mirror(root);

	/* deleting a tree */
	clear(root);

	/* make a new tree with minimal depth */
	Tree *newRoot = createMinimalBST(charArr,9);

	return 0;
}
