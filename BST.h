//Colin Brinton
//10/24/15
//Version 1.0

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

const int ZERO = 0;
const int ONE = 1;
const int NONE = -1;

// BST template
template <typename T>
class BST
{
private:
   struct BSTNode
   {
      T value;           // The value in the node
      BSTNode *left;    // Pointer to left child node
      BSTNode *right;   // Pointer to right child node
   };

   BSTNode *root;       // Pointer to the root node
   
   // Private member functions
   void insert(BSTNode *&, BSTNode *&);
   void destroySubTree(BSTNode *);
   void deleteNode(T, BSTNode *&);
   void makeDeletion(BSTNode *&);
   void displayInOrder(BSTNode *) const;
   void displayPreOrder(BSTNode *) const;
   void displayPostOrder(BSTNode *) const;
   bool isEmpty(BSTNode *) const;
   int nodes(BSTNode *) const;
   int leafNodes(BSTNode *) const;
   int height(BSTNode *) const;
   int getLevel(BSTNode *, T, int) const;
   bool ancestors(BSTNode *, T) const;
   int width(BSTNode *, int) const;
   int maxWidth(BSTNode *) const;
   
public:
   // Constructor
   BST()
      { root = nullptr; }
      
   // Destructor
   ~BST()
      { destroySubTree(root); }
      
   // Binary tree operations
   void insertNode(T);
   bool searchNode(T);
   void remove(T);
   int numNodes() const;
   int numLeafNodes() const;
   int getHeight() const ;
   int level(T) const ;
   bool displayAncestors(T) const;
   bool empty() const;
   int getWidth() const;
   
   void displayInOrder() const
      {  displayInOrder(root); }
      
   void displayPreOrder() const
      {  displayPreOrder(root); }
      
   void displayPostOrder() const
      {  displayPostOrder(root); }
};

//*************************************************************
// insert accepts a BSTNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the BSTNode pointer. This function is called recursively. *
//*************************************************************
template <typename T>
void BST<T>::insert(BSTNode *&nodePtr, BSTNode *&newNode)
{
   if (nodePtr == nullptr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************
template <typename T>
void BST<T>::insertNode(T item)
{
   BSTNode *newNode = nullptr;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new BSTNode;
   newNode->value = item;
   newNode->left = newNode->right = nullptr;
   
   // Insert the node.
   insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************
template <typename T>
void BST<T>::destroySubTree(BSTNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************
template <typename T>
bool BST<T>::searchNode(T item)
{
   BSTNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->value == item)
         return true;
      else if (item < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************
template <typename T>
void BST<T>::remove(T item)
{
   deleteNode(item, root);
}

//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************
template <typename T>
void BST<T>::deleteNode(T item, BSTNode *&nodePtr)
{
   if (item < nodePtr->value)
      deleteNode(item, nodePtr->left);
   else if (item > nodePtr->value)
      deleteNode(item, nodePtr->right);
   else
      makeDeletion(nodePtr);
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************
template <typename T>
void BST<T>::makeDeletion(BSTNode *&nodePtr)
{
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   BSTNode *tempNodePtr = nullptr;

   if (nodePtr == nullptr)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == nullptr)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == nullptr)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************
template <typename T>
void BST<T>::displayInOrder(BSTNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************
template <typename T>
void BST<T>::displayPreOrder(BSTNode *nodePtr) const
{
   if (nodePtr)
   {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************
template <typename T>
void BST<T>::displayPostOrder(BSTNode *nodePtr) const
{
   if (nodePtr)
   {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

//TODO

template <typename T>
bool BST<T>::empty()const
{
  return isEmpty(root);
}

template <typename T>
bool BST<T>::isEmpty(BSTNode *nodePtr) const
{
  if (nodePtr == nullptr)
	return true;
  else
	return false;
}

template<typename T>
int BST<T>::numNodes() const
{
  return nodes(root);
}

template <typename T>
int BST<T>::nodes(BSTNode *nodePtr ) const
{ 
  if (nodePtr == nullptr)
  	return ZERO;
  return (ONE + nodes(nodePtr->left) + nodes(nodePtr->right));
}

template <typename T>
int BST<T>::numLeafNodes() const
{
  return leafNodes(root);
}

template <typename T>
int BST<T>::leafNodes(BSTNode *nodePtr) const
{
  if(nodePtr == nullptr)
	return ZERO;
  else
	{
	  if(nodePtr->left == nullptr && nodePtr->right == nullptr)
		return ONE;
	  return(leafNodes(nodePtr->left) + leafNodes(nodePtr->right));
	}
}

template <typename T>
int BST<T>::getHeight() const
{
  return height(root);
}

template <typename T>
int BST<T>::height(BSTNode *nodePtr) const
{
  if(nodePtr == nullptr)
	return ZERO;

  int leftHeight = height(nodePtr->left);
  int rightHeight = height(nodePtr->right);

  return (leftHeight > rightHeight) ? (leftHeight + ONE) : (rightHeight + ONE);
}

template <typename T>
int BST<T>::level(T item) const
{
  return getLevel(root, item);
}

template <typename T>
int BST<T>::getLevel(BSTNode *nodePtr, T item, int level = ZERO) const
{
  if(nodePtr == nullptr)
	return NONE;

  if(nodePtr->value == item)
	return level;

  int leftLevel = getLevel(nodePtr->left, item, (level + ONE));
  int rightLevel = getLevel(nodePtr->right, item, (level + ONE));

  if(leftLevel == NONE)
	return rightLevel;
  else
	return leftLevel;
}


template <typename T>
bool BST<T>::displayAncestors(T item) const
{
  return ancestors(root, item);
}

template <typename T>
bool BST<T>::ancestors(BSTNode *nodePtr, T item) const
{
  if(nodePtr == nullptr)
	return false;

  if(nodePtr->value == item)
	return true;

  if(ancestors(nodePtr->left, item) || ancestors(nodePtr->right, item))
	{
	  cout << nodePtr->value << endl;
	  return true;
	}

  return false;
}

template <typename T>
int BST<T>::getWidth() const
{
  return maxWidth(root);
}

template <typename T>
int BST<T>:: width(BSTNode *nodePtr, int level) const
{
  if(nodePtr == nullptr)
	return ZERO;

  if(level == ONE)
	return ONE;

  if(level > ONE)
	return (width(nodePtr->left, level - ONE) +
				   width(nodePtr->right, level - ONE));
  else
	return ZERO;
}

template <typename T>
int BST<T>::maxWidth(BSTNode *nodePtr) const
{
  int w;
  int height;
  int max = ZERO;

  height = (ONE + getHeight());

  for(int i = ONE; i <= height; i++)
	{
	  w = width(nodePtr, i);
	  if(w > max)
		max = w;
	}
  return max;
}
	

#endif
