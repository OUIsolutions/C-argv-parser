





CArgvParse newCArgvPars(int argc, char **argv){
    CArgvParse cArgvPars ={0};
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
