### Basic Usage

for use the lib , you just need to start the main struct with the `newCArgvParse` function, and then you can use the functions to get the flags and the arguments.

```c
#include "CArgvParseOne.c"
#include <stdio.h>
#include <stdbool.h>


int main(int argc, char *argv[]){
  CArgvParse args = newCArgvParse(argc,argv);

  const char *arg_str = CArgvParse_get_arg(&args, 0);
  long arg_number = CArgvParse_get_arg_number(&args, 1);
  bool arg_bool = CArgvParse_get_arg_bool(&args, 2);

  printf("\n\t%s\n\t%ld\n\t%d\n", arg_str, arg_number, arg_bool?1:0);

  return 0;
}
```

Making it clear that all functions in 'lib' that return the value of 'flag' are converted to number and 'bool', with 'bool' being true only when it contains the value: [TRUE, True, true]
All functions follow this rule, with the normal name returning a string, with '_number' returning a number and with '_bool' returning a boolean value.

#### Getting a argument

you can get the arguments by using the function `CArgvParse_get_arg` and specifing the index of the argument you want to get.
In the library there is also the possibility of using namespaces.
As in the following examples:

```c
#include "CArgvParseOne.c"
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

#include "CArgvParseOne.c"
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
