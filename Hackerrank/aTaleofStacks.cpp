/* Accepted */
#include <iostream>
using namespace std;
template <class T>
struct Stack
{
    public:
        struct node{
            T data;
            node *next;
            node(T valor)
            {
                data = valor;
                next = NULL;
            }
        };
        node *tope = NULL;
        int tam;
        Stack()
        {
            tam = 0;
            tope = NULL;
        }

        bool esVacia()
        {
            return tam == 0;
        }

        int size()
        {
            return tam;
        }

        T top()
        {
            return tope -> data;
        }

        void pop()
        {
            if(!esVacia())
            {
                tope = tope -> next;
                tam--;
            }
        }

        void push(T value)
        {
            node *nuevo = new node(value);
            if(esVacia())
            {
                tope = nuevo;
                tam++;
            }
            else
            {
                nuevo -> next = tope;
                tope = nuevo;
                tam++;
            }
        }

        void vaciar()
        {
            while(!esVacia())
                pop();
            tam = 0;
        }

};

template <class T>
struct Queue
{
    public:
        struct node{
            T data;
            node *next;
            node *before;
            node(T valor)
            {
                data = valor;
                next = NULL;
                before = NULL;
            }
        };
        node *entra, *sale;
        int tam;
        Queue()
        {
            tam = 0;
            entra = NULL;
            sale = NULL;
        }

        bool esVacia()
        {
            return tam == 0;
        }

        int size()
        {
            return tam;
        }

        void pushBack(T val)
        {
            node *aux = new node(val);
            if(esVacia())
            {
                entra = aux;
                sale = aux;
                tam++;
            }
            else
            {
                aux -> next = entra;
                aux -> next -> before = aux;
                entra = aux;
                tam++;
            }
        }

        void pushFront(T val)
        {
            node *aux = new node(val);
            if(esVacia())
            {
                entra = aux;
                sale = aux;
                tam++;
            }
            else
            {
                aux -> before = sale;
                aux -> before -> next = aux;
                sale = aux;
                tam++;
            }
        }

        T front()
        {
            return sale -> data;
        }

        T back()
        {
            return entra -> data;
        }

        void popFront()
        {
            sale = sale -> before;
            tam--;
        }

        void popBack()
        {
            entra = entra -> next;
            tam--;
        }
};
//My Queue
/*
int main(void)
{
    int q, tipo, aux;
    cin >> q;
    Queue <int> *entrada = new Queue<int> ();
    while(q--)
    {
        cin >> tipo;
        if(tipo == 1)
        {
            cin >> aux;
            entrada -> pushBack(aux);
        }
        else if(tipo == 2)
        {
            entrada -> popFront();
        }
        else if(tipo == 3)
        {
            cout << entrada -> front() << "\n";
        }
    }
}
*/
//2 stacks
int main(void)
{
    int q, tipo, aux;
    cin >> q;
    Stack <int> *primera = new Stack<int> ();
    Stack <int> *segunda = new Stack<int> ();
    while(q--)
    {
        cin >> tipo;
        if(tipo == 1)
        {
            cin >> aux;
            primera -> push(aux);
        }
        else if(tipo == 2)
        {
            if(segunda -> esVacia())
                while(!primera -> esVacia())
                {
                    segunda -> push(primera -> top());
                    primera -> pop();
                }
            segunda -> pop();
        }
        else if(tipo == 3)
        {
            if(segunda -> esVacia())
                while(!primera -> esVacia())
                {
                    segunda -> push(primera -> top());
                    primera -> pop();
                }
            cout << segunda -> top() << "\n";
        }
    }
}
