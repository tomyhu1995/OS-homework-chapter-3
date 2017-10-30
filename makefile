CC = gcc

CFLAGS =
CFLAGS += -Wall
CFLAGS += -g

EXE_NAME_5_1 = OS_HW5_1
EXE_NAME_5_3 = OS_HW5_3

LIB =

INC =

SRC_5_1 = 
SRC_5_1 = ./OS_HW5_1

SRC_FILES_5_1 = ${addsuffix .c, ${SRC_5_1}}
OBJ_FILES_5_1 = ${addsuffix .o, ${SRC_5_1}}

SRC_5_3 = 
SRC_5_3 = ./OS_HW5_3

SRC_FILES_5_3 = ${addsuffix .c, ${SRC_5_3}}
OBJ_FILES_5_3 = ${addsuffix .o, ${SRC_5_3}}

all:${EXE_NAME_5_1} ${EXE_NAME_5_3}

5_1: ${EXE_NAME_5_1}

5_3: ${EXE_NAME_5_3}

$(EXE_NAME_5_1): $(OBJ_FILES_5_1)
	$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ_FILES_5_1) -o $@
$(OBJ_FILES_5_1): %.o: %.c
	$(CC) $(CFLAGS) $(INC) -c  $< -o $@

$(EXE_NAME_5_3): $(OBJ_FILES_5_3)
	$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJ_FILES_5_3) -o $@
$(OBJ_FILES_5_3): %.o: %.c
	$(CC) $(CFLAGS) $(INC) -c  $< -o $@

clean:
	rm -f ./*.txt ${EXE_NAME_5_3} ${EXE_NAME_5_1} ${OBJ_FILES_5_3} ${OBJ_FILES_5_1}