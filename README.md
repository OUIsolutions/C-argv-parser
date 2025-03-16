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