
## Basic Flags
### Geting basic flags
you can get flags from the command lines easly,by specifing the flags list, 
and the target index of the flag 

```c

#include "src/one.c"
#include <stdio.h>
int main(int argc, char *argv[]){
    CArgvParse args = newCArgvParse(argc,argv);

    const char* outputs[] = {"output","out","o"};
    int total_output_flags = sizeof(outputs)/sizeof(char*);
    int flag_index = 0;
    const char *output = CArgvParse_get_flag(&args,outputs,total_output_flags,flag_index);
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

int main(int argc, char *argv[]){
    CArgvParse args = newCArgvParse(argc,argv);

    const char* outputs[] = {"output","out","o"};
    int total_output_flags = sizeof(outputs)/sizeof(char*);
    int size = CArgvParse_get_flag_size(&args,outputs,total_output_flags);
    printf("output flags found: %d\n",size);
    
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