#include <stdio.h>
#include <stdlib.h>

#define LINE_LENGTH 3
#define STDIN 0
#define BUFFER_SIZE 10

int main(int argc, char *argv[]) {
  if (argc == 0) {
      return -1;
  }
  else if (argc == 1) {
      // single argument in input, so only 'cat' command was entered, therefore
      // echo all following command line input
      while (1) {
          // (re-)initialize array to default, empty state such that in future
          // loop iterations, the entirety of the array is cleared from the
          // previous write (if any). This way we avoid re-outputting prior
          // stdinput that would otherwise remain in the buffer.
          char buffer[BUFFER_SIZE] = {};
          ssize_t num_bytes_read = read(STDIN, buffer, BUFFER_SIZE);
          if (num_bytes_read) {
              int i;
              for (i = 0; i < BUFFER_SIZE; i++) {
                  printf("%c", buffer[i]);
              }
          } else {
              return -1; // EOF
          }
      }
  }
  else {
      // print out contents of all files passed as command line arguments
      int i;
      for (i = 1; i < argc; i++) {
          char* filename = argv[i];
          FILE* file = fopen(filename, "r");  // read-only
          if (file == NULL) {
              printf("No such file or directory\n");
              return -1;
          }
          else {
              printf("file: %s\n", filename);
              char* line = malloc(LINE_LENGTH);
              while (fgets(line, LINE_LENGTH, file) != NULL)
                  printf("%s", line);
              free(line);
              fclose(file);
          }
      }
  }
  return 0;
}
