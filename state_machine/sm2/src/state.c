#include "state.h"

EState State_Transform(TState *ptHandle)
{
	ptHandle->pfFunc(ptHandle->pcState);
	return ptHandle->eNextState;
}

void State_Done(char *pcState)
{
	printf("%s\n", pcState);
}

void State_Syn(char *pcState)
{
	printf("%s\n", pcState);
}

void State_Syn_Ack(char *pcState)
{
	printf("%s\n", pcState);
}

void State_Ack(char *pcState)
{
	printf("%s\n", pcState);
}

void State_Connect(char *pcState)
{
	printf("%s\n", pcState);
}

void State_Send(char *pcState)
{
	printf("%s\n", pcState);
}

void State_Recv(char *pcState)
{
	printf("%s\n", pcState);
}

void State_Close(char *pcState)
{
	printf("%s\n", pcState);
}

void State_Bind(char *pcState)
{
	printf("%s\n", pcState);
}

void State_Listen(char *pcState)
{
	printf("%s\n", pcState);
}

void State_Accept(char *pcState)
{
	printf("%s\n", pcState);
}

void State_Error(char *pcState)
{
	printf("%s\n", pcState);
}
