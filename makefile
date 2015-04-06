EXE = main
GTEST_DIR = ../gtest-1.7.0
SDL = -framework SDL2
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS = -std=c++11
LDFLAGS = $(SDL)

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all : $(EXE) player.o platform.o

player.o : player.h player.cc draw_object.o

platform.o : platform.h platform.cc draw_object.o

draw_object.o : draw_object.h draw_object.cc

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
	$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
	$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

clean :
	rm -rf *.o *.a

draw_object_test.o : draw_object_test.cc draw_object.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

player_test.o : player_test.cc player.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

platform_test.o : platform_test.cc platform.o $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

test : player_test.o platform_test.o \
       draw_object_test.o draw_object.o \
       player.o platform.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
	./test
	rm -f test
