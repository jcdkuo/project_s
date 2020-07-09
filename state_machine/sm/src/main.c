#include <stdio.h>

enum _cmd {
	CMD_UNKNOWN         = 0,
    CMD_3WAY_HANDSHAKE  = 1,
    CMD_CLIENT_CONNECT  = 2,
    CMD_SERVER_STARTUP  = 3,
} ECmd;

typedef enum _state {
    STATE_DONE      = 0,
    STATE_SYN       = 1,
    STATE_SYN_ACK   = 2,
    STATE_ACK       = 3,
    STATE_CONNET    = 4,
    STATE_SEND      = 5,
    STATE_RECV      = 6,
    STATE_CLOSE     = 7,
    STATE_BIND      = 8,
    STATE_LISTEN    = 9,
    STATE_ACCEPT    = 10,
    STATE_ERROR     = 11,
} EState;

typedef struct {
    char        *pcState;
} TState;

static TState g_ptStateTable[] = {
    [STATE_DONE]	= {"Done"},
    [STATE_SYN]     = {"Syn"},
    [STATE_SYN_ACK] = {"Syn-Ack"},
    [STATE_ACK]     = {"Ack"},
    [STATE_CONNET]  = {"Connect"},
    [STATE_SEND]    = {"Send"},
    [STATE_RECV]    = {"Receive"},
    [STATE_CLOSE]   = {"Close"},
    [STATE_BIND]    = {"Bind"},
    [STATE_LISTEN]  = {"Listen"},
    [STATE_ACCEPT]  = {"Accept"},
    [STATE_ERROR]   = {"Error"},
};

int main(int argc, char *argv[])
{
	int iIndex, iFlag = 0;
	EState eCurrentState = STATE_DONE;
	EState eNextState = STATE_DONE;

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

	eNextState = eCurrentState;

	while(1)
	{
		if (iFlag == 1) {
			printf("Session completed\n");
			break;
		}
		else {
			eCurrentState = eNextState;
			printf("%s\n", g_ptStateTable[eCurrentState].pcState);
		}
		
		switch (eCurrentState)
		{
			case STATE_DONE:
				iFlag = 1;
				break;
    		case STATE_SYN:
				eNextState = STATE_SYN_ACK;
				break;
    		case STATE_SYN_ACK:
				eNextState = STATE_ACK;
				break;
    		case STATE_ACK:
				eNextState = STATE_DONE;
				break;
    		case STATE_CONNET:
				eNextState = STATE_SEND;
				break;
    		case STATE_SEND:
				eNextState = STATE_RECV;
				break;
    		case STATE_RECV:
				eNextState = STATE_CLOSE;
				break;
    		case STATE_CLOSE:
				eNextState = STATE_DONE;
				break;
    		case STATE_BIND:
				eNextState = STATE_LISTEN;
				break;
    		case STATE_LISTEN:
				eNextState = STATE_ACCEPT;
				break;
    		case STATE_ACCEPT:
				eNextState = STATE_SEND;
				break;
    		case STATE_ERROR:
				eNextState = STATE_DONE;
				break;
			default:
				printf("Not valid option");
				break;
		}
	}

	return 0;
}
