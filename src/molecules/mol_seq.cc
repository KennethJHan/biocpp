// Copyright 2021 panda5176

#include <algorithm>
#include <exception>
#include <map>
#include <string>
#include <vector>

#include "biocpp/molecules.h"

using std::exception;
using std::string;
using std::vector;

namespace biocpp {

MolSeq::MolSeq(string sequence, char mol_type) {
  sequence_ = sequence;
  mol_type_ = mol_type;
}

string MolSeq::get_sequence() { return sequence_; }

char MolSeq::get_mol_type() { return mol_type_; }

MolSeq MolSeq::transcribe() {
  using std::replace;

  if (mol_type_ != 'D') {
    throw 1;
  }

  string rna_sequence = sequence_;
  replace(rna_sequence.begin(), rna_sequence.end(), 'T', 'U');

  return MolSeq(rna_sequence, 'R');
}

MolSeq MolSeq::back_transcribe() {
  using std::replace;

  if (mol_type_ != 'R') {
    throw 1;
  }

  string dna_sequence = sequence_;
  replace(dna_sequence.begin(), dna_sequence.end(), 'U', 'T');

  return MolSeq(dna_sequence, 'D');
}

MolSeq MolSeq::translate() {
  using std::map;

  if (mol_type_ == 'P') {
    throw 1;
  }

  map<string, char> codon_table;
  if (mol_type_ == 'D') {
    codon_table = {
        {"AAA", 'K'}, {"AAG", 'K'}, {"AAC", 'N'}, {"AAT", 'N'}, {"AGA", 'R'},
        {"AGG", 'R'}, {"AGC", 'S'}, {"AGT", 'S'}, {"ACA", 'T'}, {"ACG", 'T'},
        {"ACC", 'T'}, {"ACT", 'T'}, {"ATA", 'I'}, {"ATG", 'M'}, {"ATC", 'I'},
        {"ATT", 'I'}, {"CAA", 'Q'}, {"CAG", 'Q'}, {"CAC", 'H'}, {"CAT", 'H'},
        {"CGA", 'R'}, {"CGG", 'R'}, {"CGC", 'R'}, {"CGT", 'R'}, {"CCA", 'P'},
        {"CCG", 'P'}, {"CCC", 'P'}, {"CCT", 'P'}, {"CTA", 'L'}, {"CTG", 'L'},
        {"CTC", 'L'}, {"CTT", 'L'}, {"TAA", '*'}, {"TAG", '*'}, {"TAC", 'Y'},
        {"TAT", 'Y'}, {"TGA", '*'}, {"TGG", 'W'}, {"TGC", 'C'}, {"TGT", 'C'},
        {"TCA", 'S'}, {"TCG", 'S'}, {"TCC", 'S'}, {"TCT", 'S'}, {"TTA", 'L'},
        {"TTG", 'L'}, {"TTC", 'F'}, {"TTT", 'F'}, {"GAA", 'E'}, {"GAG", 'E'},
        {"GAC", 'D'}, {"GAT", 'D'}, {"GGA", 'G'}, {"GGG", 'G'}, {"GGC", 'G'},
        {"GGT", 'G'}, {"GCA", 'A'}, {"GCG", 'A'}, {"GCC", 'A'}, {"GCT", 'A'},
        {"GTA", 'V'}, {"GTG", 'V'}, {"GTC", 'V'}, {"GTT", 'V'},
    };
  } else if (mol_type_ == 'R') {
    codon_table = {
        {"AAA", 'K'}, {"AAG", 'K'}, {"AAC", 'N'}, {"AAU", 'N'}, {"AGA", 'R'},
        {"AGG", 'R'}, {"AGC", 'S'}, {"AGU", 'S'}, {"ACA", 'T'}, {"ACG", 'T'},
        {"ACC", 'T'}, {"ACU", 'T'}, {"AUA", 'I'}, {"AUG", 'M'}, {"AUC", 'I'},
        {"AUU", 'I'}, {"CAA", 'Q'}, {"CAG", 'Q'}, {"CAC", 'H'}, {"CAU", 'H'},
        {"CGA", 'R'}, {"CGG", 'R'}, {"CGC", 'R'}, {"CGU", 'R'}, {"CCA", 'P'},
        {"CCG", 'P'}, {"CCC", 'P'}, {"CCU", 'P'}, {"CUA", 'L'}, {"CUG", 'L'},
        {"CUC", 'L'}, {"CUU", 'L'}, {"UAA", '*'}, {"UAG", '*'}, {"UAC", 'Y'},
        {"UAU", 'Y'}, {"UGA", '*'}, {"UGG", 'W'}, {"UGC", 'C'}, {"UGU", 'C'},
        {"UCA", 'S'}, {"UCG", 'S'}, {"UCC", 'S'}, {"UCU", 'S'}, {"UUA", 'L'},
        {"UUG", 'L'}, {"UUC", 'F'}, {"UUU", 'F'}, {"GAA", 'E'}, {"GAG", 'E'},
        {"GAC", 'D'}, {"GAU", 'D'}, {"GGA", 'G'}, {"GGG", 'G'}, {"GGC", 'G'},
        {"GGU", 'G'}, {"GCA", 'A'}, {"GCG", 'A'}, {"GCC", 'A'}, {"GCU", 'A'},
        {"GUA", 'V'}, {"GUG", 'V'}, {"GUC", 'V'}, {"GUU", 'V'},
    };
  }

  string prot_sequence;
  char prot_mol_type = 'P';
  for (int idx = 0; idx < sequence_.length() / 3; idx++) {
    prot_sequence += codon_table.find(sequence_.substr(idx * 3, 3))->second;
  }

  return MolSeq(prot_sequence, prot_mol_type);
}

string _complement(char mol_type, string* sequence) {
  if (mol_type == 'P') {
    throw 1;
  }

  std::string complement_sequence;
  for (int idx = 0; idx < (*sequence).length(); idx++) {
    switch ((*sequence)[idx]) {
      case 'A': {
        if (mol_type == 'D')
          complement_sequence += 'T';
        else if (mol_type == 'R')
          complement_sequence += 'U';
        break;
      }
      case 'T':
      case 'U': {
        complement_sequence += 'A';
        break;
      }
      case 'G': {
        complement_sequence += 'C';
        break;
      }
      case 'C': {
        complement_sequence += 'G';
        break;
      }
    }
  }

  return complement_sequence;
}

MolSeq MolSeq::complement() {
  return MolSeq(_complement(mol_type_, &sequence_), mol_type_);
}

MolSeq MolSeq::reverse_complement() {
  using std::reverse;

  string rc_sequence = _complement(mol_type_, &sequence_);
  reverse(rc_sequence.begin(), rc_sequence.end());

  return MolSeq(rc_sequence, mol_type_);
}

int* MolSeq::count_nucleotide() {
  using std::count;

  if (mol_type_ == 'P') {
    throw 1;
  }

  static int nucleotide_counts[4];
  string::iterator begin = sequence_.begin(), end = sequence_.end();
  if (mol_type_ == 'D') {
    static int nucleotide_counts[4] = {
        static_cast<int>(count(begin, end, 'A')),
        static_cast<int>(count(begin, end, 'C')),
        static_cast<int>(count(begin, end, 'G')),
        static_cast<int>(count(begin, end, 'T')),
    };
  } else if (mol_type_ == 'R') {
    static int nucleotide_counts[4] = {
        static_cast<int>(count(begin, end, 'A')),
        static_cast<int>(count(begin, end, 'C')),
        static_cast<int>(count(begin, end, 'G')),
        static_cast<int>(count(begin, end, 'U')),
    };
  }

  return nucleotide_counts;
}

float MolSeq::calc_gc_content() {
  using std::count;

  int g_count = count(sequence_.begin(), sequence_.end(), 'G');
  int c_count = count(sequence_.begin(), sequence_.end(), 'C');

  return (g_count + c_count) / static_cast<float>(sequence_.length());
}

vector<int> MolSeq::find_motif(string motif) {
  vector<int> motif_idxes;

  for (int idx = 0; idx < sequence_.length() - motif.length() + 1; idx++) {
    if (sequence_.substr(idx, motif.length()) == motif) {
      motif_idxes.push_back(idx);
    }
  }

  return motif_idxes;
}

}  // namespace biocpp
