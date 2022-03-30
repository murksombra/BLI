#include <bfd.h>
#include "loader.h"

int load_binary(std::string &fname, Binary *bin, Binary::BinaryType type){
  return load_binary_bfd(fname, bin, type);
}

void unload_binary(Binary *bin){
  size_t i;
  Section *sec;
  for(i=0; i< bin->sections.size(); i++){
    sec = &bin->sections[i];
    if(sec->bytes){
      free(sec->bytes);
    }
  }
}

static bfd* open_bfd(std::string &fname){
  static int bfd_inited = 0;
  bfd *bfd_h;
  
  if(!bfd_inited){
    bfd_init();
    bfd_inited = 1;
  }

  bfd_h = bfd_openr(fname.c_str(), NULL);
  if(!bfd_h){
    fprintf(stderr, "Failed to open binary '%s' (%s)\n", fname.c_str(), bfd_errmsg(bfd_get_error()));
    return NULL;
  }
}
