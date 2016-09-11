#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//eliminate duplicated '*'s, O(n)
void preprocess(char *str, int len)
{
  char *ptr1, *ptr2;

  //round 1, dig holes
  for (ptr1 = ptr2 = str; *ptr2; ptr1 = ptr2) {
    ptr2++;
    if (*ptr1 == '*') {
      while (*ptr2 == *ptr1) {
	*ptr2 = 0;
	++ptr2;
      }
    }
  }

  //round2, phase 1, initialization
  ptr1 = str;
  while (*ptr1)
    ++ptr1;
  if (ptr1 - str >= len)
    return;
  
  ptr2 = ptr1 + 1;
  while ((ptr2 - str < len - 1) && !*ptr2)
    ++ptr2;
  *ptr1 = *ptr2;
  *ptr2 = 0;

  //round2, phase2, eliminate holes
  while(ptr2 - str < len - 1) {
    while (*ptr1)
      ++ptr1;
    while ((ptr2 - str < len - 1) && !*ptr2)
      ++ptr2;
    *ptr1 = *ptr2;
    *ptr2 = 0;
  }
}

int main()
{
  char s[1024];
  while(1) {
    scanf("%s", s);
    preprocess(s, strlen(s));
    puts(s);
  }
  return 0;
}

bool isMatch(char* s, char* p) {
    
}
