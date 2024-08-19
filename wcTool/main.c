#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int getfilesize(FILE* file);
int getnumberoflines(FILE* file);
int getnumberofwords(FILE* file);
int getnumberofcharacters(FILE* file);

void print_usage(const char *program_name) {
    printf("Usage: %s <option> <file>\n", program_name);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    print_usage(argv[0]);
    return 1;
  }

  if(argc == 3) {
    char* option = argv[1];
    char* filename = argv[2];

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
      perror("Error opening file");
      return 1;
    }

    // get file size in bytes
    if(strcmp(option, "-c") == 0) {
      int bytesize = getfilesize(file);
      printf("%d %s \n", bytesize, filename);
    } else if(strcmp(option, "-l") == 0) {
      // get number of lines in file
      int linecount = getnumberoflines(file);
      printf(" %d %s \n", linecount, filename);
    } else if(strcmp(option, "-w") == 0) {
      // get number of words in file
      int wordcount = getnumberofwords(file);
      printf(" %d %s \n", wordcount, filename);
    } else if(strcmp(option, "-m")== 0) {
      // get the number of characters in a file
      int charactercount = getnumberofcharacters(file);
      printf(" %d %s \n", charactercount, filename);
    }
    fclose(file);
  } else if (argc == 2) {
      char* filename = argv[1];
      FILE* file = fopen(filename, "r");

      if (file == NULL) {
        perror("Error opening file");
        return 1;
      }

      int linecount = getnumberoflines(file);
      fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning
      int wordcount = getnumberofwords(file);
      fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning
      int bytesize = getfilesize(file);
      fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning
 
      printf(" %d %d %d %s\n", linecount, wordcount, bytesize, filename);
      fclose(file);
  }

  return 0;
}

int getfilesize(FILE* file) {
    fseek(file, 0L, SEEK_END);
    long int bytesize = ftell(file); 
    fseek(file, 0L, SEEK_SET); // Reset file pointer to the beginning
    return bytesize;
}

int getnumberoflines(FILE* file) {
  int ch, linecount = 0;
  while((ch = fgetc(file)) != EOF) {
    if(ch == '\n') {
      linecount++;
    }
  }
  return linecount;
}

int getnumberofwords(FILE* file) {
  int wordcount = 0;
  char ch;
  bool isword = false;
  while ((ch = fgetc(file)) != EOF) {
    if (isspace(ch)) {
      if (isword) {
          isword = false;
      }
    } else {
      if (!isword) {
          isword = true;
          wordcount++;
      }
    }
  }
  return wordcount; 
}

int getnumberofcharacters(FILE* file) {
  int ch, characterCount = 0;
  while ((ch = fgetc(file)) != EOF) {
    characterCount++;
  }
  return characterCount;
}