# ###########################################
# Makefile for cpp-proj by Chris Sanchez    #
# ###########################################

OUT := a.out

CC := g++

LIBS := -lSDL2 -lSDL2_image -lm

CFLAGS := -c -Wall

LFLAGS := $(LIBS)

SRCDIR := src

INCDIR := -Iinclude

OBJDIR := obj

SRCFILES_ := main.cpp palette.cpp plasma.cpp

SRCFILES := $(addprefix $(SRCDIR)/,$(SRCFILES_))
OBJFILES := $(addprefix $(OBJDIR)/,$(SRCFILES_:.cpp=.o))

all: $(OBJFILES)
	$(CC) $(LFLAGS) $(INCDIR) $(OBJFILES) -o $(OUT)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

clean:
	rm $(OUT)
	rm $(OBJDIR)/*.o

