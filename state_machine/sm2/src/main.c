#include "state.h"

enum _cmd {
	CMD_UNKNOWN			= 0,
    CMD_3WAY_HANDSHAKE  = 1,
    CMD_CLIENT_CONNECT  = 2,
    CMD_SERVER_STARTUP  = 3,
} ECmd;

static TState g_ptStateTable[] = {
    [STATE_DONE]	= {"Done", 		State_Done,		STATE_DONE,		1},
    [STATE_SYN]		= {"Syn",		State_Syn,		STATE_SYN_ACK,	0},
    [STATE_SYN_ACK] = {"Syn-Ack", 	State_Syn_Ack,	STATE_ACK,		0},
    [STATE_ACK]     = {"Ack",		State_Ack,		STATE_DONE,		0},
    [STATE_CONNET]  = {"Connect",	State_Connect,	STATE_SEND,		0},
    [STATE_SEND]    = {"Send", 		State_Send,		STATE_RECV,		0},
    [STATE_RECV]    = {"Receive",	State_Recv, 	STATE_CLOSE,	0},
    [STATE_CLOSE]   = {"Close",		State_Close,	STATE_DONE,		0},
    [STATE_BIND]    = {"Bind",		State_Bind,		STATE_LISTEN,	0},
    [STATE_LISTEN]  = {"Listen",	State_Listen,	STATE_ACCEPT,	0},
    [STATE_ACCEPT]  = {"Accept", 	State_Accept,	STATE_SEND,		0},
    [STATE_ERROR]   = {"Error",		State_Error,	STATE_ERROR,	0},
};

int main(int argc, char *argv[])
{
	int iIndex;
	EState eCurrentState = STATE_DONE;

	printf("1: 3way handshake\n");
	printf("2: client connect\n");
	printf("3: server startup\n");
	scanf("%d", &iIndex);

	switch (iIndex)
	{
		case CMD_3WAY_HANDSHAKE:
			printf("- 3 Way Handshake -\n");
			eCurrentState = STATE_SYN;
			break;
		case CMD_CLIENT_CONNECT:
			printf("- Client Connect to -\n");
			eCurrentState = STATE_CONNET;
			break;
		case CMD_SERVER_STARTUP:
			printf("- Server Startup -\n");
			eCurrentState = STATE_BIND;
			break;
		case CMD_UNKNOWN:
		default:
			printf("Not valid option");
			break;
	}

	while(1)
	{
		if (g_ptStateTable[eCurrentState].iFlag == 1) {
			printf("Session completed\n");
			break;
		}
		
		eCurrentState = State_Transform(&g_ptStateTable[eCurrentState]);
	}

	return 0;
}
