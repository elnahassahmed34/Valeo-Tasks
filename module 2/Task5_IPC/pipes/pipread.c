#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main() {
    const char* file = "./fifoChannel";
    int fd = open(file, O_RDONLY);
    if (fd < 0) return -1; /* no point in continuing */

    int value;
    ssize_t count = read(fd, &value, sizeof(int));
    if (count != sizeof(int)) {
        fprintf(stderr, "Error reading from the pipe.\n");
        close(fd);
        return -1;
    }

    close(fd); /* close pipe from read end */
    unlink(file); /* unlink from the underlying file */
    printf("Received value: %d\n", value);
    return 0;
}
