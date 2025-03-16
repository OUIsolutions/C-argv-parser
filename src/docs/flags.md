
## Basic Flags
### Geting basic flags
you can get flags from the command lines easly,by specifing the flags list, 
and the target index of the flag 

```c

#include "src/one.c"
#include <stdio.h>


CArgvParseNamespace argv_namespace;
int main(int argc, char *argv[]){
    argv_namespace = newCArgvParseNamespace();
    CArgvParse args = argv_namespace.newCArgvParse(argc,argv);

    const char* outputs[] = {"output","out","o"};
    int total_output_flags = sizeof(outputs)/sizeof(char*);
    int flag_index = 0;
    
    const char *output = argv_namespace.get_flag(&args,outputs,total_output_flags,flag_index);
    printf("output: %s\n",output);
    
}
```
if you run:
```bash
./a.out  a b --out test
```
the output will be:
```bash
output: test
```

### Getting basic flags size

you can get the size of the flags by using the function `CArgvParse_get_flag_size` 
```c
#include "src/one.c"
#include <stdio.h>


CArgvParseNamespace argv_namespace;
int main(int argc, char *argv[]){
    argv_namespace = newCArgvParseNamespace();
    CArgvParse args = argv_namespace.newCArgvParse(argc,argv);

    const char* outputs[] = {"output","out","o"};
    int total_output_flags = sizeof(outputs)/sizeof(char*);
    int size = argv_namespace.get_flag_size(&args,outputs,total_output_flags);
    printf("Total output flags: %d\n",size);
    
}
```
if you run:
```bash
./a.out  a b --out test  any -o test2 
```
the output will be:
```bash
output flags found: 2
```

### Verify if flag exists
you can verify if the flag exists by using the function `CArgvParse_is_flags_present` 
```c

#include "src/one.c"
#include <stdio.h>


CArgvParseNamespace argv_namespace;
int main(int argc, char *argv[]){
    argv_namespace = newCArgvParseNamespace();
    CArgvParse args = argv_namespace.newCArgvParse(argc,argv);

    const char* help[] = {"help","h"};
    int total_output_flags = sizeof(help)/sizeof(char*);
    if(argv_namespace.is_flags_present(&args,help,total_output_flags)){
        printf("Help\n");
    }
    
}
```