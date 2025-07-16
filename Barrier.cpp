#include "Barrier.h"
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <cstring>

Barrier::Barrier(int numThreads)
    : mutex(PTHREAD_MUTEX_INITIALIZER),
      cv(PTHREAD_COND_INITIALIZER),
      count(0),
      numThreads(numThreads),
      generation(0) {}

Barrier::~Barrier()
{
    if (pthread_mutex_destroy(&mutex) != 0) {
        perror("[[Barrier]] pthread_mutex_destroy failed");
        exit(1);
    }
    if (pthread_cond_destroy(&cv) != 0){
        perror("[[Barrier]] pthread_cond_destroy failed");
        exit(1);
    }
}

void Barrier::barrier()
{
    if (pthread_mutex_lock(&mutex) != 0){
        perror("[[Barrier]] pthread_mutex_lock failed");
        exit(1);
    }

    int local_gen = generation;

    if (++count == numThreads) {
        // Last thread to arrive resets count and signals all
        count = 0;
        generation++;
        if (pthread_cond_broadcast(&cv) != 0) {
            perror("[[Barrier]] pthread_cond_broadcast failed");
            exit(1);
        }
    } else {
        // Wait until the generation number changes
        while (local_gen == generation) {
            if (pthread_cond_wait(&cv, &mutex) != 0) {
                perror("[[Barrier]] pthread_cond_wait failed");
                exit(1);
            }
        }
    }

    if (pthread_mutex_unlock(&mutex) != 0) {
        perror("[[Barrier]] pthread_mutex_unlock failed");
        exit(1);
    }
}
