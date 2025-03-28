//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.types.h"
//silver_chain_scope_end

typedef struct CArgvParseNamespace{

    CArgvParse (*newCArgvParse)(int argc, char **argv);

    const char *(*get_arg)(CArgvParse *self,int index);
    long long (*get_arg_number)(CArgvParse *self,int index);
    short (*get_arg_bool)(CArgvParse *self,int index);
    
    int (*get_flag_size)(CArgvParse *self,const char **flags,int flags_size);
    
    const char *(*get_flag)(CArgvParse *self ,const char **flags,int flags_size, int index);
    long long (*get_flag_number)(CArgvParse *self ,const char **flags,int flags_size, int index);
    short (*get_flag_bool)(CArgvParse *self ,const char **flags,int flags_size, int index);
    
    const char *(*get_next_unused_arg)(CArgvParse *self);
    long long (*get_next_unused_arg_number)(CArgvParse *self);
    short (*get_next_unused_arg_bool)(CArgvParse *self);
    
    c_argv_bool (*is_flags_present)(CArgvParse *self,const char **flag,int flags_size);
    
    c_argv_bool (*is_one_of_args_present)(CArgvParse *self,const char **args,int args_size);
    
    int (*get_infinity_flag_size)(CArgvParse *self,const char **flags,int flags_size);
    
    const char *(*get_infinty_flag)(CArgvParse *self ,const char **flags,int flags_size, int index);
    long long(*get_infinty_flag_number)(CArgvParse *self ,const char **flags,int flags_size, int index);
    short (*get_infinty_flag_bool)(CArgvParse *self ,const char **flags,int flags_size, int index);
    
    int (*get_compact_flag_size)(CArgvParse *self,const char **flags,int flags_size);
    
    const char * (*get_compact_flag)(CArgvParse *self ,const char **flags,int flags_size, int index);
    long long(*get_compact_flag_number)(CArgvParse *self ,const char **flags,int flags_size, int index);
    short (*get_compact_flag_bool)(CArgvParse *self ,const char **flags,int flags_size, int index);
    
}CArgvParseNamespace;
