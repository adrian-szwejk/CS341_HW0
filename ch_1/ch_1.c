#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

//Define the VARS to talk to PREPROCESSOR about certain character sequences
//These already defined in unistd.h
//#define STDOUT_FILENUM 1
//#define STDERROR_FILENUM 2
int main(void) {
    //Loop over & write to std & err output
    for (int i = 0 ; i < 5; ++i) {
        //1st output stream is to regular output #1 
        write(1, "Hello\n", 6);
        //2nd output stream is to error output #2 
        write(2, ".", 1);
    }


    close(2);
    //2nd argument is what we want to do with file (FLAGS)
    //Create a file called output.txt and truncate it to 0 bytes if DOESN'T EXIST (Allow for reading & writing)
    //3rd argument, mode is "WHO is allowed to do WHAT"
    mode_t mode = S_IRUSR | S_IWUSR;
    //S_IRUSR | S_IWUSR  ==  user has READ/WRITE permission
    int files = open("output.txt", O_CREAT | O_TRUNC | O_RDWR, mode);
    //The reason we get 3 is b/c 0, 1, 2 are already taken by std input, output, error
    //And we get LOWEST UNUSED FILE DESCRIPTOR or -1 if ERROR
    if (files == -1) {
        perror("open failed");
        exit(1);
    }
    printf("file is %d\n", files);
    write(files, "Opened File!\n", 13);
    close(files);

    //This will always be printed after the FOR LOOP even if placed before in code
    //This is B/C std output is buffered
    //Fix this by adding "\n" to the end
    printf("My value is %d", 42);
    //Change the exit value to whatever we want 0 -> 42
    return 0;
}

//There is no boolean type in C. 0 is false, anything else is true.
//So can write  -->  for (int i = 5 ; i; --i)