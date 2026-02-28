APP_NAME = maiden

CXX      = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# macOS frameworks for legacy OpenGL + GLUT
FRAMEWORKS = -framework OpenGL -framework GLUT

SRC = maiden.cpp sgi.cpp
OBJ = $(SRC:.cpp=.o)

all: $(APP_NAME)

$(APP_NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(FRAMEWORKS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(APP_NAME)

.PHONY: all clean

