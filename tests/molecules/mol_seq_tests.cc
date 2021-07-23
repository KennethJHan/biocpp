// Copyright 2021 panda5176

#include <biocpp/molecules.h>
#include <gtest/gtest.h>

using biocpp::MolSeq;

TEST(mol_seq, get_sequence) {
  MolSeq dna = MolSeq("ATGTAA", 'D');
  EXPECT_EQ(dna.get_sequence(), "ATGTAA");
}

TEST(mol_seq, get_mol_type) {
  MolSeq dna = MolSeq("ATGTAA", 'D');
  EXPECT_EQ(dna.get_mol_type(), 'D');
}

TEST(mol_seq, transcribe) {
  MolSeq dna = MolSeq("ATGTAA", 'D');
  EXPECT_EQ(dna.transcribe().get_sequence(), "AUGUAA");
}

TEST(mol_seq, translate) {
  MolSeq dna = MolSeq("ATGTAA", 'D');
  EXPECT_EQ(dna.translate().get_sequence(), "M*");
}

TEST(mol_seq, complement) {
  MolSeq dna = MolSeq("ATGTAA", 'D');
  EXPECT_EQ(dna.complement().get_sequence(), "TACATT");
}

TEST(mol_seq, reverse_complement) {
  MolSeq dna = MolSeq("ATGTAA", 'D');
  EXPECT_EQ(dna.reverse_complement().get_sequence(), "TTACAT");
}

TEST(mol_seq, calc_gc_content) {
  MolSeq dna = MolSeq("ATGTAA", 'D');
  EXPECT_FLOAT_EQ(dna.calc_gc_content(), 1.0 / 6.0);
}
