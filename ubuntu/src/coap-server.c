#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <dirent.h>

#ifndef SERVER_CAN_PROXY
#define SERVER_CAN_PROXY 1
#endif

#define COAP_RESOURCE_CHECK_TIME 1

#include <coap3/coap.h>

#ifndef min
#define min(a,b) ((a) < (b) ? (a) : (b))
#endif


