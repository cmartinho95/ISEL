/**
 *
 *  ISEL, LEIC, Computacional Systems Programming (PSC)
 * 
 *  Demonstrates usage of the CURL and JANSSON open source libraries.
 *
 *  Executes an HTTP GET on Thoth API, and display response contents in stdout.
 *
 *  Generate executable with: gcc -o http-get-json http-get-json.c -lcurl -ljansson
 *
 *  Execute: ./http-get-json
 *  or
 *  ./http-get-json  "https://adeetc.thothapp.com/apI/V1/classes/801/workitems"
 *
 *  Carlos Martins, May 2018
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <jansson.h>

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

    /* grow the buffer in order to hold more byteCount bytes */
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
 * Execute an HTTP GET for the specified URL and return data in a memory buffer
 * dynamically allocated.
 */

static char *http_get(const char *url)
{
	static int curl_global_init_called = 0;
    CURL *curl_handle;
    CURLcode curl_result;
    Buffer buffer = { .size = 0, .memory = NULL };	
    char *result = NULL;
    
    /* initialize once the libcurl library; cleanup will be done at program exit */
	if (!curl_global_init_called) {
    	curl_global_init(CURL_GLOBAL_ALL);
    	atexit(curl_global_cleanup);
		curl_global_init_called = 1;
	}
		
    /* initializa a CURL handle in order to perform an HTTP GET request */
    curl_handle = curl_easy_init();
    if (!curl_handle) {
        fprintf(stderr, "***error: curl_easy_init() failed\n");
        return result;
    }
    
    /* set the VERBOSE option */
    //curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);
    
    /* configure the handler with the URL */
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    
    /* some servers don't like requests that are made without a user-agent
	 * field, so we provide one */
	curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    
    /* follow HTTP 3xx redirects */
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
    
    /* set WRITEFUNCTION and WRITEDATA to save body data in a block of memory */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_to_memory);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &buffer);

    /* perform the HTTP GET request */
    curl_result = curl_easy_perform(curl_handle);
    if (curl_result != CURLE_OK) {
        fprintf(stderr, "***error: curl_easy_perform() failed: %s\n",
                curl_easy_strerror(curl_result));
		goto cleanup_handle;
    }

    /* we got success, return the memory buffer */
    result = buffer.memory;

    /**
	 * for debug purposes, we can show the contents of the data buffer
	 * on the stderr stream
	 */
    /*
    fprintf(stderr, "%zu bytes received\n", (long)buffer.size);
    fprintf(stderr, "%.*s", (int)buffer.size, buffer.memory);
    */

cleanup_handle:
    /* cleanup the curl handler */
    curl_easy_cleanup(curl_handle);
	return result;
}

/**
 * Execute an HTTP GET and display the JSON's objects on the console.
 */

int main(int argc, char *argv[])
{
    size_t i, count;
    char *json_text;
    char *url;
    json_t *root, *workitems;
    json_error_t error;
    int result = -1;

	/* assume a default URL if none is specified in the command line */
    url = (argc > 1) ? argv[1] : "https://adeetc.thothapp.com/apI/V1/classes/800/workitems";

    /* get the JSON text from the URL */
		
	json_text = http_get(url);
	if(json_text == NULL) {
    	fprintf(stderr, "***error: request returned NULL\n");
    	return result;
	}

    /* load json from JSON text */
    root = json_loads(json_text, 0, &error);

    /* now, we can free the memory buffer */
    free(json_text);
	
    if(root == NULL) {
    	/* an error  occured while parsing JSON text */
        fprintf(stderr, "***error: on line %d: %s\n", error.line, error.text);
        return result;
    }
    /* the root must be an object */
    if(!json_is_object(root)) {
        fprintf(stderr, "***error: root is not an object\n");
        goto cleanup;
    }
    /* get the workitems field from root object; this field must be an array */
    workitems = json_object_get(root, "workItems");
    if(!json_is_array(workitems)) {
        fprintf(stderr, "***error: workItems is not an array\n");
        goto cleanup;
    }
    /* read the arra elements and display its contents on the console */
    for(i = 0, count = json_array_size(workitems); i < count; i++) {
        json_t *workitem, *id, *acronym, *title, *startDate, *dueDate;
        
        /* get the workitems[i] object */
        workitem = json_array_get(workitems, i);
        if(!json_is_object(workitem)) {
            fprintf(stderr, "***error: workitems[%zu] is not an object\n", i + 1);
            goto cleanup;
        }
        /* get the workitems[i].id */
        id = json_object_get(workitem, "id");
        if(!json_is_integer(id)) {
            fprintf(stderr, "***error: workitems[%zu].id is not a number\n", i + 1);
            goto cleanup;
        }
        
        /* get the workitems[i].acronym field */
        acronym = json_object_get(workitem, "acronym");
        if(!json_is_string(acronym)) {
            fprintf(stderr, "***error: workitems[%zu].acronym is not a string\n", i + 1);
            goto cleanup;
        }
        
        /* get the workitems[i].title field */
        title = json_object_get(workitem, "title");
        if(!json_is_string(title)) {
            fprintf(stderr, "error: workitems[%zu].title is is not a string\n", i + 1);
            goto cleanup;
        }
        /* get the workitems[i].startDate field */
        startDate = json_object_get(workitem, "startDate");
        if(!json_is_string(startDate)) {
            fprintf(stderr, "error: workitems[%zu].startDate is is not a string\n", i + 1);
            goto cleanup;
        }
        /* get the workitems[i].dueDate field */
        dueDate= json_object_get(workitem, "dueDate");
        if(!json_is_string(dueDate)) {
            fprintf(stderr, "error: workitems[%zu].dueDate is is not a string\n", i + 1);
            goto cleanup;
        }
		
		/* print the workitem's information */
        printf("\n{\n\tid: %lld\n\tacronym: %s\n\ttitle: %s\n"
               "\tstartDate: %s\n\tdueDate: %s\n}",
               json_integer_value(id),
               json_string_value(acronym),
               json_string_value(title),
               json_string_value(startDate),
               json_string_value(dueDate));
	    if (i < count - 1)
			putchar(',');
		else if (i == count - 1)
			putchar('\n');
    }
    result = 0;
	
cleanup:

	/**
     * decrement reference to the root JSON object which frees all memory allocated
     * to build the object tree.
	 */
    json_decref(root);
    return result;
}
