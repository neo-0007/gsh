// ask_service.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "json_parser.h"

struct Response {
    char *data;
    size_t size;
};

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    struct Response *response = (struct Response *)userdata;
    size_t total_size = size * nmemb;

    response->data = realloc(response->data, response->size + total_size + 1);
    if (response->data == NULL) {
        fprintf(stderr, "Failed to allocate memory for response data.\n");
        return 0;
    }

    memcpy(&(response->data[response->size]), ptr, total_size);
    response->size += total_size;
    response->data[response->size] = '\0';

    return total_size;
}

void ask_gemini(const char *question) {
    CURL *curl;
    CURLcode res;

    const char *api_key = "GEMINI_API_KEY";
    const char *url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent";

    char json_payload[1024];
    snprintf(json_payload, sizeof(json_payload), "{\"contents\": [{\"parts\":[{\"text\": \"%s\"}]}]}", question);

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl) {
        char full_url[256];
        snprintf(full_url, sizeof(full_url), "%s?key=%s", url, api_key);
        curl_easy_setopt(curl, CURLOPT_URL, full_url);

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_payload);

        struct Response response = {0};
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            parse_and_print_text(response.data);
        }

        free(response.data);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}