#include<stdio.h>
#include<stdlib.h>
#include<openssl/sha.h>
#include<string.h>
#pragma warning(disable:4996)

void getSHA256(const char* str, char* result)
{
	SHA256_CTX ctx;
	SHA256_Init(&ctx);
	SHA256_Update(&ctx, str, strlen(str));
	unsigned char md[32] = { 0 };
	SHA256_Final(md, &ctx);
	for (int i = 0; i < 32; i++)
	{
		sprintf(&result[i * 2], "%02x", md[i]);
	}
}

int main()
{
	char result[65] = { 0 };
	getSHA256("Hello World!", result);
	printf("SHA256 value: %s\n", result);
	return 0;
}