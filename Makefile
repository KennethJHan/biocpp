CC = g++
INC_DIR = .
OBJ_DIR = obj
SRC_DIR = src
OUT = biocpp.exe

OBJS = $(MAIN_OBJS) $(ALGORITHMS_OBJS) $(IO_OBJS) $(MOLECULES_OBJS)

MAIN = biocpp
MAIN_OBJS = $(patsubst %,$(OBJ_DIR)/%.o,$(MAIN))
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) -c $< -o $@ -I $(INC_DIR)

ALGORITHMS = alignment
ALGORITHMS_OBJS = $(patsubst %,$(OBJ_DIR)/algorithms-%.o,$(ALGORITHMS))
$(OBJ_DIR)/algorithms-%.o: $(SRC_DIR)/algorithms/%.cc
	$(CC) -c $< -o $@ -I $(INC_DIR)

IO = files
IO_OBJS = $(patsubst %,$(OBJ_DIR)/io-%.o,$(IO))
$(OBJ_DIR)/io-%.o: $(SRC_DIR)/io/%.cc
	$(CC) -c $< -o $@ -I $(INC_DIR)

MOLECULES = gene_material
MOLECULES_OBJS = $(patsubst %,$(OBJ_DIR)/molecules-%.o,$(MOLECULES))
$(OBJ_DIR)/molecules-%.o: $(SRC_DIR)/molecules/%.cc
	$(CC) -c $< -o $@ -I $(INC_DIR)


.PHONY: install

install: $(OBJS)
	$(CC) $^ -o $(OUT) -I $(INC_DIR)
