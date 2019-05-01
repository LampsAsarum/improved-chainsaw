all:ser

ser:ser.o TcpServer.o Mqueue.o SerBridge.o SerSystem.o WorkPthread.o Contral.o View.o DataBase.o 
	g++ -o ser ser.o TcpServer.o Mqueue.o SerBridge.o SerSystem.o WorkPthread.o Contral.o View.o DataBase.o -ljson -levent -lmysqlclient

ser.o:ser.cpp
	g++ -c ser.cpp -g

TcpServer.o:TcpServer.cpp
	g++ -c TcpServer.cpp -g

SerSystem.o:SerSystem.cpp
	g++ -c SerSystem.cpp -g

WorkPthread.o:WorkPthread.cpp
	g++ -c WorkPthread.cpp -g

Mqueue.o:Mqueue.cpp
	g++ -c Mqueue.cpp -g

SerBridge.o:SerBridge.cpp
	g++ -c SerBridge.cpp -g

Contral.o:Contral.cpp
	g++ -c Contral.cpp -g

View.o:View.cpp
	g++ -c View.cpp -g

DataBase.o:DataBase.cpp
	g++ -c DataBase.cpp -g


clean:
	rm -rf *.o *.cpp~ *.h~
