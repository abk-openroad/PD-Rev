/**************************************************************************
 * Copyright(c) 2018 Regents of the University of California
 *              Kwangsoo Han, Andrew B. Kahng and Sriram Venkatesh
 * Contact      kwhan@ucsd.edu, abk@cs.ucsd.edu, srvenkat@ucsd.edu
 * Affiliation: Computer Science and Engineering Department, UC San Diego,
 *              La Jolla, CA 92093-0404, USA
 *
 *************************************************************************/

#include "mystring.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

char* string_to_char(string str)
{
	char * writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';
	//delete [] writable;
	// don't forget to free the string after finished using it
	return writable;
}

vector<string> split(string input, string delim)
{
	//cout<<input<<endl;
	vector<string> result;
	char *charArray = string_to_char(input);
	char *p = strtok(charArray, delim.c_str());
	while (p) {
		//printf ("Token: %s\n", p);
		result.push_back(string(p));
		p = strtok(NULL, delim.c_str());
	}
	//cout<<strlen(charArray)<<endl;
	delete [] charArray;
	// don't forget to free the string after finished using it
	//cout<<strlen(charArray)<<endl;
	//print_vector_string(result);
	return result;
}

void print_vector_string(vector<string> input){
	cout << "index\tvalue" << endl;
	for (unsigned i=0; i < input.size(); i++)
    	cout << i << "\t" << input[i] << endl;
	// uncommet to enable debug mode on parser.cpp
}

bool string_is_number(string input)
{
	stringstream convertor;
    int number;

    convertor << input;
    convertor >> number;

    if(convertor.fail())
    {
    	// input is not a number!
    	//cout << "Not a Number!";
    	return false;
    }
    else
    	return true;
}

bool string_is_integer_greater_than_zero(string input)
{
	int tmp=atoi(input.c_str());
	if(tmp>0)
		return true;
	else
		return false;
}

int string_to_int(string input)
{
	return atoi(input.c_str()); // cannot tell if it is zero or fail
}

bool string_is_floating_not_negative(string input)
{
	float tmp=atof(input.c_str());
	if(tmp>=0&&string_is_number(input)==1)
		return true;
	else
		return false;
}

float string_to_float(string input)
{
	return atof(input.c_str()); // cannot tell if it is zero or fail
}
