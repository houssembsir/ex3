static bool stop_flag = false;
static uint8 t item count = 0;
K_SEM_DEFINE(prod_sem, 0, 1)
struct item {
uint8 t a;
uint8 t b;
}:
static struct item last_item;
static void read_from_uart_blocking(char *buf)
{
/* Cette fonction attend (bloque) jusqu'a ce
* qu'une chaine de caractere finissant par W
* soit reque sur un bus UART.
* Ce code est un pseudo-code.
* Ne pas chercher d'erreur dans cette fonction
*/
do {
wait_for_character();
read_character(buf++);
} while (!new_line_receivedO);
}
static void producteur(void *p1, void *p2, void *p3)
{
char *msg;
while (!stop_flag) {
read from uart blocking(msg);
create_item_from_str(msg, &last_item);
k_sem_give(&prod_sem);
}

static void producteur start(void)
{
/* Cette fonction demarre un thread qui exedute
* la fonction producteur(void* void *, void *)
* Ne pas chercher d'erreur dans cette fonction
*/
start thread(producteur);
}
int main(void)
{
int err;
producteur_start();
while (itemcount < 5) {
k_sem_take(&prod_sem, K_SECONDS(1));
printf("New item received: a =%d, b = %d\n",
lastitem.a ,lastitem.b);
processing_item();
}
stop_flag = true;
return 0;
}