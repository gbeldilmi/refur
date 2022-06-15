#------------------------------------------------------------------------------#
# Project name and installation directories                                    #
#------------------------------------------------------------------------------#
PROJECT_NAME        := refur
BINARY_FILE         := $(PROJECT_NAME)
INSTALL_DIR         := ~/.$(PROJECT_NAME)
LINK_BINARY_DIR     := /usr/bin

#------------------------------------------------------------------------------#
# Source files                                                                 #
#------------------------------------------------------------------------------#
INCLUDE_DIR     := include
SOURCE_DIR      := source
BUILD_DIR       := build
H_FILES         := $(wildcard $(INCLUDE_DIR)/*.h)
C_FILES         := $(wildcard $(SOURCE_DIR)/*.c) $(wildcard $(SOURCE_DIR)/*/*.c)
O_FILES         := $(C_FILES:$(SOURCE_DIR)/%.c=$(BUILD_DIR)/%.o)

#------------------------------------------------------------------------------#
# Options for code generation                                                  #
#------------------------------------------------------------------------------#
INCLUDES_FLAGS  := -I $(INCLUDE_DIR)/
LIBRARIES_FLAGS :=
C_FLAGS         := -Wall -Werror -Wextra -O3
LD_FLAGS        :=

#------------------------------------------------------------------------------#
# Commands                                                                     #
#------------------------------------------------------------------------------#
.PHONY : all, run, clean, deploy
all : $(BUILD_DIR)/$(BINARY_FILE)
run : all
	cd $(BUILD_DIR) && ./$(BINARY_FILE)
clean :
	rm -rv $(BUILD_DIR)
deploy : all
	rm -v $(BUILD_DIR)/*.o
	mkdir -pv $(INSTALL_DIR)
	cp -frv $(BUILD_DIR)/* $(INSTALL_DIR)
	sudo ln -fsv $(INSTALL_DIR)/$(BINARY_FILE) $(LINK_BINARY_DIR)/$(BINARY_FILE)

#------------------------------------------------------------------------------#
# Dependencies                                                                 #
#------------------------------------------------------------------------------#
$(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.c
	mkdir -pv $(dir $@)
	gcc -v $(C_FLAGS) -c $< -o $@ $(INCLUDES_FLAGS)
$(BUILD_DIR)/$(BINARY_FILE) : $(O_FILES)
	gcc -v $(LD_FLAGS) $^ -o $@ $(LIBRARIES_FLAGS)
