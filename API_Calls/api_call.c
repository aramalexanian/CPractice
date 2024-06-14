#include <stdio.h>
#include <curl/curl.h>


int main(int argc, char *argv[])
{
	char* url = argv[1];

	CURL *curl = curl_easy_init();
	
	if(curl) {
		CURLcode result;
		curl_easy_setopt(curl, CURLOPT_URL, url);
		result = curl_easy_perform(curl);
		printf("\n");
	}
	curl_easy_cleanup(curl);
}//End of main
