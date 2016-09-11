#include <string.h>
#include <stdio.h>

void reverseWord(char *p1, char *p2)
{
    char ch;
    
    if (p1 < p2) {
	do {
	    ch = *p1;
	    *p1 = *p2;
	    *p2 = ch;
	} while (++p1 < --p2);
    }
}

void compressWord(char *s) {
    char *p1, *p2;
    char ch;

    p2 = p1 = s;
    while (*p1 && *p2) {
	while (*p1 && (' ' != *p1))
	    p1++;
	if (!*p1 || !*(p1+1)) break;
	
	if (p1 == s) p2 = p1 + 1;
	else p2 = ++p1 + 1;
	
	if (*p1 != ' ') {
	    continue;
	}
	while (*p2 && (' ' == *p2))
	    p2++;
	while (*p2 && (' ' != *p2)) {
	    ch = *p1;
	    *p1 = *p2;
	    *p2 = ch;
	    p1++;
	    p2++;
	}
    }

    p1 = s + strlen(s)-1;
    while (p1 >= s && *p1 == ' ')
	*p1-- = 0;
}

void reverseWords(char *s) {
    compressWord(s);

    int len = strlen(s);
    int ch;
    char *prev, *curr;

    reverseWord(s, s+len-1);
    
    prev = s;
    while (*prev) {
	while (' ' == *prev)
	    prev++;
	if (!*prev) break;
	curr = prev+1;
	while (*curr && (' ' != *curr))
	    curr++;
	reverseWord(prev, curr-1);
	prev = curr;
    }
}

int main(void)
{
    char s[] = "   ";
//    compressWord(s);
    reverseWords(s);
    printf("%s@@", s);
    
    return 0;
}
