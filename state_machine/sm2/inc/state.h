#include <stdio.h>

typedef enum _func {
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

typedef void (* Ffunc)(char *pcState);

typedef struct {
    char        *pcState;
    Ffunc       pfFunc;
    EState      eNextState;
    int         iFlag;
} TState;

EState State_Transform(TState *ptHandle);

void State_Done(char *pcState);
void State_Syn(char *pcState);
void State_Syn_Ack(char *pcState);
void State_Ack(char *pcState);
void State_Connect(char *pcState);
void State_Send(char *pcState);
void State_Recv(char *pcState);
void State_Close(char *pcState);
void State_Bind(char *pcState);
void State_Listen(char *pcState);
void State_Accept(char *pcState);
void State_Error(char *pcState);
