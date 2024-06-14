#ifndef api_call_H_
#define api_call_H_

char *web_request(char *url);

size_t static write_callback(void *buffer, size_t size, size_t num_member, void *userp);

#endif

char *web_request(char *url) {
	char *response = NULL;

    CURL *curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);

	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

	return response;
}

size_t static write_callback(void *buffer, size_t size, size_t num_member, void *userp){
	char **response_ptr = (char**)userp;

	*response_ptr = strndup(buffer, (size_t) (size * num_member) );
}
