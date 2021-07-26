// Copyright 2021 panda5176

#include "biocpp/alignment.h"

#include <string>

using std::string;

namespace biocpp {

int calc_hamming_dist(string str1, string str2) {
  int hamming_dist = 0;
  for (int idx = 0; idx < str1.size(); idx++) {
    if (str1[idx] != str2[idx]) {
      hamming_dist++;
    }
  }

  return hamming_dist;
}

}  // namespace biocpp
