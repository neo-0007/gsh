# `gsh`

Command-line tool written completly in C that allows users to interact with the **Google Gemini API** by sending questions and receiving responses. Never leave your terminal during debbuging, The tool is designed to run on **Linux** systems and is not currently supported on Windows or macOS.

## Features
- **Gemini API Interaction**: Send questions to the Google Gemini API and receive responses.
- **JSON Parsing**: Parse and display the API response using the `cJSON` library.
- **Command-Line Interface**: Simple and intuitive CLI for interacting with the tool.

## Todos
- [ ] **Chat with Gemini API**: Enable multi-turn conversations.
- [ ] **Static Linking of Dependencies**: Ensure portability and ease of deployment.
- [ ] **Cross-Compile for Windows**: Add support for Windows systems.
- [ ] **Cross-Compile for macOS**: Add support for macOS systems.

## Getting Started

To use `gsh`, you need to add your **Google Gemini API key** to the tool. Follow these steps:

1. **Obtain an API Key**:
   - Refer to [docs](https://ai.google.dev/gemini-api/docs/api-key) to get your gemini API key

2. **Add the API Key**:
   - Open the `ask_service.c` file in the `src` directory.
   - Locate the following line:
     ```c
     const char *api_key = "";
     ```
   - Replace the empty string (`""`) with your API key:
     ```c
     const char *api_key = "your_api_key_here";
     ```

3. **Recompile the Project**:
   After adding your API key, recompile the project:
   ```bash
   make clean
   make
   ```

## Dependencies

Before compiling `gsh`, ensure the following dependencies are installed on your system:

1. **libcurl**: Used for making HTTP requests.
   - Install on Ubuntu/Debian:
     ```bash
     sudo apt-get install libcurl4-openssl-dev
     ```
   - Install on Fedora:
     ```bash
     sudo dnf install libcurl-devel
     ```

2. **cJSON**: A lightweight JSON parser for C.
   - Install on Ubuntu/Debian:
     ```bash
     sudo apt-get install libcjson-dev
     ```
   - Install on Fedora:
     ```bash
     sudo dnf install cjson-devel
     ```

## Compilation

To compile `gsh`, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/gsh.git
   cd gsh
   ```
2. Compile the project:
    ```bash
    make
    ```
    This will generate the gsh executable in the project root directory.

3. (Optional) Clean build artifacts:
    ```bash
    make clean
    ```

## Usage

1. Run the gsh executable with the following options:

    ```bash
    ./gsh [OPTION]...

    Options avaialable:

    # -h, --help: Display help information and exit.

    # -v, --version: Output version information and exit.

    # -s <question>: Send a question to the Gemini API and print the response
    ```

## Platform Support
Currently, gsh is only supported on Linux. It is not available for Windows or macOS. If you would like to contribute to porting the project to other platforms, feel free to open an issue or submit a pull request.

## License
This project is licensed under the terms of the [LISCENCE](https://github.com/neo-0007/gsh/blob/main/LICENSE) file.