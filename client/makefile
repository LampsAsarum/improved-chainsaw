all:cli

cli:cli.o System.o TcpClient.o Process.o Bridge.o
	g++ -o cli cli.o System.o TcpClient.o Process.o Bridge.o -ljson -lpthread

cli.o:cli.cpp
	g++ -c cli.cpp -g

System.o:System.cpp
	g++ -c System.cpp -g

TcpClient.o:TcpClient.cpp
	g++ -c TcpClient.cpp -g

Process.o:Process.cpp
	g++ -c Process.cpp -g

Bridge.o:Bridge.cpp
	g++ -c Bridge.cpp -g

clean:
	rm -rf *.o *.cpp~ *.h~
