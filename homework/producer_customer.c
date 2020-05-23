#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/ipc.h>

#define MYFIFO              "myfifo"
#define BUFFER_SIZE         3
#define UNIT_SIZE           6
#define RUN_TIME            30
#define DELAY_TIME_LEVELS   5.0

int fd;
time_t end_time;
sem_t mutex,full,avail;

void *producer(void *arg)
{
    int real_write;
    int delay_time = 0;
    while (time(NULL) < end_time)
    {
        delay_time = (int)(rand()*DELAY_TIME_LEVELS/(RAND_MAX)/2.0)+1;
        sleep(delay_time);
        sem_wait(&avail);
        sem_wait(&mutex);
        printf("\nProducer:delay = %d\n", delay_time);
        if((real_write=write(fd,"hello", UNIT_SIZE))==-1)
        {
            if(errno==EAGAIN)
            {
                printf("The FIFO has not been read yet.Please try later\n");
            }
        }
        else
        {
            printf("Write %d to the FIFO\n", real_write);
        }
        sem_post(&full);
        sem_post(&mutex);        
    }
    pthread_exit(NULL);
}

void *customer(void *arg)
{
    unsigned char read_buffer[UNIT_SIZE];
    int real_read;
    int delay_time;

    while (time(NULL)<end_time)
    {
        delay_time = (int)(rand()*DELAY_TIME_LEVELS/(RAND_MAX))+1;
        sleep(delay_time);
        sem_wait(&full);
        sem_wait(&mutex);
        memset(read_buffer, 0, UNIT_SIZE);
        printf("\nCustomer:delay=%d\n",delay_time);

        if((real_read=read(fd, read_buffer, UNIT_SIZE))==-1)
        {
            if(errno == EAGAIN)
            {
                printf("No data yet\n");
            }
        }
        printf("Read %s from FIFO\n", read_buffer);
        sem_post(&avail);
        sem_post(&mutex);
    }
    pthread_exit(NULL);
    
}

int main()
{
    pthread_t thrd_pro_id, thrd_cus_id;
    pthread_t mon_th_id;
    int ret;

    srand(time(NULL));
    end_time = time(NULL)+RUN_TIME;
    if((mkfifo(MYFIFO, O_CREAT|O_EXCL)<0) && (errno!=EEXIST))
    {
        printf("Cannot create fifo\n");
        return errno;
    }
    fd = open(MYFIFO, O_RDWR,0666);
    if(fd == -1)
    {
        printf("Open fifo error\n");
        return fd;
    }

    ret = sem_init(&mutex, 0, 1);
    ret += sem_init(&avail, 0, BUFFER_SIZE);
    ret += sem_init(&full, 0, 0);
    if(ret != 0)
    {
        printf("Any semaphore initialization failed\n");
        return ret;
    }

    ret = pthread_create(&thrd_pro_id, NULL, producer, NULL);
    if(ret != 0)
    {
        printf("Create producer thread error\n");
        return ret;
    }
    pthread_join(thrd_pro_id, NULL);
    pthread_join(thrd_cus_id, NULL);
    close(fd);
    return 0;
}






