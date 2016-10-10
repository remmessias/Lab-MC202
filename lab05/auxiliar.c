#include "auxiliar.h"
#include <string.h>

int comecaCom(String a, String b) {
	if(strncmp(a, b, strlen(b)) == 0)
		return 1;
	return 0;
}