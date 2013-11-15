/*
* hello.cpp
* Ahoj Svete!
*/

#include <iostream>
using namespace std;

int main ( int argc, char * argv [] )
{
cout << "Hello world!\n";

#ifndef __PROGTEST__
  system ( "pause" ); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
  return 0;
} 