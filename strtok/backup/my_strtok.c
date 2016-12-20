#include <stdio.h>
#include <string.h>  
#include <malloc.h>
#include <string.h>

#include <string.h>

/* return length of initial segment of p that consists entirely of
 * characters from s */


int _strspn(const char *p, const char *s)
{
	int i, j;

	for (i = 0; p[i]; i++) {
		for (j = 0; s[j]; j++) {
			if (s[j] == p[i])
				break;
		}
		if (!s[j])
			break;
	}
	return (i);
}
#include <string.h>
int _strcspn (const char *p, const char *s)
{
	int i, j;

	for (i = 0; p[i]; i++) {
		for (j = 0; s[j]; j++) {
			if (s[j] == p[i])
				break;
		}
		if (s[j])
			break;
	}
	return (i);
}

#include <string.h>
char *my_strtok(char *p, const char *tok)
{
static char    *t;	/* XXX */
	char *r;
	int n;

	if (p)
		t = p;

	r = t + _strspn (t, tok);
	if (!(n = _strcspn (r, tok)))
		return (0);
	t = r + n;
	if (*t)
		*t++ = 0;
	return (r);
}
