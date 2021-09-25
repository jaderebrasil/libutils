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

### Dev tools ###
CFLAGS+=-DDEBUG -ggdb3

VALGRIND_FLAGS=--leak-check=full --show-leak-kinds=all\
		--track-origins=yes #--log-file=log.txt --verbose

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
all: clean options bin run
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

copypres:
	cp include/list.h ~/projs/c/cpres/include/list.h
	cp include/strext.h ~/projs/c/cpres/include/strext.h
	cp build/list.o ~/projs/c/cpres/olibs/list.o
	cp build/strext.o ~/projs/c/cpres/olibs/strext.o

valgrind:
	valgrind $(VALGRIND_FLAGS) ./build/run_test

clean:
	rm build/run_test*
	rm build/*.o
.PHONY: all test options clean
