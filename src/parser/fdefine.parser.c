





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