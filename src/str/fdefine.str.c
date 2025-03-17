//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.globals.h"
//silver_chain_scope_end


short privateArgv_parser_string_cmp(const char *s1, const char *s2) {
    if (!s1 || !s2){
        return 0;
    }

    while (*s1 && *s2) {
        if (*s1 != *s2){
            return 0;
        }
        s1++;
        s2++;
    }

    return (*s1 == *s2) ? 1 : 0;
}

long long privateArgv_parser_string_to_long_long(const char *text){
    if(!text){
        return 0;
    }

    int result = 0, sign = 1;

    if (*text == '-'){// Não vou colocar o + porque não faz sentido
        if (*text == '-') sign = -1;
        text++;
    }

    while (*text >= '0' && *text <= '9') {
        result = result * 10 + (*text - '0');//preciso fazer uma subtração pois é um valor ascii
        text++;
    }

    return result * sign;
}

long long privateArgv_parser_string_to_long_long_by_size(const char *text, long size_length){
    if(!text){
        return 0;
    }
    if(size_length <= 0){
        return 0;
    }
    if(privateArgv_parser_string_size(text) < size_length){
        return 0;
    }

    long long result = 0;
    int sign = 1;

    if (text[0] == '-'){
        sign = -1;
        if(size_length == 1){
            return 0;
        }
    }

    for(long i=1; i < size_length; i++){
        if(text[i] >= '0' || text[i] <= '9'){
            result = result * 10 + (text[i] - '0');
        }
        return 0;
    }

    return result * sign;
}

int privateArgv_parser_string_size(const char *string){
    int size = 0;
    while(string[size] != '\0'){
        size++;
    }
    return size;
}


c_argv_bool privateArgv_parsser_starts_with(const char *string,int string_size, const char *start,int start_size){    
    if(string_size < start_size){
        return 0;
    }
    for(int i = 0; i < start_size; i++){
        if(string[i] != start[i]){
            return 0;
        }
    }
    return 1;
}

c_argv_bool privateArgv_strings_equals(const char *string1,int string1_size,const char *string2,int string2_size){
    if(string1_size != string2_size){
        return 0;
    }
    for(int i = 0; i < string1_size; i++){
        if(string1[i] != string2[i]){
            return 0;
        }
    }
    return 1;
}
