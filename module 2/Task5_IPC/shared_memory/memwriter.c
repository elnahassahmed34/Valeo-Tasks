/** Compilation: gcc -o memwriter memwriter.c -lrt -lpthread **/
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>

#define BackingFile "/my_shared_memory_file"
#define AccessPerms 0644
#define ByteSize 1024
#define SemaphoreName "/my_semaphore"

void report_and_exit(const char* msg) {
  perror(msg);
  exit(-1);
}

int main() {
  int fd = shm_open(BackingFile, O_RDWR | O_CREAT, AccessPerms);
  if (fd < 0) report_and_exit("Can't open shared mem segment...");

  ftruncate(fd, ByteSize);

  void* memptr = mmap(NULL, ByteSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if ((void*) -1 == memptr) report_and_exit("Can't get segment...");

  fprintf(stderr, "shared mem address: %p [0..%d]\n", memptr, ByteSize - 1);
  fprintf(stderr, "backing file:       /dev/shm%s\n", BackingFile );

  sem_t* semptr = sem_open(SemaphoreName, O_CREAT, AccessPerms, 0);
  if (semptr == (void*) -1) report_and_exit("sem_open");

  // Open the file for reading
  FILE* file = fopen("/home/nahass/Desktop/test/test.txt", "r");
  if (file == NULL) report_and_exit("fopen");

  // Read the content of the file
  char buffer[ByteSize];
  size_t read_size = fread(buffer, sizeof(char), ByteSize, file);
  if (read_size > 0) {
    strncpy(memptr, buffer, ByteSize);
  }

    sleep(12);

  // Close the file and post the semaphore
  fclose(file);
  sem_post(semptr);

  // Cleanup
  munmap(memptr, ByteSize);
  close(fd);
  sem_close(semptr);
  shm_unlink(BackingFile);
  return 0;
}



/*to open ls*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>

#define BackingFile "/my_shared_memory_file"
#define AccessPerms 0644
#define ByteSize 1024
#define SemaphoreName "/my_semaphore"

void report_and_exit(const char* msg) {
  perror(msg);
  exit(-1);
}

int main() {
  int fd = shm_open(BackingFile, O_RDWR | O_CREAT, AccessPerms);
  if (fd < 0) report_and_exit("Can't open shared mem segment...");

  ftruncate(fd, ByteSize);

  void* memptr = mmap(NULL, ByteSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if ((void*) -1 == memptr) report_and_exit("Can't get segment...");

  fprintf(stderr, "shared mem address: %p [0..%d]\n", memptr, ByteSize - 1);
  fprintf(stderr, "backing file:       /dev/shm%s\n", BackingFile );

  sem_t* semptr = sem_open(SemaphoreName, O_CREAT, AccessPerms, 0);
  if (semptr == (void*) -1) report_and_exit("sem_open");

  // Execute "ls" command and capture its output
  FILE* ls_output = popen("ls /path/to/your/directory", "r");
  if (ls_output == NULL) report_and_exit("popen");

  // Read the output and write to shared memory
  char buffer[ByteSize];
  size_t read_size = fread(buffer, sizeof(char), ByteSize, ls_output);
  if (read_size > 0) {
    strncpy(memptr, buffer, ByteSize);
  }
    
    sleep(12);

  // Close the popen stream and the semaphore
  pclose(ls_output);
  sem_post(semptr);

  // Cleanup
  munmap(memptr, ByteSize);
  close(fd);
  sem_close(semptr);
  shm_unlink(BackingFile);
  return 0;
}
*/