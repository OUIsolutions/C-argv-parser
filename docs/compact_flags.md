### Compact Flags
Compact flags are a type of flag , that its setted in one arg, ass a prefix 
exemple **name:mateus** where **name:** its the flag and **mateus** its the value

```c
#include "src/one.c"
#include <stdio.h>


CArgvParseNamespace argv_namespace;
int main(int argc, char *argv[]){
    argv_namespace = newCArgvParseNamespace();
    CArgvParse args = argv_namespace.newCArgvParse(argc,argv);

    const char *name[] = {"name:","name="};
    int name_size = 2;
    
    int total_names = argv_namespace.get_compact_flag_size(&args,name,name_size);
    printf("total names: %d\n",total_names);
    for(int i = 0; i < total_names; i++){
        const char *name_value = argv_namespace.get_compact_flag(&args,name,name_size,i);
        printf("name: %s\n",name_value);
    }
}
```
if  you run with:
```bash
./a.out    name:mateus name=samuel 
```
your output will be:

```txt
total names: 2
name: mateus
name: samuel
```