// strucutre maillon

typedef struct maillon {
	int data;
	maillon *next;
}maillon;
// structure list
typedef struct list {
	int size;
	maillon head;
	maillon queue;
}list;

// allocation dynamique maillon

maillon *new_maillon(int d){
	maillon *m=malloc(sizeof(maillon));
	m->data=d;
	return m;
}
// allocation d'une nouvelle lists
list *new_list(){
	list *r = malloc(sizeof(list));
	r->size=0;
	r->tete=NULL;
	r->queue=NULL;
	return r;
}

// add head of the list

void add_tete(list *t , int d){
	maillom *m=new_maillon(d);
	m->next=t->head;
	t->head=m;
	if(l->size==0){
		t->queue=m;
	}
	t->size++;
}

void add_queue(list *t, int d){
	maillon *m=new_maillon(d);
	m->next=NULL;
	if(t->size>0){
		t->queue->next=m;	
	}
	else{
		t->head=m;
	}
	t->queue=m;
	t->size++;
}

// add is always a void

// delete is always the data type

// allocation is alwys the structure type
// always the * before the structure type!!!

int rem_tete(list *t){
	maillon *m=t->head;
	int r=m->data;
	
	t->head=t->head->next;
	free(m);
	t->size--;
	
	if(t->size==0){
		t->queue=NULL;
	}
	return r;
}

int rem_queue(list *t){
	maillon *av=NULL;
	maillon *last=t->head;
	int d;
	while(last!=t->queue){
		av=last;
		last=last->next;
	}
	d=last->data;
	t->	queue=av;
	free(last);
	t->size--;
	if(t->size==0){
		t->head=NULL;
	}
	return d;
}

// video une list

void vider(list *t){
	while(!est_vide){
		rem_tete(t);
	}
	free(t);
}

_Bool est_vide(list *t){
	return t->size==0;
}


void parcours_list(list *t){
	maillon *p=t->head;
	while(p!=NULL){
		// instructions
		p=p->next;
	}
}

maillon *find_maillon(list *t, int position){
	maillon *r=t->head;
	int i;
	if(position>=t->size){
		return NULL;
	}
	for(i=0;i<=position;i++){
		r=r->next;
	}
	return r;
}

int find_data(list *t,int position){
	maillon *r=find_maillon(t,position);
	if(r==NULL){
		assert(0);
	}
	return r->data;
}

void add_in_position(list *t, int position, int data){
	maillon *m, *r;
	// si position==0; add tete
	// li position== taille de la list add queue
	// else
	r=find_maillon(t,position){
		m=new_maillon(d);
		m->next=r->next;
		r->next=m;
		t->size++;
	}
}

int delete_in_position(list *t, int poition){
	maillon *r,*m;
	int d;
	// si position==0; reme tete;
	// si position ==taille rem queue;
	//else
	r=trouver_maillon(t,position-1);
	m=r->next;
	d=m->data;
	r->next=m->next;
	free(m);
	t->size--;
	return d;
}

/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////

//FiLE FIFO (first in first out) ADD_Queue rem_head
//Pile LIFO add_head rem_queue.
//list doublement chainee
// maillon ayant deux pointeur before and after

// structure de la liste same as before

// fonction de hachage: permet de diminuer le temps de parcours
// d'une chaine en divisant la chaine en plusierus chaines

// structure de donnes associer 
// maillon
// list
// table de hachage
typedef struct
{
	list **tab;
	int taille;
}tab_hachage;

// initialisation de la table de hachage
// cree une table de hachage
tab_hachage * new_tab(int taille){
	int i;
	tab_hachage *th = malloc(sizeof(tab_hachage));
	th->tab=malloc(taille*sizeof(list*));
	for(i=0;i<taille;i++){
		th->tab[i]=new_list();
	}
	th->taille=taille;
	return th;
}
//vider une table de hachage
void vider_th(tab_hachage *th){
	int i;
	for(i=0;i<taille;i++){
		vider(th->tab[i]);
	}
	
	free(th->tab);
	free(th);
	
}
//fonction de hachage
int hachage(tab_hachage *th, int d){
	return r % th->taille;
}
//ajouter
void add_tete_th(tab_hachage th, int d){
	int p=hachage(th,d);
	add_tete(th->tab[p],d);
}
//Rechercher
maillon *rechercher(tab_hachage th,int d){
	maillon *e;
	int p=hachage(th,d);
	e=th->tab[p]->head;
	while(e!=NULL){
		if(e->data==d){
			return e;
		}
		e=e->next;
	}
	return NULL;
}


// array list

// maillon
// tab maillon
typedef struct tab_maillon{
	maillon *tab
	int taille;
	struct tab_maillon *next;
}tab_maillon;

// declaration liste maillon
// declaration list tab maillon (just changer le typde de variable)

// declaration array list

typedef struct arraylist{
	list * occuper;
	list *libre;
	list_tab_maillon *ltm;
}arraylist; 

// ajouter un element dans la list

void add_tete_maillon(list *t,maillon *m){
	m->suivant=t->head;
	t->head=m;
	t->size++;
}
void add_tete_data(list *l, int d){
	add_tete_maillon*l,new_maillon(d);
}
// on fait pareil pour ajouter en quete apres avant......

maillon* rem_tete_maillon(list *t){
	maillon *r=t->head;
	t->head=t->head->next;
	t->size++;
	return t;
}

//initialisation d'une array list

void agrandir_list_libre(arraylist *arl, int taille){
	maillon *t;
	int i;
	
	// on  verifie si la liste est vide
	t=malloc(taille*sizeof(maillon));
	
	for(i=0;i<taille-1;i++){
		t[i].next=&(t[i+1]);
	}
	t[taille-1].next=NULL;
	
	arl->libre->head=&(t[0]);
	arl->libre->queue=(&t[taille-1]);
	arl->libre->size=size;
}

arraylist *new_arraylist(int size){
	arraylist *arl;
	arl=malloc(sizeof(arraylist));
	arl->occuper=new_list();
	arl->libre=newlist();
	agrandir_list_libre(arl,size);
	return arl;
}

// ajouter un element
void add_tete(arraylist *arl, int d){
	maillon *l;
	// li la liste des mailln ibre est vide
	if(est_vide(arl->libre)){
		agrandir_list)libre(arl,1.5*arl->occuper->taille);// l'espace qu'on veux allouer
	}
	l=rem_tete_maillon(arl->libres);
	l->data=d;
	add_tete_maillom(arl->occuper,l);
}

//supprimer une donner de array list

int rem_tete(arraylist*arl){
	maillon *l;
	int d;
	l=rem_tete_maillon(arl->occuper);
	d=l->data;
	add_tete_maillon(arl->libre,l);
}

void vider(arraylist *arl){
	tab_maillon *t;
	while !estvide(arl->ltm){
		t->rem_tete_maillon(arl->ltm)
		free(t->tab);
		free(t);
	}
	free(arl->libre);
	free(arl->occuper);
	free(arl->ltm);
	free(arl);
}
