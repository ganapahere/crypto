#include<stdio.h>
#include<string.h>

#define MIN(a,b) ((a) < (b) ? a : b)

unsigned char str1[] = "1c0111001f010100061a024b53535009181c";
unsigned char str2[] = "686974207468652062756c6c277320657965";

void main(int argc, char* argv[])
{
	int i, j, len;
	unsigned char x = 0, y = 0;
	unsigned char result[36] = {};

	if (argc > 1) {
		strcpy(str1, argv[1]);
		strcpy(str2, argv[2]);
	}

	printf("String1: %s\n", str1);
	printf("String2: %s\n", str2);

	len = MIN(strlen(str1), strlen(str2));

	for (i = 0, j = 0; i < len; i += 2, j += 1) {
		sscanf(str1 + i, "%2hhx", &x);
		sscanf(str2 + i, "%2hhx", &y);
		result[j] = (x) ^ (y);
	}


	printf("Result : ");
	for (j = 0; j < len/2; j += 1) {
		printf("%02x", result[j]);
	}

	printf("\n");

}
