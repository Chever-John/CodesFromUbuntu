#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/ipc.h>

#define PRODUCER_NUM   5  //生产者数
#define CONSUMER_NUM   3  //消费者数
#define PRD_NUM        20 //最多生产的产品数
#define DELAY_TIME     3  //生产(或消费)任务之间的最大时间间隔

#define QUEUE_SIZE     (PRD_NUM+1) //队列最大容纳QUEUE_SIZE-1个元素

typedef struct{
    int aData[QUEUE_SIZE];  //队列元素
    int dwHead;  //指向队首元素
    int dwTail;  //指向队尾元素的下一个元素
}T_QUEUE, *PT_QUEUE;

T_QUEUE gtQueue;
pthread_mutex_t gtQueLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t gtPrdCond = PTHREAD_COND_INITIALIZER; //Full->Not Full
pthread_cond_t gtCsmCond = PTHREAD_COND_INITIALIZER; //Empty->Not Empty

//初始化循环队列
void InitQue(PT_QUEUE ptQue)
{
    memset(ptQue, 0, sizeof(*ptQue));
}

//向循环队列中插入元素
void EnterQue(PT_QUEUE ptQue, int dwElem)
{
    if(IsQueFull(ptQue))
    {
        printf("Elem %d cannot enter Queue %p(Full)!\n", dwElem, ptQue);
        return;
    }
    ptQue->aData[ptQue->dwTail]= dwElem;
    ptQue->dwTail = (ptQue->dwTail + 1) % QUEUE_SIZE;
}

//从循环队列中取出元素
int LeaveQue(PT_QUEUE ptQue)
{
    if(IsQueEmpty(ptQue))
    {
        printf("Queue %p is Empty!\n", ptQue);
        return -1;
    }
    int dwElem = ptQue->aData[ptQue->dwHead];
    ptQue->dwHead = (ptQue->dwHead + 1) % QUEUE_SIZE;
    return dwElem;
}

//从队首至队尾依次显示队中元素值
void DisplayQue(PT_QUEUE ptQue)
{
    if(IsQueEmpty(ptQue))
    {
        printf("Queue %p is Empty!\n", ptQue);
        return;
    }

    printf("Queue Element: ");
    int dwIdx = ptQue->dwHead;
    while((dwIdx % QUEUE_SIZE) != ptQue->dwTail)
        printf("%d ", ptQue->aData[(dwIdx++) % QUEUE_SIZE]);

    printf("\n");
}

int main(void)
{
    InitQue(&gtQueue);
    srand(getpid());  //初始化随机函数发生器

    pthread_t aThrd[CONSUMER_NUM+PRODUCER_NUM];
    int dwThrdIdx;
    for(dwThrdIdx = 0; dwThrdIdx < CONSUMER_NUM; dwThrdIdx++)
    {  //创建CONSUMER_NUM个消费者线程，传入(void*)dwThrdIdx作为ConsumerThread的参数
        pthread_create(&aThrd[dwThrdIdx], NULL, ConsumerThread, (void*)dwThrdIdx);
    }
    sleep(2);
    for(dwThrdIdx = 0; dwThrdIdx < PRODUCER_NUM; dwThrdIdx++)
    {
        pthread_create(&aThrd[dwThrdIdx+CONSUMER_NUM], NULL, ProducerThread, (void*)dwThrdIdx);
    }
    while(1);
    return 0 ;
}

void *ProducerThread(void *pvArg)
{
    pthread_detach(pthread_self());
    int dwThrdNo = (int)pvArg;
    while(1)
    {
        pthread_mutex_lock(&gtQueLock);
        while(IsQueFull(&gtQueue))  //队列由满变为非满时，生产者线程被唤醒
            pthread_cond_wait(&gtPrdCond, &gtQueLock);

        EnterQue(&gtQueue, GetQueTail(&gtQueue)); //将队列元素下标作为元素值入队
        if(QueDataNum(&gtQueue) == 1) //当生产者开始产出后，通知(唤醒)消费者线程
            pthread_cond_broadcast(&gtCsmCond);
        printf("[Producer %2u]Current Product Num: %u\n", dwThrdNo, QueDataNum(&gtQueue));

        pthread_mutex_unlock(&gtQueLock);
        sleep(rand()%DELAY_TIME + 1);
    }
}

void *ConsumerThread(void *pvArg)
{
    pthread_detach(pthread_self());
    int dwThrdNo = (int)pvArg;
    while(1)
    {
        pthread_mutex_lock(&gtQueLock);
        while(IsQueEmpty(&gtQueue)) //队列由空变为非空时，消费者线程将被唤醒
            pthread_cond_wait(&gtCsmCond, &gtQueLock);

        if(GetQueHead(&gtQueue) != GetQueHeadData(&gtQueue))
        {
            printf("[Consumer %2u]Product: %d, Expect: %d\n", dwThrdNo,
                   GetQueHead(&gtQueue), GetQueHeadData(&gtQueue));
            exit(0);
        }
        LeaveQue(&gtQueue);
        if(QueDataNum(&gtQueue) == (PRD_NUM-1)) //当队列由满变为非满时，通知(唤醒)生产者线程
            pthread_cond_broadcast(&gtPrdCond);
        printf("[Consumer %2u]Current Product Num: %u\n", dwThrdNo, QueDataNum(&gtQueue));

        pthread_mutex_unlock(&gtQueLock);
        sleep(rand()%DELAY_TIME + 1);
    }
}