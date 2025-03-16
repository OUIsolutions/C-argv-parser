### Basic Usage

for use the lib , you just need to start the main struct with the `newCArgvParse` function, and then you can use the functions to get the flags and the arguments.

```c
#include "src/one.c"
#include <stdio.h>


CArgvParseNamespace argv_namespace;
int main(int argc, char *argv[]){
    argv_namespace = newCArgvParseNamespace();
    CArgvParse args = argv_namespace.newCArgvParse(argc,argv);
   
}
```

#### Getting a argument

you can get the arguments by using the function `CArgvParse_get_arg` and specifing the index of the argument you want to get.

```c
#include "src/one.c"
#include <stdio.h>


CArgvParseNamespace argv_namespace;
int main(int argc, char *argv[]){
    argv_namespace = newCArgvParseNamespace();
    CArgvParse args = argv_namespace.newCArgvParse(argc,argv);

    const char *first_arg = argv_namespace.get_arg(&args,0);
    printf("First arg: %s\n",first_arg);
    
}
```

#### Verify if a argument is present

you can verify if a argument is present by using the function `CArgvParse_is_one_of_args_present` and specifing the argument you want to verify.

```c

#include "src/one.c"
#include <stdio.h>


CArgvParseNamespace argv_namespace;
int main(int argc, char *argv[]){
    argv_namespace = newCArgvParseNamespace();
    CArgvParse args = argv_namespace.newCArgvParse(argc,argv);

    const char* help[] = {"help"};
    int total_help_size = 1;
    if(argv_namespace.is_one_of_args_present(&args,help,total_help_size)){
        printf("Help\n");
    }
    
}
```