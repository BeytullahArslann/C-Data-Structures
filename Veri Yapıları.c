#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Liste {
	int veri;
	struct Liste *onceki;
	struct Liste *sonraki;
};
struct Liste* Ilk = NULL;

struct Liste* dugumOlustur(int veri){
	struct Liste* yeniDugum = (struct Liste*)malloc(sizeof(struct Liste));
	yeniDugum->veri = veri;
	yeniDugum->onceki=NULL;
	yeniDugum->sonraki=NULL;
	
	return yeniDugum;
}

void sonaEkle(int veri){
	struct Liste* eklenecek = dugumOlustur(veri);
	if (Ilk == NULL){
		Ilk = eklenecek;
	}
	else {
		struct Liste* gecici = Ilk;
		while(gecici->sonraki != NULL){
			gecici = gecici->sonraki;
		}
		eklenecek->onceki = gecici;
		gecici->sonraki = eklenecek;
	
	}
}

void basaEkle(int veri){
	struct Liste* eklenecek =dugumOlustur(veri);
	if (Ilk == NULL){
		Ilk = eklenecek;
		return;
	}
	Ilk->onceki = eklenecek;
	eklenecek->sonraki = Ilk;
	Ilk = eklenecek;
}

void arayaEkle(int sira , int veri){
	struct Liste* gecici = Ilk;
	struct Liste* eklenecek = dugumOlustur(veri);
	struct Liste* onceki1 = NULL;
	
	if(Ilk == NULL){
		Ilk = eklenecek;
		return;
	}
	else if(Ilk->veri == sira){
		basaEkle(veri);
	}
	else{
		while(gecici->sonraki != NULL){
		if(gecici->veri == sira){
			onceki1 = gecici->onceki;
			break;
		}
		gecici = gecici->sonraki;
	}
		gecici = gecici->sonraki;
		eklenecek->sonraki = gecici;
		eklenecek->onceki = onceki1;
		onceki1->sonraki = eklenecek;
	}
		
	
	
	}

void bastanSil(){
	if(Ilk==NULL){
		printf("Liste Bos");
		return;
	}
	if(Ilk->sonraki==NULL){
		free(Ilk);
		Ilk=NULL;
		return;
	}
	
	struct Liste* ikinciEleman = Ilk->sonraki;
	free(Ilk);
	ikinciEleman->onceki=NULL;
	Ilk = ikinciEleman;
}

void sondanSil(){
	if(Ilk==NULL){
		printf("Liste Bos");
		return;
	}
	if(Ilk->sonraki=NULL){
		bastanSil();
		return;
	}
	
	struct Liste* gecici = Ilk;
	while(gecici->sonraki != NULL){
		gecici= gecici->sonraki;
	}
	struct Liste* onceki = gecici->onceki;
	onceki->sonraki=NULL;
}

void aradanSil(int silinecek){
	if(Ilk->veri==silinecek){
		bastanSil();
		return;
	}
	struct Liste* gecici = Ilk;
	while(gecici->sonraki !=NULL){
		if(gecici->veri == silinecek){
			break;
		}
		gecici = gecici->sonraki;
	}
	struct Liste* sonraki = gecici->sonraki;
	struct Liste* onceki= gecici->onceki;
	free(gecici);
	onceki->sonraki = sonraki;
	sonraki->onceki = onceki;
}

void arama(int sayi){
	if(Ilk==NULL){
		printf("Liste Bos\n");
		return;
	}
	struct Liste* gecici = Ilk;
	int i=0;	
	while(gecici!=NULL){
		i++;
		if(gecici->veri==sayi){
		printf("Aranan eleman %d. sirada\n",i);	
		break;
		}
		else{
			gecici=gecici->sonraki;
		}
	}
	printf("Aranan eleman listede yok\n");
}




void Listele(){
	struct Liste* gecici = Ilk;
	while(gecici != NULL){
			printf(" %d ",gecici->veri);
			gecici = gecici->sonraki;
		}
	printf("\n");
}

int main(){
	
	int secim,sayi,sayi1;
	while(1){
		printf("1-Sona Eleman ekleme\n");
		printf("2-Basa Eleman ekleme\n");
		printf("3-Araya Eleman ekleme\n");
		printf("4-Bastaki Elemani sil\n");
		printf("5-Sondaki Elemani sil\n");
		printf("6-Istediginiz Elemani silin\n");
		printf("7-Eleman arama\n");
		scanf("%d",&secim);
		switch(secim){
			case 1:
				printf("Eklemek istediginiz elemani giriniz\n");
				scanf("%d",&sayi);
				sonaEkle(sayi);
				Listele();
				break;
			case 2:
				printf("Eklemek istediginiz elemani giriniz\n");
				scanf("%d",&sayi);
				basaEkle(sayi);
				Listele();
				break;
			case 3:
				printf("Eklemek istediginiz elemani giriniz\n");
				scanf("%d",&sayi);
				printf("Hangi elemanin onune eklemek istiyorsunuz\n");
				scanf("%d",&sayi1);
				arayaEkle(sayi1,sayi);
				Listele();
				break;
			case 4:
				bastanSil();
				Listele();
				break;
			case 5:
				sondanSil();
				Listele();
				break;
			case 6:
				printf("Silmek istediginiz elemani giriniz\n");
				scanf("%d",&sayi);
				aradanSil(sayi);
				Listele();
				break;
			case 7:
				printf("Aramak istediginiz elemani giriniz\n");
				scanf("%d",&sayi);
				arama(sayi);
				
				break;
		}
	}
	
	return 0;
	
}
