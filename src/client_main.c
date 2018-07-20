#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "client.h"

int main(int argc, char* argv[], char* envp[])
{
        printf(" *** Launching Client ***");
        launch_client();
        printf(" *** Exiting Client Program ***");
        exit(0);
}
