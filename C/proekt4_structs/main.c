#include <stdio.h>
typedef struct {
    int ID;
    char ime[20];
    char prezime[20];
    int vozrast;
    char pol;
    int bracnaSostojba;
    int kredibilnost;
    char adresa[50];
    int tekovnaPlata;
    int poranesnaPlata;
} Vraboten;
void listaVraboteni(Vraboten vraboteni[], int size);
void kreirajVraboten(Vraboten vraboteni[], int brojac);
void koregirajVraboten(Vraboten vraboteni[], int size,int ID);
void sortKred(Vraboten vraboteni[], int size,int ID);
void sortTekovna(Vraboten vraboteni[], int size,int ID);
void sortMinata(Vraboten vraboteni[], int size,int ID);
void koregirajKredibilnost(Vraboten vraboteni[], int size, int ID);
int main() {
    Vraboten vraboteni[50];
    int size;
    int komanda;
    int id = 0;
    int brojac = 0;
    printf("kolku vraboteni sakas da vneses?");
    scanf("%d",&size);
    for (;brojac < size;brojac++)
        kreirajVraboten(vraboteni, brojac);
    listaVraboteni(vraboteni, size);
    void (*listaFcii[5])(Vraboten vraboteni[],int size,int ID)={koregirajVraboten,sortKred,sortTekovna,sortMinata,koregirajKredibilnost};
    printf("0: koregiraj vraboten\n1: sortiraj po kredibilitet\n2: sortiraj po tekovna plata\n3: sortiraj po minata plata\n4: koregiraj kredibilnost: -1:Izlezi\n");
    scanf("%d",&komanda);
    while(komanda!=-1){
        if (komanda == 0)
        {
            printf("vnesi id");
            scanf("%d",&id);
        }
        listaFcii[komanda](vraboteni,size,id);
        listaVraboteni(vraboteni,size);
         printf("0: koregiraj vraboten\n1: sortiraj po kredibilitet\n2: sortiraj po tekovna plata\n3: sortiraj po minata plata\n4: koregiraj kredibilnost: -1:Izlezi\n");
        scanf("%d",&komanda);
    }
    return 0;
}
void listaVraboteni(Vraboten vraboteni[], int size) {
    for (int i = 0;i <size;i++){
        printf("%s %s, %d godini, pol:%c, %s, kredibilnost: %d, adresa: %s,\ntekovna plata: %d, poranesna plata: %d\n\n", vraboteni[i].ime, vraboteni[i].prezime, vraboteni[i].vozrast, vraboteni[i].pol, vraboteni[i].bracnaSostojba ? "vo brak" : "ne e vo brak", vraboteni[i].kredibilnost, vraboteni[i].adresa, vraboteni[i].tekovnaPlata, vraboteni[i].poranesnaPlata);

    }
}
void kreirajVraboten(Vraboten vraboteni[], int broj) {
    printf("ID: ");
    scanf("%d", &vraboteni[broj].ID);
    printf("Ime: ");
    scanf(" %s", vraboteni[broj].ime);
    printf("Prezime: ");
    scanf(" %s", vraboteni[broj].prezime);
    printf("Vozrast: ");
    scanf("%d",&vraboteni[broj].vozrast);
    printf("Pol: ");
    scanf(" %c", &vraboteni[broj].pol);
    printf("bracna sostojba: ");
    scanf("%d", &vraboteni[broj].bracnaSostojba);
    printf("kredibilnost: ");
    scanf("%d", &vraboteni[broj].kredibilnost);
    printf("adresa: ");
    scanf(" %s", vraboteni[broj].adresa);
    printf("tekovna plata: ");
    scanf("%d", &vraboteni[broj].tekovnaPlata);
    printf("poranesna plata: ");
    scanf("%d", &vraboteni[broj].poranesnaPlata);
}
void koregirajVraboten(Vraboten vraboteni[], int size,int ID){
    int red = -1;
    for (int i = 0; i<size;i++){
        if (ID == vraboteni[i].ID)
            red = i;
    }
    if (red == -1)
        printf("ne e pronajden takov vraboten");
    else{
        printf("Ime: ");
        scanf(" %s", vraboteni[red].ime);
        printf("Prezime: ");
        scanf(" %s", vraboteni[red].prezime);
        printf("Vozrast: ");
        scanf("%d",&vraboteni[red].vozrast);
        printf("Pol: ");
        scanf(" %c", &vraboteni[red].pol);
        printf("bracna sostojba: ");
        scanf("%d", &vraboteni[red].bracnaSostojba);
        printf("kredibilnost: ");
        scanf("%d", &vraboteni[red].kredibilnost);
        printf("adresa: ");
        scanf(" %s", vraboteni[red].adresa);
        printf("tekovna plata: ");
        scanf("%d", &vraboteni[red].tekovnaPlata);
        printf("poranesna plata: ");
        scanf("%d", &vraboteni[red].poranesnaPlata);
    }
}
void sortKred(Vraboten vraboteni[],int size, int ID){
    Vraboten temp;
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (vraboteni[j].kredibilnost > vraboteni[j+1].kredibilnost){
                temp = vraboteni[j];
                vraboteni[j] = vraboteni[j+1];
                vraboteni[j+1] = temp;
            }
        }
    }
}
void sortTekovna(Vraboten vraboteni[],int size, int ID){
    Vraboten temp;
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (vraboteni[j].tekovnaPlata > vraboteni[j+1].tekovnaPlata){
                temp = vraboteni[j];
                vraboteni[j] = vraboteni[j+1];
                vraboteni[j+1] = temp;
            }
        }
    }
}
void sortMinata(Vraboten vraboteni[],int size, int ID){
    Vraboten temp;
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (vraboteni[j].poranesnaPlata > vraboteni[j+1].poranesnaPlata){
                temp = vraboteni[j];
                vraboteni[j] = vraboteni[j+1];
                vraboteni[j+1] = temp;
            }
        }
    }
}
void koregirajKredibilnost(Vraboten vraboteni[], int size, int iD){
  for (int i = 0; i < size; i++){
      if (vraboteni[i].tekovnaPlata > vraboteni[i].poranesnaPlata){
          vraboteni[i].kredibilnost+=3;
      }
      else if (vraboteni[i].tekovnaPlata < vraboteni[i].poranesnaPlata){
          vraboteni[i].kredibilnost-=3;
      }
      vraboteni[i].tekovnaPlata = vraboteni[i].poranesnaPlata;
  }
}
