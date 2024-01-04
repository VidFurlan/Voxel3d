# Compiler and compiler flags
CC = g++
CFLAGS = -Wall -g

# Source files and target executable
SOURCES = main.cpp
EXECUTABLE = voxel3d

# OpenGL library flags
LIBS = -lGL -lGLU -lglut

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES) $(LIBS)

clean:
	rm -f $(EXECUTABLE)

