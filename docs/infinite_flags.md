### Infinty flags

Infinity flags are similar to normal flags,but they can get more than one argument for each 
flag. The syntax is `--flag arg1 arg2 arg3 ...`. The arguments are stored in a list.

```c

#include "CArgvParseOne.c"
#include <stdio.h>


CArgvParseNamespace argv_namespace;
int main(int argc, char *argv[]){
    argv_namespace = newCArgvParseNamespace();
    CArgvParse args = argv_namespace.newCArgvParse(argc,argv);

    const char* entry[] = {"entry","e"};
    int entry_size = 2;
    int index = 1;
    const char* entry_arg = argv_namespace.get_infinty_flag(&args,entry,entry_size,index);
    printf("entry: %s\n",entry_arg);
    int size = argv_namespace.get_infinity_flag_size(&args,entry,entry_size);
    printf("size: %d\n",size);
}
```
if we run the program with `--entry a b c` the output will be:
```bash
entry: b
size: 3
```
note that the infinity flag,stop collecting after other flag, and turns on again after the flag is done.

if you run 
```bash
./a.out --entry a b c --a d e f --entry g h i
```
the output will be:
```bash
size: 6
```