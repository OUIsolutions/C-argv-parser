
###  Unused Mechanic 
With the Unused Mechanic you can craft sofisticated cli aproachs to your project.

#### How it Works
its basicly works by retriving the next unused item,considering args or flags
(note that argv[0] its always consdered used by default,since its the program name)

```c

#include "src/one.c"
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