// CS311 : This is the BST implementation file template by Rika Yoshii

// Each node has an Up link to make it easy to go up the tree.  It must be set as nodes are inserted.  Some deletion
// cases require Up link to be updated.
//
// INSTRUCTIONS:
// Look for ** comments to complete this file for HW4
// Try not to delete the ** comments
// Make sure all { } match. Doing Tab on each line helps.
// Draw pictures as you complete each **

// =========================================================
//HW#: HW4 BST
//Your name: James Bertel
//Complier:  g++
//File type: implementation file binstree.cpp
//================================================================
#ifndef OTEAM_CPP
#define OTEAM_CPP
using namespace std;
#include <iostream>
#include "oteam.h"

// constructor  initializes Root
OrientationTeam::OrientationTeam()
{
  Root = NULL;   // This is an empty tree
}

// destructor must completely destroy the tree
OrientationTeam::~OrientationTeam()
{
  dtraverse(Root); // traverse to delete all vertices in post order
  Root = NULL;    
}
// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:   V is a pointer to the vertex to be deleted
void OrientationTeam::dtraverse(Vertex *V)  // recursive post order traversal
{   
  if (V != NULL) 
    {
      dtraverse(V->Left);         // destroy left sub tree of V
      dtraverse(V->Right);       //  destroy right sub tree of V
      delete V;                  //  delete V
    }
}

// PURPOSE: Show vertices in IN order traversal from the Root
void OrientationTeam::Display()
{
  cout << "--------------------------" << endl;
  cout << "Elements in the IN order: " << endl;
  INorderTraversal(Root);  // start in-order traversal from the root
  cout << "\n--------------------------" << endl;
}
// PURPOSE: Does IN order traversal from V recursively
// PARAM: V is te pointer to the vertex to visit right now
// For non EC, the height and balance will always be 0 
void OrientationTeam::INorderTraversal(Vertex *V)
{
  if (V != NULL)
    {
      // ** traverse left sub-tree of V recursively
      INorderTraversal(V->Left);
      // ** display V's element, height and balance and do endl; 
      cout << V->Elem << " ";
      // ** traverse right sub-tree of V recursively
      INorderTraversal(V->Right);
    }
}

// PURPOSE: Searches for an element in PRE-order traversal
// This is the same as Depth First Traversal
bool OrientationTeam::Search(elem_t K)
{
  PREorderSearch(Root, K);  // start pre-order traversal from the root
}

// PURPOSE: Does PRE order search from V recursively
// PARAM: V is the pointer to the vertex to be visited now
//        K is what we are looking for
bool OrientationTeam::PREorderSearch(Vertex *V, elem_t K)
{
    while (V != NULL)
      {
        if (K == V->Elem) return true; // found the element in V
        else if (V->Elem > K) 
	  V = V->Left;  //** traverse left sub-tree of V recursively
	else 
	  V = V->Right;//** traverse right sub-tree of V recursively
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
void OrientationTeam::InsertVertex(elem_t E)
{
  // Set up a new vertex first
   Vertex *N;         // N will point to the new vertex to be inserted
   N = new Vertex;    // a new vertex is created
   N->Left  = NULL;   // make sure it does not
   N->Right = NULL;   // point to anything
   N->Elem  = E;      // put element E in it
   //N->Height = 0;
   //N->Balance = 0;
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
        Vertex *Parent;  // Parent will point to V's parent

        V = Root;        // start with the root as V

	// go down the tree until you cannot go any further        
	while (V != NULL)
	  {
	    if (N->Elem == V->Elem) // the element already exists
              {	 cout << "...error: the element already exists" << endl;
		return;  }
	    else
	      if (N->Elem < V->Elem)  // what I have is smaller than V
		{  cout << "...going to the left" << endl; 
		  // ** change Parent to be V to go down 
		  Parent = V;
		  // ** change V to be V's Left 
		  V = V->Left;
		}
	      else // what I have is bigger than V
		{  cout << "...going to the right" << endl;
		  // ** change Parent to be V to go down
		  Parent = V;
		  // ** change V to be V's Right 
		  V = V->Right;
		}
	  }//end of while
        
   // reached NULL -- Must add N as the Parent's child
        
        if (N->Elem < Parent->Elem)  
          {  
	    // ** Parent's Left should point to the same place as N 
	    Parent->Left = N;
            // ** N should point UP to the Parent 
	    N->Up = Parent;

	    cout << "...adding " << E << " as the left child of " 
		 << Parent->Elem << endl;
            // ** EC call here 	}
	  }
        else 
           {
	     // ** Parent's Right should point to the same place as N 
	     Parent->Right = N;
            // ** N should point UP to the Parent 
	     N->Up = Parent;

             cout << "...adding " << E << " as the right child of " 
                  << Parent->Elem << endl;
	     // ** EC call here
  	}

      }// end of normal case

}// end of InsertVertex


// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void OrientationTeam::DeleteVertex(elem_t E)
{
  cout << "Trying to delete " << E << endl;
  
  Vertex *V;              // the current vertex

  // case 1: Lonely Root  
  if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
    { cout << "...deleting the lonely root" << endl;
      delete Root; 
      Root = NULL;
      return; }  // only the Root was there and deleted it
  
  // case 2:  One Substree Root
  // ** if what you want to delete is the root
  else if(E == Root->Elem)
    {
          // ** and it has only the left subtree
      if( (Root->Left != NULL) && (Root->Right == NULL) )
	{  //** change the root to the left child and return
	  Root = Root->Left;
	  return;
	}

      // ** and it has only the right subtree
      else if(Root->Left == NULL && Root->Right != NULL)
	{ // ** change the root to the right child and return
	  Root = Root->Right;
	  return;
	}

    }// end of deleting the root with one subtree
  
  // Otherwise deleting something else
  
  V = Root;  // start with the root to look for E
  
  // going down the tree looking for E
  while (V != NULL)
    { 
      if ( E == V->Elem)   // found it
	{  cout << "...removing " << V->Elem << endl;
	  // ** call remove here to remove V
	  remove(V, V->Up);
	  return; 
	}
      
      else
	if (E < V->Elem)
	  {  cout << "...going to the left" << endl;
	    // ** update Parent and V here to go down 
	    V = V->Left;
	    
	  }
	else
	  {  cout << "...going to the right" << endl;
	    // ** update Parent and V here to go down
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
void OrientationTeam::remove(Vertex *V, Vertex *P)
{
     // ** if V is a leaf (case 1)
  if(V->Right == NULL && V->Left == NULL)
    {
      cout << "removing a leaf" << endl;
            
      if(P->Left == V)// ** if V is a left child of P
	  P->Left = NULL;
          // ** EC call from P
      else
	P->Right = NULL;

      delete V;
    }//end of leaf case
  
      // ** if V has just the left child so bypass V (case 2)
  else if(V->Right == NULL && V->Left != NULL)
    {
      cout << "removing a vertex with just the left child" << endl;

      if(P->Left == V)
	  P->Left = V->Left;
      else	 
	P->Right = V->Left;

      (V->Left)->Up = P; //left child points to parent
      delete V;

      // ** EC call from P
    }// end of V with left child       
 
      // ** if V has just the right child so bypass V (case 2)
  else if(V->Right != NULL && V->Left == NULL)
    {
      cout << "removing a vertex with just the right child" << endl;
      
      if(P->Left == V)
	P->Left = V->Right;
      else //P->Right == V
	P->Right = V->Right;

      (V->Right)->Up = P;
      delete V;
          // ** EC call from P
    }//end of V with right child
      
   else // V has two children (case 3)
     { 
       cout << "removing an internal vertex with children" << endl;
       cout << "..find the MAX of its left sub-tree" << endl;
       elem_t Melem; //Max element

       // find MAX element in the left sub-tree of V
       Melem = findMax(V); 
       cout << "..replacing " << V->Elem << " with " << Melem << endl;
       
       // ** Replace V's element with Melem here
       V->Elem = Melem;
       
     }//end of V with two children
      
}// end of remove

// PURPOSE: Finds the Maximum element in the left sub-tree of V
// and also deletes that vertex
elem_t OrientationTeam::findMax(Vertex *V)
{
  Vertex *Parent = V;
  V = V->Left;          // start with the left child of V
  
  // ** while the right child of V is still available
  while(V->Right != NULL)
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

#endif
