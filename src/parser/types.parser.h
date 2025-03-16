

typedef struct CArgvPars{

    int used_flags[C_ARGV_PARSER_MAX_FLAGS];
    const char **flags;
    int flags_size;

    const char **flag_identifiers;
    int flag_identifiers_size;

 }CArgvPars;
