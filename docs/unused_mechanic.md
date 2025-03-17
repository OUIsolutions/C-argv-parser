
###  Unused Mechanic 
With the Unused Mechanic you can craft sofisticated cli aproachs to your project.

#### How it Works
its basicly works by retriving the next unused item,considering args or flags
(note that argv[0] its always consdered used by default,since its the program name)

```c

#include "CArgvParseOne.c"
#include <stdio.h>
CArgvParseNamespace argv_namespace;
int main(int argc, char *argv[]){
    argv_namespace = newCArgvParseNamespace();
    CArgvParse args = argv_namespace.newCArgvParse(argc,argv);
    const char *next;   
    while (next = argv_namespace.get_next_unused_arg(&args)){
        printf("%s\n",next);

    }

}
```

#### Making a 'real world example'
these example simulates the gcc compiler,where you can pass multiple flags and arguments
```c

#include <stdio.h>
#include "CArgvParseOne.c"
#include <stdbool.h>

CArgvParseNamespace argv_namespace;
int main(int argc, char *argv[]){
    argv_namespace = newCArgvParseNamespace();
    CArgvParse args = argv_namespace.newCArgvParse(argc,argv);

    const char* outputs[] = {"output","out","o"};
    int total_output_flags = sizeof(outputs)/sizeof(char*);
    int flag_index = 0;
    
    const char *output = argv_namespace.get_flag(&args,outputs,total_output_flags,flag_index);

    const char *modules[] = {"c"};
    int total_module_flags = 1;
    bool its_module = argv_namespace.is_flags_present(&args,modules,total_module_flags);

    const char *target = argv_namespace.get_next_unused_arg(&args);

    const char *invalid_arg = argv_namespace.get_next_unused_arg(&args);

    if(invalid_arg != NULL){
        printf("Invalid argument: %s\n",invalid_arg);
        return 1;
    }
    if(!target){
        printf("Target not found\n");
        return 1;
    }
    if(!output){
        printf("Output not found\n");
        return 1;
    }



    printf("target: %s\n",target);
    printf("its_module: %d\n",its_module);
    printf("output: %s\n",output);
    
}
```

