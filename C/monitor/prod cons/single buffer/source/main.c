#include "../header/procedure.h"
#include "../header/monitor_signal_continue.h"

#define NUM_PROD 1
#define NUM_CONS 1

int main()
{
    int shmem;

    if(!(shmem = shmget(IPC_PRIVATE, sizeof(Buffer), IPC_CREAT | 0664))){
        perror("Errore shmget\n");
        exit(1);
    }
    
    Buffer* buf;

    if((buf = (Buffer*) shmat(shmem, NULL, 0)) == (void*)-1){
        perror("Error shmat\n");
        exit(1);
    }

    init_monitor(&(buf->monitor), NUM_PROD+NUM_CONS);
    buf->is_full = 0;

    int i;
    pid_t pid;

    for (i = 0; i < NUM_CONS; i++){
        if(!(pid = fork())){
            printf("Consumed value: %d\n", consume(buf));
            exit(0);
        }
        else if (pid < 0){
            perror("Error fork\n");
            exit(1);
        }
    }

    for (i = 0; i < NUM_PROD; i++){
        if(!(pid = fork())){
            printf("Producing...\n");
            sleep(5);
            srand(time(NULL));
            int val = rand()%10;
            produce(buf, val);
            printf("Produced: %d", val);
        }
        else if(pid < 0){
            perror("Error fork\n");
            exit(1);
        }
    }
    
    for (i = 0; i < NUM_CONS+NUM_PROD; i++)
        wait(NULL);

    remove_monitor(&(buf->monitor));
    shmctl(shmem, IPC_RMID, NULL);
    
    return 0;
}