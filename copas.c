#include <stdio.h>

int main (){
    int A = 0, B = 0, C = 0, D = 0; //determina os jogadores A, B, C e D com suas pontuações iniciais
    int num_A, num_B, num_C, num_D; //lê o número de cartas de cada jogador
    char vencedor, perdedor; //Calcula o vencedor e o perdedor
    char naipe_A, naipe_B, naipe_C, naipe_D, t; //lê o naipe das cartas
    int carta_A, carta_B, carta_C, carta_D; //lê o valor da carta  
    int rodA, rodB, rodC, rodD; //lê o valor que cada jogador ganhou na rodada  
    
    while (A < 100 && B < 100 && C < 100 && D < 100) {
          
          scanf("%d %d %d %d", &num_A, &num_B, &num_C, &num_D);
          
          rodA = 0;
          
          for (int i = 0; i < num_A; i++) {
              scanf("%d%c%c", &carta_A, &t, &naipe_A);
              if (naipe_A == 'C') {
                 A++;
                 rodA++;
              }
              else if (carta_A == 12 && naipe_A == 'E') {
                     A = A + 13;
                     rodA = rodA +13;
                  }
              
              if(rodA == 26) {
                      A = A - 26;
                      B = B + 26;
                      C = C + 26;
                      D = D + 26; 
              }
          }   
          
          rodB = 0;
          
          for (int i = 0; i < num_B; i++) {
              scanf("%d%c%c", &carta_B, &t, &naipe_B);
              if (naipe_B == 'C') {
                 B++;
                 rodB++;
              }
              else if (carta_B == 12 && naipe_B == 'E') {
                     B = B + 13;
                     rodB = rodB + 13;
                  }
                  
              if(rodB == 26) {
                      A = A + 26;
                      B = B - 26;
                      C = C + 26;
                      D = D + 26; 
              }
          }
             
          rodC = 0;   
             
          for (int i = 0; i < num_C; i++) {
              scanf("%d%c%c", &carta_C, &t, &naipe_C);
              if (naipe_C == 'C') {
                 C++;
                 rodC++;
              }
              else if (carta_C == 12 && naipe_C == 'E') {
                     C = C + 13;
                     rodC = rodC + 13;
                  }
              
              if(rodC == 26) {
                      A = A + 26;
                      B = B + 26;
                      C = C - 26;
                      D = D + 26; 
              }
          }   
          
          rodD = 0;
          
          for (int i = 0; i < num_D; i++) {
              scanf("%d%c%c", &carta_D, &t, &naipe_D);
              if (naipe_D == 'C') {
                 D++;
                 rodD++;
              }
              else if (carta_D == 12 && naipe_D == 'E') {
                     D = D + 13;
                     rodD = rodD + 13;
                  }
              
              if(rodD == 26) {
                      A = A + 26;
                      B = B + 26;
                      C = C + 26;
                      D = D - 26; 
              }
          }      
          
          printf("A: %d B: %d C: %d D: %d\n", A, B, C, D);
    }
    
    if (A < B && A < C && A < D) {
       vencedor = 'A';
    }
    else if (B < A && B < C && B < D) {
           vencedor = 'B';
    }
    else if (C < A && C < B && C < D) {
               vencedor = 'C';
    }
    else {
                   vencedor = 'D';
    }
                
    if (A > B && A > C && A > D) {
       perdedor = 'A';
    }
    else if (B > A && B > C && B > D) {
           perdedor = 'B';
    }
    else if (C > A && C > B && C > D) {
               perdedor = 'C';
    }
    else {
                   perdedor = 'D';
    }    
                
    printf("Vencedor: jogador %c; Ultimo lugar: jogador %c\n", vencedor, perdedor);
}
