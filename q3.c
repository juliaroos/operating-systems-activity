#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define NUM_THREADS 8

static long long contaA = 100000000;
static long long contaB = 0;
static long long auditoria = 0;
// compartilhado
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* worker(void* arg) {
    (void)arg;
    long long local_sum = 0;

    while (contaA > 0) {
        pthread_mutex_lock(&mtx);
        if (contaA > 0) {
            long long v;
            if (contaA < 100){
                v = contaA;
            } else {
                v = rand() % 100 + 1;
            }
            contaA -= v;
            contaB += v;
            local_sum += v;
        }
        pthread_mutex_unlock(&mtx);
    }

    pthread_mutex_lock(&mtx);    
    auditoria += local_sum;
    pthread_mutex_unlock(&mtx);
    return NULL;
}

int main(void) {
    pthread_t th[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&th[i], NULL, worker, NULL) != 0) {
            perror("pthread_create");
            return 1;
        }
    }
    for (int i = 0; i < NUM_THREADS; i++) pthread_join(th[i], NULL);

    printf("Conta A=%lld Conta B=%lld Auditoria=%lld\n",
       contaA, contaB, auditoria);
    return 0;
}