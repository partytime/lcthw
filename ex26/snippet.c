#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[])
{
    int result;
    int errno = 0;

    // array of strings that is the location of files to read
    char **files;
    char word[128];
    char tempf[512];
    int lineno = 0;

    FILE *fp;
    // list.txt is a file containing a list of other filenames to open
    // file1.txt, file2.txt, file3.txt
    char *fname = "list.txt";
    // open the file, assign to *fp
       if((fp = fopen(fname, "r")) == NULL) {
        printf("cant find file");
        return(-1);
    } 
    // read in the list of files 
    // set tokens to ignore
    // char badtoks[] = "\n\v\x19";
    char badtoks[] = "\n";
    while(fgets(tempf, 512, fp) != NULL) {
        //files[lineno] = strtok(tempf, badtoks);
        files = (char**)realloc(files, (lineno + 1)*sizeof(*files));
        word = strtok(tempf, badtoks);
        files[lineno] = (char*)malloc(sizeof(word));
        strcpy(files[lineno-1], word);
        printf("files[%d] is %s\n", lineno,  files[lineno]);
        lineno++;
    }
    // now the while loops is done so read back the files array
    int z = 0;
    for(z = 0; files[z] != '\0'; z++) {
            printf("file %d is  %s\n", z, files[z]); 
    }
    return 0;
}