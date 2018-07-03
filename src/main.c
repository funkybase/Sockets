#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "client.h"
#include "server.h"
#define MAX_CHAR_BUFFER 1024

int main(int argc, char* argv[], char* envp[])
{
        /* Prints Program Options */
        char option[MAX_CHAR_BUFFER];
        int value, rt_value;
        printf("\n\n ******* Client-Server Program ******* \n");
        printf("  -Select program side to be launched.\n");
        printf("     1) Launches Server-side\n");
        printf("     2) Launches Client-side\n");
        printf(" *************************************\n\n");
        /* Menu End */

        /* Validation Loop For Options */
        do{
                printf("Insert Option:\n");
                fgets(option, MAX_CHAR_BUFFER, stdin);
                value = atoi(option);
        }while(value!=1 && value!=2);
        /* End Of Loop */

        /* Process Value Input */
        switch(value){
        case 1:
                launch_server();
                exit(0);
        case 2:
                launch_client();
                exit(0);
        }
        /* End Of Switch Statement */

        exit(0);
}
