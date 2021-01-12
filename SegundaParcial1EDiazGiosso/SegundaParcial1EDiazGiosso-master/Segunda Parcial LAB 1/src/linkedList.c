#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL)
	{
        	this->pFirstNode = NULL;
        	this->size = 0;
	}
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{

	Node* nodeAux = NULL;
	int i;
	int len = ll_len(this);


	if(this != NULL && nodeIndex >= 0 && nodeIndex < len)
	{
		nodeAux = this ->pFirstNode;

		for(i = 0; i < nodeIndex; i++)
		{
			nodeAux = nodeAux->pNextNode;
		}
	}
	return nodeAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* pNode = NULL;
    Node* pNodeAux = NULL;

    len = ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= len)
    {
    	pNode = (Node*)malloc(sizeof(Node));

    	if(pNode != NULL)
    	{
    		pNode ->pElement = pElement;

    		if(nodeIndex == 0)
    		{
    			pNode ->pNextNode = this->pFirstNode; // le asigno la posicion de memoria
    			this->pFirstNode = pNode;
    			this->size++;
    			returnAux = 0;
    		}
    		else
    		{
    			pNodeAux = getNode(this,nodeIndex - 1);

    			if(pNodeAux != NULL)
    			{
    				pNode ->pNextNode = pNodeAux->pNextNode; //le asigno un nuevo valor
    				pNodeAux ->pNextNode = pNode;
    				this ->size++;
    				returnAux = 0;
    			}
    		}
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);;

    if(this != NULL)
    {
    	addNode(this,len,pElement);
    	returnAux = 0;
    }


    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index) // obtiene
{
    void* returnAux = NULL;
    int len = ll_len(this);
    Node* nodeAux;

    if(this != NULL && index >= 0 && index < len )
    {
    	nodeAux = getNode(this,index);				// valor guardado = asignar valor de la izq  	. referencia de campo de estructura     ->
    	returnAux = nodeAux->pElement;
    }
    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement) // carga
{
    int returnAux = -1;
    int len = ll_len(this);
    Node* nodeAux = NULL;

    if(this != NULL && index >= 0 && index <= len)
    {
    	nodeAux = getNode(this,index);

    	if(nodeAux != NULL)
    	{
    		nodeAux->pElement = pElement;
			returnAux = 0;
    	}

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodeAux;
    Node* nodeRemove;

    int len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	nodeAux = getNode(this,index);

    	if(index == 0)
    	{
    		this->pFirstNode = nodeAux->pNextNode;
    	}
    	else
    	{
    		nodeRemove = getNode(this,index-1);
    		nodeRemove->pNextNode = nodeAux->pNextNode;
    	}

    	free(nodeAux);
    	this->size--;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista(empieza desde el final hasta el principio)
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len = ll_len(this);


    if(this != NULL && len >= 0)
    {
    	int i;

    	for(i = len; i >= 0;i++)
    	{
    		ll_remove(this,len-1);
    		free(this);
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int i;
    int returnAux = -1;
    int len = ll_len(this);
    Node* nodeAux = NULL;

    if(this != NULL && pElement != NULL)
    {
    	for(i = 0; i < len; i++)
    	{
    		nodeAux = getNode(this,i);

    		if(nodeAux != NULL)
    		{
    			if(nodeAux->pElement == pElement)
				{
    				returnAux = i;
    				break;
				}

    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len = ll_len(this);

    if(this != NULL && len > 0 )
    {
    		returnAux = 0;
    }
    else
    {
    		returnAux = 1;
    }


    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    if(this != NULL && index <= len && index >= 0)
    {
    	if(addNode(this,index,pElement)== 0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    int len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	 returnAux = ll_get(this, index);

    	if(returnAux != NULL)
		{
			ll_remove(this, index);

		}

    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_indexOf(this,pElement) != -1)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len = ll_len(this);
    int len2 = ll_len(this2);
    void* aux;
    int i;

    if(this != NULL && this2 != NULL)
    {
    	if(len != len2)
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		for (i=0;i < len2; i++)
    		{
    			aux = ll_get(this2,i);

    			if(ll_contains(this,aux) == 0)
				{
    				returnAux = 0;
				}
    		}
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    int i;
    void* aux;

    if(this != NULL && from >= 0 && from < len && to > from && to <= len)
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for(i = from; i < to; i++)
			{
    			aux = ll_get(this,i);
    			ll_add(cloneArray,aux);
			}
    	}
	}
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);

    if(this != NULL)
    {
    	cloneArray = ll_subList(this,0,len);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*fn) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int i;
    int flag;
    int len = ll_len(this);
    void* aux;
    void* element1;
	void* element2;

    if(this != NULL && (order == 1 ||order == 0) && pFunc != NULL)
    {
    	if (len >= 1)
    	{
			do
			{
				flag = 0;

				for(i=0; i < len - 1; i++)
				{
					element1 = ll_get(this,i);
					element2 = ll_get(this,i+1);

					if((pFunc(element1,element2) < 0 && order == 0) || (pFunc(element1,element2) > 0 && order == 1))
					{
						aux = element1;
						ll_set(this,i,element2);
						ll_set(this,i + 1,aux);
						flag = 1;
					}
				}
			}while(flag == 1);
    	}
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Mapea los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*fn) Puntero a la funcion criterio
 * \return int Retorna
 */

int ll_map(LinkedList* this,int(*fn)(void* element))
{
	int back = -1;
	int i;
	int len = ll_len(this);

	if(this != NULL && fn != NULL)
	{
		back = 0;

		for(i=0; i < len; i++)
		{
			fn(ll_get(this,i));
		}
	}
	return back;
}

/**
 * \brief Determina si el elemento se encuentra o no en la lista, devolviendo su resultado.
 * 		  Agrega una nueva lista si devuelve verdadero.
 *	\param pList LinkedList* Puntero a la lista.
 *	\param pFunc (*fn) Puntero a la funcion.
 *	\return (-1) Error: si alguno de los punteros a la lista o el puntero a funcion son NULL
 *			(0) Agregando los elementos de this contenidos en la lista.
 */

LinkedList* ll_filter(LinkedList* this,int(*fn)(void*))
{
	LinkedList* list = NULL;
	int i;
	int len = ll_len(this);
	void* element;

	if(this != NULL && fn != NULL)
	{
		list = ll_newLinkedList();

		if(list != NULL)
		{
			for(i=0; i < len; i++ )
			{
				element = ll_get(this,i);

				if(fn(element))
				{
					ll_add(list, element);
				}
			}
		}
	}
	return list;
}

/** \brief Cuenta los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*fn) Puntero a la funcion criterio
 * \return int -1 error, retorno numero positivo el conteo
 */

int ll_count(LinkedList* this,int(*fn)(void* element))
{
	int back = -1;
	int i;
	int len = ll_len(this);

	if(this != NULL && fn != NULL)
	{
		back = 0;

		for(i = 0; i < len; i++)
		{
			back = back + fn(ll_get(this,i));
		}
	}
	return back;
}
