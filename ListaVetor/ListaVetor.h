#define MAXLISTA 1000000
typedef struct
{
	int valor;
} Item;

typedef struct
{
	//Fim aponta para a primeira posição livre.
	//Inicio aponta para o primeiro elemento.
	size_t Inicio,Fim;
	Item itens[MAXLISTA];

} Lista;

void ListaCria(Lista *lista);
void ListaZera(Lista *lista);


uint8_t ListaImprima(Lista *lista);
uint8_t ListaRetira(Lista *lista, Item *item,size_t posicao);
uint8_t ListaInsira(Lista *lista, Item *item, size_t posicao);
uint8_t ListaRetornaElemento(Lista *lista, Item *item, size_t posicao);
uint8_t ListaCopia(Lista *destino, Lista *fonte);
uint8_t ListaConcatena(Lista *destino, Lista *fonte);
uint8_t ListaIntercala(Lista *resultado, Lista *lista1, Lista *lista2);

size_t ListaRetornaFim(Lista *lista);
size_t ListaRetornaInicio(Lista *lista);
size_t ListaRetornaTamanho(Lista *lista);
