#include <locale.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#define PXEGG 12.50 
#define PXTUDO 15.00 
#define PXCALABRESA 13.00 
#define PXSALADA 14.00 
#define PCOCACOLA 4.00 
#define PFANTALARANJA 3.50 
#define PFANTAUVA 3.50 
#define PGUARANAANTARTICA 3.50 #define PSUCOLARANJA 4.00 
#define PCAIPIRINHAMORANGO 10.00 #define PCAIPIRINHALIMAO 10.00 #define PCAIPIRINHAKIWI 11.00 #define PMOSCOWMULE 12.00 #define PGINTONICAMORANGO 12.00 #define PGINTONICALIMAO 11.00 #define PGINTONICAKIWI 13.00 #define PAGUAMINERAL 2.00 
#define PAGUAMINERALGAS 2.50 #define PREDBULL 7.00 
#define PWHISKYJACKDANIELS 15.00 #define PWHISKYREDLABEL 13.00 #define PCERVEJAORIGINAL600ML 8.00 #define PCERVEJAHEINEKEN600ML 9.00 
#define PBATATAFRITA 10.00 
#define PFRANGOPASSARINHO 15.00 #define PCONTRAFILE 20.00 
#define PPICANHA 25.00 
#define PTABUAFRIOS 30.00 
#define PSORVERTEBAUNILHA 7.00 #define PSORVETEMORANGO 7.00 #define PSORVETECHOCOLATE 7.00 #define PPUDIM 6.00 
// cores 
#define RESET "\033[0m" 
#define BOLD "\033[1m" 
#define BLINK "\033[5m" 
#define RED "\033[31m" 
#define GREEN "\033[32m"
#define YELLOW "\033[33m" 
#define ORANGE "\033[38;5;214m" 
#define LIGHT_YELLOW "\033[38;5;229m" // Amarelo claro 
#define REDDISH_ORANGE "\033[38;5;202m" // Laranja avermelhado 
// Fun��o para limpar a tela 
void clear_screen() { 
#ifdef _WIN32 
system("cls"); 
#else 
system("clear"); 
#endif 
} 
int main() { 
setlocale(LC_ALL, "Portuguese"); 
char continuarPedido, nome[100]; 
int escolha_menu_lanches, escolha_menu_bebidas, escolha_menu_porcoes, escolha_menu_sobremesas; 
int mesa, quantidade = 0; 
double pedidoatual = 0.0, total = 0.0, total_acumulado = 0.0; 
int total_pedidos = 0; 
int escolha_menu, contador; 
int taxa_servico = 0.0; 
// Arrays para armazenar os valores dos pedidos 
double pedidos[100]; 
int numeroPedidos = 0; 
clear_screen(); // limpar tela antes de retornar, tirar lixo visual de erros. 
do { 
double total = 0.0, total_acumulado = 0.0, pedidoatual = 0.0; 
int mesa = 0, total_pedidos = 0, quantidade = 0; 
int escolha_menu = 0, escolha_menu_lanches = 0, escolha_menu_bebidas = 0; int escolha_menu_porcoes = 0, escolha_menu_sobremesas = 0, contador = 0; numeroPedidos = 0; 
clear_screen(); 
// Menu inicial. 
printf(REDDISH_ORANGE 
"____________________________________________________" 
"________________" RESET); 
printf(LIGHT_YELLOW " BEM-VINDO AO MODERN BAR " RESET); 
printf(REDDISH_ORANGE 
"____________________________________________________" 
"________________\n" RESET); 
printf(REDDISH_ORANGE 
"___________________________________________________________________" "___________________________________________________________________"
"___________________________\n" RESET); 
printf(LIGHT_YELLOW "\nDigite seu nome: " RESET); 
scanf("%s", nome); 
// Loop de valida��o para garantir que o n�mero da mesa seja um inteiro e // esteja no intervalo correto 
do { 
printf(LIGHT_YELLOW "\nDigite o n�mero da mesa que est� acomodado (entre " "1 e 30): " RESET); 
if (scanf("%d", &mesa) != 1 || mesa < 1 || mesa > 30) { 
printf( 
RED 
"\nN�mero de mesa inv�lido. Por favor, digite novamente.\n" RESET); sleep(2); // Time de 2 segundos para apresentar o menu 
while (getchar() != '\n') 
; // Limpar o buffer de entrada 
clear_screen(); 
} 
} while (mesa < 1 || mesa > 30); 
printf(LIGHT_YELLOW 
"\n\nCerto, %s. Vou lhe apresentar nosso card�pio.\n" RESET, 
nome); 
sleep(2); // Time de 2 segundos para apresentar o menu 
// Menu principal. 
do { 
do { // Loop de valida��o para garantir que a entrada do menu seja um // inteiro entre 1 e 4 
printf(REDDISH_ORANGE 
"\n______________________________________________" 
"_________________________" RESET); 
printf(LIGHT_YELLOW " MENU PRINCIPAL " RESET); 
printf(REDDISH_ORANGE 
"________________________________________________" 
"__________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_______________________________________________________________" "_______________________________________________________________" "___________________________________\n" RESET); 
printf(LIGHT_YELLOW "1: Acessar o menu de Lanches\n" RESET); printf(LIGHT_YELLOW "2: Acessar o menu de Bebidas\n" RESET); 
printf(LIGHT_YELLOW "3: Acessar o menu de Por��es\n" RESET); 
printf(LIGHT_YELLOW "4: Acessar o menu de Sobremesas\n" RESET); printf(REDDISH_ORANGE 
"_______________________________________________________________" "_______________________________________________________________" "___________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "Digite a op��o escolhida (1 a 4): " RESET); if (scanf("%d", &escolha_menu) != 1 || escolha_menu < 1 || 
escolha_menu > 4) {
printf(RED "\nOp��o inv�lida. Por favor, digite novamente.\n" RESET); sleep(3); 
while (getchar() != '\n') 
; // Limpar o buffer de entrada 
clear_screen(); 
} 
} while (escolha_menu < 1 || escolha_menu > 4); 
// Limpar valores do pedido atual 
double pedidoatual = 0.0; 
int quantidade = 0; 
switch (escolha_menu) { 
case 1: 
printf(LIGHT_YELLOW "\n\nCerto, %s vou apresentar abaixo o nosso " "card�pio de Lanches\n" RESET, 
nome); 
do { // Loop de valida��o para garantir que a escolha do menu seja um // n�mero inteiro entre 1 e 4 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " MENU DE LANCHES " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW 
"1: X-egg - P�o de Brioche, Hamb�rguer(150g), Queijo prato, " 
"Molho Billy Jack e ovo. - Pre�o: R$ %.2lf \n" RESET, 
PXEGG); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n"); 
printf(LIGHT_YELLOW 
"2: X-tudo - P�o de hamburguer americano, Hamb�rguer(150g), " 
"Queijo prato, Maionese da casa, Bacon, ovo, alface e tomate. " 
"- Pre�o: R$ %.2lf \n" RESET, 
PXTUDO); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n"); 
printf(LIGHT_YELLOW 
"3: X-calabresa - P�o de hamburguer americano, " 
"Hamb�rguer(150g), Queijo prato, Maionese da casa, Calabresa " 
"e Cebola caramelizada. - Pre�o: R$ %.2lf \n" RESET,
PXCALABRESA); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW 
"4: X-salada - P�o de hamburguer americano, Hamb�rguer(150g), " 
"Queijo prato, Maionese da casa, Ketchup, alface e tomate. - " 
"Pre�o: R$ %.2lf \n" RESET, 
PXSALADA); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_______________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "Digite a op��o escolhida (1 a 4): " RESET); 
if (scanf("%d", &escolha_menu_lanches) != 1 || 
escolha_menu_lanches < 1 || escolha_menu_lanches > 4) { 
printf(LIGHT_YELLOW 
"\nOp��o inv�lida. Por favor, digite novamente.\n" RESET); 
sleep(3); 
while (getchar() != '\n') 
; // Limpar o buffer de entrada 
clear_screen(); 
} 
} while (escolha_menu_lanches < 1 || escolha_menu_lanches > 4); 
// Solicita a quantidade 
do { 
printf(LIGHT_YELLOW "\nQuantos desse item voc� deseja pedir? " RESET); if (scanf("%d", &quantidade) != 1 || quantidade < 0) { 
// Verifica se a quantidade � zero ou positiva 
printf(LIGHT_YELLOW "\nQuantidade inv�lida.\n" RESET); 
sleep(3); 
while (getchar() != '\n') 
; // Limpar o buffer de entrada 
clear_screen(); 
quantidade = 0; 
} 
} while (quantidade < 0); 
switch (escolha_menu_lanches) { 
case 1: 
pedidoatual = PXEGG; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu X-egg. Pre�o: R$ %.2lf e " 
"solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 2: 
pedidoatual = PXTUDO; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu X-tudo. Pre�o: R$ %.2lf e " 
"solicitou a quantidade %d vezes.", 
pedidoatual, quantidade); 
break; 
case 3: 
pedidoatual = PXCALABRESA; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu X-calabresa. Pre�o: R$ %.2lf e " "solicitou a quantidade %d vezes.", 
pedidoatual, quantidade); 
break; 
case 4: 
pedidoatual = PXSALADA; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu X-salada. Pre�o: R$ %.2lf e " "solicitou a quantidade %d vezes.", 
pedidoatual, quantidade); 
break; 
} 
break; 
// Menu Bebidas. 
case 2: 
printf(LIGHT_YELLOW "\n\nCerto, %s vou apresentar abaixo o nosso " "card�pio de Bebidas\n" RESET, 
nome); 
do { // Loop de valida��o para garantir que a escolha do menu seja um // n�mero inteiro entre 1 e 19 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " MENU DE BEBIDAS " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "1: Coca-Cola - R$ %.2lf \n" RESET, PCOCACOLA); printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW "2: Fantalaranja - R$ %.2lf \n", PFANTALARANJA); printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW "3: Fantauva - R$ %.2lf \n" RESET, PFANTAUVA); printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW "4: Guarana Antartica - R$ %.2lf \n" RESET, 
PGUARANAANTARTICA); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW
"5: Suco de Laranja - Delicioso suco de fruta, feito com " "laranjas doces e saborosas. - Pre�o: R$ %.2lf \n" RESET, PSUCOLARANJA); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf( 
LIGHT_YELLOW 
"6: Caipirinha de Morango - Drink � base de Vodka Smirnoff, " "gelo, morangos doces e suculentos. - Pre�o: R$ %.2lf \n" RESET, PCAIPIRINHAMORANGO); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW 
"7: Caipirinha de Lim�o - O drink mais pedido da casa, � base " "de Vodka Smirnoff, gelo, suco e raspas de lim�o.\n Um toque " "do chefe para um drink suave e que n�o amarga. - Pre�o: R$ " "%.2lf \n" RESET, 
PCAIPIRINHAMORANGO); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf( 
LIGHT_YELLOW 
"8: Caipirinha de Kiwi - Drink � base de Vodka Smirnoff, gelo, " "kiwis saborosos e suculentos. - Pre�o: R$ %.2lf \n" RESET, PCAIPIRINHAKIWI); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW 
"9: Moscow Mule - Drink � base de vodka Smirnoff, ginger " "beer, suco de lim�o, espuma de gengibre e bastante gelo.\n " "Refrescante e saboroso, servido em uma caneca de cobre para " "manter a bebida gelada por mais tempo. - Pre�o: R$ %.2lf " "\n" RESET, 
PMOSCOWMULE); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf( 
LIGHT_YELLOW
"10: Gin T�nica Sunset - Drink � base de Gin, �gua t�nica, " "pimenta rosa, calda e peda�os de morango.\n A harmonia perfeita " "entre doce e fresco, criando uma experi�ncia sensorial " "agrad�vel e aveludada ao paladar. - Pre�o: R$ %.2lf \n" RESET, PGINTONICAMORANGO); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW 
"11: Gin T�nica C�trica - Drink � base de Gin, �gua t�nica e " "suco de lim�o.\n Ideal para amantes de sabores c�tricos e " "refrescantes. - Pre�o: R$ %.2lf \n" RESET, 
PGINTONICALIMAO); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW 
"12: Gin T�nica Tropical - Drink � base de Gin, �gua t�nica, " "hortel�, flor de hibisco, calda e peda�os de kiwi.\n Uma " "explos�o de sabores ex�ticos e refrescantes, viaje aos " "tr�picos em cada gole. - Pre�o: R$ %.2lf \n" RESET, 
PGINTONICAKIWI); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW "13: �gua Mineral - Pre�o: R$ %.2lf \n" RESET, PAGUAMINERAL); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW 
"14: �gua Mineral com G�s - Pre�o: R$ %.2lf \n" RESET, PAGUAMINERALGAS); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW "15: Red Bull - Pre�o: R$ %.2lf \n" RESET, PREDBULL); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW
"16: Whisky Jack Daniels - Pre�o: R$ %.2lf \n" RESET, 
PWHISKYJACKDANIELS); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW "17: Whisky Red Label - Pre�o: R$ %.2lf \n" RESET, PWHISKYREDLABEL); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW 
"18: Cerveja Original (600ml) - Pre�o: R$ %.2lf \n" RESET, 
PCERVEJAORIGINAL600ML); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"......................................\n" RESET); 
printf(LIGHT_YELLOW 
"19: Cerveja Heineken (600ml) - Pre�o: R$ %.2lf \n" RESET, 
PCERVEJAHEINEKEN600ML); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "Digite a op��o escolhida (1 a 19): " RESET); if (scanf("%d", &escolha_menu_bebidas) != 1 || 
escolha_menu_bebidas < 1 || escolha_menu_bebidas > 19) { 
printf(LIGHT_YELLOW "\nOp��o inv�lida. Por favor, digite uma op��o " "v�lida.\n" RESET); 
sleep(3); 
// Limpa o buffer de entrada para evitar loops infinitos em caso de // entrada inv�lida 
while (getchar() != '\n') 
; // Limpar o buffer de entrada 
clear_screen(); 
} 
} while (escolha_menu_bebidas < 1 || escolha_menu_bebidas > 19); // Solicita a quantidade 
do { 
printf(LIGHT_YELLOW "\nQuantos desse item voc� deseja pedir? " RESET); if (scanf("%d", &quantidade) != 1 || quantidade < 0) { 
// Verifica se a quantidade � zero ou positiva 
printf(LIGHT_YELLOW "\nQuantidade inv�lida.\n" RESET); 
sleep(3); 
while (getchar() != '\n')
; // Limpar o buffer de entrada 
clear_screen(); 
quantidade = 0; 
} 
} while (quantidade < 0); 
switch (escolha_menu_bebidas) { 
case 1: 
pedidoatual = PCOCACOLA; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Coca-Cola. Pre�o: R$ %.2lf e " "solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 2: 
pedidoatual = PFANTALARANJA; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Fanta Laranja. Pre�o: R$ %.2lf " "e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 3: 
pedidoatual = PFANTAUVA; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________"
"_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Fanta Uva. Pre�o: R$ %.2lf e " "solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 4: 
pedidoatual = PGUARANAANTARTICA; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Guaran� Antartica. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 5: 
pedidoatual = PSUCOLARANJA; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Suco de Laranja. Pre�o: R$ %.2f " "e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 6: 
pedidoatual = PCAIPIRINHAMORANGO; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________"
"_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW 
"\nVoc� escolheu Caipirinha de Morango. Pre�o: R$ %.2lf e " 
"solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 7: 
pedidoatual = PCAIPIRINHALIMAO; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Caipirinha de Lim�o. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 8: 
pedidoatual = PCAIPIRINHAKIWI; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Caipirinha de Kiwi. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 9: 
pedidoatual = PMOSCOWMULE; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Moscow Mule. Pre�o: R$ %.2lf e " "solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 10: 
pedidoatual = PGINTONICAMORANGO; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Gin T�nica Sunset. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 11: 
pedidoatual = PGINTONICALIMAO; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Gin T�nica C�trica. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 12: 
pedidoatual = PGINTONICAKIWI; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Gin T�nica Tropical. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 13: 
pedidoatual = PAGUAMINERAL; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu �gua Mineral. Pre�o: R$ %.2lf e " "solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 14: 
pedidoatual = PAGUAMINERALGAS; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu �gua Mineral com G�s. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 15: 
pedidoatual = PREDBULL; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Red Bull. Pre�o: R$ %.2lf e " "solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 16: 
pedidoatual = PWHISKYJACKDANIELS; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Whisky Jack Daniel's. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 17: 
pedidoatual = PWHISKYREDLABEL; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Whisky Red Label. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 18: 
pedidoatual = PCERVEJAORIGINAL600ML; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW 
"\nVoc� escolheu Cerveja Original (600ml). Pre�o: R$ %.2lf e " 
"solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 19: 
pedidoatual = PCERVEJAHEINEKEN600ML; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW 
"\nVoc� escolheu Cerveja Heineken (600ml). Pre�o: R$ %.2lf e " 
"solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
} 
break; 
// Menu Por��es. 
case 3: 
printf(LIGHT_YELLOW "\n\nCerto, %s vou apresentar abaixo o nosso " "card�pio de Por��es.\n" RESET, 
nome); 
do { // Solicitar a escolha do menu de Por��es 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " MENU DE POR��ES " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_______________________________________\n\n" RESET); 
printf(LIGHT_YELLOW 
"1: Batata Frita - Deliciosas batatas fritas crocantes por " 
"fora e macias por dentro. Acompanha: Maionese, Ketchup, " 
"Chedder. - Pre�o: R$ %.2lf \n" RESET, 
PBATATAFRITA);
printf(YELLOW 
"............................................................." 
"............................................................." 
"...............................................\n" RESET); 
printf( 
LIGHT_YELLOW 
"2: Frango � Passarinho - Por��es suculentas de frango � " 
"passarinho, crocantes por fora e macias por dentro.\n " 
"Acompanha: Molho disponivel na casa e torradas.\nOp��es Molho: " "Alho, Verde, Maionese caseira ou BillyJack\n (Observa��o " 
"limitado a uma escolha de molho e as op��es podem variar de " "acordo com a disponibilidade) Pre�o: R$ %.2lf \n" RESET, 
PFRANGOPASSARINHO); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"................................................\n" RESET); 
printf(LIGHT_YELLOW "3: Contra Fil� - Generosa por��o de contra fil� " "grelhado no ponto ideal. Acompanha: Vinagre, " 
"Torradas. - Pre�o: R$ %.2lf \n" RESET, 
PCONTRAFILE); 
printf(YELLOW 
"............................................................." 
"............................................................." 
"................................................\n" RESET); 
printf(LIGHT_YELLOW 
"4: Picanha - Fatias suculentas de picanha grelhada, com um " "toque especial de temperos que real�am seu sabor �nico. " 
"Acompanha: Vinagrete, Torradas. - Pre�o: R$ %.2lf \n" RESET, PPICANHA); 
printf(YELLOW 
"............................................................." 
"............................................................." 
".................................................\n" RESET); 
printf(LIGHT_YELLOW 
"5: T�bua de Frios - Uma sele��o especial de frios de alta " 
"qualidade, queijos, presuntos, salames uma experi�ncia " 
"gastron�mica completa. - Pre�o: R$ %.2lf \n" RESET, 
PTABUAFRIOS); 
printf(REDDISH_ORANGE 
"\n\n_________________________________________________________" "_____________________________________________________________" "_________________________________________________\n" RESET); printf(LIGHT_YELLOW "Digite a op��o escolhida: " RESET); 
if (scanf("%d", &escolha_menu_porcoes) != 1 || 
escolha_menu_porcoes < 1 || escolha_menu_porcoes > 5) { 
printf(LIGHT_YELLOW "\nOp��o inv�lida. Por favor, digite uma op��o " "v�lida.\n" RESET);
sleep(3); 
// Limpa o buffer de entrada para evitar loops infinitos em caso de 
// entrada inv�lida 
while (getchar() != '\n') 
; 
clear_screen(); 
} 
} while (escolha_menu_porcoes < 1 || escolha_menu_porcoes > 5); 
// Solicita a quantidade 
do { 
printf(LIGHT_YELLOW "\nQuantos desse item voc� deseja pedir? " RESET); if (scanf("%d", &quantidade) != 1 || quantidade < 0) { 
// Verifica se a quantidade � zero ou positiva 
printf(LIGHT_YELLOW "\nQuantidade inv�lida.\n" RESET); 
sleep(3); 
while (getchar() != '\n') 
; // Limpar o buffer de entrada 
clear_screen(); 
quantidade = 0; 
} 
} while (quantidade < 0); 
switch (escolha_menu_porcoes) { 
case 1: 
pedidoatual = PBATATAFRITA; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Batata Frita. Pre�o: R$ %.2lf e " "solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 2: 
pedidoatual = PFRANGOPASSARINHO; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________"
"_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Frango Passarinho. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 3: 
pedidoatual = PCONTRAFILE; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Contra Fil�. Pre�o: R$ %.2lf e " "solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 4: 
pedidoatual = PPICANHA; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Picanha. Pre�o: R$ %.2lf e " "solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 5: 
pedidoatual = PTABUAFRIOS; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________"
"_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu T�bua de Frios. Pre�o: R$ %.2lf " "e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
} 
break; 
// Menu Sobremesas. 
case 4: 
printf(LIGHT_YELLOW "\n\nCerto, %s vou apresentar abaixo o nosso " "card�pio de Sobremesas.\n" RESET, 
nome); 
do { // Solicitar a escolha do menu de Sobremesas 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " MENU DE SOBREMESAS " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"__________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW 
"1: Sorvete Baunilha - tr�s bolas de sorvete cremoso, � base " 
"de leite e baunilha. - Pre�o: R$ %.2lf\n" RESET, 
PSORVERTEBAUNILHA); 
printf(YELLOW 
"............................................................." 
"............................................................." 
".........................................\n" RESET); 
printf(LIGHT_YELLOW 
"2: Sorvete Morango - tr�s bolas de sorvete cremoso, � base " 
"de leite e morango. - Pre�o: R$ %.2lf\n" RESET, 
PSORVETEMORANGO); 
printf(YELLOW 
"............................................................." 
"............................................................." 
".........................................\n" RESET); 
printf(LIGHT_YELLOW 
"3: Sorvete Chocolate - tr�s bolas de sorvete cremoso, � base " 
"de leite e chocolate. - Pre�o: R$ %.2lf\n" RESET, 
PSORVETECHOCOLATE); 
printf(YELLOW 
"............................................................." 
"............................................................." 
".........................................\n" RESET);
printf( 
LIGHT_YELLOW 
"4: Pudim - 1 fatia deliciosamente cremosa de pudim, � base de " 
"leite fresco, ovos delicadamente batidos e leite condensado, " 
"calda de a��car caramelizado. - Pre�o: R$ %.2lf\n" RESET, 
PPUDIM); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "Digite a op��o escolhida: " RESET); 
if (scanf("%d", &escolha_menu_sobremesas) != 1 || 
escolha_menu_sobremesas < 1 || escolha_menu_sobremesas > 4) { 
printf(LIGHT_YELLOW "\nOp��o inv�lida. Por favor, digite uma op��o " "v�lida.\n" RESET); 
sleep(3); 
// Limpa o buffer de entrada para evitar loops infinitos em caso de 
// entrada inv�lida 
while (getchar() != '\n') 
; 
clear_screen(); 
} 
} while (escolha_menu_sobremesas < 1 || escolha_menu_sobremesas > 4); // Solicita a quantidade 
do { 
printf(LIGHT_YELLOW "\nQuantos desse item voc� deseja pedir?" RESET); if (scanf("%d", &quantidade) != 1 || quantidade < 0) { 
// Verifica se a quantidade � zero ou positiva 
printf(LIGHT_YELLOW "\nQuantidade inv�lida.\n" RESET); 
sleep(3); 
while (getchar() != '\n') 
; // Limpar o buffer de entrada 
clear_screen(); 
quantidade = 0; 
} 
} while (quantidade < 0); 
switch (escolha_menu_sobremesas) { 
case 1: 
pedidoatual = PSORVERTEBAUNILHA; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________"
"_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Sorvete Baunilha. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 2: 
pedidoatual = PSORVETEMORANGO; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Sorvete Morango. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 3: 
pedidoatual = PSORVETECHOCOLATE; 
printf(REDDISH_ORANGE "\n____________________________________________" "___________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________" "_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Sorvete Chocolate. Pre�o: R$ " "%.2lf e solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
case 4: 
pedidoatual = PPUDIM; 
printf(REDDISH_ORANGE "\n____________________________________________" "____________________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"______________________________________________" 
"____________________________\n" RESET); 
printf(REDDISH_ORANGE 
"_____________________________________________________________" "_____________________________________________________________"
"_________________________________________\n\n" RESET); 
printf(LIGHT_YELLOW "\nVoc� escolheu Pudim. Pre�o: R$ %.2lf e " "solicitou a quantidade %d vezes." RESET, 
pedidoatual, quantidade); 
break; 
} 
break; 
} 
total = pedidoatual * quantidade; 
pedidos[numeroPedidos++] = total; 
total_acumulado += total; 
total_pedidos++; 
for (contador = 0; contador < numeroPedidos; contador++) { 
printf(BOLD LIGHT_YELLOW "\nO valor do seu %d� pedido: R$ %.2lf" RESET, contador + 1, pedidos[contador]); 
} 
printf(RED "\n___________________________________________________________" " " RESET); 
printf(RED "\n Total acumulado: R$ %.2lf " 
" " RESET, 
total_acumulado); 
printf(RED "\n___________________________________________________________" " " RESET); 
printf(REDDISH_ORANGE 
"\n_______________________________________________________________" "_________________________________________________________________" "___________________________________\n\n" RESET); 
do { 
printf(LIGHT_YELLOW "\nDeseja realizar outro pedido? S/N: " RESET); if (scanf(" %c", &continuarPedido) != 'S' && continuarPedido != 's' && continuarPedido != 'N' && continuarPedido != 'n') { 
printf(RED 
"\nOp��o inv�lida. Por favor, 'S' ou 's, 'N' ou 'n'.\n" RESET); 
sleep(3); 
// Limpa o buffer de entrada para evitar loops infinitos em caso de 
// entrada inv�lida 
while (getchar() != '\n') 
; 
} 
pedidoatual = 0.0; 
quantidade = 0; 
clear_screen(); 
} while (continuarPedido != 'S' && continuarPedido != 's' && 
continuarPedido != 'N' && continuarPedido != 'n'); 
pedidoatual = 0.0; 
quantidade = 0; 
clear_screen();
} while (continuarPedido == 'S' || continuarPedido == 's'); 
printf(REDDISH_ORANGE 
"\n__________________________________________________" 
"______________________" RESET); 
printf(LIGHT_YELLOW " RESUMO DE CONTA " RESET); 
printf(REDDISH_ORANGE 
"____________________________________________________" 
"______________________\n" RESET); 
printf(REDDISH_ORANGE 
"___________________________________________________________________" "___________________________________________________________________" "__________________________\n\n" RESET); 
double taxa_servico = total_acumulado * 0.10; 
printf(BOLD GREEN "Pedido Finalizado!\n" RESET); 
printf(LIGHT_YELLOW "Valor total acumulado: R$ %.2lf\n" RESET, 
total_acumulado); 
printf(LIGHT_YELLOW "Total de pedidos realizados: %d\n" RESET, 
total_pedidos); 
printf(LIGHT_YELLOW "Taxa de servi�o: R$ %.2f\n" RESET, taxa_servico); printf(GREEN "Observ��o: Taxa de servi�o � o valor cobrado de 10%% sobre " "os pedidos, a mesma � opcional.\n" RESET); 
printf(LIGHT_YELLOW "Agradecemos o seu pedido, Volte sempre!\n" RESET); printf(REDDISH_ORANGE "Obs: Aguarde um momento, em 10 segundos iremos " "retorna ao menu de boas vindas.\n" RESET); 
sleep(10); 
clear_screen(); 
printf(REDDISH_ORANGE 
"\n_________________________________________________________________" "___________________________________________________________________" "_____________________________\n\n" RESET); 
clear_screen(); 
} while (continuarPedido == 'n' || continuarPedido == 'N'); 
system("pause"); // Pausa a execu��o para visualizar os resultados 
return 0; 
}

