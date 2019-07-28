// c implementation made by me reading jwasham code

// vector implementation
#include <stdio.h>
#include <stdlib.h>
#include "darray.h"

DArray *darray_new(int capacity) {
	int true_capacity = darray_determine_capacity(capacity);

	DArray *array = malloc(sizeof(DArray));
	check_address(array);

	array->size = 0;
	array->capacity = true_capacity;
	array->data = (int *)malloc(sizeof(int) * true_capacity);
	check_address(array->data);

	return array;
}

void darray_resize_for_size(DArray *arrayPointer, int candidate_size) {
	if (arrayPointer->size < candidate_size) { // growing
		if (arrayPointer->size == arrayPointer->capacity) {
			darray_upsize(arrayPointer);
		}
	} else if (arrayPointer->size > candidate_size) { // shrinking
		if (arrayPointer->size < arrayPointer->capacity / kShrinkFactor) {
			darray_downsize(arrayPointer);
		}
	} // will not be equal, if so, will do nothing
}

void darray_upsize(DArray *arrayPointer) {
	int old_capacity = arrayPointer->capacity;
	int new_capacity = darray_determine_capacity(old_capacity);

	int *new_data = (int *)malloc(sizeof(int) * new_capacity);
	check_address(new_data);

	for (int i = 0; i < old_capacity; i++) {
		*(new_data + i) = *(arrayPointer->data + i);
	}

	free(arrayPointer->data);

	arrayPointer->data = new_data;
	arrayPointer->capacity = new_capacity;
}

void darray_downsize(DArray *arrayPointer) {
	int old_capacity = arrayPointer->capacity;
	int new_capacity = arrayPointer->capacity / kGrowthFactor;

	if (new_capacity < kMinCapacity) {
		new_capacity = kMinCapacity;
	}

	if (new_capacity != old_capacity) {
		int *new_data = (int *)malloc(sizeof(int) * new_capacity);
		check_address(new_data);

		for (int i = 0;  i < arrayPointer->size; i++) {
			*(new_data + i) = *(arrayPointer->data + i);
		}

		free(arrayPointer->data);

		arrayPointer->data = new_data;
		arrayPointer->capacity = new_capacity;
	}
}

int darray_determine_capacity(int capacity) {
	const int kMinInitialCapacity = 1;
	int true_capacity = kMinCapacity;

	if (capacity < kMinInitialCapacity) {
		exit(EXIT_FAILURE);
	}

	while (capacity > true_capacity / kGrowthFactor) {
		true_capacity *= kGrowthFactor;
	}

	return true_capacity;
}

int darray_size(DArray *arrayPointer) {
	return arrayPointer->size;
}

void darray_destroy(DArray *arrayPointer) {
	free(arrayPointer->data);
	free(arrayPointer);
}

void darray_push(DArray *arrayPointer, int item) {
	darray_resize_for_size(arrayPointer, arrayPointer->size + 1);

	*(arrayPointer->data + arrayPointer->size) = item;
	(arrayPointer->size)++;
}

void darray_print(DArray *arrayPointer) {
	printf("Size: %d\n", arrayPointer->size);
	printf("Capacity: %d\n", arrayPointer->capacity);

	printf("Items:\n");
	for (int i = 0; i < arrayPointer->size; i++) {
		printf("%d: %d\n", i, *(arrayPointer->data + i));
	}

	printf("-----------\n");
}

int darray_capacity(DArray *arrayPointer) {
	return arrayPointer->capacity;
}

bool darray_is_empty(DArray *arrayPointer) {
	return arrayPointer->size == 0;
}

int darray_at(DArray *arrayPointer, int index) {
	if (index < 0 || index > arrayPointer->size - 1) {
		exit(EXIT_FAILURE);
	}

	return *(arrayPointer->data + index);
}

void darray_insert(DArray *arrayPointer, int index, int value) {
	if (index < 0 || index > arrayPointer->size - 1) {
		exit(EXIT_FAILURE);
	}

	darray_resize_for_size(arrayPointer, arrayPointer->size + 1);

	// shift items to the right

	int end_index = arrayPointer->size - 1;

	for (int i = end_index + 1; i > index; i--) {
		*(arrayPointer->data + i) = *(arrayPointer->data + i - 1);
	}

	arrayPointer->size += 1;
}

void darray_prepend(DArray *arrayPointer, int value) {
	darray_insert(arrayPointer, 0, value);
}

int darray_pop(DArray *arrayPointer) {
	if (arrayPointer->size == 0) {
		exit(EXIT_FAILURE);
	}

	darray_resize_for_size(arrayPointer, arrayPointer->size - 1);

	int popped_value = *(arrayPointer->data + arrayPointer->size - 1);
	arrayPointer->size--;

	return popped_value;
}

void darray_delete(DArray *arrayPointer, int index) {
	if (index < 0 || index >= arrayPointer->size) {
		exit(EXIT_FAILURE);
	}

	darray_resize_for_size(arrayPointer, arrayPointer->size - 1);

	int end_index = arrayPointer->size - 1;

	for (int i = index; i < end_index; i++) {
		*(arrayPointer->data + i) = *(arrayPointer->data + i + 1);
	}

	(arrayPointer->size)--;
}

void darray_remove(DArray *arrayPointer, int value) {
	for (int i = 0; i < arrayPointer->size; i++) {
		int check_value = *(arrayPointer-> data + i);
		if (check_value == value) {
			darray_delete(arrayPointer, i);
			i--; // to recheck the index we just copied data into
		}
	}
}

int darray_find(DArray *arrayPointer, int value) {
	int found_index = -1;

	for (int i = 0; i < arrayPointer-> size; i++) {
		if (*(arrayPointer->data + i) == value) {
			found_index = i;
			break;
		}
	}

	return found_index;
}

void check_address(void *p) {
	if (p == NULL) {
		printf("Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
	}
}

//============= tests =============

void run_all_tests() {
	void test_size_init();
	void test_append();
	void test_empty();
	void test_resize();
	void test_at();
	void test_insert();
	void test_prepend();
	void test_pop();
	void test_remove();
	void test_find_exists();
	void test_find_not_exists();
}

void test_size_init() {
	DArray *arrayPointer = darray_new(5);
	int initial_size = darray_size(arrayPointer);
	assert(initial_size == 0);
	darray_destroy(arrayPointer);
}

void test_append() {
	DArray *arrayPointer = darray_new(2);
	darray_push(arrayPointer, 2);
	darray_push(arrayPointer, 12);
	int new_size = darray_size(arrayPointer);
	assert(new_size == 2);
	darray_destroy(arrayPointer);
}

void test_resize() {
	DArray *arrayPointer = darray_new(2);

	int old_capacity = darray_capacity(arrayPointer);
	assert(old_capacity == 16);

	// forces a resize up
	for (int i = 0; i < 18; ++i) {
		darray_push(arrayPointer, i + 1);
	}

	assert(darray_capacity(arrayPointer) == 32);

	// forces a resize down
	for (int j = 0; j < 15; ++j) {
		darray_pop(arrayPointer);
	}

	assert(darray_capacity(arrayPointer) == 16);

	darray_destroy(arrayPointer);
}

void test_empty() {
	DArray *arrayPointer = darray_new(2);
	bool empty = darray_is_empty(arrayPointer);
	assert(empty == true);
	darray_push(arrayPointer, 1);
	empty = darray_is_empty(arrayPointer);
	assert(empty == false);
	darray_destroy(arrayPointer);
}

void test_at() {
	DArray *arrayPointer = darray_new(2);
	for (int i = 0; i < 12; ++i) {
		darray_push(arrayPointer, i + 3);
	}
	assert(darray_at(arrayPointer, 6) == 9);
	darray_destroy(arrayPointer);
}

void test_insert() {
	DArray *arrayPointer = darray_new(2);
	for (int i = 0; i < 5; ++i) {
		darray_push(arrayPointer, i + 5);
	}
	darray_insert(arrayPointer, 2, 47);
	assert(darray_at(arrayPointer, 2) == 47);
	assert(darray_at(arrayPointer, 3) == 7);
	darray_destroy(arrayPointer);
}

void test_prepend() {
	DArray *arrayPointer = darray_new(2);
	for (int i = 0; i < 3; ++i) {
		darray_push(arrayPointer, i + 1);
	}
	darray_prepend(arrayPointer, 15);
	assert(darray_at(arrayPointer, 0) == 15);
	assert(darray_at(arrayPointer, 1) == 1);
	darray_destroy(arrayPointer);
}

void test_pop() {
	DArray *arrayPointer = darray_new(2);
	for (int i = 0; i < 3; ++i) {
		darray_push(arrayPointer, i + 1);
	}
	assert(arrayPointer->size == 3);
	for (int j = 0; j < 3; ++j) {
		darray_pop(arrayPointer);
	}
	assert(darray_is_empty(arrayPointer) == 1);
	darray_destroy(arrayPointer);
}

void test_remove() {
	DArray *arrayPointer = darray_new(2);
	darray_push(arrayPointer, 12);
	darray_push(arrayPointer, 3);
	darray_push(arrayPointer, 41);
	darray_push(arrayPointer, 12);
	darray_push(arrayPointer, 12);
	darray_remove(arrayPointer, 12);
	assert(darray_size(arrayPointer) == 2);
	darray_destroy(arrayPointer);
}

void test_find_exists() {
	DArray *arrayPointer = darray_new(2);
	darray_push(arrayPointer, 1);
	darray_push(arrayPointer, 2);
	darray_push(arrayPointer, 3);
	darray_push(arrayPointer, 4);
	darray_push(arrayPointer, 5);
	assert(darray_find(arrayPointer, 1) == 0);
	assert(darray_find(arrayPointer, 4) == 3);
	assert(darray_find(arrayPointer, 5) == 4);
	darray_destroy(arrayPointer);
}

void test_find_not_exists() {
	DArray *arrayPointer = darray_new(2);
	darray_push(arrayPointer, 1);
	darray_push(arrayPointer, 2);
	darray_push(arrayPointer, 3);
	assert(darray_find(arrayPointer, 7) == -1);
	darray_destroy(arrayPointer);
}