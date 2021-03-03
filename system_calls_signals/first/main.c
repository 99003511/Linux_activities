#include "copy.h"

int main()
{
  bool c;
  c = copyfile();
  if(c)
  {
    printf("Content copied\n");
  }
  else
  {
    printf("No content copied\n");
  }
  
  return 0;
}
