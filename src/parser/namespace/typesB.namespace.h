//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.types.h"
//silver_chain_scope_end

typedef struct CArgvParseNamespace{

    CArgvParse (*newCArgvParse)(int argc, char **argv);
    const char *(*get_arg)(CArgvParse *self,int index);
    int (*get_flag_size)(CArgvParse *self,const char **flags,int flags_size);
    const char * (*get_flag)(CArgvParse *self ,const char **flags,int flags_size, int index);
    const char *(*get_next_unused_arg)(CArgvParse *self);
    c_argv_bool (*is_flags_present)(CArgvParse *self,const char **flag,int flags_size);
    c_argv_bool (*is_one_of_args_present)(CArgvParse *self,const char **args,int args_size);

}CArgvParseNamespace;
