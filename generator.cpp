#include <stdio.h>
#include <string.h>
int main(){
    int c, msglen, plen, i, j,mlen;
    char msg[100], poly[50], rem[100];

    printf("N bit Data: ");
	gets(msg);
	msglen = strlen(msg);
	mlen=msglen-1;

    printf("K bit Polynomial: ");
	gets(poly);
	plen = strlen(poly);
    printf("\n");
    for(i=0;i<plen;i++)
    {
        msg[mlen+i] = '0';
    }

    for (i = 0; i < msglen + plen - 1; i++){
	rem[i] = msg[i];
    }

    for (i = 0; i < msglen - 1; i++){
	if (rem[i] == '1'){
	    for (j = i; j < plen + i; j++){
		if (rem[j] == poly[j - i]) rem[j] = '0';
		else rem[j] = '1';
	    }
	}
	else{
	    for (j = i; j < plen + i; j++){
		if (rem[j] == '0') rem[j] = '0';
		else rem[j] = '1';
	    }
	}
    }
    printf("Generated message is: ");
    for (i = 0; i < msglen + plen - 1; i++){
	if (rem[i] == msg[i])
        msg[i] = '0';
	else msg[i] = '1';
	putchar(msg[i]);
    }
    printf("\n");

    return 0;
}
