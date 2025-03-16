




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


int CArgvPars_get_flag_size(CArgvParse *self,const char **flags,int flags_size){
    int found=0;
    for(int i = 0; i < self->total_args-1; i++){


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
                found++;
            }
        }

    }
    return found;
}    


const char * CArgvPars_get_flag(CArgvParse *self ,const char **flags,int flags_size, int index){
    int found=0;
    for(int i = 0; i < self->total_args-1; i++){


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

                if(found == index){

                    private_CArgvParse_add_used(self,i);
                    private_CArgvParse_add_used(self,i+1);
                    const  char *next = self->args[i+1];
                    return next;
                }
                found++;
            }
        }

    }
    return C_ARGV_PARSER_NULL;
}