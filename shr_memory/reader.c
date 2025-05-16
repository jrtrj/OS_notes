#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int shmid;
    void *shared_memory;

    // Access the existing shared memory segment
    shmid = shmget((key_t)2345, 1024, 0666);
    printf("Key of shared memory is %d\n", shmid);

    // Attach to address space
    shared_memory = shmat(shmid, NULL, 0);
    printf("Process attached at %p\n", shared_memory);

    // Read from shared memory
    printf("Data read from shared memory is: %s\n", (char *)shared_memory);

    return 0;
}
