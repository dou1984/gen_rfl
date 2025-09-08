#include <string>
#include "tpl.h"

const std::string make_tpl = R"(
CXX := g++
CXXFLAGS := -std=c++17 -Wall

INCLUDE_DIRS := {{SRC}} ../ /usr/local/include/ /usr/include/
INCLUDE_FLAGS := $(addprefix -I,$(INCLUDE_DIRS))

CXXFLAGS += $(INCLUDE_FLAGS)

# 递归查找所有 .cpp 文件
SRCS := $(shell find . -name "*.cpp")
OBJS := $(SRCS:.cpp=.o)
LIBRARY := librfl.a

$(LIBRARY): $(OBJS)
	ar rcs $@ $(OBJS)
	ranlib $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: lib clean install

lib: $(LIBRARY)

install:
	cp $(LIBRARY) ../{{SRC}}/libs

clean:
	rm -f $(OBJS) $(TARGET)
)";

namespace tpl
{
	const std::string &makefile()
	{
		return make_tpl;
	}
}