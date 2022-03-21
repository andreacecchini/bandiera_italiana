/*

     Il problema si puo risolvere in tempo lineare senza applicare nessun tipo di algoritmo di ordinamento in tempo lineare come il counting sort.
     Sia v = indice che indica la fine dei elementi GREEN
     Sia i = indiche che indica la fine dei elementi WHITE
     Sia r = indice che indica l'inizio del elementi RED
     Sia j = indice che indica l'elemento che stiamo esaminando
     Sia questa l'invariante di ciclo che caraterizza l'array da ordinare

     V[0...v-1] -> Contiene solamente elementi GREEN
     B[v...i-1] -> Contiene solamente elementi WHITE
     R[r...n-1] -> Contiene solamente elementi RED
     F[i ... r] -> Contiene elementi non ordinati e sconosciuti

     Allora a fine ciclo la bandiera sara' ordinata in tempo lineare.
     Questo perche' l'invariante conserva le sue proprieta' anche a fine ciclo.
     Il valore dei indici  a fine ciclo saranno tali che F[i...r] = Insieme Vuoto.

     Se v = 0 -> Non ci sono elementi GREEN
     Se i = v -> Non ci sono elementi WHITE
     Se r = size - 1 -> Non ci sono elenti RED;

*/


#include <stdio.h>
#include <stdlib.h>
enum COLOR {GREEN , WHITE , RED};
typedef enum COLOR COLOR;


void excange_cell_with_f_of_v(COLOR *f , size_t v , size_t j){
  /* Scambia il valore di f[j] con flag[v] */
  f[j] = f[v];
  f[v] = GREEN;
}

void excange_cell_with_f_of_r(COLOR *f , size_t r , size_t j){
  /* Scambio il valore di f[j] con f[r]*/
  f[j] = f[r];
  f[r] = RED;
}



/* Ordina il vettore in base al colore della bandiera con un costo computazionale che risulta essere O(n) */
void sorting_flag(COLOR *f , size_t size){
  /* Fine dei verdi */
  size_t  v = 0;
  /* Fine dei bianchi */
  size_t i = 0;
  /* Inizio dei rossi  */
  size_t r = size - 1;


  size_t j = i;
  while(j < r + 1){
    switch(f[j]){
      case GREEN :
                  excange_cell_with_f_of_v(f , v , j);
                  /* Sposto gli indici nella posizione giusta incrementandoli di uno */
                  v += 1;
                  i += 1;
                  break;

      case WHITE:
                /*Incremento semplicemente i contatori*/
                i+=1;
                j+=1;
                break;
      case RED:
                excange_cell_with_f_of_r(f, r , j);
                /* Sposto l'indice dei RED decrementandolo di uno */
                r -=1;
                break;
    }
  }

}

void print_flag(COLOR *f ,  size_t  size){
  size_t i;
  for(i = 0 ; i < size ; ++i){
      switch (f[i]) {
        case GREEN:
                    printf(" GREEN ");
                    break;
        case WHITE:
                    printf(" WHITE " );
                    break;
        case RED:
                    printf(" RED " );
                    break;
      }

  }
  printf("\n");
}

int main(int argc, char const *argv[]) {

  COLOR flag[] = {WHITE , GREEN , GREEN , RED , WHITE , RED, WHITE , GREEN , WHITE , WHITE , RED , GREEN , WHITE};
  size_t size_of_flag = sizeof(flag) / sizeof(flag[0]);
  sorting_flag(flag , size_of_flag);
  print_flag(flag , size_of_flag);
  return 0;
}
