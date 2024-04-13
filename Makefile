CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude

SRCDIR = src
OBJDIR = obj

SRCFILES = $(wildcard $(SRCDIR)/*.cc)
OBJFILES = $(patsubst $(SRCDIR)/%.cc,$(OBJDIR)/%.o,$(SRCFILES))
EXECUTABLE = biblioteca

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJFILES) main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cc | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(EXECUTABLE)
