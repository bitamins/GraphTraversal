// =======================================================
// template: Rika Yoshii
// name: Michael Bridges
// Compiler:  g++ 
// File type: header file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef char el_t ;  // elements will be **

//this struct will take up less memory than a node class
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //checks to see if the list is empty
  bool isEmpty();
    
  //displays all elements
  void displayAll();

  //adds an element to the front of the list
  void addFront(el_t);
    
  //adds an element to the rear of the list
  void addRear(el_t);

  //deletes an element from the front of the list
  void deleteFront(el_t&);
    
  //deletes an element from the rear of the list
  void deleteRear(el_t&);
    
  //deletes a node at the selection index
  void deleteIth(int, el_t&);

  //adds a node in before the selected index    
  void addbeforeIth(int, el_t);
    
};
