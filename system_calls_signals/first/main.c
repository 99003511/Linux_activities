#include "copy.h"

int main()
{
  bool c;
  c = copyfile();    // COPY FILE FUNCTION
  if(c)
  {
    printf("Content is copied\n");
  }
  else
  {
    printf("No content copied as per now\n");
  }
  
  return 0;
}
