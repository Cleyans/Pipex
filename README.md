# pipex User Guide
This guide explains how to use the pipex project to execute shell commands through pipes.

## Installation
1. Clone the pipex repository from GitHub:

    ```shell
    git clone https://github.com/your-username/pipex.git
    ```

2. Navigate to the project directory:

    ```shell
    cd pipex
    ```

3. Compile the project by running the make command:

    ```shell
    make
    ```

## Usage
To use pipex, follow these steps:

1. Execute the following command to run a shell command through a pipe:

    ```shell
    ./pipex input_file cmd1 cmd2 output_file
    ```

    - `input_file`: the input file containing the data to be sent to the first command.
    - `cmd1`: the first command to be executed.
    - `cmd2`: the second command to be executed.
    - `output_file`: the output file where the results will be stored.

2. The command's results will be written to the specified output file.

## Examples
Here are some examples of using pipex:

- To execute the command `ls -l | grep .txt` and save the results to the file `results.txt`, use the following command:

  ```shell
  ./pipex file.txt "ls -l" "grep .txt" results.txt
  ```

- To execute the command `cat file.txt | sort | uniq` and display the results on the screen, use the following command:

  ```shell
  ./pipex file.txt "cat" "sort" "uniq"
  ```
