//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.globals.h"
//silver_chain_scope_end


CArgvParseNamespace newCArgvParseNamespace(){
  CArgvParseNamespace self ={0};
  self.newCArgvParse = newCArgvParse;
  
  self.get_arg = CArgvParse_get_arg;
  self.get_arg_number = CArgvParse_get_arg_number;
  self.get_arg_bool = CArgvParse_get_arg_bool;

  self.get_flag_size = CArgvParse_get_flag_size;
  
  self.get_flag = CArgvParse_get_flag;
  self.get_flag_number = CArgvParse_get_flag_number;
  self.get_flag_bool = CArgvParse_get_flag_bool;
  
  self.get_next_unused_arg = CArgvParse_get_next_unused_arg;
  self.get_next_unused_arg_number = CArgvParse_get_next_unused_arg_number;
  self.get_next_unused_arg_bool = CArgvParse_get_next_unused_arg_bool;
  
  self.is_flags_present = CArgvParse_is_flags_present;
  self.is_one_of_args_present = CArgvParse_is_one_of_args_present;
  self.get_infinity_flag_size = CArgvParse_get_infinity_flag_size;
  
  self.get_infinty_flag = CArgvParse_get_infinty_flag;
  self.get_infinty_flag_number = CArgvParse_get_infinty_flag_number;
  self.get_infinty_flag_bool = CArgvParse_get_infinty_flag_bool;
  
  self.get_compact_flag_size = CArgvParse_get_compact_flag_size;
  
  self.get_compact_flag = CArgvParse_get_compact_flag;
  self.get_compact_flag_number = CArgvParse_get_compact_flag_number;
  self.get_compact_flag_bool = CArgvParse_get_compact_flag_bool;
  
  return self;   
}
