#include <iostream>
#include "myarray.h"

myarray::myarray(int s)
{ size = s;
  elt = new int[size];
 
}
myarray::~myarray(){
  delete [] elt;
}