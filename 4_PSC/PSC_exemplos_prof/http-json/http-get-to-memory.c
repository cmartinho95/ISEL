/**
 *
 *  ISEL, LEIC, Computacional Systems Programming (PSC)
 * 
 *  Demonstrates usage of the CURL open source library.
 *
 *  Executes an HTTP GET on the specified site and store the response body
 *  in a dynamically allocated buffer.
 *
 *  Generate executable with: gcc -o http-get-to-memory http-get-to-memory.c -lcurl
 *
 *  Execute: ./http-get-to-memory
 *  or
 *  ./http-get-to-memory www.google.com > google.html
 *
 *  Carlos Martins, May 2018
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

/**
 *  The buffer type.
 */

typedef struct _Buffer {
    size_t size;
    char *memory;
} Buffer;

/**
 * A write_function that copies data to a buffer.
 */

static size_t write_to_memory(char *data, size_t size, size_t nmemb, void *context)
{
    size_t byteCount = size * nmemb;
    Buffer *bufptr = (Buffer *)context;

    /* grow the buffer in order to hold the new bytes */
    bufptr->memory = realloc(bufptr->memory, bufptr->size + byteCount + 1);
    if (bufptr->memory == NULL) {
        /* out of memory! */
        fprintf(stderr, "***error: not enough memory\n");
        return 0;
    }
    /* copy the new data block */
    memcpy(bufptr->memory + bufptr->size, data, byteCount);

    /* update size and close the C string */
    bufptr->size += byteCount;
    bufptr->memory[bufptr->size] = '\0';
    return byteCount;
}

/**
 * Executes an HTTP GET and copy the data to a memory buffer.
 */

int main(int argc, char *argv[])
{
    CURL *curl_handle;
    CURLcode result;
    char *url;
    Buffer buffer = { .size = 0, .memory = NULL };
    int exitcode = 0;
    
    /* define the URL to GET */
    url = (argc > 1) ? argv[1] : "http://www.isel.pt";
    
    /* initialize the libcurl library */
    curl_global_init(CURL_GLOBAL_ALL);
    
    /* initializa a CURL handle to perform the HTTP GET */
    curl_handle = curl_easy_init();
    if (!curl_handle) {
        fprintf(stderr, "***error: curl_easy_init() failed\n");
        exitcode = -1;
        goto global_cleanup;
    }
    
    /* set the VERBOSE option */
    //curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);

    /* configure the handler with the URL */
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    
    /* follow HTTP 3xx redirects */
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);

    /* set WRITEFUNCTION and WRITEDATA to save body data in a block of memory */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_to_memory);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &buffer);

    
    /* perform the HTTP get request */
    result = curl_easy_perform(curl_handle);
    if (result != CURLE_OK) {
        fprintf(stderr, "***error: curl_easy_perform() failed: %s\n",
                curl_easy_strerror(result));
        exitcode = -1;
        goto handle_cleanup;
    }

    /* success - display the data on the console  */
    
    fprintf(stderr, "%lu bytes received\n", (long)buffer.size);
    fprintf(stdout, "%.*s", (int)buffer.size, buffer.memory);

handle_cleanup:
    /* cleanup curl handler */
    curl_easy_cleanup(curl_handle);

global_cleanup:
    /* global libcurl cleanup */
    curl_global_cleanup();

    /* free the memory buffer */
    free(buffer.memory);
    return exitcode;
}
