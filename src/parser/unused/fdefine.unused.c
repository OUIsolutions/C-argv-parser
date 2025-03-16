

c_argv_bool private_CArgvParse_its_used(CArgvParse *self,int index){
    for(int i = 0; i < self->total_used_args; i++){
        if(self->used_args[i] == index){
            return C_ARGV_PARSER_TRUE;
        }
    }
    return C_ARGV_PARSER_FALSE;
}
void private_CArgvParse_add_used(CArgvParse *self,int index){
    if(private_CArgvParse_its_used(self,index)){
        return;
    }
    self->used_args[self->total_used_args] = index;
    self->total_used_args++;
}


const char *CArgvParse_get_next_unused_arg(CArgvParse *self){
    for(int i = C_ARGV_UNUSED_START; i < self->total_args; i++){
        if(!private_CArgvParse_its_used(self,i)){
            private_CArgvParse_add_used(self,i);
            return self->args[i];
        }
    }
    return C_ARGV_PARSER_NULL;
}