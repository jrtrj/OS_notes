#include <stdio.h>
#include <unistd.h>     
#include <sys/types.h>  
#include <sys/stat.h>   
#include <fcntl.h>      

int main() {
    int n, fd, fr;
    char buff[50];

    fd = open("text.txt", O_RDONLY);
    printf("file descriptor %d",fd);
    n = read(fd, buff, 10);
    fr = open("text.txt",O_WRONLY|O_CREATE);
    write(fr, buff, n);  
    return 0;
}
