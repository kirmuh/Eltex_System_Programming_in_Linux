#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 1000

typedef struct {
    int start;
    int end;
    long long result;
} ThreadArgs;

void* sum_of_squares(void* args) {
    ThreadArgs* threadArgs = (ThreadArgs*)args;
    long long sum = 0;

    for (int i = threadArgs->start; i <= threadArgs->end; i++) {
        sum += i * i;
    }

    threadArgs->result = sum;
    return NULL;
}

int main() {
    pthread_t threads[2];
    ThreadArgs threadArgs[2];

    threadArgs[0].start = 1;
    threadArgs[0].end = N / 2;

    threadArgs[1].start = N / 2 + 1;
    threadArgs[1].end = N;

    for (int i = 0; i < 2; i++) {
        if (pthread_create(&threads[i], NULL, sum_of_squares, &threadArgs[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    long long total_sum = threadArgs[0].result + threadArgs[1].result;

    printf("Сумма квадратов чисел от 1 до %d: %lld\n", N, total_sum);

    return 0;
}