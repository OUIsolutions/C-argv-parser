

typedef struct CArgvParse{

    int used_flags[C_ARGV_PARSER_MAX_FLAGS];
     char **args;
    int total_args;

    const char **flag_identifiers;
    int total_flag_indentifiers;

 }CArgvParse;
