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
