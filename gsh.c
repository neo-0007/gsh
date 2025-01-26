#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


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
        } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
            print_version();
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
    printf("_|_|_|    _|_|_|    _|    _|  \n");
    printf("_|        _|        _|    _|  \n");
    printf("_|  _|_|    _|_|    _|_|_|_|  \n");
    printf("_|    _|        _|  _|    _|  \n");
    printf(" _|_|_|    _|_|_|   _|    _|  \n");
    printf("                              \n");
    printf("                              \n");

    printf("Usage: gsh [OPTION]...\n");
    printf("Options:\n");
    printf("  -h, --help     Display this help and exit\n");
    printf("  -v, --version  Output version information and exit\n");
}

void print_version()
{
    printf("Version 1.0.0\n");
}