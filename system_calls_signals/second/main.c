#include "count.h"

int main()
{
  printf("Check for file contents\n");
  checkfile();
  printf("Lines Count : %d\n", getLines());
  printf("Words Count : %d\n", getWords());
  printf("Characters Count : %d\n", getCharacters());
}
