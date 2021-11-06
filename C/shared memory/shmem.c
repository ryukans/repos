#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>


int main()
{
    key_t shm_key; //shared memory id key.
    shm_key = IPC_PRIVATE; // Private key, only accesable by parent process and its children processes.
    //shm_key = ftok(".", 'A');  

    //creating shared memory; shmget returns shared memory segment.
    int shm = shmget(shm_key, sizeof(int), IPC_CREAT | 0664);
    
  
    if(shm < 0){
        perror("Error shmget function !\n");
           exit(EXIT_FAILURE);
    }
        
    int* shmptr = (int*) shmat(shm, NULL, 0);
   
    // shmat attaches shared memory segment; shmat retuns a (void*) pointer, therefore pointer casting is needed.
    int* shmptr = (int*) shmat(shm, NULL, 0);

    if(shmptr == (void*)-1){ /* Casting to void is used to suppress compiler warnings. 
                              * The Standard says in §5.2.9/4 says:
                              * Any expression can be explicitly converted to type “cv void.” The expression value is discarded.
                              */
        perror("Error linking memory to the caller!\n");
        exit(EXIT_FAILURE);
    }

    printf("Shared memory created:\nIPC key: %d \nmem identifier: %d \naddress after attach: %p \n", shm_key, shm, shmptr);


    key_t pid = fork();

    if (pid == -1){
        perror("Error\n");
        exit(EXIT_FAILURE);
    }
 	if(pid == 0){
        *shmptr = 123;
        exit(EXIT_SUCCESS);
 	} 
    else if(pid > 0) {
    	wait(NULL);
    	printf("What's in SHM: %d\n", *shmptr);
 	}

    //Shared memory control operation; IPC_RMID removes identifier. 
    shmctl(shm, IPC_RMID, NULL);

    return 0;
}