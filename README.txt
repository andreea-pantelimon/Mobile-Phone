Timpul de rezolvare:	
	Rezolvarea acestui proiect/teme mi-a luat aproximativ o saptamana jumatate, aproape 2 saptamani.

Idei de rezolvare:
	Initial, m-am gandit sa fac un sablon/matrice cu tastele telefonului, insa aceasta prima idee nu a dat roade. In urma recitirii cursurilor si a laboratoarelor, am ajuns la concluzia ca cel mai adecvat ar fi sa lucrez cu codurile ASCII.

Metoda de rezolvare:
	-Cerinta 1:
		Am incercat sa gasesc un algoritm care sa imi dea drept rezultat valorile de la 0 pana la 9(tastele), si un alt algoritm care sa imi ofere de cate ori este apasata o tasta. Aceasta formula poate fi regasita in cod. Insa am fost nevoita sa modific aceasta formula pentru tastele 8 si 9 si ,de asemenea, sa iau separat literele 's' si 'z'. 
	-Cerinta 2:
		Am gasit o formula care sa transforma tastele in litere, folosindu-ma de codurile ASCII. In aceasta functia am doua "pozibilitati mari". In cazul in care s-a citit unu am lucrat ca urmatoarea litera sa fie scrisa cu majuscula, iar in cazul in care nu s-a gasit valoarea unu, litera sa nu fie scrisa cu majuscula.
	-Cerinta 3:
		Am construit struct-ul pentru dictionar si dupa aceea in functia autoCorect am apelat acest struct. Am citit dictionarul (numarul de cuvinte, cuvinte gresite, cuvinte corecte) si dupa aceea am cautat in propozitie daca existau cuvinte cu acceasi lungime ca cel al cuvantului gresit. In cazul in care se gasea, acestea era inlocuit cu propozitia corecta si adaugat intr-un sir nou. In final, sirul nou rezultat urma sa fie transmis in functia ce rezolva prima cerinta pentru a fi codificat.
	-Cerinta 4:
		In aceasta functie, am aflat numarul de componente, le-am separat si dupa care am luat fiecare componenta in parte pentru a afla care este maximul si pozitia.

Probleme aparute:
	La completarea cerintei 4, testele picau pentru celelalte cerinte. Am adus modificarile necesare pentru ca aceasta problema sa fie remediata.
