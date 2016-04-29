#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

 /*
  * KOCAELÝ ÜNÝVERSÝTESÝ
  * Bilgisayar Mühendisliði
  *
  * Yazarlar:
  * 		Arda ÞAHÝN
  * 		Emre ÖZHAN
  *
  */

int main(void) {
	srand(time(NULL));
	int rasat,rasut;
	rasat=1+rand()%(9);
	rasut=1+rand()%(19);
	int i,j,k=0;
	char sec=' ';
	//int as;
	int dur=1;
	int ile=0;
	int yb=1;

	int oas=20,oasu=50;
	char osecim='a';
	do {
		printf("Snake v3\n");
		printf("Varsayilan boyut icin 'd' giriniz.(20x50)\n");
		printf("Oyun alani belirlemek icin 'o' giriniz.\nSecim: ");
		scanf("%c", &osecim);
		if(osecim=='d') {
			printf("DEFAULT");
		}
		else if(osecim=='o') {
			printf("\nSatir: 10-30 arasi\nSutun: 20-100 arasi\n");
			printf("Satir: "); scanf("%d", &oas);
			printf("Sutun: "); scanf("%d", &oasu);
		}
		else
			continue;
	} while(oas<10 || oasu<20 || oas>30 || oasu>100);

	char oyunalani[30][100];
	for (i=0;i<oas;i++)
		for (j=0;j<oasu;j++)
			oyunalani[i][j]=' ';
	int yilan[3000][2];
	for (i=0;i<oas*oasu;i++)
		for (j=0;j<2;j++)
			yilan[i][j]=5;

	while(1){

clock_t zamanlayici;                       //zamanlayýcý
zamanlayici =  clock() + (0.2) * CLK_TCK;  //
while( clock() < zamanlayici) {}           //

		for (i=0;i<oas;i++){
			for (j=0;j<oasu;j++) {
						oyunalani[i][j]=' ';

			}
		}

		for (i=2;i<=yb;i++) {//Yýlanýn kendi üzerine çarpma durumu.
			for (j=0;j<2;j++) {
					if(yilan[i][1]==yilan[0][1] && yilan[i][2]==yilan[0][2]) {
						if (ile!=0)
							dur=0;
					}
			}
		}
        if (dur==0) {
			break;
		}
		oyunalani[rasat][rasut]='*';
		for (i=0;i<yb;i++) {
			oyunalani[yilan[i][1]][yilan[i][2]]='x';
		}
		system("cls");
		printf("SNAKE V3");
		for (i=9;i<oasu-5;i++)
			printf(" ");
		printf("%dx%d",oas,oasu);
		printf("\n");
		for (i=0;i<=oasu;i++)
			printf("_");
		printf("\n");
		for (i=0;i<oas;i++){
			printf("|");
			for (j=0;j<oasu;j++)
				printf("%c",oyunalani[i][j]);
			printf("|");
			printf("\n");
		}
		for (i=0;i<=oasu;i++)
			printf("¯");
		printf("\n");

		printf("Toplanan: %d\n",k);
		for (i=yb;i>=0;i--) {
			yilan[i+1][1]=yilan[i][1];
			yilan[i+1][2]=yilan[i][2];
		}
		if(kbhit()) {
			sec=getch();
			ile=1;
		}
		if(sec=='w'){
			yilan[0][1]--;
		}
		else if(sec=='s') {
			yilan[0][1]++;
		}
		else if(sec=='a') {
			yilan[0][2]--;
		}
		else if(sec=='d') {
			yilan[0][2]++;
		}
		if (yilan[0][1]<0 || yilan[0][1]>oas-1 || yilan[0][2]<0 || yilan[0][2]>oasu-1)
			break;

		if(yilan[0][1]==rasat && yilan[0][2]==rasut) {
			int durum=1;
			while (durum==1) {
				rasat=1+rand()%(oas-1);
				rasut=1+rand()%(oasu-2);

				for (i=0;i<=yb;i++) {
					if(rasat==yilan[i][1] && rasut==yilan[i][2]) {
						durum=1;
						break;
					}
					else {
						durum=0;
					}
				}
			}
			k++;
			yb++;
		}

	}
	printf("********Sonuc***********\n");
	printf("Skor: %d\n",yb);
	return 0;
}
