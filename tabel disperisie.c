#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    int id;
    struct node_type *left, *right;

} NodeT;
typedef struct node_type2
{
    int id;
    struct node_type *next;

} NodeT2;

NodeT *root;
int B=10;

NodeT *insertNode2( NodeT2 *nod, int key )
{
    if(nod==NULL)
    {
        NodeT2 *p;
        p = ( NodeT2 *) malloc( sizeof( NodeT2 ));
        if ( p == NULL )
            return 0;

        p->id = key;
        p->next = NULL;
        return p;
    }
    else
    {

        NodeT2 *p;
        p = ( NodeT2 *) malloc( sizeof( NodeT2 ));
        if ( p == NULL )
            return 0;

        p->id = key;
        p->next = nod;
        return p;
    }
}


void insertElement(NodeT2* tabel[B], int key)
{

    if(tabel[key%B]==NULL)
        tabel[key%B]=insertNode2(tabel[key%B],key);
    else{
        tabel[key%B]=insertNode2(tabel[key%B],key);
    }



}


NodeT2* findElement(NodeT2* tabel[B], int key)
{

    if(tabel[key%B]==NULL)
        return NULL;
    else{
        NodeT2 *p;
        p=tabel[key%B];
        while(p!=NULL&&p->id!=key)
            p=p->next;
        return p;
    }

}
void deleteElement(NodeT2* tabel[B], int key)
{
    NodeT2 *k;
    NodeT2 *p;

    k=findElement(tabel,key);
    if(k!=NULL)
    {
        if(k->next!=NULL)

            {p=k;
            k=k->next;
            free(p);}
        else{
            free(p);
        }
    }




}



int main()
{


    FILE *f = fopen("ArboreBinar.txt", "r");

    if (!f)
    {
        printf("Nu se poate deschide fisierul ArboreBinar.txt\n");
        return -1;
    }


    int lista_dispersie[7]={-1},c;
    fscanf(f, "%d", &c);

    while(c>=0)
    {
        if(lista_dispersie[c%7]<0)
            lista_dispersie[c%7]=c;
        else{
            int i=1;
            while(lista_dispersie[c%7+i]>=0)
            {
                ++i;
            }
            lista_dispersie[c%7+i]=c;
        }
        fscanf(f, "%d", &c);
    }

    for(int i=0;i<7;++i)
        printf("%d ",lista_dispersie[i]);









    fclose(f);





}
