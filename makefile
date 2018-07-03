CC	=	gcc
CFLAGS	=	-std=c99	-c	-Iinc/

all:	program

program:	main.o	client.o	server.o
	$(CC)	-o program	obj/main.o	obj/client.o	obj/server.o
	@echo " *** Compilation Of Object Files ***"
	@mv program bin/
	@echo ""

main.o:	src/main.c
	$(CC)	$(CFLAGS)	src/main.c
	@echo	" *** Compiled Main ***"
	@mv	main.o obj/
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
	cd	bin	&&	rm	-rf	program
	cd	..
	@echo " *** All files deleted ***"
