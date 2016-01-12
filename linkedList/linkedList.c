#include"linkedList.h"
#include<stdlib.h>
#include<stdio.h>

LinkedList createList(void){
  LinkedList list = *(LinkedList *)malloc(sizeof(LinkedList));
  list.head = NULL;
  list.tail = NULL;
  list.num_of_ele = 0;
  return list;
};

int add_to_list(LinkedList *list, void *element){
  Element *ele = (Element *)malloc(sizeof(Element));
  ele -> value = element;
  ele -> next = NULL;
  ele -> prev = list -> tail;
  if(list -> tail != NULL)
    list -> tail -> next = ele;
  else
    list -> head = ele;
  list -> tail = ele;
  return ++(list -> num_of_ele);
};

void *get_first_element(LinkedList list){
  if(list.head)
    return list.head -> value;
  return NULL;
};

void *get_last_element(LinkedList list){
  if(list.tail)
    return list.tail -> value;
  return NULL;
};

void forEach(LinkedList list, ElementProcessor e){
  while(list.head != NULL){
    e(list.head -> value);
    list.head = list.head -> next;
  };
};

void *getElementAt(LinkedList list, int index){
  Element *e = list.head;
  if(list.num_of_ele <= index || index < 0)
    return NULL;
  while(index != 0){
    e = e -> next;
    index--;
  };
  return e -> value;
};

int indexOf(LinkedList list, void *address_of_element){
  int count = 0;
  while(list.head != NULL){
    if(list.head -> value == address_of_element)
      return count;
    count++;
    list.head = list.head -> next;
  };
  return -1;
};

void *deleteElementAt(LinkedList *list, int index){
  Element *e = list -> head;
  while(index != 0){
    e = e -> next;
    index--;
  };
  if(e -> prev != NULL)
    e -> prev -> next = e -> next;
  else
    list -> head = e -> next;

  if(e -> next != NULL)
    e -> next -> prev = e -> prev;
  else
    list -> tail = e -> prev;
  (list -> num_of_ele)--;
  return (e -> value);
};

//----------------------------------------------------------------------------------------------------------------------//

int isEven(void *hint, void *ele){
  int *num = (int *)ele;
  if(*num % 2 == 0)
    return 1;
  return 0;
};


LinkedList filter(LinkedList list, MatchFunc *match){
  LinkedList filteredList = createList();
  while(list.head != NULL){
    if(match(NULL, list.head -> value))
      add_to_list(&filteredList, list.head -> value);
    list.head = list.head -> next;
  };
  return filteredList;
};

//----------------------------------------------------------------------------------------------------------------------//

int asArray(LinkedList list, void **dest, int maxElements){
  int elements_copied = 0;
  for(int i = 0; i < maxElements && i < list.num_of_ele; i++){
    dest[i] = list.head -> value;
    list.head = list.head -> next;
    elements_copied++;
  };
  return elements_copied;
};
