CC = g++ -std=c++17

CFLAGS = 

TARGET = ncc

SRCS = main.cpp CCCommand.cpp CCConfig.cpp CCConfigFactory.cpp CCExecutionInput.cpp CCLogger.cpp CommandExecutor.cpp uuid.cpp

OBJS    = $(SRCS:.cpp=.o)

INCDIR  = -I ../

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)

all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d
