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

long long CArgvParse_get_compact_flag_number(CArgvParse *self ,const char **flags,int flags_size, int index){
    return privateArgv_parser_string_to_long_long(CArgvParse_get_compact_flag(self, flags, flags_size, index));
}

short CArgvParse_get_compact_flag_bool(CArgvParse *self ,const char **flags,int flags_size, int index){
    const char *response = CArgvParse_get_compact_flag(self ,flags, flags_size, index);
    short true_bool = privateArgv_parser_string_cmp(response, "true");
    short True_bool = privateArgv_parser_string_cmp(response, "True");
    short TRUE_bool = privateArgv_parser_string_cmp(response, "TRUE");

    if(true_bool || True_bool || TRUE_bool){
        return 1;
    }

    return 0;
}
