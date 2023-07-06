SOURCE = main.cpp

EXECUTABLE = weather_app

CXX_STD = -std=c++14
CXX = g++
CXXFLAGS = -Wall -lcurl $(CXX_STD)

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
	$(CXX) $(SOURCE) $(CXXFLAGS) -o $(EXECUTABLE) 

run: all
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
