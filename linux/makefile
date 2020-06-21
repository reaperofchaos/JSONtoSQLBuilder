# change application name here (executable output name)
TARGET=SqlBuilder

# compiler
CC=g++
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall
#src directory
SRCDIR=../src
#object directoy
OBJDIR=obj

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
# linker
LD=g++
LDFLAGS=$(PTHREAD) -export-dynamic

OBJS=    $(OBJDIR)/main.o \
		 $(OBJDIR)/jsonParser.o\
		 $(OBJDIR)/sqlBuilder.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(OBJDIR)/jsonParser.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/jsonParser.cpp -o $(OBJDIR)/jsonParser.o
	
	
$(OBJDIR)/sqlBuilder.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/sqlBuilder.cpp -o $(OBJDIR)/sqlBuilder.o	
	
$(OBJDIR)/main.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o
    
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)