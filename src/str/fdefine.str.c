

int privateArgv_parser_string_size(const char *string){
    int size = 0;
    while(string[size] != '\0'){
        size++;
    }
    return size;
}


int privateArgv_parsser_starts_with(const char *string,int string_size, const char *start,int start_size){    
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

int privateArgv_strings_equals(const char *string1,int string1_size,const char *string2,int string2_size){
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