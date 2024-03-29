// CS311 : This is the BST implementation file template by Rika Yoshii

// Each node has an Up link to make it easy to go up the tree.  It must be set as nodes are inserted.  Some deletion
// cases require Up link to be updated.  Couts are there to test to make sure
// you set the Up links correctly!!!! (Fall 19)
//
// INSTRUCTIONS:
// Look for ** comments to complete this file for HW4
// Try not to delete the ** comments, but add the code next to them
// Make sure all { } match. Doing Tab on each line helps.
// Draw pictures as you complete each **

// =========================================================
//HW#: HW4 BST
//Your name: Mike Sharko
//Complier:  g++
//File type: implementation file binstree.cpp
//================================================================

using namespace std;
#include <iostream>
#include "binstree.h"

// constructor  initializes Root
BST::BST()
{
  Root = NULL;   // This is an empty tree
}

// destructor must completely destroy the tree
BST::~BST()
{
  dtraverse(Root); // traverse to delete all vertices in post order
  Root = NULL;    
}
// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:   V is a pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // recursive post order traversal
{   
  if (V != NULL) 
    {
      dtraverse(V->Left);         // destroy left sub tree of V
      dtraverse(V->Right);       //  destroy right sub tree of V
      delete V;                  //  delete V
    }
}

// PURPOSE: Show vertices in IN order traversal from the Root
void BST::Display()
{
  cout << "Elements in the IN order: " << endl;
  INorderTraversal(Root);  // start in-order traversal from the root
  cout << endl;
}


// PURPOSE: Does IN order traversal from V recursively
// PARAM: V is a pointer to the vertex to visit right now
// For non EC, the height and balance will always be 0 
void BST::INorderTraversal(Vertex *V)
{
  if (V != NULL)
    {
	  V->Height = 0;
	  V->Balance = 0;
	  INorderTraversal(V->Left); // **traverse left sub-tree of V recursively !!!!!!!!!!!!!!!!!
	  cout << V->Elem; //<< V->Height << V->Balance; // ** display V's element, height and balance and do endl; !!!!!!!!!!!!!!!!
	  INorderTraversal(V->Right);// ** traverse right sub-tree of V recursively!!!!!!!!!!!!!!!!!!!
    }
}

// PURPOSE: Searches for an element in PRE-order traversal
// This is the same as Depth First Traversal
bool BST::Search(elem_t K)
{
	 
	return PREorderSearch(Root, K);  // start pre-order traversal from the root
	 
	 
}
 //PURPOSE: Does PRE order search from V recursively
 //PARAM: V is the pointer to the vertex to be visited now
 //       K is what we are looking for
bool BST::PREorderSearch(Vertex *V, elem_t K)

 {
	if (V != NULL)
	{
 		if (K == V->Elem) return true; // found the element in V
		else if (K < V->Elem)
			return PREorderSearch(V->Left, K);	//** traverse left sub-tree of V recursively
		else if (K>V->Elem)
			return PREorderSearch(V->Right, K);//** traverse right sub-tree of V recursively
	}
	return false;
 }


// ------ The following are for adding and deleting vertices -----


// PURPOSE: Adds a vertex to the binary search tree for a new element 
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively)
// to demonstrate the algorithm that is in the notes
//    - smaller than the current -> go to the left
//    - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::InsertVertex(elem_t E)
{
  // Set up a new vertex first
   Vertex *N;         // N will point to the new vertex to be inserted
   N = new Vertex;    // a new vertex is created
   N->Left  = NULL;   // make sure it does not
   N->Right = NULL;   // point to anything
   N->Elem  = E;      // put element E in it
    N->Height = 0;
   N->Balance = 0;
   N->Up = NULL;      // no parent for now
   cout << "Trying to insert " << E << endl;

   if (Root == NULL)  // Special case: we have a brand new empty tree
     {
       Root = N;      // the new vertex is added as the root
       cout << "...adding " << E << " as the root" << endl; 
     }// end of the special case

   else  // the tree is not empty
     {
        Vertex *V;       // V will point to the current vertex
        Vertex *Parent;  // Parent will always point to V's parent
		V = Root;        // start with the root as V
        Parent = NULL;   // above V so it does not point to anything  

	// go down the tree until you cannot go any further        
	while (V != NULL)
	  {
	    if (N->Elem == V->Elem) // the element already exists
              {	 cout << "...error: the element already exists" << endl;
		return;  }
	    else
	      if (N->Elem < V->Elem)  // what I have is smaller than V
		{  cout << "...going to the left" << endl; 
		Parent = V;//   Parent to be V to go down 
		V = V->Left;  //   V to be V's Left 
		}
	      else // what I have is bigger than V
		{  cout << "...going to the right" << endl;
		Parent = V;  //   Parent to be V to go down
		V = V->Right; //   V to be V's Right 
		}
	  }//end of while
        
   // reached NULL -- Must add N as the Parent's child
        
        if (N->Elem < Parent->Elem)  
          {  
	    // ** Parent's Left should point to the same place as N 
	    cout << "...adding " << E << " as the left child of " 
		 << Parent->Elem << endl;
		 
		Parent->Left = N;
		N->Left = NULL;
		N->Right = NULL; 
		
		// ** N must point UP to the Parent !!!!!!!! 
//             cout << N->Elem  << " now points UP to " << N->Up->Elem << endl;   
            // *** EC call here to adjust height and BF	
		}
        else 
           {
			Parent->Right = N;// ** Parent's Right should point to the same place as N 
             cout << "...adding " << E << " as the right child of " 
                  << Parent->Elem << endl;
			 
			 Parent->Right = N;
			 N->Left = NULL;
			 N->Right = NULL;
			 //Parent->Elem =N->Up->Elem;// ** N must point UP to the Parent !!!!!!!!!!!!!!!
        //     cout << N->Elem << " now points UP to " << N->Up->Elem << endl;   
	     // *** EC call here to adjust height and BF
  	}

      }// end of normal case

}// end of InsertVertex


// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove 
void BST::DeleteVertex(elem_t E)
{
	cout << "Trying to delete " << E << endl;

	Vertex* V;       // the current vertex
	Vertex* Parent;  // Parent will always point to V's parent

	// case 1: Lonely Root  --------------------
	if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
	{
		cout << "...deleting the lonely root" << endl;
		delete Root;
		Root = NULL;
		return;
	}  // only the Root was there and deleted it

// case 2:  One Substree Root ----------------

	 cout << "... deleting the root with just one child" << endl;
	
	if (E == Root->Elem) // ** if what you want to delete is the root
	{// ** and it has only the left subtree
		if ((Root->Left != NULL) && (Root->Right == NULL)) 
		{
			Root = Root->Left; //change the root to the left child and return
			return;
		} 
	      //making sure the old root has been deleted and the new root's UP is NULL 
 
	// ** and it has only the right subtree
		else if ((Root->Left == NULL) && (Root->Right != NULL))
		{
			Root = Root->Right; // ** change the root to the right child and return
			return;
		}
	} 
	  //    making sure the old root has been deleted and the new root's UP is NULL 
	
	// end of deleting the root with one subtree

	// ---- Otherwise deleting something else  --------------

	V = Root;  // start with the root to look for E
	Parent = NULL;  // above the V so does not point to anything yet

	// going down the tree looking for E
	while (V != NULL)
	{
		if (E == V->Elem)   // found it
		{
			cout << "...removing " << V->Elem << endl;
			remove(V, Parent);// ** call remove here to remove V
			return;
		}

		else
			if (E < V->Elem)
			{
				cout << "...going to the left" << endl;
				// ** update Parent and V here to go down 
				Parent = V;
				V = V->Left;
			}
			else
			{
				cout << "...going to the right" << endl;
				// ** update Parent and V here to go down
				Parent = V;
				V = V->Right;
			}

	}// end of while

  // reached NULL  -- did not find it
	cout << "Did not find the key in the tree." << endl;

}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf, delete it
// Case 2: it has just one child, bypass it
// Case 3: it has two children, replace it with the max of the left subtree
void BST::remove(Vertex *V, Vertex *P)
{
  // ** if V is a leaf (case 1)
	if ((V->Left == NULL) && (V->Right == NULL))

      {
	cout << "removing a leaf" << endl;
	// ** if V is a left child of P
	if (V == P->Left)
	{
	  // ** delete V and also make Parent's left NULL 
		delete V;
		P->Left = NULL;
          // *** EC call here from P to adjust height and BF  

	}
	else // V is a right child of the Parent
	  { 
          // ** delete V and also make Parent's right NULL 
		delete V;
		P->Right = NULL;
          // *** EC call from P to adjust height and BF
	  }
      }//end of leaf case
    
	else if ((V->Left != NULL) && (V->Right == NULL)) // ** if V has just the left child so bypass V (case 2)
     { P = V->Left; // the left child !!!!!!!!!!!!
	  cout << "removing a vertex with just the left child" << endl;
          // ** You need if then else to determine Parent's left or right
	  //    should point to V's left child;
	  if (P->Elem > V->Elem)
	  {
		  P->Left = V->Left;
		  delete V;  // ** Be sure to delete V
	  }
      else
	  {
		  P->Right = V->Left;
		  delete V;
	  }

	  //** Make V's left child point UP to the parent;
	//  cout << V->Elem << " points up to " << V->Up->Elem << endl;
          // *** EC call from P to adjust height and BF
	}// end of V with left child       
 
   else if ((V->Left == NULL) && (V->Right != NULL))// ** if V has just the right child so bypass V (case 2)
     { P = V->Right;  // the right child
	  cout << "removing a vertex with just the right child" << endl;
	  // ** You need if then else to determine Parent's left or right
	  if (P->Elem > V->Elem)
	  {
		  P->Left = V->Right; //    should point to V's right child; 
		  delete V;
	  }
	  else
	  {
		  P->Right = V->Right;
		  delete V;
	  }
	   // ** Make V's right child point UP to the parent;   
          //cout <<V->Elem << " points up to " << V->Up->Elem << endl;
          // ** Be sure to delete V
          // *** EC call from P to adjust height and BF 
        }//end of V with right child
      
   else // V has two children (case 3)
	{ cout << "removing an internal vertex with children" << endl;
	  cout << "..find the MAX of its left sub-tree" << endl;
	  elem_t Melem;
	  // find MAX element in the left sub-tree of V
          Melem = findMax(V); 
          cout << "..replacing " << V->Elem << " with " << Melem << endl;
          // ** Replace V's element with Melem here
        }//end of V with two children
      
}// end of remove

// PURPOSE: Finds the Maximum element in the left sub-tree of V
// and also deletes that vertex
elem_t BST::findMax(Vertex *V)
{
  Vertex *Parent = V;
  V = V->Left;          // start with the left child of V
  
  while (V->Right != NULL) // ** while the right child of V is still available
  {
	  // ** update Parent and V to go to the right
	  Parent = V;
	  V = V->Right;
  }
  
  // reached NULL Right  -- V now has the MAX element
  elem_t X = V->Elem;
  cout << "...Max is " << X << endl;
  remove(V, Parent);    // remove the MAX vertex 
  return X;             // return the MAX element
  
}// end of FindMax

