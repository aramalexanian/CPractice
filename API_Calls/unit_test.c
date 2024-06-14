#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include "api_call.h"

int main(void){
	printf("Test function char *web_request(char *url) with https://api.agify.io?name=Aram.\nExpected Result: Pass\n");
	char *result = web_request("https://api.agify.io?name=Aram");
	printf("Result: ");
	if( strcmp(result, "{\"count\":2550,\"name\":\"Aram\",\"age\":52}") == 0) {
		printf("Pass\n");
	} else {
		printf("Fail\nOutput: %s", result);
	}
}

