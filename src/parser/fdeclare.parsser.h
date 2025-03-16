


CArgvPars newCArgvPars(const char **flags,int flags_size);

const char *CArgvPars_get_arg(CArgvPars *self,int index);

const char * CArgvPars_get_flag(CArgvPars *self,const char *flag,int index);


