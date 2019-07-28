// c implementation made by me reading jwasham code

#include <stdio.h>
#include <stdlib.h>
#include "darray.h"
#include "darray.c"

void run_example();

// Implements a vector (called DArray) from a C array

int main(int argc, char* argv[]) {
  run_all_tests();
  run_example();

  return EXIT_SUCCESS;
}

void run_example() {
    int capacity = 0;

    printf("Enter many numbers would you like to store: ");
    scanf("%d", &capacity);

    printf("You'll be storing %d numbers.\n", capacity);

    // make it so

    DArray* arrayPointer = darray_new(capacity);

    for (int d = 1; d <= capacity; ++d) {
      darray_push(arrayPointer, d);
    }

    int insert_value = 999;
    printf(" - Inserting %d at index %d.\n", insert_value, capacity - 1);
    darray_insert(arrayPointer, capacity - 1, insert_value);

    printf(" - Prepending %d.\n", 12);
    darray_prepend(arrayPointer, 12);

    printf(" - Popping an item: %d\n", darray_pop(arrayPointer));

    darray_print(arrayPointer);

    int index_to_remove = darray_size(arrayPointer) - 3;
    printf(" - Deleting from index %d\n", index_to_remove);
    darray_delete(arrayPointer, index_to_remove);

    darray_push(arrayPointer, 12);
    darray_push(arrayPointer, 12);

    darray_print(arrayPointer);

    printf(" - Deleting 12s\n");

    darray_remove(arrayPointer, 12);

    darray_print(arrayPointer);

    darray_destroy(arrayPointer);
}