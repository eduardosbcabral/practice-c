// c implementation made by me reading jwasham code

#ifndef PROJECT_DARRAY_H
#define PROJECT_DARRAY_H

#include <assert.h>
#include <stdbool.h>

const int kMinCapacity = 16;
const int kGrowthFactor = 2;
const int kShrinkFactor = 4;

typedef struct ImplementationArray {
  int size;
  int capacity;
  int *data;
} DArray;

// array functions

// Create a new DArray (vector in our case) to accommodate the given initial capacity
DArray *darray_new(int capacity);
void darray_destroy(DArray *arrayPointer);

// Checks to see if resizing is needed to support the candidate_size and resizes to accommodate.
void darray_resize_for_size(DArray *arrayPointer, int candidate_size);
// Determines the actual capacity (in terms of the power of growth factor)
// required to accommodate a given capacity
int darray_determine_capacity(int capacity);
// Increases the array size to size determined by growth factor
void darray_upsize(DArray *arrayPointer);
// Decreases the array size to suze determined by growth factor
void darray_downsize(DArray *arrayPointer);
// Returns the number of elements managed in the array
int darray_size(DArray *arrayPointer);
// Appends the givem item to the end of the array
void darray_push(DArray *arrayPointer, int item);
// Prints public information about the array for debug purposes
void darray_print(DArray *arrayPointer);
// Returns the actual capacity the array cab accommodate
int darray_capacity(DArray *arrayPointer);
// Returns the value stored at the given index
int darray_at(DArray *arrayPointer, int index);
// Returns true if array is empty
bool darray_is_empty(DArray *arrayPointer);
// Inserts the given value at the given index, shifting
// current and trailing elements to the right
void darray_insert(DArray *arrayPointer, int index, int value);
// Prepends the given value to the array, shifting trailing elements to the right
void darray_prepend(DArray *arrayPointer, int value);
// Removes the last item from thje array and returns its value
int darray_pop(DArray *arrayPointer);
// Deletes the item stored at the given index, shifting trailing elements to the left
void darray_delete(DArray *arrayPointer, int index);
// Removes the given value from the array, even if it appears more than once
void darray_remove(DArray *arrayPointer, int value);
// Returns the index of the first occurrence of the given value in the array
int darray_find(DArray *arrayPointer, int value);
// Checks to see if given value is valid for memory, and exits if so
void check_address(void *p);

// tests

void run_all_tests();

void test_append();
void test_size_init();
void test_append_past_capacity();
void test_capacity();
void test_empty();
void test_resize();
void test_at();
void test_insert();
void test_prepend();
void test_pop();
void test_remove();
void test_find_exists();
void test_find_not_exists();

#endif