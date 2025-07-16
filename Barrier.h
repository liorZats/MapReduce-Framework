#ifndef BARRIER_H
#define BARRIER_H

#include <pthread.h>

class Barrier {
public:
    explicit Barrier(int numThreads);
    ~Barrier();
    void barrier();

private:
    pthread_mutex_t mutex;
    pthread_cond_t cv;
    int count;
    int numThreads;
    int generation;  // Tracks barrier rounds to avoid spurious wakeups
};

#endif // BARRIER_H
