#include <string.h>
#include <stdio.h>


char *thousands[] = {"", "Thousand", "Million", "Billion"};
char *under_twenty[] = {"", "One", "Two", "Three", "Four", "Five",
		      "Six", "Seven", "Eight", "Nine", "Ten",
		      "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
			"Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
	      "Seventy", "Eighty", "Ninety"};
long int dividers[] = {1, 1000, 1000000, 1000000000, 1000000000000};
char result[1024];

//return zero if all zero
int translate_hundred(int num, char *result)
{

  int hundred, ten;
  char *first_byte = result;
  
  result[0] = '\0';
  if ((hundred = num / 100))
      result += sprintf(result, "%s Hundred ",under_twenty[hundred]);

  num = num % 100;
  ten = num / 10;
  if (ten >= 2) {
    result += sprintf(result, "%s ", tens[ten]);
  } else if (ten == 1) {
    result += sprintf(result, "%s ", under_twenty[num]);
    goto RETURN;
  } 

  num = num % 10;
  if (num) {
    result += sprintf(result, "%s ", under_twenty[num]);
  }

 RETURN:
  return *first_byte;
}

char* numberToWords(int num)
{
  char *result_ptr = result, hundred_str[512];
  int hundred_num;

  strcpy(result_ptr, "Zero ");
  for (int nthousand = 3; nthousand >= 0; --nthousand) {
    if (nthousand)
      hundred_num = num / dividers[nthousand]
	- num / dividers[nthousand + 1] * 1000;
    else
      hundred_num = num % 1000;

    if (hundred_num < 0)
      hundred_num = 0;

    if (translate_hundred(hundred_num, hundred_str))
      result_ptr += sprintf(result_ptr, "%s%s ", hundred_str, thousands[nthousand]);
  }

  //eliminate the trailling space
  for(int i = strlen(result) - 1; result[i] == ' '; --i)
    result[i] = '\0';
  
  return result;
}

int main()
{
  int num;
  while(1) {
    scanf("%d", &num);
    puts(numberToWords(num));
  }
  return 0;
}
