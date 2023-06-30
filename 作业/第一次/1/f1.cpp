#include <iostream>
 extern int x;

 void foo() {
     int x;
     x = 10;
 }

 int main() {
     foo();
     std::cout << "x = " << x << std::endl;
     return 0;
 }