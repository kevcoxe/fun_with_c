#include <iostream>

using namespace std;


void doArrays() {
  int X = 3;
  int Y = 3;

  int numberGrid[][3] = {
    {0,2,4},
    {1,3,5},
    {6,7,9}
  };

  for (int i = 0; i < X; i++) {
    cout << i << ": [";
    for (int j = 0; j < Y; j++) {
      cout << " " << numberGrid[i][j];
    }
    cout << " ]" << endl;
  }

  return;
}


void inputOutput() {

  string name;
  cout << "Please enter your name: ";
  getline(cin, name);

  cout << "Thank you " << name << ", let's begin" << endl;


  int age;
  cout << "Please enter your age: ";
  cin >> age;

  bool over21 = age > 21;
  string over21text = over21 ? "are" : "are not";
  cout << "Thank you " << name << ", it looks like you " << over21text << " over 21" << endl;

  return;
}


void pointerStuff() {
  int a = 0;
  cout << "a is: " << a << endl;

  int *aptr = &a;
  cout << "pointer is pointing at: " << aptr << endl;
  cout << "value at pointer is: " << *aptr << endl;

  int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << "b is: " << b << endl;

  int *bptr = b;

  for (int i = 0; i < 10; i++) {
    cout << "-------------------------------------" << endl;
    cout << "index: " << i << endl;
    cout << "pointer is pointing at: " << bptr+i << endl;
    cout << "value at pointer is: " << *bptr+i << endl;
  }

  cout << "===============================" << endl;

  char c[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  cout << "c is: " << c << endl;

  char *cptr = c;

  for (int i = 0; i < 10; i++) {
    cout << "-------------------------------------" << endl;
    cout << "index: " << i << endl;
    cout << "pointer is pointing at: " << cptr[i] << endl;
    cout << "value at pointer is: " << *cptr+i << endl;
  }

  return;
}


class Person {
  public:
    int age;
    string firstName;
    string lastName;
    string fullName;

    Person() {
      age = 0;
      firstName = "John";
      lastName = "Doe";
      fullName = firstName + " " + lastName;
    }

    Person(int a, string f, string l) {
      age = a;
      firstName = f;
      lastName = l;
      fullName = firstName + " " + lastName;
    }

    void sayHi() {
      cout << "Hi, my name is " << fullName << endl;
    }
};


class Programmer : public Person {
  public:
    string title;

    Programmer() : Person() {
      title = "unemployed";
    }

    Programmer(int a, string f, string l, string t) : Person(a, f, l) {
      title = t;
    }

    void sayInfo() {
      sayHi();
      cout << "my title is: " << title << endl;

      return;
    }
};


void classStuff() {
  Person p1(27, "Billy", "Lolz");
  Person p2(28, "Rogger", "Taccos");
  Person p3;


  cout << "Fist to sign up was: " << p1.fullName << endl;
  cout << "Second to sign up was: " << p2.fullName << endl;
  cout << "third to sign up was: " << p3.fullName << endl;

  p1.sayHi();
  p2.sayHi();
  p3.sayHi();

  return;
}


void inheritanceStuff() {
  Programmer d1;
  d1.sayInfo();

  cout << endl;

  Programmer d2(25, "Bob", "Jones", "software developer");
  d2.sayInfo();

  return;
}


int main() {
  // inputOutput();
  // doArrays();
  // pointerStuff();
  // classStuff();
  // inheritanceStuff();

  return 0;
}
