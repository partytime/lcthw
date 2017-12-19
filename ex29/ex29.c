#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>
#include <limits.h>
#include <stdlib.h>

typedef int (*lib_function) (const char* data, long len);

int main(int argc, char *argv[])
{
    int rc = 0;
    check(argc == 5, "USAGE: ex29 libex29.so function data, len");

    char *lib_file = argv[1];
    char *func_to_run = argv[2];
    char *data = argv[3];

    void *lib = dlopen(lib_file, RTLD_NOW);
    check(lib != NULL, "failed to open lib %s: %s", lib_file, 
            dlerror())

    lib_function func = dlsym(lib, func_to_run);
    check(func != NULL,
        "Did not find %s func in the lib %s: %s", func_to_run,
        lib_file, dlerror());
    //cast argv[4] which is type char* to long
    //this prints a bunch of stuff if your len is longer than the string tho..bad
    long len = strtol(argv[4], (char **)NULL, 10);
    check(len != 0, "Conversion of string to long failed, or 0 received");
    rc = func(data, len);

    check(rc == 0, "func %s return %d for data: %s", func_to_run,
            rc, data);

    rc = dlclose(lib);
    check(rc == 0, "Failed to close %s", lib_file);

    return 0;

error:
    return 1;
}
