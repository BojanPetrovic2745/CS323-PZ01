#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct korisnik{

	char ime[20];
	char prezime[20];
	int PIN;
	int racun;


}Korisnici;

int   MIN = 500;
int  MAX = 10000;
int unesi;
FILE *file1;


void sacuvajPodizanje(char, int);
void sacuvajUplatu(char, int);
void citaj(char);
void izbrisi(char);



void start() {
	printf("Pritisnuti slovo a za prvog korisnika, ali za drugog slovo b \n");
	
}

int main() {

	Korisnici k[10];
	int stanje = 0;

	strcpy(k[0].ime, "Pera");
	strcpy(k[0].prezime, "Peric");
	k[0].PIN = 1423;
	k[0].racun = 1000000;

	strcpy(k[1].ime, "Nikola");
	strcpy(k[1].prezime, "Nikolic");
	k[1].PIN = 1122;
	k[1].racun = 1000000;

	start();
	int *min, *max, *racun;
	
	char p;

	p = getch();

	min = &MIN;
	max = &MAX;
	racun = &k[0].racun;

	if (p == 'a') {
		printf("Unesi pin za prvog korisnika \n");
		scanf("%d", &k[0].PIN);
		
	

		while (k[0].PIN != 1423) {
			system("cls");
			printf("Unesi pin za prvog korisnika \n");
			scanf("%d", &k[0].PIN);
		
		
		}

		if (k[0].PIN == 1423) {
			printf("Dobrodosli %s %s! Molim vas da odaberete jednu od sledecih mogucnosti! \n", k[0].ime, k[0].prezime);

			printf("1. Podigni novac. \n");

			printf("2. Uplati novac. \n");

			printf("3. Istorija transakcija. \n");

			printf("4. Izbrisi transakcije. \n");

			printf("5. Exit. \n");

			p = getch();
			if (p == '1') {

				system("cls");
				
				printf("Unesite pin ponovo : ");
				scanf("%d", &k[0].PIN);


				if (k[0].PIN == 1423) {
					system("cls");
					
					printf("Dobrodosli %s %s! Koliko novca zelite da podignete ? \n", k[0].ime, k[0].prezime);

					
	
					scanf("%d", &unesi);
					stanje = *racun - unesi;
					if (unesi % *min == 0 && unesi <= *max && unesi <= *racun) {
						printf("Podigli ste %d dinara i vase stanje na racunu je %d \n", unesi, stanje);
						sacuvajPodizanje("transankcija1.txt", stanje);
					} if (unesi > *max && unesi <= *racun) {
						printf("Ne mozete podici toliko novca u toku dana. Molimo vas unesite ponovo iznos.\n");
						scanf("%d", &unesi);
						while (unesi > *max && unesi <= *racun) {
							system("cls");
							printf("Unesite iznos: \n");
							scanf("%d", &unesi);
							if (unesi % *min == 0 && unesi <= *max && unesi <= *racun) {
								printf("Podigli ste %d dinara i vase stanje na racunu je %d \n", unesi, stanje);
								sacuvajPodizanje("transankcija1.txt", stanje);
							}
						}

					}
				}

				if (unesi > *racun) {
					printf("Nemate dovoljno sredstava na racunu. Molimo vas unesito ponovo  iznos \n");
					scanf("%d", &unesi);

					while (unesi > *racun) {

						printf("Nemate dovoljno sredstava na racunu. Molimo vas unesito ponovo  iznos \n");
						scanf("%d", &unesi);
						if (unesi % *min == 0 && unesi <= *max && unesi <= *racun) {
							printf("Podigli ste %d dinara i vase stanje na racunu je %d \n", unesi, stanje);
							sacuvajPodizanje("transankcija1.txt", stanje);
						}
					}
				}if (unesi < *min) {
					printf("Ne mozete podici toliki iznos. Molimo vas unesite ponovo iznos: \n");
					scanf("%d", &unesi);

					while (unesi < *min) {

						printf("Ne mozete podici toliki iznos. Molimo vas unesite ponovo iznos: \n");
						scanf("%d", &unesi);
						if (unesi % *min == 0 && unesi <= *max && unesi <= *racun) {
							printf("Podigli ste %d dinara i vase stanje na racunu je %d \n", unesi, stanje);
							sacuvajPodizanje("transankcija1.txt", stanje);


						}
					}
				}

			}

			else if (p == '2') {
				system("cls");
				printf("Unesite pin: \n");
				scanf("%d", &k[0].PIN);
				if (k[0].PIN == 1423)
				{
					system("cls");
					printf("Dobar dan %s %s ! Koliko novca zelite da uplatite na racun? \n", k[0].ime, k[0].prezime);
					scanf("%d", &unesi);
					stanje = *racun + unesi;
					printf("Uplatili ste %d dinara i vase stanje na racunu je %d. \n", unesi, stanje);
					sacuvajUplatu("transankcija1.txt", stanje);
				}

			}

			else if (p == '3') {
				system("cls");
				printf("Unesite pin: \n");
				scanf("%d", &k[0].PIN);
				if (k[0].PIN == 1423)
				{
					system("cls");

					citaj("transankcija1.txt");
				}

				

			}

			else if (p == '4') {
				system("cls");
				printf("Unesite pin: \n");
				scanf("%d", &k[0].PIN);
				if (k[0].PIN == 1423)
				{
					system("cls");
					printf("Izbrisali ste istoriju transakcija. \n");
					izbrisi("transankcija1.txt");

				}

			}
			else if (p == '5') {
				exit(0);

			}
		
		}


	

	}

	if (p == 'b') {
		racun = &k[1].racun;
		int stanje = *racun - unesi;
		printf("Unesi pin za drugog korisnika \n");
		scanf("%d", &k[1].PIN);

		while (k[1].PIN != 1122) {
			system("cls");
			printf("Unesi pin za drugog korisnika \n");
			scanf("%d", &k[1].PIN);


		}
		printf("Dobrodosli %s %s! Molim vas da odaberete jednu od sledecih mogucnosti! \n", k[1].ime, k[1].prezime);
		printf("1. Podigni novac. \n");

		printf("2. Uplati novac. \n");

		printf("3. Istorija transakcija. \n");

		printf("4. Izbrisi transakcije. \n");

		printf("5. Exit. \n");

		p = getch();


		if (k[1].PIN == 1122) {
			if (p == '1') {
				system("cls");
				printf("Unesite pin ponovo: ");
				scanf("%d", &k[1].PIN);




				if (k[1].PIN = 1122) {
					system("cls");
					racun = &k[1].racun;
					printf("Dobrodosli %s %s! \n Koliko novca zelite da podignete ? \n", k[1].ime, k[1].prezime);
					scanf("%d", &unesi);
					stanje = *racun - unesi;
					if (unesi % *min == 0 && unesi <= *max && unesi <= *racun) {
						printf("Podigli ste %d dinara i vase stanje je %d. \n ", unesi, stanje);
						sacuvajPodizanje("transankcija2.txt", stanje);
					} if (unesi > *max && unesi <= *racun) {
						printf("Ne mozete podici toliko novca u toku dana. Molimo vas unesite ponovo iznos.\n");
						scanf("%d", &unesi);
						while (unesi > *max && unesi <= *racun) {
							system("cls");
							printf("Unesite iznos: \n");
							scanf("%d", &unesi);
							if (unesi % *min == 0 && unesi <= *max && unesi <= *racun) {
								printf("Podigli ste %d dinara i vase stanje je %d. \n ", unesi, stanje);
								sacuvajPodizanje("transankcija2.txt", stanje);
							}
						}

					}

				}


				if (unesi > *racun) {
					printf("Nemate dovoljno sredstava na racunu. Molimo vas unesito ponovo  iznos \n");
					scanf("%d", &unesi);

					while (unesi > *racun) {

						printf("Nemate dovoljno sredstava na racunu. Molimo vas unesito ponovo  iznos \n");
						scanf("%d", &unesi);
						if (unesi % *min == 0 && unesi <= *max && unesi <= *racun) {
							printf("Podigli ste %d dinara i vase stanje je %d. \n ", unesi, stanje);
							sacuvajPodizanje("transankcija2.txt", stanje);
						}
					}
				}if (unesi < *min) {
					printf("Ne mozete podici toliki iznos. Molimo vas unesite ponovo iznos: \n");
					scanf("%d", &unesi);

					while (unesi < *min) {

						printf("Ne mozete podici toliki iznos. Molimo vas unesite ponovo iznos: \n");
						scanf("%d", &unesi);
						if (unesi % *min == 0 && unesi <= *max && unesi <= *racun) {
							printf("Podigli ste %d dinara i vase stanje je %d. \n ", unesi, stanje);
							sacuvajPodizanje("transankcija2.txt", stanje);


						}
					}
				}

			}

			else if (p == '2') {
				system("cls");
				printf("Unesite pin: \n");
				scanf("%d", &k[1].PIN);
				if (k[1].PIN == 1122){

					system("cls");
					printf("Dobar dan %s %s ! Koliko novca zelite da uplatite na racun? \n", k[1].ime, k[1].prezime);
					scanf("%d", &unesi);
					stanje = *racun + unesi;
					printf("Uplatili ste %d dinara i vase stanje na racunu je %d. \n", unesi, stanje);
					sacuvajUplatu("transankcija2.txt", stanje);
				}
				

			}

			else if (p == '3') {
				system("cls");
				printf("Unesite pin: \n");
				scanf("%d", &k[1].PIN);
				if (k[1].PIN == 1122)
				{
					system("cls");

					citaj("transankcija2.txt");
				}

			}

			else if (p == '4') {
				system("cls");
				printf("Unesite pin: \n");
				scanf("%d", &k[1].PIN);
				if (k[1].PIN == 1122)
				{
					system("cls");
					printf("Izbrisali ste istoriju transakcija. \n");
					izbrisi("transankcija2.txt");

				}

			}
			else if (p == '5') {
				exit(0);

			}
		
		
		
		}


	}

	system("pause");

	return 0;
}

void sacuvajUplatu( char imeFajla[20], int stanje) {
	file1 = fopen(imeFajla, "a");

	fprintf(file1, "Uplatili ste: %d dinara i vase stanje je %d. \n", unesi, stanje);
	fclose(file1);
}

void sacuvajPodizanje(char imeFajla[20], int stanje) {
	file1 = fopen(imeFajla, "a");

	fprintf(file1, "Podigli ste: %d dinara i vase stanje na racunu je %d. \n", unesi, stanje);
	fclose(file1);
}
void izbrisi(char imeFajla[20]) {
	file1 = fopen(imeFajla, "w+");
	fprintf(file1, "");
	fclose(file1);
}
void citaj(char imeFajla[20]) {
	file1 = fopen(imeFajla, "r");
	char * singleLine = malloc(500 * sizeof(char));
	while (fgets(singleLine, 500, file1) != NULL) {
		puts(singleLine);
	}
	free(singleLine);
	fclose(file1);
}

