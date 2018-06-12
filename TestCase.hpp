#pragma once
#ifndef TEST_CASE_H
#include <string>
#include <stdio.h>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>

using namespace std;

class TestCase
{
private:
	string name;
	size_t succeed;
	size_t faild;
	size_t total;
	ostream* output;
public:

	TestCase(const string st, ostream& myStream);

	template<typename T>
	inline TestCase& check_equal(T a, T b)
	{// MyStrct(5) should equal MyStrct(5)!
		total++;
		if (a == b)
		{
			succeed++;
		}
		else
		{
			*output << name << ": Failure in test #" << total << ": " << a << " should be equal " << b << "!" << endl;
			faild++;
		}
		return *this;
	}
	
	template<typename T>
	TestCase& check_different(T a, T b)
	{//OtherStruct(5) should differ than OtherStruct(6)!
		total++;
		if (!(a != b))
		{
			faild++;
			*output << name << ": Failure in test #" << total << ": " << a << " should differ than " << b << "!"  << endl;
		}
		else
		{
			succeed++;
		}
		return *this;
	}

	template<typename T>
	TestCase& check_output(T element, string desired)
	{//string value should be MyStruct(5) but is MyStrct(5)
		total++;
		std::stringstream ss;
		ss << element;
		if (!ss.str().compare(desired))
		{
			succeed++;
		}
		else
		{
			*output << name << ": Failure in test #" << total << ": string value should be " << desired << " but is " << ss.str() << "!" << endl;
			faild++;
		}
		return *this;
	}

	template<typename T, typename S>
	TestCase& check_function(S(*func) (T val), T element, S desired)
	{
		total++;
		S re = func(element);
		if (re == desired)
		{
			succeed++;
		}
		else
		{
			*output << name << ": Failure in test #" << total <<
				": Function should return " << desired <<
				" but returned " << re << "!" << endl;
			faild++;
		}
		return *this;
	}

	template<typename T, typename R>
	TestCase & check_function(R(*func)(const T &v), const T element, R desired)
	{
		total++;
		R re = func(element);
		if (re == desired)
		{
			succeed++;
		}
		else
		{
			*output << name << ": Failure in test #" << total <<
				": Function should return " << desired <<
				" but returned " << re << "!" << endl;
			faild++;
		}
		return *this;
	}

	template<typename T, typename R>
	TestCase & check_function(function<R(const T& v)> & f, const T elem, R desired)
	{
		total++;
		R re = f(elem);
		if (re == desired)
		{
			succeed++;
		}
		else
		{
			*output << name << ": Failure in test #" << total <<
				": Function should return " << desired <<
				" but returned " << re << "!" << endl;
			faild++;
		}
		return *this;
	}

	template<typename func, typename V, typename R>
	TestCase & check_function(func f, V elem, R desired)
	{
		total++;
		R re = f(elem);
		if (re == desired)
		{
			succeed++;
		}
		else
		{
			*output << name << ": Failure in test #" << total <<
				": Function should return " << desired <<
				" but returned " << re << "!" << endl;
			faild++;
		}
		return *this;
	}

	TestCase& print();

	~TestCase();
};

#endif // !TEST_CASE_H


