GCC = g++
STND = -std=c++17
CFLAGS = -c -Wall -Wextra -Werror -pedantic -g
LINK = -I. -L. -lsqlite3 -lws2_32
all: server client

server: server.o database.o errors.o
	$(GCC) -o server server.o database.o errors.o $(LINK)

client: client.o errors.o
	$(GCC) -o client client.o errors.o $(LINK)

server.o: ./server/server.cpp
	$(GCC) $(CFLAGS) $(STND) ./server/server.cpp

client.o: ./client/client.cpp
	$(GCC) $(CFLAGS) $(STND) ./client/client.cpp

database.o: ./database/database.cpp
	$(GCC) $(CFLAGS) $(STND) ./database/database.cpp

errors.o: ./errors/errors.cpp
	$(GCC) $(CFLAGS) $(STND) ./errors/errors.cpp

clean:
	del /Q *.o *.exe
