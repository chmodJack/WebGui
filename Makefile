CXX=emcc
OUTPUT=imgui.js

SOURCES+=main.cpp
SOURCES+=imgui_impl_glfw.cpp
SOURCES+=imgui_impl_opengl3.cpp
SOURCES+=imgui.cpp
SOURCES+=imgui_draw.cpp
SOURCES+=imgui_demo.cpp

LIBS+=-lGL

WEBGL_VER+=-s USE_WEBGL2=1
WEBGL_VER+=-s USE_GLFW=3
#WEBGL_VER+=-s USE_GLFW=2
WEBGL_VER+=-s FULL_ES3=1
USE_WASM+=-s WASM=1

all: $(SOURCES) $(OUTPUT)

$(OUTPUT):$(SOURCES)
	$(CXX) $(SOURCES) -std=c++11 -o $(OUTPUT) $(LIBS) $(WEBGL_VER) -O2 --preload-file data $(USE_WASM)
clean:
	rm -f $(OUTPUT)
