#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int SIZE = 55;

//typedef int elem_t;


struct elem_t //each oteamer
{
  string firstName;
  string lastName;
  string major;
  char position; //D = Director/Co-Director , L = Leader, O = Oteamer
  //int numOrts; //number orientations signed up for
  string email;
  long phoneNum;

  //bool returner; //true = returning Oteamer, false = first time oteamer
}; 

struct Vertex
{
  Vertex *Up;  // points to the parent node 
  Vertex *Left;
  Vertex *Right;
  elem_t Elem;
};   

// this is set up to be inherited by another class
class OrientationTeam
{  
 public:
  
  OrientationTeam();  // intializes Root
  ~OrientationTeam();  // destructor calls dtraverse to destroy the dynamic tree
  
  // PURPOSE: these will show the vertices in IN order 
  // TO CALL: No parameter  but provide a pointer to 
  //          the root vertex in calling INorderTraversal
  void Display();      
  void INorderTraversal(Vertex*); // recursive
  
  // PURPOSE: these will search in PRE order - same as Depth First
  // TO CALL: provide the element to search for; provide a pointer to 
  //          the root vertex in calling PREorderSearch
  bool Search(elem_t);
  bool PREorderSearch(Vertex*, elem_t); // recursive
  
  // PURPOSE: This adds a new vertex into the OrientationTeam 
  // TO CALL: provide the element to be added to the tree
  void InsertVertex(elem_t);
  
  // PURPOSE: This deletes a vertex with the given element 
  //     - calls remove and  findMax (see below)
  // TO CALL: provide the element to be removed from the tree
  void DeleteVertex(elem_t);
  

  // vvv FUNCTIONS ADDED FOR FINAL BELOW vvv

  // PURPOSE: Checksv to see if two elements are identical
  bool operator==(const elem_t&);//, const elem_t&);
  //bool operator<(const elem_t& OtherOne);
  //bool operator>(const elem_t& OtherOne);
  //elem_t loadTree();

 protected:
  Vertex *Root; //  Root which is a pointer to the root vertex

  // utility functions follow - these are not for the clients to use
  // These were created to implement the public methods
  
  void dtraverse(Vertex*);
  // traverse and delete all vertices in post order
  
  void remove(Vertex*, Vertex*); 
  // removes the vertex knowing its parent
  
  elem_t findMax(Vertex*);  // finds the MAX element in the
  // left sub-tree of the vertex and also deletes it
  
};
