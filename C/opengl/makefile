CC = g++
CFLAGS = -Wall -std=c++11 -g
LIBS = -lglut -lGLU -lGL

all: hello_opengl

hello_opengl: hello_opengl.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f hello_opengl

run:
	./hello_opengl