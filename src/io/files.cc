// Copyright 2021 panda5176

#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "biocpp/io.h"

using std::map;
using std::string;
using std::vector;

namespace biocpp {

vector<string> read_txt(string txt_path) {
  using std::getline;
  using std::ifstream;

  ifstream txt_handle(txt_path);

  string line;
  vector<string> txt_data;
  while (getline(txt_handle, line)) {
    txt_data.push_back(line);
  }

  txt_handle.close();

  return txt_data;
}

map<string, string> read_fasta(string fasta_path) {
  using std::getline;
  using std::ifstream;

  ifstream fasta_handle(fasta_path);

  string line, seq_id, sequence;
  map<string, string> fasta_data;
  while (getline(fasta_handle, line)) {
    if (line[0] == '>') {
      if (!seq_id.empty()) {
        fasta_data[seq_id] = sequence;
      }
      seq_id = line.substr(1);
      sequence.clear();
      continue;
    }
    sequence += line;
  }
  if (!seq_id.empty()) {
    fasta_data[seq_id] = sequence;
  }

  fasta_handle.close();

  return fasta_data;
}

}  // namespace biocpp
