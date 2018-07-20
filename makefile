CC	=	gcc
CFLAGS	=	-std=c99	-c	-Iinc/

all:	myftp
all:	myftpd

myftp:	client_main.o client.o
	$(CC) -o myftp obj/client_main.o obj/client.o
	@echo	"*** Compilation of Client executable concluded ***"
	@mv	myftp bin/
	@echo	""

myftpd:	server_main.o	server.o
	$(CC)	-o myftpd obj/server_main.o	obj/server.o
	@echo "*** Compilation of Server executable concluded ***"
	@mv	myftpd	bin/
	@echo	""

client_main.o:	src/client_main.c
	$(CC) $(CFLAGS)	src/client_main.c
	@echo "*** Compiled client main ***"
	@mv	client_main.o	obj/
	@echo	""

server_main.o: src/server_main.c
	$(CC)	$(CFLAGS)	src/server_main.c
	@echo	"** Compilef server main ***"
	@mv	server_main.o obj/
	@echo ""

client.o:	src/client.c
	$(CC)	$(CFLAGS)	src/client.c
	@echo	" *** Compiled Client Object ***"
	@mv	client.o obj/
	@echo ""

server.o:	src/server.c
	$(CC)	$(CFLAGS)	src/server.c
	@echo	" *** Compiled Server Object ***"
	@mv	server.o obj/
	@echo ""

clean:
	cd	obj	&&	rm	-rf	*.o
	cd	..
	cd	bin	&&	rm	-rf	myftp	myftpd
	cd	..
	@echo " *** All files deleted ***"
