// Copyright 2021 panda5176

#ifndef BIOCPP_INC_BIOCPP_IO_H_
#define BIOCPP_INC_BIOCPP_IO_H_

#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

namespace biocpp {

vector<string> read_txt(string txt_path);
map<string, string> read_fasta(string fasta_path);

}  // namespace biocpp

#endif  // BIOCPP_INC_BIOCPP_IO_H_
