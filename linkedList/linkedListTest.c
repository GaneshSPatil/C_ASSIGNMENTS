#include"linkedList.c"
#include<assert.h>

void test_createList_should_return_an_initialized_list(){
  LinkedList list = createList();
  assert(list.head == NULL);
  assert(list.tail == NULL);
  assert(list.num_of_ele == 0);
};

void test_add_to_list_should_add_the_given_element_into_the_linked_list(){
  LinkedList list = createList();
  int val = 2;
  add_to_list(&list, &val);
  assert(list.head -> value == &val);
  assert(list.tail -> value == &val);
  assert(list.num_of_ele == 1);
};

void test_add_to_list_should_return_the_new_length_of_linked_list(){
  LinkedList list = createList();
  int val = 2;
  int count = add_to_list(&list, &val); 
  assert(count == list.num_of_ele);
  assert(count == 1);
};

void test_add_to_list_should_add_element_add_the_end_of_the_list(){
  LinkedList list = createList();
  int val_1 = 1;
  int val_2 = 2;
  int val_3 = 3;
  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);

  assert(list.head -> value == &val_1);
  assert(list.tail -> value == &val_2);
  assert(list.num_of_ele == 2);

  add_to_list(&list, &val_3);
  assert(list.head -> value == &val_1);
  assert(list.tail -> value == &val_3);
  assert(list.num_of_ele == 3);
};

void test_add_to_list_should_add_elements_of_diffrent_types(){
  LinkedList list = createList();
  int val_1 = 1;
  char val_2 = 'a';
  int* val_3 = &val_1;

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);

  assert(list.head -> value == &val_1);
  assert(list.tail -> value == &val_3);
  assert(list.num_of_ele == 3);

  assert(list.head -> prev == NULL);
  assert(list.head -> next -> value == &val_2);
  assert(list.tail -> prev -> value == &val_2);
  assert(list.tail -> next == NULL);
};

void test_get_first_element_should_return_the_address_of_first_element(){
  LinkedList list = createList();
  int val_1 = 1;
  add_to_list(&list, &val_1);
  int *address_of_first_element = (int *)get_first_element(list);

  assert(address_of_first_element == &val_1);
};

void test_get_first_element_should_return_null_if_the_list_is_empty(){
  LinkedList list = createList();
  assert(get_first_element(list) == NULL);
};


void test_get_last_element_should_return_the_address_of_last_element(){
  LinkedList list = createList();
  int val_1 = 1;
  add_to_list(&list, &val_1);
  int *address_of_last_element = (int *)get_last_element(list);

  assert(address_of_last_element == &val_1);
};

void test_get_last_element_should_return_null_if_the_list_is_empty(){
  LinkedList list = createList();
  assert(get_last_element(list) == NULL);
};

void square (void *item){
  *((int *)item) = *((int *)item) * *((int *)item);
}; 

void test_forEach_should_call_the_specified_function_with_all_the_list_elements(){
  LinkedList list = createList();
  int val_1 = 1;
  int val_2 = 2;
  int val_3 = 3;
  int val_4 = 4;
  int val_5 = 5;

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);
  add_to_list(&list, &val_4);
  add_to_list(&list, &val_5);
  
  forEach(list, &square); 

  assert(val_1 == 1);
  assert(val_2 == 4);
  assert(val_3 == 9);
  assert(val_4 == 16);
  assert(val_5 == 25);
};


void increment (void *item){
  *((char *)item) = *(char *)item + 1;
}; 

void test_forEach_should_increment_all_the_elements_of_the_list(){
  LinkedList list = createList();
  char val_1 = 'a';
  char val_2 = 'b';
  char val_3 = 'c';
  char val_4 = 'd';
  char val_5 = 'e';

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);
  add_to_list(&list, &val_4);
  add_to_list(&list, &val_5);
  
  forEach(list, &increment); 

  assert(val_1 == 'b');
  assert(val_2 == 'c');
  assert(val_3 == 'd');
  assert(val_4 == 'e');
  assert(val_5 == 'f');
};

void test_getElementAt_should_return_the_element_at_the_given_index(){
  LinkedList list = createList();
  char val_1 = 'a';
  char val_2 = 'b';
  char val_3 = 'c';
  char val_4 = 'd';
  char val_5 = 'e';

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);
  add_to_list(&list, &val_4);
  add_to_list(&list, &val_5);
  
 assert(getElementAt(list, 0) == &val_1);
 assert(getElementAt(list, 1) == &val_2);
 assert(getElementAt(list, 2) == &val_3);
 assert(getElementAt(list, 3) == &val_4);
 assert(getElementAt(list, 4) == &val_5);
};


void test_getELementAt_should_return_NULL_for_invalid_index(){
  LinkedList list = createList();
  char val_1 = 'a';
  char val_2 = 'b';
  char val_3 = 'c';
  char val_4 = 'd';
  char val_5 = 'e';

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);
  add_to_list(&list, &val_4);
  add_to_list(&list, &val_5);
  
 assert(getElementAt(list, 5) == NULL);
 assert(getElementAt(list, -1) == NULL);
};

void test_indexOf_should_return_the_index_of_the_searched_element(){
  LinkedList list = createList();
  char val_1 = 'a';
  char val_2 = 'b';
  char val_3 = 'c';
  char val_4 = 'd';
  char val_5 = 'e';

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);
  add_to_list(&list, &val_4);
  add_to_list(&list, &val_5);

 assert(indexOf(list, &val_1) == 0); 
 assert(indexOf(list, &val_2) == 1); 
 assert(indexOf(list, &val_3) == 2); 
 assert(indexOf(list, &val_4) == 3); 
 assert(indexOf(list, &val_5) == 4);
};

void test_indexOf_should_return_the_first_occurance_of_the_element(){
  LinkedList list = createList();
  char val_1 = 'a';
  char val_2 = 'b';
  char val_3 = 'a';
  char val_4 = 'a';
  char val_5 = 'b';

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);
  add_to_list(&list, &val_4);
  add_to_list(&list, &val_5);

 assert(indexOf(list, &val_1) == 0); 
 assert(indexOf(list, &val_2) == 1); 
};

void test_indexOf_should_return_minus_one_if_the_element_is_not_there_in_the_list(){
  LinkedList list = createList();
  char val_1 = 'a';
  char val_2 = 'b';
  char val_3 = 'c';
  char val_4 = 'd';
  char val_5 = 'e';

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);

 assert(indexOf(list, &val_5) == -1); 
};

void test_deleteElementAt_should_delete_the_element_at_specific_index(){
  LinkedList list = createList();
  char val_1 = 'a';
  char val_2 = 'b';
  char val_3 = 'c';
  char val_4 = 'd';
  char val_5 = 'e';

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);
  add_to_list(&list, &val_4);
  add_to_list(&list, &val_5);
  
  assert(deleteElementAt(&list, 0) == &val_1);
  
 assert(getElementAt(list, 0) == &val_2);
 assert(getElementAt(list, 1) == &val_3);
 assert(getElementAt(list, 2) == &val_4);
 assert(getElementAt(list, 3) == &val_5);
};

void test_filter_should_filter_the_given_list_and_return_new_filtered_list(){
  LinkedList list = createList();
  int val_1 = 1;
  int val_2 = 2;
  int val_3 = 3;
  int val_4 = 4;
  int val_5 = 5;

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);
  add_to_list(&list, &val_4);
  add_to_list(&list, &val_5);
  
  LinkedList newlist = filter(list, &isEven);
  
  assert(getElementAt(newlist, 0) == &val_2);
  assert(getElementAt(newlist, 1) == &val_4);
  assert(getElementAt(newlist, 2) == NULL);
};

void test_asArray_should_copy_all_elements_of_list_into_given_array(){
  LinkedList list = createList();
  int val_1 = 1;
  int val_2 = 2;
  int val_3 = 3;
  int val_4 = 4;
  int val_5 = 5;

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);
  add_to_list(&list, &val_4);
  add_to_list(&list, &val_5);
  
  void *dest[5];
  asArray(list, dest, 5);

  assert(dest[0] == &val_1);
  assert(dest[1] == &val_2);
  assert(dest[2] == &val_3);
  assert(dest[3] == &val_4);
  assert(dest[4] == &val_5);

};

void test_asArray_should_copy_elements_equal_to_the_size_of_array(){
  LinkedList list = createList();
  int val_1 = 1;
  int val_2 = 2;
  int val_3 = 3;
  int val_4 = 4;
  int val_5 = 5;

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);
  add_to_list(&list, &val_4);
  add_to_list(&list, &val_5);
  
  void *dest[5];
  asArray(list, dest, 3);

  assert(dest[0] == &val_1);
  assert(dest[1] == &val_2);
  assert(dest[2] == &val_3);
  assert(dest[3] != &val_4);
  assert(dest[4] != &val_5);

};

void test_asArray_should_return_the_count_of_copied_array(){
  LinkedList list = createList();
  int val_1 = 1;
  int val_2 = 2;
  int val_3 = 3;
  int val_4 = 4;
  int val_5 = 5;

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);
  add_to_list(&list, &val_4);
  add_to_list(&list, &val_5);
  
  void *dest[10];
  int copied_elment_count = asArray(list, dest, 10);
  
  assert(copied_elment_count == 5);
};

void test_asArray_should_return_the_count_of_copied_array_when_array_is_smaller_than_list(){
  LinkedList list = createList();
  int val_1 = 1;
  int val_2 = 2;
  int val_3 = 3;
  int val_4 = 4;
  int val_5 = 5;

  add_to_list(&list, &val_1);
  add_to_list(&list, &val_2);
  add_to_list(&list, &val_3);
  add_to_list(&list, &val_4);
  add_to_list(&list, &val_5);
  
  void *dest[3];
  int copied_elment_count = asArray(list, dest, 3);
  
  assert(copied_elment_count == 3);
};
