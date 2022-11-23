CC      = g++
CFLAGS  = -O3
OPTION  = -std=c++14
LIBS    = -lboost_system -lboost_thread -pthread

all: chat_server chat_client

chat_server: 
	g++ -o chat_server LocalMessages.cpp chat_server.cpp -lboost_system -lboost_thread -pthread

chat_client: 
	g++ -o chat_client chat_client.cpp -lboost_system -lboost_thread -pthread
# msg.o: LocalMessages.cpp
# 	$(CC) $(OPTION) -c $(CFLAGS) LocalMessages.cpp

# chat_server.o: chat_server.cpp protocol.hpp
# 	$(CC) $(OPTION) -c $(CFLAGS) chat_server.cpp

# chat_client.o: chat_client.cpp protocol.hpp
# 	$(CC) $(OPTION) -c $(CFLAGS) chat_client.cpp

.PHONY: clean

clean:
	rm chat_server chat_client
