#include <stdbool.h>

bool match_star(char *s, char *p);
bool match(char *s, char *p);

bool match_star(char *s, char *p)
{
        if(!*s)
            return true;

        if(match(s, p + 1))
                        return true;

        for(int i = 0; s[i] && (s[i] == p[-1] || '.' == p[-1]); ++i) {
                if(match(s + i + 1, p + 1)) {
                        return true;
                }
        }

        return false;
}
bool match(char *s, char *p)
{
        while(*s && *p) {
                if(p[1] && '*' == p[1]) {
                        return match_star(s, p + 1);
                } else if('.' == *p || *p == *s) {
                        ++p;
                        ++s;
                } else {
                        return false;
                }
        }

        while(p[0] && p[1] && '*' == p[1])
            p += 2;

        if(!*p && !*s)
                return true;
        else
                return false;

}

bool isMatch(char* s, char* p)
{
        return match(s, p);
}
