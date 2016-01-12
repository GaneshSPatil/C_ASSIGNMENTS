typedef struct element {
  void *value;
  struct element *prev;
  struct element *next;
} Element;

typedef struct linkedList{
  Element *head;
  Element *tail;
  int num_of_ele;
} LinkedList;

typedef void (*ElementProcessor)(void *);
typedef int(MatchFunc)(void *, void*); 

LinkedList createList(void);
int add_to_list(LinkedList *, void *);
void *get_first_element(LinkedList);
void *get_last_element(LinkedList);
void forEach(LinkedList, ElementProcessor);
void *getElementAt(LinkedList, int);
int indexOf(LinkedList, void *);
void *deleteElementAt(LinkedList *, int);
