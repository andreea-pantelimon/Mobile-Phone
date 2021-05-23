#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 300

//struct-ul pentru dictionar

typedef struct dictionar {
	char corect[SIZE], gresit[SIZE];
} dictionar;

//functie pentru codificarea textului

/*tasta = valoarea de pe tasta telefonului; apasari = numarul de apasari al tastei;
tastav = cu ajutorul acesteia urmarim daca 2 litere consecutive se afla pe aceeiasi tasta;
codat = sirul in care se va introduce noul rezultat*/
char * codificareText(char *sir) {
	char *codat = NULL;	
	codat = malloc(SIZE * sizeof(char)); //aloc dinamic memorie pentru sirul codat
	strcpy(codat, "");
	int k = 0;
	int i, j, tasta, apasari, tastav = -1;
	for(i = 0; i < strlen(sir); i++) { //parcurgem sirul si verificam fiecare caz
		if(sir[i] == ' ') { //cazul in care elementul este spatiu, se va introduce in sir 0
			codat[k++] = '0';
			tasta = 0;
		}
		
		if(sir[i] >= 'A' && sir[i] <='Z') { //facem un caz special pentru majuscule
			codat[k++] = '1'; //se va introduce in sir 1
			if(sir[i] == 'S') { //luam cazuri particulare pentru S si Z
				tasta = 7;
				apasari = 3;
			} else if(sir[i] == 'Z') {
				tasta = 9;
				apasari = 3;
			} else if(sir[i] >= 'T' && sir[i] <= 'Y') { //cazuri particulare pentru literele cuprinse intre T si Y
				tasta = (sir[i] - 'A' + 5) / 3;
				apasari = (sir[i] - 'A' + 5) % 3;
			} else { //pentru restul tastelor ce nu au indeplinit conditiile anterioare
				tasta = (sir[i] - 'A' + 6) / 3;
				apasari = (sir[i] - 'A') % 3;
			}
			for(j = 0; j <= apasari; j++) { //in functie de cate apasari avem se va intrudoce tasta
			codat[k++] = (char)(tasta + '0');
			}
		}
		tastav = tasta; //tastav care initial are o valoare data, devine tasta in urma verificarii algoritmului
		if(sir[i] >= 'a' && sir[i] <= 'z') { //facem un caz special pentru literele mici
			if(sir[i] == 's') { //luam cazuri particulare pentru s si z
				tasta = 7;
				apasari = 3;
			} else if(sir[i] == 'z') {
				tasta = 9;
				apasari = 3;
			} else if(sir[i] >= 't' && sir[i] <= 'y') { //cazuri particulare pentru literele cuprinse intree t si y
				tasta = (sir[i] - 'a' + 5) / 3;
				apasari = (sir[i] - 'a' + 5) % 3;
			} else { //pentru restul literelor ce nu au indeplinit conditiile anterioare
				tasta = (sir[i] - 'a' + 6) / 3;
				apasari = (sir[i] - 'a') % 3;
			}

			if (tastav == tasta) { //in cazul in care tastav = tasta, inseamna ca avem doua litere consecutive de pe aceesi tasta
				codat[k++] = '#'; //si se va introduce #
			}
			tastav = tasta;
			for(j = 0; j <= apasari; j++) { //in functie de cate apasari avem se va introduce tasta
				codat[k++] = (char)(tasta + '0');
			}
		}
	}
	int size = strlen(codat);
	codat[size] = '\0'; //se introduce terminatorul de sir
	return codat; //returnam sirul rezultat
}

//functie pentru decodificarea textului

/* apasari = de cate ori este apasata o tasta;
litera = valoarea literei de pe tasta respectiva*/
void decodificareText(char *cod)
{
	int i, apasari, j;
	char litera;
	for(i = 0; i < strlen(cod); i++) {//parcurgem sirul dat de la tastatura
		if(cod[i] == '1') { //in cazul in care elementul este egal cu 1	
			i++; //se va trece la elementul urmator din sir si se va verifica de pe ce tasta face parte, si se va trece drept majuscula
			if(cod[i] >= '2' && cod[i] <= '7') {//caz pentru tastele 2 si 7
				apasari = 0;
				for(j = i+1; j < strlen(cod) && apasari < 3; j++) { //se va verifica urmatorul element din sir
					if(cod[i] == cod[j]) { //atata timp cat tasta precedenta este egala cu tasta curenta
						apasari++;
						i = j;
					} else { //daca conditia precedenta nu este indeplinita se va iesi fortat
						break; 
					}
				}
				litera = (char)cod[i] * 3 - 6 + 'a' + apasari - 144 -32;
				printf("%c", litera);
			}
			else 
				if(cod[i] >= '8' && cod[i] <= '9') { // caz pentru tastele 8 si 9
					apasari = 0;
					for(j = i+1; j < strlen(cod) && apasari < 3; j++) { //se vor verifica urmatoarele elemente din sir
						if(cod[i] == cod[j]) {  //atata timp cat tasta precedenta este egala cu tasta curenta
							apasari++;
							i = j;
						} else { //daca conditia precedenta nu este indeplinita se va iesi fortat
							break;
						}
					}
					litera = (char)cod[i] * 3 - 6 + 'a' + apasari - 143 -32;
					printf("%c", litera);
				}
		}
		else if(cod[i] == '0') { // in caz in care tasta este 0 se va introduce spatiu
				printf(" ");
			}
		else if(cod[i] == '#') { // in caz in care tasta este # se va ignora
				continue;
			}
		else if(cod[i] >= '2' && cod[i] <= '7') { //cazul in care inainte nu s-a intalnit tasta 1, avem numai litere mici; 
				apasari = 0;
				for(j = i+1; j <strlen(cod) && apasari < 3; j++) {
					if(cod[i] == cod[j]) {
						apasari++;
						i = j;
					} else {
						break;
					}
				}
			litera = (char)cod[i] * 3 - 6 + 'a' + apasari - 144;			
			printf("%c", litera);
			}
		else if(cod[i] >= '8' && cod[i] <= '9') { // caz special pentru tastele 8 si 9
				apasari = 0;
				for(j = i+1; j <strlen(cod) && apasari < 3; j++) {
					if(cod[i] == cod[j]) {
						apasari++;
						i = j;
					} else {
						break;
					}
				}
			litera = (char)cod[i] * 3 - 6 + 'a' + apasari - 143;
			printf("%c", litera);
			}
	}
	printf("\n");
}

//functie pentru autocorector

/*sirCorect = sirul in care se va introduce noul sir in urma corectarii;
numar = numarul de cuvinte care trebuiesc inlocuite*/
char * autoCorect(char text[])
{
	int i, numar, ok;
	char *sirCorect = malloc(SIZE * sizeof(char)); //aloc dinamic memorie sirului rezultat
	char *cuvinte;

	//citim dictionarul
	scanf("%d", &numar);
	dictionar *d = malloc(numar * sizeof(dictionar));
	for(i = 0; i < numar; i++) {
		scanf("%s%s", d[i].gresit, d[i].corect);
	}

	cuvinte = strtok(text, " \n"); //luam fiecare cuvant din sir, separatorii fiind " " si "\n"
	while(cuvinte != NULL) { //verificam atata timp cat cuvantul nu este NULL
		ok = 0; //contor de urmarire
		for(i = 0; i < numar; i++) {
			if(strcmp(d[i].gresit, cuvinte) == 0) {  //daca lungimea cuvinte este egala cu d[i].gresit, acesta va fi inlocuit cu d[i].corect
				strcat(sirCorect, d[i].corect);
				ok = 1; //in cazul in care s-a gasit un cuvant de aceeasi lungime cu d[i].gresit, ok va deveni 1
				break;
			}
		}

		if (ok == 0) { //in cazul in care nu s-a gasit un cuvant de aceeasi lungime cu d[i].gresit, nu se va produce nicio schimbare
			strcat(sirCorect, cuvinte);
		}

		strcat(sirCorect, " "); //adaugam spatiu dupa verificarea/inlocuirea fiecarui cuvant
		cuvinte = strtok(NULL, " ");  //trecem la urmatorul cuvant din sir
	}

	// Sterg ultimul spatiu care e in plus
	sirCorect[strlen(sirCorect) - 1] = '\0';
	return sirCorect;
	
}

//functie care afiseaza numarul de componente

//numar = numarul de componente
int numar_componente(char *input){
	int numar = 1;
	int i;
	char *codat = codificareText(input); //se va codifica textul dat de la tastatura
	for(i = 0; i < strlen(codat); i++) { 
		if(codat[i] == '0') {  //la intalnirea lui 0, numarul va creste cu 1
			numar++;
		}
	}
	printf("%d\n", numar);
	return 0;
}

/*int numar_magic(char *input){
	int N, i, suma = 0, integer;
	char *rezultat = codificareText(input);
	//printf("%s\n" , rezultat);
	for( i = 0; i < strlen(rezultat); i++){
		if( rezultat[i] != '#'){
			integer = (char)rezultat[i] - 48;
			//printf("%d\n", integer);
			suma =  suma + integer;
			//printf("%d\n", suma);
		}
	}
	N = suma % 9 ;
	//printf("Numarul magic este: %d\n", N);
	return 0;
}*/

long long fcmmdc(long long a, long long b){ //folosim euclid pentru a afla cmmdc
	long long rest;

	while (b != 0) {
		rest = a % b;
		a = b;
		b = rest;
	}
	return a;
}

//functie care determina sirul de componente, afiseaza maximul si pozitia

/*codat = sirul codificat; sir = sirul codificat fara #;
rezultat = sirul fara separatori; copie = sir cu componentele drept elemente
max =componenta maxima; poz = pozitia componentei maxime*/
void componente( char *input){
	int j = 0, k, i, p = 0, poz;
	long long max;
	long long cmmdc;
	char *codat = codificareText(input); //codific textul dat de la tastatura;
	char *sir = malloc(SIZE * sizeof(char)); //aloc dinamic memorie pentru sir
	for(i = 0; i < strlen(codat); i++) {
		if(codat[i] == '#')
			continue;
		else 
			sir[p++] = codat[i]; //adaug elementele din codat in sir fara #
	}

	free(codat);
	char *rezultat = malloc(SIZE * sizeof(char)); //aloc dinamic memorie pentru sirul rezultat si copie
	long long *copie = malloc(SIZE * sizeof(long long));
	rezultat = strtok(sir, "0"); //parcurg fiecare set de cifre pana la intalnirea separatorului 0
	while(rezultat != NULL)
	{
		copie[j] = atol(rezultat); //transform caracterele in intregi lungi
		j++;
		rezultat = strtok(NULL, "0"); //trec la urmatorul set de cifre
	}
	for( k = 0; k < j; k++)
		printf("%lli ", copie[k]); // afisez componentele
	printf("\n");

	max = copie[0]; //presupun ca primul element este maxim 
	for(k = 1; k < j; k++){ //parcurg sirul copie si verific daca exista un element mai mare ca max
		if(copie[k] > max){
			max = copie[k];	//in caz afirmativ, noul max
		}
	}
	for(k = 0; k < j; k++){ //parcurgem din nou sirul copie si la intalnirea lui max afisam pozitia acestuia
		if(copie[k] == max)
			poz = k + 1;
	}
	printf("%lli %d", max, poz);
	printf("\n");
	free(rezultat);

	cmmdc = fcmmdc(copie[0], copie[1]); //verificam daca elementele lui copie sunt prime intre ele doua cate doua
	for(k = 2; k < j; k++)
		cmmdc = fcmmdc(cmmdc, copie[k]);
	if (cmmdc == 0)
		printf("1");
	else
		printf("0"); 
	printf("\n");
	
	
}

int main()
{
	// CERINTA 1
	char text1[SIZE];
	fgets(text1, 300, stdin);
	// Sterg enter-ul de la finalul string-ului (daca exista); procedez la fel si pentru restul cerintelor
	if (text1[strlen(text1) - 1] == '\n')
		text1[strlen(text1) - 1] = '\0';
	char *rez = codificareText(text1);
	printf("%s\n", rez);
	
	//CERINTA 2
	
	char text2[SIZE];
	fgets(text2, 300, stdin);
	decodificareText(text2);
	
	// CERINTA 3
	char text3[SIZE];
	fgets(text3, 300, stdin);
	if (text3[strlen(text3) - 1] == '\n')
		text3[strlen(text3) - 1] = '\0';
	char *sirCorect = autoCorect(text3);
	char *sirCorectCodificat = codificareText(sirCorect);
	printf("%s\n", sirCorectCodificat);
	getchar();

	//Cerinta 4
	char text4[SIZE];
	fgets(text4, 300, stdin);
	if (text4[strlen(text4) - 1] == '\n')
		text4[strlen(text4) - 1] = '\0';
	char copie1[SIZE];
	strcpy(copie1, text4);
	//strcpy(copie2, text4);
	numar_componente(text4);
	componente(copie1);
	//numar_magic(copie2);*/


	return 0;
}


