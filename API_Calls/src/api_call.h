#ifndef api_call_H_
#define api_call_H_

//Function prototypes
char *http_get_request(char *url);
size_t static write_callback(void *buffer, size_t size, size_t num_member, void *userp);

#endif

/*
 * Creates a HTTPGET request to a desired url
 * url:		The passed url to get request
 * return:	The response to the get request
 */
char *http_get_request(char *url) {

	if( !strcmp(url, "") )
		return "Failed";

	if( url == NULL )
		return "Failed";

	//Variable to hold the response
	char *response = NULL;

	//Initializes the curl variable
    CURL *curl = curl_easy_init();

	//Sets URL for this transfer
    curl_easy_setopt(curl, CURLOPT_URL, url);
	//Asks for HTTP GET request
	curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
	//Follows http redirects
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
	//Callback for writing received data
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	//Pointer passed to the write callback
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

	//Performs the request with all the settings
    curl_easy_perform(curl);
	//Cleans the curl
    curl_easy_cleanup(curl);

	return response;
}

/*
 * Callback function used to format data and add it to the writedata pointer
 * buffer: Data coming from request
 * size: Size of the data
 * num_bytes: Number of bytes
 * user_pointer: The pointer passed from writedata
 */
size_t static write_callback(void *buffer, size_t size, size_t num_bytes, void *user_pointer){
	char **response_ptr = (char**)user_pointer;

	*response_ptr = strndup(buffer, (size_t) (size * num_bytes) );
}
