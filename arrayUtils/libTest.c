#include"lib.c"
#include<assert.h>
#include<stdio.h>

void test_create_array_util_should_return_a_array_util_struct(){
  ArrayUtil arr = create(4, 10);
  assert(arr.typeSize == 4);
  assert(arr.length == 10);
};

void test_areEqual_should_return_true_if_both_utils_are_equal(){
  ArrayUtil arr = create(1, 5);
  ArrayUtil arr2 = create(1, 5);
  assert(areEqual(arr, arr2) == 0);
};

void test_areEqual_should_return_false_if_both_utils_are_NOT_equal(){
  ArrayUtil arr = create(4, 4);
  *(int *)(arr.base) = 10;
  ArrayUtil arr2 = create(1, 4);
  assert(areEqual(arr, arr2) != 0);
};

void test_resize_should_modify_the_existing_array_util(){
  ArrayUtil arr = create(1,5);
  assert(arr.length == 5);
  arr = resize(arr, 10);
  assert(arr.length == 10);
};

void test_resize_should_copy_the_existing_array_element_into_resized_array(){
  ArrayUtil arr = create(1, 5);
  *(char *)(arr.base) = 65;
  arr = resize(arr, 3);
  assert(arr.length == 3);
  assert(*(char *)arr.base == 65);
};

void test_findIndex_should_return_the_index_of_serached_element(){
  ArrayUtil arr = create(1, 5);
  *(char *)(arr.base) = 65;
};

void test_areEqual_when_they_are_not_equal(){
  ArrayUtil a = create(4, 7);
  int * list_array = (int *)(a.base);
  list_array[0] = 10;
  ArrayUtil b = create(4, 10);
  assert(areEqual(a,b) != 0);
  dispose(a);
  dispose(b);
};

void test_areEqual_when_they_are_actually_Equal(){
  ArrayUtil a = create(4, 5);
  ArrayUtil b = create(4, 5);
  assert(areEqual(a,b) == 0);
  dispose(a);
  dispose(b);
};
void test_create(){
  ArrayUtil a = create(4, 5);

  assert(a.length == 5);
  assert(a.typeSize == 4);

  ArrayUtil util = create(4, 5);
    int * list_array = (int *)(util.base);
    list_array[0] = 10;
    list_array[1] = 20;
    list_array[2] = 30;
    list_array[3] = 40;
    list_array[4] = 50;
    assert(list_array[0] == 10);
    assert(list_array[3] == 40);
    assert(list_array[4] == 50);

    dispose(a);
    dispose(util);
};

void test_resize(){
  ArrayUtil util = create(4, 5);
  int * list_array = (int *)(util.base);
  list_array[0] = 10;
  list_array[1] = 20;
  list_array[2] = 30;
  list_array[3] = 40;
  list_array[4] = 50;

  assert(util.length == 5);
  ArrayUtil resized_util = resize(util, 7);
  assert(resized_util.length = 7);

  int * resized_list_array = (int *)(resized_util.base);
  assert(resized_list_array[4] == 50);
  assert(resized_list_array[5] == 0);
  assert(util.length == 5);

  assert(list_array[4] == 50);

  dispose(util);
}

void test_findIndex(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 1;
  list_array[1] = 2;
  list_array[2] = 3;
  list_array[3] = 4;
  list_array[4] = 5;

  int x = 1;
  int y = 2;
  int z = 14;

  assert(findIndex(a, &x) == 0);
  assert(findIndex(a, &y) == 1);
  assert(findIndex(a, &z) == -1);

  dispose(a);
};

void test_findFirst(){
  ArrayUtil a = create(4,5);
  int * list_array = a.base;
  list_array[0] = 12;
  list_array[1] = 2;
  list_array[2] = 34;
  list_array[3] = 4;
  list_array[4] = 5;

  int hint = 4;
  MatchFunc *match = &isEven;
  void * find = findFirst(a, match, &hint);
  int res = *(int *)find;
  assert(res == 12);
};


void test_findLast(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 12;
  list_array[1] = 25;
  list_array[2] = 34;
  list_array[3] = 45;
  list_array[4] = 5;
  
  assert(*(int *)findLast(a, &isEven, NULL) == 34);

  int x = 5;
  assert(*(int *)findLast(a, &isDivisible, &x) == 5);
};

void test_count(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 12;
  list_array[1] = 25;
  list_array[2] = 34;
  list_array[3] = 45;
  list_array[4] = 5;
  
  assert(count(a, &isEven, NULL) == 2);
  int x = 5;
  assert(count(a, &isDivisible, &x) == 3);
};

void test_filter_should_return_count_of_filtered_elements(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 12;
  list_array[1] = 25;
  list_array[2] = 34;
  list_array[3] = 45;
  list_array[4] = 5;
  

  ArrayUtil dest_arr = create(8, 10);
  int hint = 2;
  dest_arr.length = filter(a, &isEven, NULL, dest_arr.base, 10); 
  assert(dest_arr.length == 2);
};

void test_filter_should_add_elements_into_given_array(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 12;
  list_array[1] = 25;
  list_array[2] = 34;
  list_array[3] = 45;
  list_array[4] = 5;

  ArrayUtil dest = create(8, 10);
  assert(filter(a, &isEven, NULL, dest.base, 10) == 2);
  
  assert(((int **)dest.base)[0] == &list_array[0]);
  assert(((int **)dest.base)[1] == &list_array[2]);
};

void test_filter_should_add_the_addresses_of_elements_into_given_array(){
  ArrayUtil a = create(1,5);
  char * list_array = (char *)(a.base);
  list_array[0] = 'a';
  list_array[1] = 'b';
  list_array[2] = 'c';
  list_array[3] = 'd';
  list_array[4] = 'e';

  ArrayUtil dest = create(1, 10);
  assert(filter(a, &isEven, NULL, dest.base, 10) == 2);
  
  assert(((char **)dest.base)[0] == &list_array[1]);
  assert(((char **)dest.base)[1] == &list_array[3]);
};

void test_map_should_map_each_element_of_the_array_and_stores_result_in_destination(){
  ArrayUtil source = create(4,5);
  int * list_array = (int *)(source.base);
  list_array[0] = 12;
  list_array[1] = 2;
  list_array[2] = 3;
  list_array[3] = 4;
  list_array[4] = 5;
  
  ArrayUtil destination = create(4,5);
  map(source, destination, &square, NULL);
  assert(((int *)destination.base)[0] == 144);
  assert(((int *)destination.base)[1] == 4);
  assert(((int *)destination.base)[2] == 9);
  assert(((int *)destination.base)[3] == 16);
  assert(((int *)destination.base)[4] == 25);
};

void test_forEach_will_execute_operation_for_each_element_in_the_array(){
  ArrayUtil source = create(4,5);
  int * list_array = (int *)(source.base);
  list_array[0] = 12;
  list_array[1] = 2;
  list_array[2] = 3;
  list_array[3] = 4;
  list_array[4] = 5;
 
  int hint = 10; 
  forEach(source, &increment_by, &hint);
  assert(((int *)source.base)[0] == 22);
  assert(((int *)source.base)[1] == 12);
  assert(((int *)source.base)[2] == 13);
  assert(((int *)source.base)[3] == 14);
  assert(((int *)source.base)[4] == 15);
};


void test_forEach_will_execute_operation_for_each_char_element_in_the_array(){
  ArrayUtil source = create(1,5);
  char * list_array = (char *)(source.base);
  list_array[0] = 'a';
  list_array[1] = 'b';
  list_array[2] = 'c';
  list_array[3] = 'd';
  list_array[4] = 'e';
 
  char hint = 2; 
  forEach(source, &shift_by, &hint);
  assert(((char *)source.base)[0] == 'c');
  assert(((char *)source.base)[1] == 'd');
  assert(((char *)source.base)[2] == 'e');
  assert(((char *)source.base)[3] == 'f');
  assert(((char *)source.base)[4] == 'g');
};

void test_reduce_should_reduce_the_array_to_one_value(){
  ArrayUtil source = create(4,5);
  int * list_array = (int *)(source.base);
  list_array[0] = 10;
  list_array[1] = 2;
  list_array[2] = 3;
  list_array[3] = 4;
  list_array[4] = 5;
 
  int hint = 0;
  int initial_value = 0;
  void *add = reduce(source, &total, &hint, &initial_value);
  assert(*((int *)add) == 24);
  assert(list_array[0] == 10);
  assert(list_array[1] == 2);
  assert(list_array[2] == 3);
  assert(list_array[3] == 4);
  assert(list_array[4] == 5);
};

void test_reduce_should_return_the_largest_character(){
  ArrayUtil source = create(1,5);
  char * list_array = (char *)(source.base);
  list_array[0] = 'a';
  list_array[1] = 'd';
  list_array[2] = 'b';
  list_array[3] = 'z';
  list_array[4] = 'h';
 
  char hint = 0;
  char initial_value = 'g';
  void *large = reduce(source, &largest, &hint, &initial_value);
  assert(*((char *)large) == 'z');
  assert(list_array[0] == 'a');    
};
