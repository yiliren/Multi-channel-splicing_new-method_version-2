main: 
	g++ -std=c++11 -g -pthread -o client client.cpp
	g++ -std=c++11 -g -pthread -o server server.cpp
clean:
	-rm client server
