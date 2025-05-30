#include "util.hpp"

using std::cout;
using std::endl;

Base *generate(void)
{
	unsigned int t = time(NULL);
	Base *result = 0;
	t ^= (t << 13);
	t ^= (t >> 17);
	t ^= (t << 5);
	t %= 3;

	switch (t)
	{
		case 0:
			result = new A();
			cout << "Generated A" << endl;
			break;
		case 1:
			result = new B();
			cout << "Generated B" << endl;
			break;
			default:
			result = new C();
			cout << "Generated C" << endl;
	}
	return (result);
}

void identify (Base *p)
{
	if (dynamic_cast<A *>(p))
		cout << "Object pointed to Class A." << endl;
	else if (dynamic_cast<B *>(p))
		cout << "Object pointed to Class B." << endl;
	else if (dynamic_cast<C *>(p))
		cout << "Object Pointed to Class C." << endl;
	else
		cout << "None of the object pointing to A/B/C Classes!" << endl;
}

void identify (Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		cout << "Identified class: Class A" << endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Unknown class A error: " << e.what() << '\n';
	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		cout << "Identified class: Class B" << endl;
		(void)b;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Unknown class B error: " << e.what() << '\n';
	}
	
	try
	{
		C &c = dynamic_cast<C &>(p);
		cout << "Identified class: Class C" << endl;
		(void)c;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Unknown class C error: " << e.what() << '\n';
	}
}