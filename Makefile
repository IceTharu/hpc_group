SRCS	= main.c datatools.c mmmult.c
OBJS	= $(SRCS:.c=.o)
TARGET	= mmmult.$(CC)

CC	= gcc
INCS	= 
DBG	= -g
OPT	= -o3 -L /usr/lib64/atlas -lsatlas
PARA	= 
CFLAGS	= $(DBG) $(OPT) $(PARA) $(XOPTS)

LIBS	= 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	@/bin/rm -f $(OBJS) *~ core*

realclean: clean
	@/bin/rm -f $(TARGET)

