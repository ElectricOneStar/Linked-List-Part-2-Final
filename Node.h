// Node Header File

#ifndef NODE_H
#define NODE_H
#include "Student.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Node {
 public:
  Node();
  ~Node();
  void setStudent(Student*);
  Student* getStudent();
  void setNext(Node* NextNextNode);
  Node* getNext();
 private:
  Student* student;
  Node* nextNode;

};

#endif
