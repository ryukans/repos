#include "../header/procedure.h"

#define N_THREADS 2
#define MIN_BUFFERED_FRAMES 4

void* Producer(void *);
void* Consumer(void *);

int main()
{
    struct streaming_buffer* buf; //alt: Buffer* buf;
    pthread_attr_t attr;
    pthread_t threads[N_THREADS];

    buf = malloc(sizeof(struct streaming_buffer)); // atl: malloc(sizeof(Buffer));
    init(buf);

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    

    int i;
    /* 
    for (i = 0; i < N_THREADS; i++){
        if (i % 2 == 0){
            printf("Producer thread: %d\n", i);
            pthread_create(&threads[i], &attr, Producer, (void *)buf);
        }
        else{
            printf("Consumer thread: %d\n", i);
            pthread_create(&threads[i], &attr, Consumer, (void *)buf);
        }
    }
    */

    pthread_create(&threads[0], &attr, Producer, (void *)buf);
    pthread_create(&threads[1], &attr, Consumer, (void *)buf);

    for (i = 0; i < N_THREADS; i++){
        printf("Thread %d terminated\n", i);
        pthread_join(threads[i], NULL);
    }

    pthread_attr_destroy(&attr);
    destr(buf);
    free(buf);

    pthread_exit(NULL);

    return 0;
}

void* Producer(void* srcbuf)
{
    int i;
    Buffer* buf = (Buffer*)srcbuf;

    for(i = 0; i < 10; i++){
        frame_video frame;

        frame[0][0] = rand() % 11;
        frame[0][1] = rand() % 11;
        frame[1][0] = rand() % 11;
        frame[1][1] = rand() % 11;

        /* TBD: Chiamare il metodo "produci()" del monitor */
        produci(buf, frame);
        sleep(1);
    }

    pthread_exit(NULL);
}

void* Consumer(void* srcbuf) 
{
    int i;
    Buffer* buf = (Buffer*)srcbuf;
    
    /* TBD: Chiamare il metodo "bufferizza()" del monitor */
    buffer(buf, MIN_BUFFERED_FRAMES);    
    
    for(i = 0; i < 10; i++){
        frame_video frame;

        /* TBD: Chiamare il metodo "consuma()" del monitor */
        consuma(buf, frame);
        sleep(1);
    }

    pthread_exit(NULL);
}