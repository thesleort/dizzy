
EXE = dizzy.out

SRC_DIR = src
OBJ_DIR = build
INC_DIR = include
LIB_DIR = lib

PKG = gtk+-3.0 gstreamer-1.0 gstreamer-video-1.0

LIB = $(LDFLAGS)

CC = g++
#`pkg-config --cflags $(PKG)`
CPPFLAGS += -std=c++11  -Wall -Wextra -pedantic -g

LDFLAGS += -Llib
#`pkg-config --libs $(PKG)`
LDLIBS += -lm 

SRC = $(wildcard $(SRC_DIR)/*.cpp \
		$(SRC_DIR)/*/*.cpp)
INC		= -I$(INC_DIR)/ -I$(LIB_DIR)/
OBJROOT = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OBJ 	= $(OBJROOT:$(SRC_DIR)/*/%.cpp=$(OBJ_DIR)/*/%.o)

MODULES = $(filter-out $(MOD_DIR)/README.md $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(INC_DIR)/*.hpp), $(wildcard $(SRC_DIR)/*/))

all: $(EXE)

$(EXE): $(OBJ) 
	$(CC) $(INC) $^ -o $@ $(LIB) $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
	mkdir -p $(addprefix $(OBJ_DIR)/, $(MODULES:$(SRC_DIR)/%=%))
	$(CC) $(INC) -c $< -o $@ $(CPPFLAGS)

clean:
	rm -rf $(OBJ_DIR)/*
	$(RM) $(EXE)