#ifndef LOADER_H
#define LOADER_H

#include <stdint.h>
#include <string>
#include <vector>


class Symbol{
 public:
  enum SymbolType {
    SYM_TYPE_UKN = 0,
    SYM_TYPE_FUNC = 1
  };

  Symbol() : type(SYM_TYPE_UKN), name(), addr(0) {}
  SymbolType type;
  std::string name;
  uint64_t
  
};

class Section {

 public:
  enum SectionType{
    SEC_TYPE_NONE = 0,
    SEC_TYPE_CODE = 1,
    SEC_TYPE_DATA = 2
    
  };//end SectionType

 Section(): binary(NULL), type(SEC_TYPE_NONE), vma(0), size(0), bytes(NULL){}
 bool contains(uint64_t addr) {return (addr >= vma) && (addr-vma < size);}

 Binary *binary;
 std::string name;
 SectionType type;
 uint64_t vma;
 uint64_t size;
 uint8_t *bytes;
};//end Class Section

