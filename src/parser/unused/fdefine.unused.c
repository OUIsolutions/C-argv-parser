//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end


c_argv_bool private_CArgvParse_its_used(CArgvParse *self,int index){
    for(int i = 0; i < self->total_used_args; i++){
        if(self->used_args[i] == index){
            return C_ARGV_PARSER_TRUE;
        }
    }
    return C_ARGV_PARSER_FALSE;
}
void private_CArgvParse_add_used(CArgvParse *self,int index){
    if(private_CArgvParse_its_used(self,index)){
        return;
    }
    if(self->total_used_args >= C_ARGV_PARSER_MAX_ARGS){
        return;
    }
    self->used_args[self->total_used_args] = index;
    self->total_used_args++;
}


const char *CArgvParse_get_next_unused_arg(CArgvParse *self){
    for(int i = C_ARGV_UNUSED_START; i < self->total_args; i++){
        if(!private_CArgvParse_its_used(self,i)){
            private_CArgvParse_add_used(self,i);
            return self->args[i];
        }
    }
    return C_ARGV_PARSER_NULL;
}

long long CArgvParse_get_next_unused_arg_number(CArgvParse *self){
    return privateArgv_parser_string_to_long_long(CArgvParse_get_next_unused_arg(self));
}

short CArgvParse_get_next_unused_arg_bool(CArgvParse *self){
    const char *response = CArgvParse_get_next_unused_arg(self);
    short true_bool = privateArgv_parser_string_cmp(response, "true");
    short True_bool = privateArgv_parser_string_cmp(response, "True");
    short TRUE_bool = privateArgv_parser_string_cmp(response, "TRUE");

    if(true_bool || True_bool || TRUE_bool){
        return 1;
    }

    return 0;
}
