CXX = g++
EXEC = miu
OBJECTS = rules.o rule.o

${EXEC} : ${OBJECTS} miu.cpp
	${CXX} ${OBJECTS} miu.cpp -o ${EXEC}

rule.o : rule.hpp rule.cpp
	${CXX} -c rule.cpp -o rule.o
rules.o : rules.hpp rules.cpp rule.o
	${CXX} -c rules.cpp -o rules.o

clean:
	rm -fr ${OBJECTS} ${EXEC}
