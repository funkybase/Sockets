#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "server.h"

int main(int argc, char* argv[], char* envp[])
{
        printf(" *** Launching Client ***");
        launch_server();
        printf(" *** Exiting Server Launch ***");
        exit(0);
}
