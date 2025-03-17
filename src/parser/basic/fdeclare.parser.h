




CArgvParse newCArgvParse(int argc, char **argv);

const char *CArgvParse_get_arg(CArgvParse *self,int index);

int privateCArgv_parser_get_flag_identifier_start_size(CArgvParse *self,const char *flag,int flag_size);

c_argv_bool CArgvParse_is_flags_present(CArgvParse *self,const char **flags,int flags_size);

c_argv_bool CArgvParse_is_one_of_args_present(CArgvParse *self,const char **args,int args_size);
