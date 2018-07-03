#include <stdio.h>
#include <stdlib.h>
#include <server.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>

/* MACROS */
#define SERV_INET_NO 2255700040
#define SERV_TCP_PORT 40001
/*   END  */

void daemon_init(void)
{
        pid_t pid;
        if((pid=fork()) < 0){                   /* -1 Means Error */
                fprintf(stderr, "Failed Daemon Launch\n");
                return;
        }else if(pid != 0){                     /* To Exit Parent */
                exit(0);
        }
        setsid();                               /*Sets itself as session leader*/
        chdir("/");                             /* Change to root directory */
        umask(0);                               /* Clear Mask */
}

void launch_server(void)
{
        pid_t pid;
        int sock_rt, nsd, client_addr_len;      /* Socket return value */
        struct sockaddr_in server_addr,         /*  Socket Addresses   */
                           client_addr;
        FILE* f_ptr;                            /* File Pointer */
        const char* f_name = "daemon_log.txt";  /*  File Name   */

        f_ptr = fopen(f_name, "w+");
        if(!f_ptr){
                fprintf(stderr, " ** Couldn't create or open log file. ** \n");
                exit(1);
        }

        /* Set up socket */
        if((sock_rt = socket(AF_INET, SOCK_STREAM, 0)) < 0){
                perror("server: Socket Error");
                exit(1);
        }
        /* End of socket setup */

        /* Build Internet Socket Address */
        bzero((char*)&server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(SERV_TCP_PORT);
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        /* End Of Internet Socket Build */

        /* Bind Server Address To Socket */
        if(bind(sock_rt, (struct sockaddr*) &server_addr,
                sizeof(server_addr))<0){
                perror("server bind");
                exit(1);
        }
        /* End of Bind */

        /* Become a listening socket */
        listen(sock_rt, 5);

        /* Daemon Section */
        daemon_init();                          /* Launch Daemon */
        while(1){
                client_addr_len = sizeof(client_addr);
                nsd = accept(sock_rt,
                             (struct sockaddr*) &client_addr,
                             &client_addr_len);
                if(nsd < 0){                    /* Handle Possible Error */
                        perror("Server: accept error.");
                        exit(1);
                }

                /* Create Child Process For Client */
                if((pid = fork()) < 0){
                        perror("Server: Error Forking For Child.");
                        exit(1);
                }else if(pid > 0){
                        close(nsd);
                        continue;        /* Parent Advances to next iteration */
                }

                /* Within Child -> Serve Client */
                close(sock_rt);
                sleep(10);
                fprintf(f_ptr, "Daemon is here!\n");
                fflush(f_ptr);
        }
        /* End Daemon Section */
}
