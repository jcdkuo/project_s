#include "main.h"

static TFunc g_ptFuncTable[] = {
    [FUNC_ADD]  = {"Addition",      add},
    [FUNC_SUB]  = {"Subtract",      sub},
    [FUNC_MUL]  = {"Multiple",      mul},
    [FUNC_MOD]  = {"Modulo",        mod},
};

int main(int argc, char *argv[])
{
	int iIndex, iResult;
	int ia =43, ib = 26;

	while(1)
	{
		printf("\n1:ADD\n2:SUB\n3:MUL\n4:MOD\n");
		scanf("%d", &iIndex);

		switch (iIndex)
		{
			case FUNC_ADD:
			case FUNC_SUB:
			case FUNC_MUL:
            case FUNC_MOD:
                iResult = g_ptFuncTable[iIndex].pfFunc(&ia, &ib);
				printf("%s : %d", g_ptFuncTable[iIndex].pcFuncName, iResult);	
				break;
			default:
				printf("Not valid option");
				break;
		}
	}
	return 0;
}
