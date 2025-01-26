// json_parser.c
#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>

void parse_and_print_text(const char *json_response) {
    cJSON *root = cJSON_Parse(json_response);
    if (root == NULL) {
        fprintf(stderr, "Error parsing JSON response.\n");
        return;
    }

    cJSON *error = cJSON_GetObjectItem(root, "error");
    if (error != NULL) {
        cJSON *error_message = cJSON_GetObjectItem(error, "message");
        if (error_message != NULL && cJSON_IsString(error_message)) {
            fprintf(stderr, "API Error: %s\n", error_message->valuestring);
        } else {
            fprintf(stderr, "Unknown API error.\n");
        }
        cJSON_Delete(root);
        return;
    }

    cJSON *candidates = cJSON_GetObjectItem(root, "candidates");
    if (candidates != NULL && cJSON_IsArray(candidates)) {
        cJSON *candidate = cJSON_GetArrayItem(candidates, 0);
        if (candidate != NULL) {
            cJSON *content = cJSON_GetObjectItem(candidate, "content");
            if (content != NULL) {
                cJSON *parts = cJSON_GetObjectItem(content, "parts");
                if (parts != NULL && cJSON_IsArray(parts)) {
                    cJSON *part = cJSON_GetArrayItem(parts, 0);
                    if (part != NULL) {
                        cJSON *text = cJSON_GetObjectItem(part, "text");
                        if (text != NULL && cJSON_IsString(text)) {
                            printf("%s\n", text->valuestring);
                        } else {
                            fprintf(stderr, "Error: 'text' field not found or is not a string.\n");
                        }
                    } else {
                        fprintf(stderr, "Error: 'parts' array is empty.\n");
                    }
                } else {
                    fprintf(stderr, "Error: 'parts' field not found or is not an array.\n");
                }
            } else {
                fprintf(stderr, "Error: 'content' field not found.\n");
            }
        } else {
            fprintf(stderr, "Error: No candidate found in the response.\n");
        }
    } else {
        fprintf(stderr, "Error: 'candidates' field not found or is not an array.\n");
    }

    cJSON_Delete(root);
}