#include "addons.h"

int strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') ++i;
    return i;
}

void append(char s[], char n) {
    int len = strlen(s);
    s[len] = n;
    s[len+1] = '\0';
}

int __strcmp(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') return 0;
    }
    return s1[i] - s2[i];
}

void* __memmove(void *dest, const void *src, size_t len)
{
  char *d = (char*)dest;
  const char *s = (const char*)src;
  if (d < s)
    while (len--)
      *d++ = *s++;
  else
    {
      char *lasts = (char*)s + (len-1);
      char *lastd = d + (len-1);
      while (len--)
        *lastd-- = *lasts--;
    }
  return dest;
}