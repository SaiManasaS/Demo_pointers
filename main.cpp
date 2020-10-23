/* Copyright (C) 2020 Sai Manasa S
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Description: This is a program used to demo use of pointers
 *
 * Revision History:
 * Initial version     : Oct 19th, 2020
 * Added more functions: Oct 20th, 2020
 * Added more functions: Oct 21st, 2020
 */

/*
(0,0)   (0,1)   (0,2)   (0,3)   (0,4)
  3       5       4       6       9
-------------------------------------
(1,0)   (1,1)   (1,2)   (1,3)   (1,4)
  2       3       7       8       5
-------------------------------------
(2,0)   (2,1)   (2,2)   (2,3)   (2,4)
  4       7       3       9       0
-------------------------------------
(3,0)   (3,1)   (3,2)   (3,3)   (3,4)
  1       2       6       2       1
-------------------------------------
(4,0)   (4,1)   (4,2)   (4,3)   (4,4)
  6       9       1       3       2
-------------------------------------
*/

#include <iostream>

using namespace std;

int guest_multiply(int in_a, int in_b)
{
	return (in_a * in_b);
}

int host(int (pf)(int a, int b)) // Learn to use this syntax
{
	int ret_val = pf(12, 13);
	return ret_val;
}

int guest_func2(int x, int y)
{
	return (x+y);
}

int host_func2(int (*pf)(int, int))
{
	int a = 10, b = 20;
	int ret_val = (pf) (a, b);
	cout << "Inside the host function2" << endl;
	return ret_val;
}

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

void demo_doubleDarr()
{
	//             r  c
	int doubledarr[2][2] = {{3, 4}, {5 , 6}};
	int *parray;

	cout << "doubledarr[1][1]:" << doubledarr[1][1] << endl;
	cout << "*doubledarr[1]:" << *doubledarr[1] << endl;
	cout << "*(*(doubledarr + 1))" << *(*(doubledarr + 1)) << endl;
	cout << "*(*(doubledarr + 1) + 1):" << *(*(doubledarr + 1) + 1) << endl;
	cout << "*(*(doubledarr + 0) + 1):" << *(*(doubledarr + 0) + 1) << endl;

/*
	for(r = 0; r < 2; r++)
	{
		for(c = 0; c < 2; c++)
		{
			//cout << doubledarr[r][c] << " ";
			cout << *(*(doubledarr + r) + c ) << " ";
		}
		cout << endl;
	}
*/
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
	char mystring[] = {'h', 'e', 'l', 'l' , 'o', '\0'};

	int i = 0, r = 0, c = 0;
	int *parray;
	char *pchararray;

	parray = &intarray[0];
	//parray = intarray;

	cout << "Value pointed to by parray: " << *parray << endl;
	cout << "Value pointed to by parray+1: " << *(parray+1) << endl;
	cout << "Value pointed to by parray+2: " << *(parray+2) << endl;
	//cout << "Value pointed to by parray+2: " << *(parray+3) << endl; //THIS IS ILLEGAL  MEMORY ACCESS VIOLATION

	parray = intarray;

	cout << "Value pointed to by intarray: " << *intarray << endl;
	cout << "Value pointed to by (intarray+1): " << *(intarray + 1) << endl; // This is pointer arithmetic
	cout << "Value pointed to by (intarray+2): " << *(intarray + 2) << endl;

	cout << "Value pointed to by intarray: " << *intarray << endl;
	cout << "Value pointed to by intarray + 1: " << *intarray + 10 << endl; // This is NOT pointer arithmetic
	cout << "Value pointed to by intarray + 2: " << *intarray + 20 << endl;
	
	cout << "sizeof(intarray): " << sizeof(intarray) << endl;

	pchararray = mystring; // Arrays behave like pointers
	cout << "Value at pchararray: " << *pchararray << endl;

	// *mystring gives the value at the first address of the array mystring
	cout << "Value at *mystring: " << *mystring << endl; // Arrays behave like pointers
	cout << "Value at mystring: " << mystring << endl; // Arrays behave like pointers

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
	int ret_val;
/*
	cout << "a: " << a << endl;
	demo_callbyval(a);
	cout << "a: " << a << endl;

	cout << "b: " << b << endl;
	demo_callbyref(&b);
	cout << "b: " << b << endl;

	//demo_ptrarrays();

	demo_doubleDarr();
*/
	ret_val = host(guest_multiply);
	cout << "ret_val:" << ret_val << endl;

	a = host_func2(guest_func2);
	cout << "a after experimenting with passing pointer to function:" << a << endl;


	while(1);
}