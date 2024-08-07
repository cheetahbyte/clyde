BUILD_DIR := build
CMAKE := cmake
CMAKE_FLAGS := -DCMAKE_BUILD_TYPE=Release
FORMAT := clang-format
SOURCE_DIR = src
SOURCE_EXTENSIONS := cpp h
SOURCES := $(shell find $(SOURCE_DIR) -type f \( -name '*.cpp' -o -name '*.h' \))

all: configure build

create-build-dir:
	mkdir -p $(BUILD_DIR)

configure: create-build-dir
	cd $(BUILD_DIR) && $(CMAKE) $(CMAKE_FLAGS) ..

build: configure
	cd $(BUILD_DIR) && $(CMAKE) --build .

format:
	$(FORMAT) -i $(SOURCES)

clean:
	rm -rf $(BUILD_DIR)

