#include <iostream> // this is the .cpp file for the student class
#include "Student.h"
#include<cstring>
using namespace std;

Student::Student(){ // constructor

}
Student::~Student(){ // destructor
  delete name;
  delete id;
    delete gpa;
}
void Student::setName(char* n){ // set the name variable
  name = n;
}
char* Student::getName(){ // gets the name
  return name;
}
int* Student::getID(){ // gets the id
  return id;
}
void Student::setID(int* i){ // sets the id variable
  id = i;
}
float* Student::getGPA(){ // gets the gpa
  return gpa;
}
void Student::setGPA(float* g){ // set the gpa variable
  gpa = g;
}
