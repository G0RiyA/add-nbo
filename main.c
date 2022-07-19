#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char** argv) {
  FILE *fp;
  uint32_t a, b;
  if(argc != 3) {
    fprintf(stderr, "[Usage]: %s <file1> <file2>\n", *argv);
    exit(1);
  }

  if((fp = fopen(argv[1], "rb")) == NULL || fread(&a, 4, 1, fp) != 1) {
    fprintf(stderr, "File error: \"%s\"\n", argv[1]);
    exit(2);
  }

  if((fp = fopen(argv[2], "rb")) == NULL || fread(&b, 4, 1, fp) != 1) {
    fprintf(stderr, "File error: \"%s\"\n", argv[2]);
    exit(2);
  }

  a = __builtin_bswap32(a);
  b = __builtin_bswap32(b);

  printf("%u + %u = %u\n", a, b, a+b);

  return 0;
}
