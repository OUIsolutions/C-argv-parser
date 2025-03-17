//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end




int CArgvParse_get_compact_flag_size(CArgvParse *self,const char **flags,int flags_size){
    int size = 0;
    for(int i = 0; i < self->total_args; i++){
        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        for(int j=0; j < flags_size;j++){
            const char *flag = flags[j];
            int flag_size = privateArgv_parser_string_size(flag);
        
            if(privateArgv_parsser_starts_with(current_arg,current_arg_size,flag,flag_size)){
                size++;
            }
        }
    }
    return size;
}    


const char * CArgvParse_get_compact_flag(CArgvParse *self ,const char **flags,int flags_size, int index){
    int found=0;
    for(int i = 0; i < self->total_args; i++){

        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        for(int j=0; j < flags_size;j++){
            const char *flag = flags[j];
            int flag_size = privateArgv_parser_string_size(flag);
        
            if(privateArgv_parsser_starts_with(current_arg,current_arg_size,flag,flag_size)){
                if(found == index){
                    return current_arg + flag_size;
                }
                found++;
            }
        }
    }
    return C_ARGV_PARSER_NULL;
}