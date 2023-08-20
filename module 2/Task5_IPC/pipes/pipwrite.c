#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <-r or -l>\n", argv[0]);
        return -1;
    }

    int value;
    if (strcmp(argv[1], "-r") == 0) {
        value = 0;
    } else if (strcmp(argv[1], "-l") == 0) {
        value = 1;
    } else {
        fprintf(stderr, "Invalid argument. Please provide -r or -l.\n");
        return -1;
    }

    const char* pipeName = "./fifoChannel";
    mkfifo(pipeName, 0666); /* read/write for user/group/others */
    int fd = open(pipeName, O_CREAT | O_WRONLY); /* open as write-only */
    if (fd < 0) return -1; /* can't go on */

    write(fd, &value, sizeof(int));
    close(fd); /* close pipe */
    unlink(pipeName); /* unlink from the implementing file */
    printf("Value %d sent to the pipe.\n", value);
    return 0;
}
