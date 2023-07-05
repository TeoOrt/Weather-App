SOURCE = main.cpp

EXECUTABLE = weather_app

CXX = g++
CXXFLAGS = -Wall -lcurl
all: $(EXECUTABLE)


$(EXECUTABLE): $(SOURCE)
	$(CXX) $(SOURCE) $(CXXFLAGS) -o $(EXECUTABLE) 


run: all
	./$(EXECUTABLE)


clean:
	rm -f $(EXECUTABLE)
