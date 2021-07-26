// Copyright 2021 panda5176

#ifndef BIOCPP_INC_BIOCPP_ALIGNMENT_H_
#define BIOCPP_INC_BIOCPP_ALIGNMENT_H_

#include <string>

using std::string;

namespace biocpp {

int calc_hamming_dist(string str1, string str2);
// TODO(panda5176): MSA

}  // namespace biocpp

#endif  // BIOCPP_INC_BIOCPP_ALIGNMENT_H_
