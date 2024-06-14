#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include "api_call.h"


int main(int argc, char *argv[])
{
	char* url = argv[1];

	char* url_return = NULL;

	url_return = web_request(url);

	printf("%s", url_return);

}//End of main
