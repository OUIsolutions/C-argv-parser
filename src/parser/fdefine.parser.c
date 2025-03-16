





CArgvParse newCArgvPars(int argc, char **argv){
    CArgvParse cArgvPars;
    cArgvPars.args = argv;
    cArgvPars.total_args = argc;
    cArgvPars.flag_identifiers = CArgvPars_defult_identifiers;
    cArgvPars.total_flag_indentifiers = CArgvPars_defult_identifiers_size;
    return cArgvPars;
}

const char *CArgvPars_get_arg(CArgvParse *self,int index){
    if(index < self->total_args){
        return self->args[index];
    }
    return C_ARGV_PARSER_NULL;
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

const char * CArgvPars_get_flag(CArgvParse *self,const char *flag,int index){
    int flag_size = privateArgv_parser_string_size(flag);
    int found=0;
    for(int i = 0; i < self->total_args-1; i++){
        
        const char *current_arg = self->args[i];
        int current_arg_size = privateArgv_parser_string_size(current_arg);
        int identifier_start_size = privateCArgv_parser_get_flag_identifier_start_size(self,current_arg,current_arg_size);        
        c_argv_bool its_flag = identifier_start_size != -1;
        //means its not a flag
        if(!its_flag){
            continue;;
        }


        const char *formmated_flag_comparaton_flag = current_arg+identifier_start_size;
        int formmated_flag_comparaton_flag_size = current_arg_size-identifier_start_size;

        
        if(privateArgv_strings_equals(formmated_flag_comparaton_flag,formmated_flag_comparaton_flag_size,flag,flag_size)){
            if(found == index){
               const  char *next = self->args[i+1];
                return next;
            }
            found++;
        }
    }
    return C_ARGV_PARSER_NULL;
}