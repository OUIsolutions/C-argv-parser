//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.consts.h"
//silver_chain_scope_end


typedef struct CArgvParse{

    int used_args[C_ARGV_PARSER_MAX_ARGS];
    int total_used_args;
     char **args;
    int total_args;

    const char **flag_identifiers;
    int total_flag_indentifiers;

 }CArgvParse;
