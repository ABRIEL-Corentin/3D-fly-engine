########################
##
##  Created on Sun Jan 22 2023
##
##  Makefile
##
########################

FILE_TYPE = .cpp
COMPILER = g++
SRC_DIR = src
BUILD_DIR = obj

SRC =\
	${SRC_DIR}/scene/scene.cpp\
	${SRC_DIR}/scene/entity.cpp\
	${SRC_DIR}/system/uuid.cpp\
	${SRC_DIR}/component/component.cpp\
	${SRC_DIR}/component/components/identity.cpp\
	${SRC_DIR}/component/components/transform.cpp\

INCLUDE =\
	-I./include/\

OBJ = ${SRC:${SRC_DIR}/%${FILE_TYPE}=${BUILD_DIR}/%.o}
OBJ_FLAGS = -g3 -O3 -W -Wall -Wextra -Werror -std=c++20 ${INCLUDE}
BIN_FLAGS =
NAME = engine.so

all:
	@echo -e "\e[94mENGINE OBJ\e[0m"
	@make -sj ${OBJ}
	@echo -e "\e[94mENGINE BIN\e[0m"
	@make -s ${NAME}

${BUILD_DIR}/%.o: ${SRC_DIR}/%${FILE_TYPE}
	echo -e "\e[92m\t$<\e[0m"
	mkdir -p ${dir $@}
	${COMPILER} -MD -fPIC ${OBJ_FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	echo -e "\e[92m\t${NAME}\e[0m"
	${COMPILER} -shared -o ${NAME} ${OBJ} ${BIN_FLAGS}

clean:
	@echo -e "\e[91mENGINE CLEAN\e[0m"
	@rm -rf ${BUILD_DIR}

fclean: clean
	@echo -e "\e[91mENGINE FCLEAN\e[0m"
	@rm -f ${NAME}

re: fclean all

-include ${OBJ:%.o=%.d}
