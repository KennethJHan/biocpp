// Copyright 2021 panda5176

#ifndef BIOCPP_INC_BIOCPP_MOLECULES_H_
#define BIOCPP_INC_BIOCPP_MOLECULES_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace biocpp {

class MolSeq {
 private:
  string sequence_;
  string mol_type_;

 public:
  explicit MolSeq(string sequence, string mol_type);
  string get_sequence();
  string get_mol_type();
  MolSeq transcribe();
  MolSeq translate();
  MolSeq complement();
  MolSeq reverse_complement();
  int* count_nucleotide();
  float calc_gc_content();
  vector<int> find_motif(string motif);
};

}  // namespace biocpp

#endif  // BIOCPP_INC_BIOCPP_MOLECULES_H_
