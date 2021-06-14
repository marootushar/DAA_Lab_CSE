#include <stdio.h>
#include <string.h>

int main()
{
  char str[100], substr[100];
  printf("Enter the string : ");
  scanf("%s", str);
  printf("Enter the sub-string : ");
  scanf("%s", substr);
  int i, flag = 0, opcount = 0;
  for (i = 0; i < strlen(str) - strlen(substr) + 1; i++)
  {
    opcount++;
    if (str[i] != substr[0])
      continue;
    int j = 1;
    while (substr[j] != '\0' && substr[j] == str[i + j])
    {
      j++;
      opcount++;
    }
    if (substr[j] == '\0')
    {
      flag = 1;
      break;
    }
  }
  if (flag)
    printf("Substring found at index %d.\n", i);
  else
    printf("Substring not found.\n");
  printf("Opcount = %d",opcount);
}