#ifndef HEADER_H
#define HEADER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>

#define MAX_CLIENTS 100
#define BUFFER_SZ 2048
#define LENGTH 2048


typedef struct{
	struct sockaddr_in address; /* Stores ip (sin_addr.s_addr), port (sin_port) and ip format (sin_family = AF_INET) */
	int sockfd;
	int uid;
	char name[32];
} client_t; /* Handles all neccesary info about client */


typedef struct
{
    char *ipv4; /* IP in char* format. Standard 127.0.0.1*/ 
    int port; /* Port in int format*/
    struct sockaddr_in address; /*Server IP, Port and ip format */
	int listenfd; /* Main server socket*/
    int uid; /* Used to set id for new clients*/
    client_t **clients; /* Array of clients*/
    pthread_mutex_t clients_mutex; /* Main server mutex*/
    pthread_t tid; /* Pthread to handle connections */

    _Atomic unsigned int cli_count; /* Client count. _Atomic is used as a built-in mutex */

} server_info_t;

typedef struct {
    server_info_t *serv_inf;
    int uid;
} buff_t; /* Buffer that is used to transfer info to the new thread*/


void str_overwrite_stdout();
void str_trim_lf (char* arr, int length);
void print_client_addr(struct sockaddr_in addr);

void queue_add(client_t *cl, server_info_t *serv_inf);
void queue_remove(int uid, server_info_t *serv_inf);


#endif
