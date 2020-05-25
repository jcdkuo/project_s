#include <stdio.h>

enum _func {
    FUNC_ADD     = 1,
    FUNC_SUB     = 2,
    FUNC_MUL     = 3,
    FUNC_MOD     = 4,
} EFunc;

typedef int (* Ffunc)(int *ia, int *ib);

typedef struct {
    char        *pcFuncName;
    Ffunc       pfFunc;
} TFunc;

int add(int *i, int *j);
int sub(int *i, int *j);
int mul(int *i, int *j);
int mod(int *i, int *j);
