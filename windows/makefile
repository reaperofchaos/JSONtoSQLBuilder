# change application name here (executable output name)
TARGET=SqlBuilder.exe

# compiler
CC=g++
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall
#src directory
SRCDIR=..\src
#object directoy
OBJDIR=obj
#target directory

CCFLAGS=$(DEBUG) $(OPT) $(WARN) -pipe
# linker
LD=g++
LDFLAGS=$(PTHREAD)

OBJS=    $(OBJDIR)\main.o \
		 $(OBJDIR)\jsonParser.o\
		 $(OBJDIR)\sqlBuilder.o\
		 $(OBJDIR)\csvParser.o\
		 $(OBJDIR)\utilities.o\

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(OBJDIR)\jsonParser.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)\jsonParser.cpp -o $(OBJDIR)\jsonParser.o

$(OBJDIR)\csvParser.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)\csvParser.cpp -o $(OBJDIR)\csvParser.o	

$(OBJDIR)\utilities.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)\utilities.cpp -o $(OBJDIR)\utilities.o

$(OBJDIR)\sqlBuilder.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)\sqlBuilder.cpp -o $(OBJDIR)\sqlBuilder.o	
	
$(OBJDIR)\main.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)\main.cpp -o $(OBJDIR)\main.o
    
clean:
	del $(OBJDIR)\*.o $(TARGET)