build: telefon.c
	gcc -Wall telefon.c -o telefon
run: telefon.c
	./telefon
clean: telefon.c
	rm -f telefon
