

int CArgvParse_get_infinity_flag_size(CArgvParse *self,const char **flags,int flags_size){
    int found=0;
    int flag_found_index = -1;
    c_argv_bool inside_flag = C_ARGV_PARSER_FALSE;
    for(int i = 0; i < self->total_args; i++){

        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        int identifier_start_size = privateCArgv_parser_get_flag_identifier_start_size(self,current_arg,current_arg_size);        
        c_argv_bool its_flag = identifier_start_size != -1;
        //means its not a flag
        if(!its_flag &&!inside_flag){
            continue;
        }

        if(!its_flag &&inside_flag){            
            found++;
            continue;
        }

        // if its here, than its a flag

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
                flag_found_index = i;
                inside_flag = C_ARGV_PARSER_TRUE;
                break;
            }
            if(!is_the_current_flag){
                inside_flag = C_ARGV_PARSER_FALSE;
                flag_found_index = -1;
            }
        }

    }
    return found;
}    


const char * CArgvParse_get_infinty_flag(CArgvParse *self ,const char **flags,int flags_size, int index){
    int found=0;
    int flag_found_index = -1;
    c_argv_bool inside_flag = C_ARGV_PARSER_FALSE;
    for(int i = 0; i < self->total_args; i++){

        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        int identifier_start_size = privateCArgv_parser_get_flag_identifier_start_size(self,current_arg,current_arg_size);        
        c_argv_bool its_flag = identifier_start_size != -1;
        //means its not a flag
        if(!its_flag &&!inside_flag){
            continue;
        }

        if(!its_flag &&inside_flag){            
            if(found == index){
                private_CArgvParse_add_used(self,flag_found_index);
                private_CArgvParse_add_used(self,i);
                return self->args[i];
            }        
            found++;
            continue;
        }

        // if its here, than its a flag

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
                flag_found_index = i;
                inside_flag = C_ARGV_PARSER_TRUE;
                break;
            }
            if(!is_the_current_flag){
                inside_flag = C_ARGV_PARSER_FALSE;
                flag_found_index = -1;
            }
        }

    }
    return C_ARGV_PARSER_NULL;
}