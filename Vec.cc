// Vec.cc
#include "Vec.h"
#include <algorithm>

using namespace std;

Vec::Vec()
{
	array_current_size = array_limit = 0;
	pointer_to_data = 0;
}

// Constructor
Vec::Vec(int a)
{
	array_current_size = 0;
	array_limit = a;

	// Allocate new memory for array.
	pointer_to_data = new double[array_limit];

}
// Overloading the copy constructor.
Vec::Vec(const Vec& vec_to_copy)
{
	array_current_size = vec_to_copy.array_current_size;
	array_limit = vec_to_copy.array_limit;

	// Allocate new memory for array.
	pointer_to_data = new double[array_limit];

	// Copy data across.
	for (int i = 0; i != array_current_size; ++i) {
		pointer_to_data[i] = vec_to_copy.pointer_to_data[i];
	}
}
// Destructor
Vec::~Vec()
{
	// Free array memory
	delete[] pointer_to_data;
	// Set pointer to null
	pointer_to_data = 0;
	array_current_size = array_limit = 0;
} 
// Overloading the assignment operator.
Vec& Vec::operator=(const Vec& rhs)
{
	// Check for self-assignment.
	if (&rhs != this) {
		// Free lhs array memory.
		delete[] pointer_to_data;

		// Allocate new memory for lhs array.
		array_current_size = rhs.array_current_size;
		array_limit = rhs.array_limit;
		pointer_to_data = new double[array_limit];

		// Copy rhs data across.
		for (int i = 0; i != array_current_size; ++i) {
			pointer_to_data[i] = rhs.pointer_to_data[i];
		}
	}		

	return *this;
}
// Overloading the index operator
double& Vec::operator[](int i)
{
	return pointer_to_data[i];
}
// push_back(val) - Append input values - If array full call grow() 
void Vec::push_back(const double& val) {
	// Initially array_current_size == array_limit (both 0 from default constructor)
	if(array_current_size == array_limit) {
		grow();
	}
	pointer_to_data[array_current_size] = val;
	array_current_size++; // Each value input will increase the array_current_size
}
// grow() - Increase array limit and copy array
void Vec::grow() {
	// Allocates a new array with twice the space
	if(array_limit != 0) {
		// Assign new value to array_limit - double if not 0
		array_limit *= 2;
	} else {
		// Assign new value to array_limit - from 0 to 1
		array_limit = 1;
	}
	// Allocate new memory for array.
	double* temp_data = new double[array_limit];	// Allocation
	// Copy data across.
	for (int i = 0; i != array_current_size; ++i) {
		temp_data[i] = pointer_to_data[i];	
	}
	// Delete old array - avoid memory leak - Deallocation
	// Free array memory
	delete[] pointer_to_data;
	// Set pointer to point to new memory locations
	pointer_to_data = temp_data;
}
