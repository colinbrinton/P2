//Colin Brinton
//10/24/15
//Version 1.0

#include "BST.h"

const int NODE1 = 15;
const int NODE2 = 28;
const int NODE3 = 8;
const int NODE4 = 2;
const int NODE5 = 19;
const int NODE6 = 12;
const int NODE7 = 32;


//Final expected output below function calls
int main()
{
   cout << "Initializing an int type BST class object, 'intBST'" << endl << endl;
   BST<int> intBST;
   
  //***insertNode***
    cout << "Calling 'insertNode(T)' with the following values: " << endl
	   << "15, 28, 8, 2, 19, 12, 32" << endl << endl;
  intBST.insertNode(NODE1);
  intBST.insertNode(NODE2);
  intBST.insertNode(NODE3);
  intBST.insertNode(NODE4);
  intBST.insertNode(NODE5);
  intBST.insertNode(NODE6);
  intBST.insertNode(NODE7);

 
  //***displayInOrder***
  cout << "Calling 'displayInOrder()'" << endl;
  intBST.displayInOrder();
  cout << endl;

  //2
  //8
  //12
  //15
  //19
  //28
  //32

  //***displayPreOrder***
  cout << "Calling 'displayPreOrder()'" << endl;
  intBST.displayPreOrder();
  cout << endl;

  //15
  //8
  //2
  //12
  //28
  //19
  //32

  //***displayPostOrder***
  cout << "Calling 'displayPostOrder()'" << endl;
  intBST.displayPostOrder();
  cout << endl;

  //2
  //12
  //8
  //19
  //32
  //28
  //15

  //***searchNode(12)***
  cout << "Calling 'searchNode(12)'" << endl;
  if(intBST.searchNode(NODE6))
	cout << "Value found." << endl;
  if(!intBST.searchNode(NODE6))
	cout << "Value not found." << endl;
  cout << endl;

  //Value found.

  //***empty***
  cout << "Calling 'empty()'" << endl;
  if(intBST.empty())
	cout << "Tree is empty." << endl;
  if(!intBST.empty())
	cout << "Tree is not empty." << endl;
  cout << "Initializing empty tree" << endl;
  BST<int> empty;
  cout << "Calling 'empty()'" << endl;
  if(empty.empty())
	cout << "Tree is empty." << endl;
  if(!empty.empty())
	cout << "Tree is not empty." << endl;
  cout << endl;

  

  //(Not currently implemented, test result = false)
  //Tree is not empty.

  //***numNodes***
  cout << "Calling 'numNodes()'" << endl;
  cout << "The number of nodes is: " << intBST.numNodes() << endl;
  cout << endl;
  
  //(Not currently implemented, test result = 0)
  //7

  //***numLeafNodes***
  cout << "Calling 'numLeafNodes()'" << endl;
  cout << "The number of leaf nodes is: " << intBST.numLeafNodes() << endl;
  cout << endl;

  //(Not currently implemented, test result = 0)
  //4

  //***getHeight***
  cout << "Calling 'getHeight()'" << endl;
  cout << "The height of the tree is: " << intBST.getHeight() << endl;
  cout << endl;
  //(Not currently implemented, test result = 0)
  //3

  //***level(12)***
  cout << "Calling 'level(12)'" << endl;
  cout << "The level of T is: " << intBST.level(NODE6) << endl;
  cout << endl;
  cout << intBST.level(15) << endl;
  cout << intBST.level(28) << endl;
  cout << intBST.level(19) << endl;
  cout << intBST.level(8) << endl;

  cout << endl;

  //(Not currently implemented, test result = 0)
  //3

  //***displayAncestors(12)***
  cout << "Calling 'displayAncestors(12)'" << endl;
  int temp;
  temp = intBST.displayAncestors(NODE6);
	if (temp) cout << "Node found." << endl;
    else cout << "No node found." << endl;
	
	cout << endl;

  //***remove(12)***
  cout << "Calling 'remove(12)'" << endl;
  intBST.remove(NODE6);
  cout << endl;

  //**displayInOrder***
  cout << "Calling 'displayInOrder()'" << endl;
  intBST.displayInOrder();
  cout << endl;

  //2
  //8
  //15
  //19
  //28
  //32

  cout << "Calling 'getWidth()'" << endl;
  cout << intBST.getWidth() << endl;

  cout << "Inserting 12 back into tree with insertNode(12)" << endl;
  intBST.insertNode(NODE6);

  cout << "Calling 'getWidth()'" << endl;
  cout << intBST.getWidth() << endl;
  
 
  return ZERO;
}
