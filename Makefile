# Basic #
#########
CC=gcc
VERSION=0.0.1

##########
# CFlags #
##########
STDC=c99
POSIX_SOURCE=200809L

CFLAGS=-Wall -Wextra -Wpedantic \
       -Wformat=2 -Wno-unused-parameter -Wshadow \
       -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
       -Wredundant-decls -Wnested-externs -Wmissing-include-dirs \
       -Wno-deprecated-declarations \
	   -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=${POSIX_SOURCE} -DVERSION=\"${VERSION}\" \
	   -std=${STDC} -Os\
	   -Iinclude/

# GCC warnings that Clang doesn't provide:
ifeq (${CC},gcc)
    CFLAGS+=-Wjump-misses-init -Wlogical-op
    CFLAGS+=-ftrack-macro-expansion=0# metalang99
endif

#################
BUILD_DIR=build
SRC=$(shell find . -name "*.c")
OBJ=$(SRC:%.c=%.o)
OBJ_BUILD=$(addprefix ./${BUILD_DIR}/,$(notdir ${OBJ}))
TARGET=./${BUILD_DIR}/run_test
##########################
all: options bin run

test: CFLAGS+=-DDEBUG -g
test: clean options bin run
##########################

options:
	@echo "---------------------"
	@echo "   build options:"
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo "SRC      = ${SRC}"
	@echo "OBJ      = ${OBJ}"
	@echo "TARGET   = ${TARGET}"
	@echo "---------------------"


bin: ${OBJ}
	$(CC) -o ${TARGET} ${OBJ_BUILD} ${LDFLAGS}

%.o: %.c
	${CC} -c ${CFLAGS} -o $(addprefix ./${BUILD_DIR}/,$(notdir $@)) $<

run:
	@echo "----------------------"
	./${TARGET}

.PHONY: all test options clean
