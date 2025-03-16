//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.fdeclare.h"
//silver_chain_scope_end






CArgvParse newCArgvParse(int argc, char **argv){
    CArgvParse cArgvPars ={0};
    cArgvPars.args = argv;
    cArgvPars.total_args = argc;
    cArgvPars.flag_identifiers = CArgvPars_defult_identifiers;
    cArgvPars.total_flag_indentifiers = CArgvPars_defult_identifiers_size;
    return cArgvPars;
}

const char *CArgvParse_get_arg(CArgvParse *self,int index){
    if(index < self->total_args){
        private_CArgvParse_add_used(self,index);
        return self->args[index];
    }
    return C_ARGV_PARSER_NULL;
}

c_argv_bool CArgvParse_is_flags_present(CArgvParse *self,const char **flags,int flags_size){
    
    for(int i = 0; i < self->total_args; i++){
        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        int identifier_start_size = privateCArgv_parser_get_flag_identifier_start_size(self,current_arg,current_arg_size);        
        c_argv_bool its_flag = identifier_start_size != -1;

        //means its not a flag
        if(!its_flag){
            continue;
        }
        const char *formmated_flag_comparaton_flag = current_arg + identifier_start_size;
        int formmated_flag_comparaton_flag_size = current_arg_size-identifier_start_size;

        for(int j = 0; j < flags_size;j++){
            const char *flag = flags[j];
            int flag_size = privateArgv_parser_string_size(flag);

            c_argv_bool is_the_current_flag = privateArgv_strings_equals(
                formmated_flag_comparaton_flag,
                formmated_flag_comparaton_flag_size,
                flag,
                flag_size
            );
            if(is_the_current_flag){
                private_CArgvParse_add_used(self,i);
                return C_ARGV_PARSER_TRUE;
            }
        }

    }
    return C_ARGV_PARSER_FALSE;
}





int privateCArgv_parser_get_flag_identifier_start_size(CArgvParse *self,const char *flag,int flag_size){
    for(int i = 0; i < self->total_flag_indentifiers; i++){
        const char *current_identifier = self->flag_identifiers[i];
        int current_identifier_size = privateArgv_parser_string_size(current_identifier);
        if(privateArgv_parsser_starts_with(flag,flag_size,current_identifier,current_identifier_size)){
            return current_identifier_size;
        }
    }
    return -1;
}
c_argv_bool CArgvParse_is_one_of_args_present(CArgvParse *self,const char **args,int args_size){
    for(int i = 0; i < self->total_args; i++){
        const char *current_arg = self->args[i];

        
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        for(int j = 0; j < args_size;j++){
            const char *arg = args[j];
            int arg_size = privateArgv_parser_string_size(arg);
            c_argv_bool is_the_current_arg = privateArgv_strings_equals(
                current_arg,
                current_arg_size,
                arg,
                arg_size
            );
            if(is_the_current_arg){
                private_CArgvParse_add_used(self,i);
                return C_ARGV_PARSER_TRUE;
            }
        }
    }
    return C_ARGV_PARSER_FALSE;
}