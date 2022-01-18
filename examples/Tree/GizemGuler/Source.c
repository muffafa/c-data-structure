#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct topluluk {
	int bilgi;
	char mesaj[100];
	struct topluluk *sag, *sol;
}AGAC2;
AGAC2 kok = NULL;
AGAC2 *ara(), *sil(), *okuKlavye(), *sayAgacDugum();
void yazEkrana(), ekle(), listele();
int maint() {
	AGAC2 *yeni, *adres;
	int bilgi, miktar;
	char secim;
	while (1) {
		puts("\Ekleme\nListeleme\nArama\nSilme\nMiktar\nÇıkış\nSeçim?");
		secim = getch();
		switch (secim) {
		case 'E':yeni = okuKlavye();
			ekle(kok, yeni);
			break;
		case 'L':if (kok != NULL)
			listele(kok);
				 else
			puts("Boş Liste!");
		case'A':puts("Aranan:"); scanf("%d", &bilgi);
			adres = ara(kok, bilgi);
			if (adres == NULL)
				puts("Aranan Bulunamadı");
			else yazEkrana(adres);
			break;
		case'M':miktar = sayAgacDugum(kok, 0);
			printf("Agaçtaki toplam kayıt sayıyı=%d\n", miktar);
			break;
		case'S':puts("Silinecek:"); scanf("%d", &bilgi);
			adres = sil(kok, bilgi);
			if (adres != NULL)
				puts("Silindi...");
			else
				puts("Silinmek istenen yok!");
			break;
		case'Ç':case'ç':case'c':case'C':puts("Hoşçakal!");
			exit(0);
		default:puts("Yanlış Seçim!!\n");

			void ekle(agacKok, yeni) {

				AGAC2 *agacKok, *yeni;

				if (afacKok == NULL) kok = yeni;
				else {
					if (yeni->bilgi <= agacKok->bilgi) {
						if (agacKok->sol == NULL)
							agacKok->sol = yeni;
						else ekle(agacKok->sag, yeni);
					}
				}
			}
			void listele(AGAC2 *agacKok)
			{
				if (agacKok != NULL) {
					listele(agacKok->sol);
					yazEkrana(agacKok);
					listele(agacKok->sag);
				}
				AGAC2 *ara(agacKok, aranan)
					AGAC2 *agacKok;
				int aranan;
				{
					while (agacKok != NULL && agacKok->bilgi != aranan) {
						if (aranan < agacKok->bilgi)
							agacKok = agacKok->sol
						else
							agacKok = agacKok->sag;
					}
					return agacKok;
					AGAC2 *sil(AGAC2 *agacKok, int silinecek)
					{
						AGAC2 *qa, *q, *qc, *sa, *s;
						if (agacKok == NULL)
							return NULL;
						q = agacKok;
						qa = NULL;
						while (q != NULL && q->bilgi != silinecek) {
							qa = q;
							if (silinecek <= q->bilgi)
								q = q->sol;
							else
								q = q->sag;
						}
						if (q == NULL)
							return NULL;
						if (q->sol != NULL && q->sag != NULL) {
							s = q->sol;
							sa = q;
							while (s->sag != NULL) {
								sa = s;
								s = s->sag;
							}
							q->bilgi = s->bilgi;
							strcpy(q->mesaj, s->mesaj);
							q = s;
							qa = sa;
						}
						if (q->sol != NULL)
							qc = q->sol;
						else
							qc = q->sag;
						if (q == agacKok) {
							kok = qc;
						}
						else {
							if (q == qa->sol) {
								qa->sol = qc;
							}
							else {
								qa->sag = qc;
							}
						}
						free(q);
						return q;
					}
					int sayAgacDugum(AGAC2 *agacKok, int miktar)
					{
						if (agacKok == NULL)
							return miktar;
						miktar++;
						miktar = sayAgacDugum(agacKok->sol, miktar);
						miktar = sayAgacDugum(agacKok->sag, miktar);
						return miktar;
					}

					void yazEkrana(AGAC2 *veri)
					{
						printf("bilgi:%d,mesaj:%s\n", veri->bilgi, veri->mesaj);
					}
					AGAC2 *okuKlavye() {
						AGAC2 *yeni;
						yeni = malloc(sizeof(AGAC2));
						if (yeni == NULL) {
							puts("bellek doludur!");
							return NULL;
						}
						puts("bilgi giriniz:");
						scanf("%d", &(yeni->bilgi));
						puts("mesaj giriniz:");
						scanf("%s", yeni->mesaj);
						yeni->sağ = NULL;
						yeni->sol = NULL;
						return yeni;
					}

					AGAC2 ** sayAgacDugum()
					{
						return nullptr;
					}

					AGAC2 ** sil()
					{
						return nullptr;
					}

					AGAC2 * ara()
					{
						return nullptr;
					}
