//structs
struct node{
    int cod;
};

struct item{
    struct item *prev;
    struct node data;
    struct item *next;
};
typedef struct item* List;
typedef struct item Item;

List* init_list(); // inicializa a lista

void free_list(List* li); // libera lista
int inserts_final_list(List* li, struct node d); // insere na lista >> final
int inserts_start_list(List* li, struct node d); // insere na lista >> começo
int list_size(List* li); // quantidade de elementos na lista
void list_prints(List* li); // imprime lista

// functions
	// inicializa a lista
List* init_list()
{
    List* li = (List*) malloc(sizeof(List));
    
    if(li != NULL)
    {
    	*li = NULL;
	}
        
    return li;
}
	// libera lista
void free_list(List* li)
{
    if(li != NULL)
	{
        Item* node;
        while((*li) != NULL)
		{
            node = *li;
            *li = (*li)->next;
            free(node);
        }
        
        free(li);
    }
}
	// insere na lista >> final
int inserts_final_list(List* li, struct node d)
{
    Item *node;
    node = (Item*) malloc(sizeof(Item));

    node->data = d;
    node->next = NULL;
    
    if((*li) == NULL)
	{
        node->prev = NULL;
        *li = node;
    }
	else
	{
        Item *aux;
        aux = *li;
        
        while(aux->next != NULL)
		{
            aux = aux->next;
        }
        
        aux->next = node;
        node->prev = aux;
    }
    
    return 1;
}
	// insere na lista >> começo
int inserts_start_list(List* li, struct node d)
{
    Item* node;
    node = (Item*) malloc(sizeof(Item));
        
    node->data = d;
    node->next = (*li);
    node->prev = NULL;
    
    if(*li != NULL)
    {
    	(*li)->prev = node;
	}
        
    *li = node;
    return 1;
}
	// quantidade de elementos na lista
int list_size(List* li)
{
	int list_size = 0;
	Item* node = *li;
	
    if(li != NULL)
    {
    	while(node != NULL)
		{
	        list_size++;
	        node = node->next;
	    }
	}
            
    return list_size;
}
	// imprime lista
void list_print(List* li)
{
	Item* node = *li;
	
    if(li != NULL)
    {
	
    	while(node != NULL)
		{
	        printf(" [%d] ",node->data.cod);
	
	        node = node->next;
	    }
    }
}

