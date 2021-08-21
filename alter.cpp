#include <stdio.h>
#include <string.h>
int main(){
    int msglen, i, alter;
    char msg[100];

    printf("N bit Data: ");
	gets(msg);
	msglen = strlen(msg);

	printf("Which position should be altered: ");
	scanf("%d",&alter);

	if(msg[alter-1] == '0')
        msg[alter-1] = '1';
    else msg[alter-1] = '0';

    for(i=0;i<msglen;i++)
    {
        putchar(msg[i]);
    }


}
