#Make file for the ModberryPi

CMPLR = g++

TARGET = mbpi

FILES = $(wildcard *.cpp)

OBJS = $(FILES:.CPP=.O)

ASMS = $(FILES:.CPP=.s)


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CMPLR) -DDEBUG_MODE -o $(TARGET) $(OBJS) #running in debug mode

%.o:	%.cpp
	$(CMPLR) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

run:
	sudo ./$(TARGET)
