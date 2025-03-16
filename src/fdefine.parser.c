

#include "c-argv-parsser.h"


const char *CArgvPars_defult_identifiers[] = {"-","--"};
const int CArgvPars_defult_identifiers_size = 2;

CArgvPars newCArgvPars(const char **flags,int flags_size){
    CArgvPars cArgvPars;
    cArgvPars.flags = flags;
    cArgvPars.flags_size = flags_size;
    cArgvPars.flag_identifiers = CArgvPars_defult_identifiers;
    cArgvPars.flag_identifiers_size = CArgvPars_defult_identifiers_size;
    return cArgvPars;
}

const char *CArgvPars_get_arg(CArgvPars *self,int index){
    if(index < self->flags_size){
        return self->flags[index];
    }
    return C_ARGV_PARSER_NULL;
}
int privateArgv_parser_string_size(const char *string){
    int size = 0;
    while(string[size] != '\0'){
        size++;
    }
    return size;
}
int privateArgv_parsser_starts_with(const char *string,int string_size, const char *start,int start_size){    
    if(string_size < start_size){
        return 0;
    }
    for(int i = 0; i < start_size; i++){
        if(string[i] != start[i]){
            return 0;
        }
    }
    return 1;
}

int privateCArgv_parser_get_flag_identifier_start_size(CArgvPars *self,const char *flag){
    for(int i = 0; i < self->flag_identifiers_size; i++){
        char *current_identifier = self->flag_identifiers[i];
        if(privateArgv_parsser_starts_with(flag,current_identifier)){
            return privateArgv_parser_string_size(current_identifier);
        }
    }
    return -1;
}

const char * CArgvPars_get_flag(CArgvPars *self,const char *flag,int index){
    for(int i = 0; i < self->flags_size; i++){

    }
    return C_ARGV_PARSER_NULL;
}