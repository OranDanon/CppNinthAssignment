#include "TestCase.hpp"



TestCase::TestCase(const string st, ostream& myStream): name(st), output(&myStream), succeed(0), faild(0), total(0)
{
}

TestCase& TestCase::print()
{
	*output << name << "Number of tests:" << total << "Faild:" << faild << "Succeed" << succeed << endl;
	return *this;
}

TestCase::~TestCase()
{
}

