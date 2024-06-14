#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include "../api_call.h"
/*
 * Unit test for api_call.h
 */
int main(void){
	//Result of the tests
	char *result;
	/*
	 * TEST 1 Checking the results from an appropriat get request
	 */
	printf("Test function char *http_get_request(char *url) with https://api.agify.io?name=Aram.\n");
	result = http_get_request("https://api.agify.io?name=Aram");
	printf("Result: ");
	if( !strcmp(result, "{\"count\":2550,\"name\":\"Aram\",\"age\":52}") ) {
		printf("Pass\n");
	} else {
		printf("Fail\nOutput: %s", result);
	}

	/*
     * TEST 2 Checking the results from an empty ulr fail
     */
	printf("\nTest function char *http_get_request(char *url) with \"\"\n");
	result = http_get_request("");
	printf("Result: ");
	if( !strcmp(result, "Failed") ) {
		printf("Pass\n");
	} else {
		printf("Fail\nOutput: %s", result);
	}
	
}

