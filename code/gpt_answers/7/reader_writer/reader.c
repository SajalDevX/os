#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>

int main() {
    int fd;
    char str[200];
    int chars = 0, words = 0, lines = 0;
    int in_word = 0;

    mkfifo("fifo1", 0666);  // Create FIFO if not exists

    fd = open("fifo1", O_RDONLY);
    while (read(fd, str, sizeof(str)) > 0) {
        for (int i = 0; str[i] != '\0'; i++) {
            chars++;
            if (str[i] == '\n') lines++;
            if (isspace(str[i])) in_word = 0;
            else if (in_word == 0) {
                in_word = 1;
                words++;
            }
        }
    }
    close(fd);

    printf("\n--- Text Statistics ---\n");
    printf("Characters: %d\n", chars);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}
