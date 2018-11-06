/**
 *
 *  ISEL, LEIC, Computacional Systems Programming (PSC)
 * 
 *  Demonstrates usage of the CURL open source library.
 *
 *  Executes an HTTP GET and display response body in stdout.
 *
 *  Generate executable with: gcc -o http-get http-get.c -lcurl
 *
 *  Execute: ./http-get www.tsf.pt
 *  or
 *  ./http-get www.isel.pt > isel.html
 *
 *  Carlos Martins, May 2018
 *
 **/

#include <stdio.h>
#include <curl/curl.h>

/**
 * Execute an HTTP GET and display the response's body on the stdout
 */

int main(int argc, char *argv[])
{
	CURL *curl_handle;
	CURLcode result;
	char *url;
    int exitcode = 0;
	
	url = (argc > 1) ? argv[1] : "http://www.isel.pt";
    
  	/* global initialize */
	curl_global_init(CURL_GLOBAL_ALL);
	/* initialize a curl handle */
	curl_handle = curl_easy_init();
    if (!curl_handle) {
    	exitcode = -1;
        goto global_cleanup;
    }
	
	/**
	 * configure the curl handle
	 */
	
    /* set the URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);

    /* follow HTTP 3xx redirects */
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);

    /* some servers don't like requests that are made without a user-agent
       field, so we provide one */
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
	
	/**
	 *
	 */
    //curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, stdout);
	
	
	/**
	 * HTTP contents will be written to the console.
	 */

    /**
	 * perform the HTTP GET, result will get the return code
	 */
    result = curl_easy_perform(curl_handle);
    if (result != CURLE_OK)
		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(result));

handle_cleanup:
    /* cleanup curl handler */
    curl_easy_cleanup(curl_handle);

global_cleanup:
    /* global libcurl cleanup */
    curl_global_cleanup();

    return exitcode;
}
