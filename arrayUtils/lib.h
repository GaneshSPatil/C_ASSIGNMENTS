typedef struct arrayUtil{
  void * base;
  int typeSize;
  int length;
} ArrayUtil;

typedef int(MatchFunc)(void *, void*);
typedef void(ConvertFunc)(void *, void *, void *);
typedef void(OperationFunc)(void *, void *);
typedef void *(ReducerFunc)(void *, void *i, void *);

ArrayUtil create(int, int);
void print_arr(ArrayUtil);
int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil resize(ArrayUtil, int);
int findIndex(ArrayUtil, void *);
void dispose(ArrayUtil);
void *findFirst(ArrayUtil, MatchFunc *, void *);
void *findLast(ArrayUtil, MatchFunc *, void *);
int filter(ArrayUtil util, MatchFunc *match, void *hint, void **destination, int maxItems);

void map(ArrayUtil, ArrayUtil, ConvertFunc *, void *);
void forEach(ArrayUtil, OperationFunc *, void *);
void *reduce(ArrayUtil, ReducerFunc *, void *, void *);
