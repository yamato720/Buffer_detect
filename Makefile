NAME = test
BUILD_DIR = ./build
GCC_FLAG += `pkg-config --cflags opencv4 --libs opencv4`
BIN = $(BUILD_DIR)/$(NAME)
$(shell mkdir -p $(BUILD_DIR))

$(BIN):
	g++ main.cpp -o $(BIN) `pkg-config --cflags opencv4 --libs opencv4`
clean:
	rm -rf build

run:$(BIN)
	$^

yolov5_det: 
	$(MAKE) -f yolov5_build/Makefile yolov5_det
.PHONY : yolov5_det

.PHONY: .clean .build .run
