/* Member pointers example, compile with: g++ main.cpp -o main -Wno-format */

#include <iostream>
#include <cstdio>

using namespace std;

class A {
public:
  virtual void meth(int x) { cout << "A::meth() called." << endl; }
};
class B : public A {
public:
  void meth(int x) { cout << "B::meth() called." << endl; }
};
class C : public A {
public:
  void meth(int x) { cout << "C::meth() called." << endl; }
};

void meth(int x) { cout << "Global meth() called." << endl; }

int main(int argc, char** argv) {
  cout << "Method pointer test." << endl;

  A a;
  B b;
  C c;
  void (A::*m)(int x);
  void (*g)(int x);

  m = &A::meth;
  (a.*m)(10);
  (b.*m)(10);
  (c.*m)(10);

  g = &meth;
  (*g)(10);

  cout << "Raw pointer values: " << endl;
  printf("g: %p\n", g);
  printf("m: %p\n", m);

  return 0;
}
