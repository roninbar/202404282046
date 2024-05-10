#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  const size_t nbytes = 100;
  char buffer[nbytes];

  // Open the file for reading
  int fd = open("example.txt", O_RDONLY);

  if (fd == -1) {
    perror("Error opening file");
    return 1;
  }

  // Read data from the file
  ssize_t count = read(fd, buffer, nbytes);

  if (count == -1) {
    perror("Error reading from file");
    close(fd); // Close the file before returning on error
    return 1;
  }

  // Close the file
  if (close(fd) == -1) {
    perror("Error closing file");
    return 1;
  }

  // Print the read data
  printf("Read %zd bytes: %.*s\n", count, (int)count, buffer);

  return 0;
}
