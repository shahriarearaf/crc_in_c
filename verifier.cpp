#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(){
    int c, msglen, polylen, i, j;
    char message[100], polynomial[50], remainder[100];
    printf("Message sent: ");
	gets(message);
	msglen = strlen(message);

    printf("Polynomial: ");
	gets(polynomial);
	polylen = strlen(polynomial);

    for (i = 0; i < msglen; i++)
    {
        remainder[i] = message[i];
    }

    //xor perfomed here
    for (i = 0; i <= msglen - polylen; i++)
    {
            if (remainder[i] == '1')
            {
                for (j = i; j < polylen + i; j++)
                {
                    if (remainder[j] == polynomial[j - i])
                    remainder[j] = '0';
                    else remainder[j] = '1';
                }
            }
            else{
                for (j = i; j < polylen + i; j++)
                {
                    if (remainder[j] == '0') remainder[j] = '0';
                    else remainder[j] = '1';
                }
                }
    }

    int plen,mlen,prlen;
	plen = strlen(polynomial);
	mlen = strlen(message);
	prlen = mlen - plen;

	int count = 0;
    for (i = 0; i < msglen; i++)
    {
        if (remainder[i] == '1')
        {
            count++;
            continue;
        }
    }

    if (count == 0){
	printf("The message is transmitted successfully.\n");
	printf("The original message is: ");
	for (i = 0; i <=prlen; i++)
        {
           printf("%c",message[i]);
        }
	printf("\n");
    }
    else printf("Message is not transmitted successfully.\n");
    return 0;
}
