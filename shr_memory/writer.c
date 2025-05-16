#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int shmid;
    void *shared_memory;
    char buff[100];

    // Create shared memory segment
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    printf("Key of shared memory is %d\n", shmid);

    // Attach shared memory segment to address space
    shared_memory = shmat(shmid, NULL, 0);
    printf("Process attached at %p\n", shared_memory);

    // Read from stdin and write to shared memory
    printf("Enter some data to write to shared memory: ");
    read(0, buff, 100);
    strcpy(shared_memory, buff);

    printf("You wrote: %s\n", (char *)shared_memory);

    return 0;
}
