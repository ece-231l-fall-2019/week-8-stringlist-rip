#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#if 1
#include "StringList.h"
#else
#include <list>
#include <string>
typedef std::list<std::string> StringList;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	StringList a;
	a.push_back("A");
	a.push_back("B");
	a.push_front("C");
	a.push_front("D");
	a.push_back("E");

	Assert(a.getSize() == 5, "size method");
	Assert(a.front() == "D", "front method");
	a.pop_front();
	Assert(a.front() == "C", "pop_front method");
	Assert(a.back() == "E", "back method");
	a.pop_back();
	Assert(a.back() == "B", "pop_back method");
	a.pop_front();
	Assert(a.front() == "A", "front method");
	a.pop_back();
	Assert(a.back() == "A", "back method");

	StringList x;
	x.push_back("H");
	x.push_back("e");
	x.push_back("l");
	x.push_back("l");
	x.push_back("o");
	x.push_back(" ");
	x.push_back("D");
	x.push_back("a");
	x.push_back("v");
	x.push_back("i");
	x.push_back("d");
	Assert(x.getSize() == 11, "size");
	x.printstr();
	x.reverse();
	Assert(x.front() == "d", "Test reverse");
	x.printstr();
	x.reverse();
	x.unique();
	Assert(x.getSize() == 10, "size");
	x.pop_back();
	Assert(x.back()== "i", "pop back");
	x.pop_front();
	Assert(x.front() == "e", "pop front");
	x.clear();
	Assert(x.empty() == true, "clear and empty");

	StringList y;
	y.push_back("C");
	y.push_back("h");
	y.push_back("a");
	y.push_back("s");
	y.push_back("e");

	StringList z;
	z=y;
	Assert(z.getSize() == y.getSize(), "Test operator =");
	z.reverse();
	z.pop_front();
	Assert(z.front() == "s", "pop front with reverse");
	z.pop_back();
	Assert(z.back() == "h", "pop back");

	StringList c;
	c.push_back("c");
	c.push_back("c");
	c.push_back("c");
	c.push_back("c");
	c.push_back("c");
	c.unique();
	Assert(c.getSize() == 1, "unique with 5 c's");

	StringList j;
	j.push_front("J");
	Assert(j.front() == "J", "push front");
	Assert(j.back() == j.front(), "checking to see if front and back == with 1 elm");
	j.push_back("E");
	j.push_back("R");
	j.push_back("R");
	j.push_back("E");
	j.push_back("Y");
	j.push_back(" ");
	j.push_back("G");
	j.push_back("A");
	j.push_back("R");
	j.push_back("C");
	j.push_back("I");
	j.push_back("A");
	Assert(j.getSize() == 13, "size");
	j.reverse();
	Assert(j.back() == "J", "reverse back");
	Assert(j.front() == "A", "reverse front");

StringList davidPlease;
davidPlease.push_back("c");
davidPlease.push_back("a");
davidPlease.push_back("n");
davidPlease.push_back(" ");
davidPlease.push_back("w");
davidPlease.push_back("e");
davidPlease.push_back(" ");
davidPlease.push_back("g");
davidPlease.push_back("e");
davidPlease.push_back("t");
davidPlease.push_back(" ");
davidPlease.push_back("e");
davidPlease.push_back("x");
davidPlease.push_back("t");
davidPlease.push_back("r");
davidPlease.push_back("a");
davidPlease.push_back(" ");
davidPlease.push_back("c");
davidPlease.push_back("r");
davidPlease.push_back("e");
davidPlease.push_back("d");
davidPlease.push_back("i");
davidPlease.push_back("t");
davidPlease.push_back(" ");
davidPlease.push_back("f");
davidPlease.push_back("o");
davidPlease.push_back("r");
davidPlease.push_back(" ");
davidPlease.push_back("a");
davidPlease.push_back(" ");
davidPlease.push_back("p");
davidPlease.push_back("r");
davidPlease.push_back("i");
davidPlease.push_back("n");
davidPlease.push_back("t");
davidPlease.push_back(" ");
davidPlease.push_back("m");
davidPlease.push_back("e");
davidPlease.push_back("t");
davidPlease.push_back("h");
davidPlease.push_back("o");
davidPlease.push_back("d");
davidPlease.push_back("?");
davidPlease.printstr();
	return 0;
}
