#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// See if a file contains a string matching 'string'


int searchfile(char *fname, char *str) {
    FILE *fp;
    int line_num = 1;
    int find_result = 0;
    char temp[512];

    // open the file, assign to fp
    if((fp = fopen(fname, "r")) == NULL) {
        return(-1);
    }

    // read the fp file 512 bytes at a time, store in buffer 'temp'
    while(fgets(temp, 512, fp) != NULL) {
        printf("searching lineno %d which contains: ", line_num);
        puts(temp);
        printf("\n");
        // search the 'temp' buffer for 'str'
        if((strstr(temp, str)) != NULL) {
            printf("found on line %d\n", line_num);
            printf("\n%s\n", temp);
            find_result ++;
        }
        line_num++;
    }
    if(find_result == 0){
        printf("Couldnt find %s in %s\n", str, fname);
    }
    if(fp) {
        fclose(fp);
    }
    return(0);
}

int main(int argc, char *argv[])
{
    int result;
    int errno = 0;

    if(argc < 3 || argc > 3) {
        printf("need 3 args");
    }

    // array of strings that is the location of files to read
    char *files[4];
    char tempf[512];
    int lineno = 0;

    FILE *fp;
    char *fname = "list.txt";
    // open the file, assign to fp
       if((fp = fopen(fname, "r")) == NULL) {
        printf("cant find file");
        return(-1);
    } 
    // read in the list of files 
    // set bad tokens, why does \v and \x19 get read from the text file?
    char badtoks[] = "\n\v\x19";
    while(fgets(tempf, 512, fp) != NULL) {
        char *tempvar = strtok(tempf, badtoks);
        files[lineno] = tempvar;
        printf("TEMPVAR IS %s\n", tempvar);
        printf("files[%d] is %s\n", lineno,  files[lineno]);
        lineno++;
    }
    int z = 0;
    for(z = 0; files[z] != '\0'; z++) {
            printf("file %d is  %s\n", z, files[z]); 
    }

    printf("size of files is %d\n", sizeof(files));
    //int len = sizeof(files) / sizeof(files[0]);
    int len = sizeof(files);
    int i;
    for(i = 0; files[i] != '\0'; i++) {
        printf("searching in file %s\n", files[i]);
        printf("i is %d\n", i);
        result = searchfile(files[i], argv[2]);
        if(result == -1) {
            perror("Error");
            printf("errno %d\n", errno);
            exit(1);
        }
    }

    return 0;

}