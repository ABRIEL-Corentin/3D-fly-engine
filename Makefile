########################
##
##  Created on Fri Mar 10 2023
##
##  Makefile
##
########################

COMPILER = c++

SRC_PATH = ./src
BIN_PATH = ./bin
BUILD_PATH = ./build

CORE_PATH = ${SRC_PATH}/core
EDITOR_PATH = ${SRC_PATH}/editor
ENGINE_PATH = ${SRC_PATH}/engine
IMGUI_PATH = ${SRC_PATH}/imgui

CORE_BIN = core.so
EDITOR_BIN = editor.so
ENGINE_BIN = engine.so
IMGUI_BIN = imgui.so

SRC_CORE_BIN = ${CORE_PATH}/${CORE_BIN}
SRC_EDITOR_BIN = ${EDITOR_PATH}/${EDITOR_BIN}
SRC_ENGINE_BIN = ${ENGINE_PATH}/${ENGINE_BIN}
SRC_IMGUI_BIN = ${IMGUI_PATH}/${IMGUI_BIN}

DEST_CORE_BIN = ${BIN_PATH}/${CORE_BIN}
DEST_EDITOR_BIN = ${BIN_PATH}/${EDITOR_BIN}
DEST_ENGINE_BIN = ${BIN_PATH}/${ENGINE_BIN}
DEST_IMGUI_BIN = ${BIN_PATH}/${IMGUI_BIN}

BIN_EDITOR_NAME = fly-engine-editor
BIN_EDITOR_PATH = ${BUILD_PATH}/editor/${BIN_EDITOR_NAME}
BIN_EDITOR_FLAGS =\
	-lGL -lGLEW -lglfw\
	${DEST_CORE_BIN}\
	${DEST_EDITOR_BIN}\
	${DEST_ENGINE_BIN}\
	${DEST_IMGUI_BIN}\

editor:
	@make -sC ${CORE_PATH}
	@make -sC ${EDITOR_PATH}
	@make -sC ${ENGINE_PATH}

	@mkdir -p ${BIN_PATH}
	@mkdir -p ${dir ${BIN_EDITOR_PATH}}

	@cp ${SRC_CORE_BIN} ${DEST_CORE_BIN}
	@cp ${SRC_EDITOR_BIN} ${DEST_EDITOR_BIN}
	@cp ${SRC_ENGINE_BIN} ${DEST_ENGINE_BIN}
	@cp ${SRC_IMGUI_BIN} ${DEST_IMGUI_BIN}
	@cp ${BIN_PATH} ${BUILD_PATH}/editor/bin -r

	@echo -e "\e[94m\nFINAL EDITOR BIN\e[0m"
	@make -s ${BIN_EDITOR_PATH}

${BIN_EDITOR_PATH}:
	echo -e "\e[92m\t${BIN_EDITOR_PATH}\e[0m"
	@${COMPILER} -o ${BIN_EDITOR_PATH} ${BIN_EDITOR_FLAGS}

clean:
	@make -sC ${CORE_PATH} clean
	@make -sC ${EDITOR_PATH} clean
	@make -sC ${ENGINE_PATH} clean

fclean:
	@make -sC ${CORE_PATH} fclean
	@make -sC ${EDITOR_PATH} fclean
	@make -sC ${ENGINE_PATH} fclean
	@rm -rf ${BUILD_PATH}
	@rm -rf ${BIN_PATH}

re: fclean editor
