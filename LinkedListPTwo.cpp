/*
Linked List Part 2 by Andrew Thomas Mr.Galbraith P3 C++ Class 1/15/19. I used Ali's Linked List part 1 code. This code is a list of students. The user can ADD, PRINT, DELETE, QUIT, and AVERAGE the list. ADD is the function that adds a student to the list. PRINT is the function that prints all the students in the list by order of increasing ID. DELETE function deletes a student from the list. QUIT exits the program. AVERAGE averages all the students GPA.
 */
#include <iostream> // initializes libraries
#include <cstring>
#include <cstdlib>
//#include <vector>
#include <cmath>
#include "Node.h"
//#include "Student.h"
#include <iomanip>
using namespace std; // uses namespace std
Student* Add(Node* ListTail); // initializes the function
void Subtract(Node* ListTail, int* DeletedID, Node* previous, int* counterThree, int* counterFour, int* counterFive);
void Print(Node* ListTail, int* counterTwo);
Node* getEnd(Node* Current);
void Average(Node* ListFront, int* counterFive, float* sum, float* num);
void SortList(Node* ListFront, Node* SortedFront, int* counterSix, int* Least, Node* Beginning, int* counterSeven, Node* previous, int* counterThree, int* counterFour, int* counterFive, int* counterNine, int* counterTen, int* size, Node* Header, int* sizeTwo, int* LSize, int* counterThis);
Node* MatchGPA(Node* ListFront,int* Least, int* counterSeven);
void Ignore(Node* ListTail, int* DeleteID, Node* previous, int* counterThree, int* counterFour, int* counterFive, int* LSize);
void Duplicate(Node* Header, Node* DuplicateHeader, int* counterEight);
int* Size(Node* Header, int* counterTen, int* size);
void CheckDuplicate(Node* header, bool* Dup, int* counterOne, int* DupID);
int main() { // main function
  bool stop = false; // initializes the variables
  char stopChar;
  Student* temp = new Student;
  Student* tempTwo = new Student;
  Student* tempThree = new Student;
 Student* tempFour = new Student;
 Student* tempFive = new Student;
 tempFive = NULL;
 Node* previous = new Node();
 (*previous).setStudent(tempFive);
 Node* Header = new Node();
 (*Header).setStudent(temp);
  Node* SortedHeader = new Node(); // sorted header
  (*SortedHeader).setStudent(tempTwo);
  Node* DuplicateHeader = new Node(); // duplicate header
  (*DuplicateHeader).setStudent(tempFour);
  Node* Beginning = new Node();
  (*Beginning).setStudent(tempThree);
  int* DeletedID = new int;
  int* LSize = new int;
  
  (*LSize) = 0;
  bool* Dup = new bool;
  int* DupID = new int;
  (*Dup) = false;
  cout << "Welcome to StudentList. Here you can add, print, or delete sets of information about studnet. each set has the first name, last name, ID number, and GPA for the student. if you want to quit this app then type QUIT" << endl; // introduciton
  char input[20];
  char quit[5];
  
  int* Least = new int;
  (*Least) = 0;
  int counter = 0;
  /*
  int* counterTwo = 0;
  //counterTwo = 0;
  int* counterThree = 0;
  */
  int* ResetCounterTwo = new int; // initializing all the counters
  (*ResetCounterTwo) = 0;
  int* counterTwo = new int;
  (*counterTwo) = 0;
  int* counterThree = new int;
  (*counterThree) = 0;
  int* ResetCounter = new int;
  (*ResetCounter) = 0;
  int* counterFour = new int;
  (*counterFour) = 0;
    int* counterFive = new int;
    (*counterFive) = 0;
        int* counterSix = new int;
    (*counterSix) = 0;
    int* counterSeven = new int;
    (*counterSeven) = 0;
    int* counterEight = new int;
    (*counterEight) = 0;
    int* counterNine = new int;
    (*counterNine) = 0;
   int* counterTen = new int;
    (*counterTen) = 0;
    int* size = new int;
    (*size) = 0;
   int* sizeTwo = new int;
    (*sizeTwo) = 0;
    int* counterThis = new int;
    (*counterThis) = 0;
    float* sum = new float;
    (*sum) = 0;
    float* num = new float;
    (*num) = 0;
    Student* temporary = new Student;
    do{ // Continues running the programm until the QUIT funciton
      cout << "What would you like to do?" << endl;
	    cin.get(input, 20); // asks and gets input
	    cin.clear();
	    cin.ignore();
	    //temporary = Add(getEnd(Header));
	    if(strcmp(input, "ADD") == 0){ // ADD function
	      //cout << "here " << endl;  
	       temporary = Add(getEnd(Header));
	      (*counterNine) = 0;
	      // cout << "here2" << endl;
	      //Print(Header, counterTwo);
	      //cout << ""
	      if((*Header).getNext() != NULL){
	      CheckDuplicate(Header, Dup, counterNine, (*temporary).getID());
	      }
	      else{

	      }
	      (*counterNine) = 0;
	      //cout << "Here3" << endl;
	      if((*Dup) == false){ 
		//Add(getEnd(Header));
		Node* newNode = new Node();
		(*newNode).setStudent(temporary);
		(*getEnd(Header)).setNext(newNode);
		
	      }
	      else{
		cout << "There is already a student with this ID." << endl;
		(*Dup) = false;
	      }
	      //	      (*counterNine) = 0;
	      // Print(Header, counterTwo);
	      //CheckDuplicate(Header, Dup, counterNine, DupID);
	      //(*counterNine) = 0;
		  } 
	    else if(strcmp(input, "DELETE") == 0){ // DELETE function
	      if((*Header).getNext() != NULL){
	      cout << "Please Enter the ID of the student you want to delete" << endl;
	      cin >> (*DeletedID);
	      cin.clear();
	      cin.ignore();
	      //cout << "LOL" << endl;
	      Subtract(Header, DeletedID, previous, counterThree, counterFour, counterFive);
	      // cout << "LOL2" << endl;
	      if((*counterFour) == 0){
		  cout << "That ID does not match any ID of the students" << endl;
		}
		(*counterFour) = 0;
		(*counterThree) = 0;
	      }
	      else{
		cout << "You can't delete from an empty list." << endl;
		}
	      }
	      
	    else if(strcmp(input, "QUIT") == 0){ // QUIT function
	      stop = true; // sets the stop boolean to true
	    }
	    else if(strcmp(input, "AVERAGE") == 0){ // AVERAGES the GPA
	      Average(Header, counterFive, sum, num);
	      (*sum) = (*sum) / (*num);
		  cout << "Average: ";
		  cout << fixed << setprecision(2) << (*sum) << endl; // prints the AVERAGE with a percision of 2

	      (*counterFive) = 0;
	      (*sum) = 0;
	      (*num) = 0;
	    }
	    else if(strcmp(input, "PRINT") == 0){ // PRINT function
	      if((*Header).getNext() != NULL){
    
			(*SortedHeader).setNext(NULL);
			//Print(Header, counterTwo);
			//Print(SortedHeader, counterTwo);
			//cout << "Size" << endl;
			//cout << (*LSize) << endl;
			SortList(Header, SortedHeader, counterSix, Least, Beginning, counterSeven, previous, counterThree, counterFour,  counterFive, counterNine, counterTen, size, Header, sizeTwo, LSize, counterThis); // sorts the list
		
			//	cout << "Print" << endl;
		(*counterTwo) = 0;
		
		
		(*counterTwo) = 0;
	       
		Print(SortedHeader, counterTwo); // prints the list
	       
		Duplicate(SortedHeader, Header, counterEight); // resets the initial list
		//Duplicate(Header, SortedHeader, counterEight);
		(*counterTwo) = 0; // resetting the counters
		(*counterEight) = 0;
	(*SortedHeader).setNext(NULL);
		(*counterSix) = 0;
		(*Least) = 0;
		(*counterSeven) = 0;
		(*counterThree) = 0;
		(*counterFour) = 0;
		(*counterFive) = 0;
		(*counterNine) = 0;
		(*Beginning).setNext(NULL);
		(*previous).setStudent(NULL);
		(*counterTen) = 0;
		(*size) = 0;
		(*sizeTwo) = 0;
		(*LSize) = 0;
		(*counterThis) = 0;
		(*counterTwo) = 0;
		}
	      else{ // there is nothing in the list
		cout << "empty list" << endl;
		}
		
	        }
	    else{
	      cout << "Command not recognized. Please check your spelling and make sure it is all capital letters." << endl; // input is not any of the commands
	    }
	    
	  }
    while(stop == false); // keeps going while stop is false
    //if((*Dup) == true){
    //cout << "There are two studnets in the list with duplicate ID's" << endl;
    //}
    return 0;
}
Student* Add(Node* Current){ // creates the student pointer to add to vector
  
    Student *create = new Student(); // student created
  cout << "Please enter the student's name." << endl;
  char* Name = new char[20];
  cin.get(Name, 20); // firstname
  cin.clear();
  cin.ignore();
  (*create).setName(Name);
  int* ID = new int;
  cout << "Please enter the student's ID number." << endl;
  
  cin >> (*ID); //id
  cin.clear();
  cin.ignore();
  (*create).setID(ID);
  float* GPA = new float;
  cout << "Please enter the student's GPA." << endl;
  cin >> (*GPA); // gpa
    cin.clear();
    cin.ignore();
    (*create).setGPA(GPA);

    /*
    Node* newNode = new Node(create);
    (*Current).setNext(newNode);
    */
    return create;
}
void Subtract(Node* ListTail, int* DeleteID, Node* previous, int* counterThree, int* counterFour, int* counterFive){ // deletes the student from the vector
  if((*counterThree) == 0){
    (*counterThree)++;
    //cout << "here" << endl;
    previous = ListTail; // sets the previous as the list tail
   Subtract((*ListTail).getNext(), DeleteID, previous, counterThree, counterFour, counterFive);
  }
  if((*(*(*ListTail).getStudent()).getID()) == (*DeleteID)){ // checks if ID is the ID that one wants to delete
    cout << "Deleted" << endl;
    (*counterFour)++;
    if((*ListTail).getNext() != NULL){ // DELETE node is in middle or beginning
      // cout << "Deleted1" << endl;
      //cout << "Here1" << endl;
      (*previous).setNext((*ListTail).getNext());
      //cout << "a" << endl;
      delete (*ListTail).getStudent();
      //delete ListTail;
      //delete previous;
      //cout << "Here2" << endl;
      //cout << "Here1" << endl;
	return;
	//cout << "Here2" << endl;
      }
    else if(ListTail == NULL){ // DELETE node is at the end
      //cout << "Here3" << endl;
      return;
    }
      else{
	//cout << "Here3" << endl;
	//cout << "Deleted2" << endl;
	(*previous).setNext(NULL); 
	// cout << "b" << endl;
	//delete ListTail;
	delete (*ListTail).getStudent();
	//delete ListTail;
	//delete previous;
	//cout << "Here4" << endl;
	//cout << "Here4" << endl;
	return;
	//cout << "Here5" << endl;
      }
  }
  //else{
  //cout << "wow1" << endl;
  //}
  
  if((*ListTail).getNext() != NULL){ // recusive function that goes through the list until it matches the ID
    // cout << "This" << endl;
    previous = ListTail; 
    Subtract((*ListTail).getNext(), DeleteID, previous, counterThree, counterFour, counterFive); 
	}
  else{
    //cout << "wow" << endl;
    return;
  }
  
}
void Print(Node* ListTail, int* counterTwo){ // prints all the students in the vector
 
  if((*counterTwo) == 0){ // ignore header
     
    (*counterTwo)++;
    Print((*ListTail).getNext(), counterTwo);
  }
  else{
    for(int i = 0; i < strlen((*(*ListTail).getStudent()).getName()); i++){ 
      cout << (*(*ListTail).getStudent()).getName()[i]; // print name
    }
	cout << " ";
	cout << (*(*(*ListTail).getStudent()).getID()); // prints ID
      	cout << " ";
	cout << fixed << setprecision(2) << (*(*(*ListTail).getStudent()).getGPA()); //prints GPA to a precision of 2
	cout << endl;
	if((*ListTail).getNext() != NULL){ // recursive funtion that goes through the list and prints every node
	  Print((*ListTail).getNext(), counterTwo); 
	}
	
  }
}
Node* getEnd(Node* Current){ // gets the last node
  if((*Current).getNext() != NULL){ 
    getEnd((*Current).getNext()); // recuursive funtcion that goes through the list until last node
  }
  else{ // last node!
    return Current;
  }
}
void Average(Node* ListFront, int* counterFive, float* sum, float* num){ // average function
    if((*counterFive) == 0){
     
    (*counterFive)++;
    Average((*ListFront).getNext(), counterFive, sum, num); // ignore header
  }
    else{
      
      (*sum) = (*sum) + (*(*(*ListFront).getStudent()).getGPA()); // adds the gpa to the sum
      (*num)++; // increments the number of values
    
      if((*ListFront).getNext() != NULL){ // recursive function that goes through all the nodes
      //  cout << "here1" << endl;
      Average((*ListFront).getNext(), counterFive, sum, num);
    }
    
    }
}
void SortList(Node* ListFront, Node* SortedFront, int* counterSix, int* Least, Node* Beginning, int* counterSeven, Node* previous, int* counterThree, int* counterFour, int* counterFive, int* counterNine, int* counterTen, int* size, Node* Header, int* sizeTwo, int* LSize, int* counterThis){ // sorts an unsorted list
  if((*counterSix) == 0){ // ignore header
          
    (*counterSix)++;
    if((*counterThis) == 0){
    (*Beginning).setNext(ListFront);
    (*LSize) = (*Size(ListFront, counterTen, size));
    (*counterTen) = 0;
      }
    (*counterThis)++;
    
      SortList((*ListFront).getNext(), SortedFront, counterSix, Least, Beginning, counterSeven,  previous, counterThree, counterFour, counterFive, counterNine, counterTen, size, Header, sizeTwo, LSize, counterThis);
  }
  //cout << "Here" << endl;
    else{
      // cout << "Here" << endl;
      if((*counterNine) == 0){ // picks the least
	//cout << "LOL" << endl;
	(*counterNine)++;
	(*Least) = (*(*(*ListFront).getStudent()).getID());
	//cout << (*Least) << endl;
	//cout << "Here1" << endl;
      }
      else{ // compares the least to the ID of the current student
    if((*Least) > (*(*(*ListFront).getStudent()).getID())){
      //cout << "LOL2" << endl;
      (*Least) = (*(*(*ListFront).getStudent()).getID());
      //cout << (*Least) << endl;
      // cout << "Here2" << endl;
    }
    else{
      
    }
      }
      if((*ListFront).getNext() != NULL){ // recursive function that goes through all the nodes and finds the least value
	
	SortList((*ListFront).getNext(), SortedFront, counterSix, Least, Beginning, counterSeven,  previous, counterThree, counterFour, counterFive, counterNine, counterTen, size, ListFront, sizeTwo, LSize, counterThis);
    }
      else{
	//cout << "Here3" << endl;
	//cout << (*(*(*MatchGPA((*Beginning).getNext(), Least, counterSeven)).getStudent()).getID()) << endl;
	(*counterSeven) = 0;
	//cout << (*Least) << endl;
	(*getEnd(SortedFront)).setNext(MatchGPA((*Beginning).getNext(), Least, counterSeven)); // put the node with the least value into the sorted list
	
	(*counterSeven) = 0;
	
	(*previous).setStudent(NULL);
	(*counterThree) = 0;
	  (*counterFour) = 0;
	  (*counterFive) = 0;
	  //cout << "Here4" << endl;
	  Ignore((*Beginning).getNext(), Least, previous, counterThree, counterFour, counterFive, LSize); // ignores the least node in the unsorted header so it wont get picked again
	  (*previous).setStudent(NULL);
	//cout << "Here5" << endl;
	(*counterThree) = 0; // reset some counters
	  (*counterFour) = 0;
	  (*counterFive) = 0;
	  (*counterTen) = 0;
	  (*size) = 0;
	  
	  (*counterTen) = 0;
	  (*size) = 0;
	  //cout << (*LSize) << endl;
	  
	  (*sizeTwo) = 0;
	  (*counterTen) = 0;
	  //cout << "Here6" << endl;
	  // Print(SortedFront, counterTen);
	  (*counterTen) = 0;
	  //cout << (*counterTen) << endl;
	  //cout << (*sizeTwo) << endl;
	  // cout << (*Size(SortedFront, counterTen, sizeTwo)) << endl;
	  (*sizeTwo) = 0;
	  //cout << (*Size(ListFront, counterTen, sizeTwo)) << endl;
	  (*counterTen) = 0;
	  (*sizeTwo) = 0;
	  //cout << "Here7" << endl;
	  if((*LSize) != (*Size(SortedFront, counterTen, sizeTwo))){ // checks if the size of the sorted list does not match the initial size of the unsorted list
	    //cout << "Here8" << endl;
	    (*counterTen) = 0;
	  (*sizeTwo) = 0;
	    (*counterSix) = 0;
	    (*counterNine) = 0;
	    SortList((*Beginning).getNext(), SortedFront, counterSix, Least, Beginning, counterSeven,  previous, counterThree, counterFour, counterFive, counterNine, counterTen, size, ListFront, sizeTwo, LSize, counterThis); // keep on sorting(recursive)
	  }
	  (*counterTen) = 0;
	  }
      }
    

}
Node* MatchGPA(Node* ListFront,int* Least, int* counterSeven){// This actuall was supposed to be named match ID because it matches the ID of the student to the corresponding node
  if((*counterSeven) == 0){ // ignore header
      
    (*counterSeven)++;

    MatchGPA((*ListFront).getNext(), Least, counterSeven);
  }
    else{
      if((*Least) == (*(*(*ListFront).getStudent()).getID())){// if matching ID return that node
	return ListFront; 
      }
      if((*ListFront).getNext() != NULL){ // else continue through the list it is a recursive function	
     MatchGPA((*ListFront).getNext(), Least, counterSeven); 
      }
      }
    

}
void Duplicate(Node* Header, Node* DuplicateHeader, int* counterEight){ //make duplicate header the same as the normal header
  
  (*DuplicateHeader).setNext((*Header).getNext()); // matches the lists
  
  if((*Header).getNext() != NULL){  // recursive function that goes through teh list until all the nodes are matched
	      Duplicate((*Header).getNext(), (*DuplicateHeader).getNext(), counterEight); 
      }

	    

}
int* Size(Node* Header, int* counterTen, int* size){ // gets size of the list
  
  if((*counterTen) == 0){ // ignore header
    (*size) = 0;
    (*counterTen)++;
    Size((*Header).getNext(), counterTen, size);
  }
  else{
    (*size)++; // increments size
    if((*Header).getNext() != NULL){ // recusive function that goes through the whole list
	Size((*Header).getNext(), counterTen, size);
      }
      else{
      (*counterTen) = 0;
      return size;
      }
      
  }
  }
void Ignore(Node* ListTail, int* DeleteID, Node* previous, int* counterThree, int* counterFour, int* counterFive, int* LSize){ // Identical to the delete funciton except that it does not delete the node it only changes the connection in the list(used in the sort funciton)
  if((*counterThree) == 0){ // ignore header
    (*counterThree)++;
   previous = ListTail;
   Ignore((*ListTail).getNext(), DeleteID, previous, counterThree, counterFour, counterFive, LSize);
  }
  if((*(*(*ListTail).getStudent()).getID()) == (*DeleteID)){ // this is the node we want to ignore
    (*counterFour)++;
    if((*ListTail).getNext() != NULL){ // middle or beginning DLEETE note
	(*previous).setNext((*ListTail).getNext());
	(*ListTail).setNext(NULL); // ignores
	return;
      }
    else if(ListTail == NULL){ // end of list
      return;
    }
      else{
	
	
	(*previous).setNext(NULL);
	 
       
	return;
	
      }
  }
  else{
   
  }
  
  if((*ListTail).getNext() != NULL){ // recursive function that goes through all the list until it finds the node it wants to ignore
    previous = ListTail; 
    Ignore((*ListTail).getNext(), DeleteID, previous, counterThree, counterFour, counterFive, LSize); 
	}
  else{
  }
 
}
void CheckDuplicate(Node* header, bool* Dup, int* counterOne, int* DupID){ // checks if invalid input
  if((*counterOne) == 0){
    (*counterOne)++;
    //cout << "here" << endl;
    //Print(header);
    CheckDuplicate((*header).getNext(), Dup, counterOne, DupID);

    // cout << "here" << endl;
  }
    if((*(*(*header).getStudent()).getID()) == (*DupID)){
      //cout << "Dup" << endl;
    // cout << "here3" << endl;
    (*Dup) = true;
    return;
    }
  if((*header).getNext() != NULL){
    //cout << "here4" << endl;
    CheckDuplicate((*header).getNext(), Dup, counterOne, DupID);
  }
  else{
    //cout << "here5" << endl;
  //(*counterOne) = 3;
  //cout << (*counterOne);
  return;
  }
}

  
