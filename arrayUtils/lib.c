#include"lib.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

ArrayUtil create(int typeSize, int length){
  ArrayUtil arr = *(ArrayUtil *)malloc(sizeof(ArrayUtil));
  arr.typeSize = typeSize;
  arr.length = length;
  arr.base = (void *)calloc(length, typeSize);
  return arr;
};

int areEqual(ArrayUtil a, ArrayUtil b){
  return memcmp(a.base, b.base, a.length);
};

ArrayUtil resize(ArrayUtil util, int length){
  util.base = realloc(util.base, length);
  util.length = length;
  return util;
};

void print_arr(ArrayUtil arr){
  for(int i = 0; i < arr.length; i++)
    printf("%d ", ((int *)arr.base)[i]);
}; 

int findIndex(ArrayUtil arr, void *element){
  void *base = arr.base;
  for(int i = 0; i < arr.length; i++){
    if(memcmp(base, element, arr.typeSize) == 0)
      return i;
    base = base + arr.typeSize;
  };
  return -1;
};

void dispose(ArrayUtil arr){
  free(arr.base);
  arr.length = 0;
};

//----------------------------------------------------------------------------------------------------------//

void *findFirst(ArrayUtil util, MatchFunc* match, void *hint){
  void *base = util.base;
  for(int i = 0; i < util.length; i++){
    if(match(hint, base))
      return base;
    base = base + util.typeSize;
  };
  return (void *)NULL;
};

int isEven(void *hint, void *item){
  int *num = (int *)item;
  if(*num % 2 == 0)
    return 1;
  return 0;  
};

int isDivisible(void *hint, void *item){
  int *num = (int *)item;
  int *div = (int *)hint;
  
  if((*num % *div) == 0)
    return 1;
  return 0;
};


//----------------------------------------------------------------------------------------------------------//

void *findLast(ArrayUtil util, MatchFunc* match, void *hint){
  void *base = util.base + ((util.length-1) * util.typeSize);
  for(int i = 0; i < util.length; i++){
    if(match(hint, base))
      return base;
    base = base - util.typeSize;
  };
  return (void *)NULL;
};

//----------------------------------------------------------------------------------------------------------//

int count(ArrayUtil util, MatchFunc* match, void *hint){
  int count = 0;
  void *base = util.base;
  for(int i = 0; i < util.length; i++){
    if(match(hint, base))
      count++;
    base = base + util.typeSize;
  };
  return count;
};

//----------------------------------------------------------------------------------------------------------//

int filter(ArrayUtil util, MatchFunc *match, void *hint, void **destination, int maxItems){
  void *base = util.base;
  int count = 0;
  for(int i = 0; i < util.length; i++){
    if(match(hint, base)){
      destination[count] = base; 
      count++;
    };
    base = base + util.typeSize;
  };
  return count;
};

//----------------------------------------------------------------------------------------------------------//

void square(void *hint, void *sourceItem, void *destinationItem){
  int *num = (int *)sourceItem;
  *num = *num * *num;
  *((int *)destinationItem) = *num;
};

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc *convert, void *hint){
  void *base = source.base;
  void *dest = destination.base;
  for(int i = 0; i < source.length; i++){
    convert(hint, base, dest);
    base = base + source.typeSize;
    dest = dest + destination.typeSize;
  };
};

//----------------------------------------------------------------------------------------------------------//

void increment_by (void *hint, void *item){
  *((int *)item) = *((int *)item) + *((int *)hint);
};

void shift_by (void *hint, void *item){
  *((char *)item) = *((char *)item) + *((char *)hint);
};

void forEach(ArrayUtil util, OperationFunc *operation, void *hint){
  void *base = util.base;
  for(int i = 0; i < util.length; i++){
    operation(hint, base);
    base = base + util.typeSize;
  };
};

//----------------------------------------------------------------------------------------------------------//

void *total (void *hint, void *previousItem, void *item){
  int *temp = malloc(sizeof(item));
  *temp = *((int *)previousItem) + *((int *)item);
  return temp;
};

void *largest (void *hint, void *previousItem, void *item){
  if(*((char *)previousItem) > *((char *) item))
    return previousItem;
  return item;
};

void *reduce(ArrayUtil util, ReducerFunc * reducer, void *hint, void *initialValue){
  void *item = util.base;
  void *previousItem = initialValue;
  for(int i = 0; i < util.length; i++){
    void *ptr = reducer(hint, previousItem, item);
    previousItem = ptr;
    item = item + util.typeSize;
  };
  return previousItem;
};

//----------------------------------------------------------------------------------------------------------//
