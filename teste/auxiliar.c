#include "auxiliar.h"
#include <string.h>

int comecaCom(String palavra, String prefixo) {
	if(strncmp(palavra, prefixo, strlen(prefixo)) == 0)
		return 1;
	return 0;
}