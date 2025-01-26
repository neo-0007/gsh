// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask_service.h" 


void print_help();
void print_version();

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("No arguments provided. Use -h to see available options.\n");
        return 1;
    }

    int invalid_options = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
            print_version();
            return 0;
        } else if (strcmp(argv[i], "-s") == 0) {
            if (i + 1 < argc) {
                char question[1024] = {0};
                for (int j = i + 1; j < argc; j++) {
                    strcat(question, argv[j]);
                    if (j < argc - 1) {
                        strcat(question, " ");
                    }
                }
                ask_gemini(question);
                return 0;
            } else {
                printf("Error: No question provided after -s.\n");
                return 1;
            }
        } else {
            printf("Unknown option: %s\n", argv[i]);
            invalid_options = 1;
        }
    }

    if (invalid_options) {
        printf("Use -h to see available options.\n");
        return 1;
    }

    return 0;
}

void print_help()
{

    printf("\n");
    printf("_|_|_|    _|_|_|  _|    _|  \n");
    printf("_|        _|        _|    _|  \n");
    printf("_|  _|_|    _|_|    _|_|_|_|  \n");
    printf("_|    _|        _|  _|    _|  \n");
    printf("  _|_|_|  _|_|_|    _|    _|  \n");
    printf("                              \n");
    printf("                              \n");

    printf("Usage: gsh [OPTION]...\n");
    printf("Options:\n");
    printf("  -h, --help     Display this help and exit\n");
    printf("  -v, --version  Output version information and exit\n");
    printf("  -s <question>  Send a question to Gemini and print the response\n");
}

void print_version()
{
    printf("GSH Version 1.0\n");
}