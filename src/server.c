#include <stdio.h>
#include <stdlib.h>
#include <server.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

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
        FILE* f_ptr;                            /* File Pointer */
        const char* f_name = "daemon_log.txt";  /*  File Name   */
        f_ptr = fopen(f_name, "w+");
        if(!f_ptr){
                fprintf(stderr, " ** Couldn't create or open log file. ** \n");
                exit(1);
        }

        /* Daemon Section */
        daemon_init();                          /* Launch Daemon */
        while(1){
                sleep(10);
                fprintf(f_ptr, "Daemon is here!\n");
                fflush(f_ptr);
        }
        /* End Daemon Section */
}
