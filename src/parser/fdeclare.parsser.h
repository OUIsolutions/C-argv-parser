




CArgvParse newCArgvPars(int argc, char **argv);

const char *CArgvPars_get_arg(CArgvParse *self,int index);

int privateCArgv_parser_get_flag_identifier_start_size(CArgvParse *self,const char *flag,int flag_size);

const char * CArgvPars_get_flag(CArgvParse *self,const char *flag,int index);
