#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fd;
    char str[200];

    mkfifo("fifo1", 0666);  // Create FIFO if not exists

    printf("Enter sentences (use Ctrl+D to end):\n");
    fd = open("fifo1", O_WRONLY);
    while (fgets(str, sizeof(str), stdin))
        write(fd, str, sizeof(str));
    close(fd);

    return 0;
}
