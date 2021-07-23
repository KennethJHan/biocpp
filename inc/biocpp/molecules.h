// Copyright 2021 panda5176

#ifndef BIOCPP_INC_BIOCPP_MOLECULES_H_
#define BIOCPP_INC_BIOCPP_MOLECULES_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace biocpp {

class MolSeq {
  // TODO(panda5176): ostream& operator<< overriding
  // TODO(panda5176): operator[], operator ==/!=, slicing overriding
 private:
  string sequence_;
  char mol_type_;

 public:
  explicit MolSeq(string sequence, char mol_type);
  string get_sequence();
  char get_mol_type();
  MolSeq transcribe();
  // TODO(panda5176): back_transcribe()
  MolSeq translate();
  MolSeq complement();
  // TODO(panda5176): reverse()
  MolSeq reverse_complement();
  int* count_nucleotide();
  float calc_gc_content();
  vector<int> find_motif(string motif);
};

}  // namespace biocpp

#endif  // BIOCPP_INC_BIOCPP_MOLECULES_H_
