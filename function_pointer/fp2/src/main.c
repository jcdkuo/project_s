#include <stdio.h>

enum _func {
    FUNC_ADD     = 1,
    FUNC_SUB     = 2,
    FUNC_MUL     = 3,
    FUNC_MOD     = 4,
} EFunc;

int add(int *i, int *j)
{
	printf("Add = ");
	return (*i + *j);
}

int sub(int *i, int *j)
{
	printf("Sub = ");
	return (*i - *j);
}

int mul(int *i, int *j)
{
	printf("Mul = ");
	return (*i * *j);
}

int mod(int *i, int *j)
{
	printf("Mod = ");
	return (*i % *j);
}

int (*pFunc[])(int *ia, int *ib) = { add, sub, mul, mod };

int main(int argc, char *argv[])
{
	int iIndex;
	int ia =43, ib = 26, iResult = 0;

	while(1)
	{
		printf("\n1:ADD\n2:SUB\n3:MUL\n4:MOD\n");
		scanf("%d", &iIndex);

		if (iIndex > 4) {
			printf("Not valid option");
			continue;
		}

		iResult = pFunc[iIndex-1](&ia,&ib);
		printf("%d", iResult);
	}
	return 0;
}
