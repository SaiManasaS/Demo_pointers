/* Copyright (C) 2020 Sai Manasa S
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Description: This is a program used to demo use of pointers
 *
 * Revision History:
 * Initial version: Oct 20th, 2020
 */

#include <iostream>

using namespace std;

/*int guest_func(int x, int y)
{
	return (x+y);
}

int host_func(int (*pf)(int, int))
{
	int a = 10, b = 20;
	int ret_val = (*pf) (a, b);
	cout << "Inside the host function" << endl;
	return ret_val;
}
*/

/*****************************************************/
// Function:     demo_callbyval()
// Description:  This function demos the use of pointers
//               to demo call by value in functions
// Inputs:       integer value
// Return value: None
/*****************************************************/
void demo_callbyval(int a)
{
	int afunc = a;
	
	afunc = 99;
	cout << "afunc: " << afunc << endl;
}

/*****************************************************/
// Function:     demo_callbyref()
// Description:  This function demos the use of pointers
//               to demo call by reference in functions
// Inputs:       integer pointer
// Return value: None
/*****************************************************/
void demo_callbyref(int *b)
{
	int* bfunc = b;
	
	*bfunc = 82;
	cout << "*bfunc: " << *bfunc << endl;
}

void demo_ptrarrays()
{
	int intarray[] = {1, 2, 3};
	int i = 0;
	int *parray;

	parray = &intarray[0];
	//parray = intarray;

	cout << "Value pointed to by parray: " << *parray << endl;
	cout << "Value pointed to by parray+1: " << *(parray+1) << endl;
	cout << "Value pointed to by parray+2: " << *(parray+2) << endl;

	for(i = 0; i < 3; i++)
	{

	}

	for(i = 0; i < 3; i++)
	{
		cout << "Array element: " << intarray[i] << " " ;
	}

}


/*****************************************************/
// Function:     demo_ptr_asstmt()
// Description:  This function demos the use of pointers
// Inputs:       None
// Return value: None
/*****************************************************/
void demo_ptr_asstmt()
{
	int a = 10, b = 19;
	int *ptr = &a;
	cout << "*ptr: " << *ptr << endl;

	ptr = &b;
	cout << "*ptr: " << *ptr << endl;

	*ptr = 20;
	cout << "*ptr: " << *ptr << endl;

	cout << "b: " << b << endl;

	cout << "ptr: " << ptr << endl;

	ptr = (int*) 0x00078EF0; // DONT' DO THIS!!
	cout << "ptr: " << ptr << endl;

	*ptr = 64; // DON'T DO THIS!!
	cout << "*ptr: " << *ptr << endl;

}

/*****************************************************/
// Function:     main()
// Description:  This is the main() function for entry
//               into program execution
// Inputs:       None
// Return value: None
/*****************************************************/
void main()
{
	int a = 19, b = 28;
	//demo_ptr_asstmt();

/*
	cout << "a: " << a << endl;
	demo_callbyval(a);
	cout << "a: " << a << endl;

	cout << "b: " << b << endl;
	demo_callbyref(&b);
	cout << "b: " << b << endl;
*/
	demo_ptrarrays();
/*
	a = host_func(*guest_func);
	cout << "a after experimenting with passing pointer to function:" << a << endl;
*/

	while(1);
}