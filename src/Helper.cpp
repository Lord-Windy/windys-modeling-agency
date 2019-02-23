//
// Created by sam on 2/20/19.
//

#include "Helper.h"

int load_from_file(const char *filename, char **result) {
  int size = 0;
  FILE *f = fopen(filename, "rb");
  if (f == nullptr)
  {
    *result = nullptr;
    return -1; // -1 means file opening fail
  }
  fseek(f, 0, SEEK_END);
  size = ftell(f);
  fseek(f, 0, SEEK_SET);
  *result = (char *)malloc(size+1);
  if (size != fread(*result, sizeof(char), size, f))
  {
    free(*result);
    return -2; // -2 means file reading fail
  }
  fclose(f);
  (*result)[size] = 0;
  return size;
}
