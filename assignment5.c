#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;
int readcount = 0;
int data = 0;

void *reader(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&mutex);
    readcount++;
    if (readcount == 1)
        sem_wait(&wrt);
    sem_post(&mutex);

    printf("Reader %d is reading data = %d\n", id, data);
    sleep(1);

    sem_wait(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&wrt);
    sem_post(&mutex);

    printf("Reader %d finished\n", id);
    return NULL;
}

void *writer(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&wrt);
    data++;
    printf("Writer %d wrote data = %d\n", id, data);
    sleep(1);
    sem_post(&wrt);

    printf("Writer %d finished\n", id);
    return NULL;
}

int main()
{
    int nr, nw, i;
    pthread_t r[10], w[10];
    int rid[10], wid[10];

    printf("Enter number of readers: ");
    scanf("%d", &nr);
    printf("Enter number of writers: ");
    scanf("%d", &nw);

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (i = 0; i < nr; i++) {
        rid[i] = i + 1;
        pthread_create(&r[i], NULL, reader, &rid[i]);
    }
    for (i = 0; i < nw; i++) {
        wid[i] = i + 1;
        pthread_create(&w[i], NULL, writer, &wid[i]);
    }

    for (i = 0; i < nr; i++)
        pthread_join(r[i], NULL);
    for (i = 0; i < nw; i++)
        pthread_join(w[i], NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}
