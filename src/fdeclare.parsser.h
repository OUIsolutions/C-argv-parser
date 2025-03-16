

#ifndef C_ARGV_PARSER_H
#define C_ARGV_PARSER_H

#ifndef C_ARGV_PARSER_MAX_FLAGS
#define C_ARGV_PARSER_MAX_FLAGS 1000
#endif

#define C_ARGV_PARSER_NULL (void*)0
typedef struct CArgvPars{

    int used_flags[C_ARGV_PARSER_MAX_FLAGS];
    const char **flags;
    int flags_size;

    const char **flag_identifiers;
    int flag_identifiers_size;

 }CArgvPars;

CArgvPars newCArgvPars(const char **flags,int flags_size);

const char *CArgvPars_get_arg(CArgvPars *self,int index);

const char * CArgvPars_get_flag(CArgvPars *self,const char *flag,int index);


#endif 