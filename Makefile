INC := -I./

STL_SRC := $(wildcard STL/src/*.cpp)
STL_OBJ := $(patsubst STL/src/%.cpp, STL/obj/%.o, $(STL_SRC))
STL_HDR := $(wildcard STL/hdr/*.hpp)
TYP_SRC := $(wildcard Type/src/*.cpp)
TYP_OBJ := $(patsubst Type/src/%.cpp, Type/obj/%.o, $(TYP_SRC))
TYP_HDR := $(wildcard Type/hdr/*.hpp)
MATR_SRC := $(wildcard Matrix/src/*.cpp)
MATR_OBJ := $(patsubst Matrix/src/%.cpp, Matrix/obj/%.o, $(MATR_SRC))
MATR_HDR := $(wildcard Matrix/hdr/*.hpp)

STL/obj/%.o : STL/src/%.cpp
	@echo building $@ 
	@mkdir -p STL/obj
	@g++ -c $< $(INC) -o $@
	@echo Done...

Type/obj/%.o  : Type/src/%.cpp
	@echo building $@
	@mkdir -p Type/obj
	@g++ -c $< $(INC) -o $@
	@echo Done...

Matrix/obj/%.o : Matrix/src/%.cpp
	@echo building $@
	@mkdir -p Matix/obj
	@g++ -c $< $(INC) -o $@
	@echo Done...

vector : STL/obj/vector.o STL/obj/vector_main.o
	@echo building $@
	@mkdir -p STL/bin
	@g++ $^ -o STL/bin/$@
	@echo Done...

list : STL/obj/list.o STL/obj/list_main.o
	@echo building $@
	@mkdir -p STL/bin
	@g++ $^ -o STL/bin/$@
	@echo Done...

BinaryTree : STL/obj/BinaryTree.o STL/obj/BinaryTree_main.o
	@echo building $@
	@mkdir -p STL/bin
	@g++ $^ -o STL/bin/$@
	@echo Done...

STL : $(STL_OBJ)
	@echo building $@
	@mkdir -p STL/bin
	@make vector
	@make list
	@make BinaryTree
	@echo Done...

Integer : Type/obj/Integer.o
	@echo building $@
	@mkdir -p Type/bin
	@g++ $< -o Type/bin/$@
	@echo Done...

Rational : Type/obj/Rational.o
	@echo building $@
	@mkdir -p Type/bin
	@g++ $< -o Type/bin/$@
	@echo Done...

#One more Type missing here 

Type : $(TYP_OBJ)
	@echo building $@
	@mkdir -p Type/bin
	@g++ $^ -o Type/bin/$@
	@echo Done...

#MatrixGenerator : Matrix/obj/MatrixGenerator.o
#	@mkdir -p Matrix/bin
#	@g++ $< -o Matrix/bin/$@

#gauss : Matrix/obj/MatrixGenerator.o Matrix/obj/DUT.o Matrix/obj/gauss.o
#	@mkdir -p Matrix/bin
#	@g++ $^ -o Matrix/bin/$@

#other algorithms ...

#DUT : Matrix/obj/DUT.o 
#	@mkdir -p Matrix/bin
#	@g++ $^ -o Matrix/bin/$@

clean:
	@rm -rf STL/bin
	@rm -rf STL/obj
	@rm -rf Type/bin
	@rm -rf Type/obj
