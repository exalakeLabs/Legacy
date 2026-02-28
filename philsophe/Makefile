# Simple cross-platform Makefile for dining philosophers examples

UNAME_S := $(shell uname -s 2>/dev/null)

ifeq ($(UNAME_S),Darwin)
  CXX ?= clang++
  PLATFORM_DEFINES += -DPLATFORM_MACOS
else
  CXX ?= g++
endif

CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic
CXXFLAGS += $(PLATFORM_DEFINES)

# Use pthreads on POSIX platforms
LDFLAGS ?=
LDFLAGS += -pthread

SRCS := dinphil.cpp dinphil2.cpp philosophe.cpp
OBJS := $(SRCS:.cpp=.o)

BINARIES := dinphil dinphil2 philosophe

.PHONY: all clean

all: $(BINARIES)

dinphil: dinphil.o
	$(CXX) $^ $(LDFLAGS) -o $@

dinphil2: dinphil2.o
	$(CXX) $^ $(LDFLAGS) -o $@

philosophe: philosophe.o
	$(CXX) $^ $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BINARIES)

