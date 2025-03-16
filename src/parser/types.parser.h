

typedef struct CArgvParse{

    int used_args[C_ARGV_PARSER_MAX_FLAGS];
    int total_used_args;
     char **args;
    int total_args;

    const char **flag_identifiers;
    int total_flag_indentifiers;

 }CArgvParse;
