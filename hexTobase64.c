#include<stdio.h>
#include<string.h>

#define BASE64_MASK		0xfc000000
#define BASE64_SHIFT_LEFT	6
#define BASE64_SHIFT_RIGHT	26

unsigned char hexStr[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
unsigned char base64[64];
unsigned char base64Str[64];
unsigned char base64Tbl[64] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','-','_'};

unsigned char *answer = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

void main(int argc, char* argv[])
{
	int i, j = 0;
	unsigned int tmpHex;

	if (argc > 1) {
		strcpy(hexStr, argv[1]);
	}

	for (i = 0; sscanf(hexStr + 2*i, "%6x", &tmpHex) > 0; i += 3) {
		tmpHex <<= 8;
		base64[j + 0] = (tmpHex & BASE64_MASK) >> BASE64_SHIFT_RIGHT;
		base64[j + 1] = ((tmpHex << BASE64_SHIFT_LEFT*1) & BASE64_MASK) >> BASE64_SHIFT_RIGHT;
		base64[j + 2] = ((tmpHex << BASE64_SHIFT_LEFT*2) & BASE64_MASK) >> BASE64_SHIFT_RIGHT;
		base64[j + 3] = ((tmpHex << BASE64_SHIFT_LEFT*3) & BASE64_MASK) >> BASE64_SHIFT_RIGHT;
		j += 4;
	}

	printf("\n");
	if (argc == 1) {
		printf("Original:%s\n", hexStr);
		printf("Expected:%s\n", answer);
	}

	for (i = 0; i < strlen(base64); i++) {
		base64Str[i] = base64Tbl[base64[i]];
	}

	base64Str[i] = '\0';
	printf("Result  :%s\n", base64Str);

	printf("\n");

	if (argc == 1) {
		if (!strncmp(answer, base64Str, 64)) {
			printf("\nRIGHT!\n");
		} else {
			printf("\nWRONG!\n");
		}
	}
}
