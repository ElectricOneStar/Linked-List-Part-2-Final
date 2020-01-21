#ifndef STUDENT_H
#define STUDENT_H
#include <iostream> // header file for the student class
//#include "Node.h"
#include <cstdlib>
#include <cstring> // libraries
using namespace std;

class Student{ // student class
 public:
  Student(); // initailizes constuctor, destructor, and funcitons
  ~Student();
  void setName(char* n);
  char* getName();
  int* getID();
  void setID(int* i);
  float* getGPA();
  void setGPA(float* g);
 private:
  //  Node* node = new Node;
  char* name = new char; // name, ida, and gpa pointers variables initialized
  int* id = new int;
  float* gpa = new float;
};
#endif
