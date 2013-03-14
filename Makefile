CXX = clang++
EXEC = miu
OBJECTS = rules.o

${EXEC} : ${OBJECTS} miu.cpp
	${CXX} ${OBJECTS} miu.cpp -o ${EXEC}

rules.o : rules.hpp rules.cpp
	${CXX} -c rules.cpp -o rules.o
