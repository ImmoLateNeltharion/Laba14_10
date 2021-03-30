#include <iostream>
#include <ctime>
using namespace std;
struct Node //описание узла списка
{
	int data; //информационное поле
	Node* next; //указатель на следующий элемент
};

struct Queue //описание очереди
{
	int size; //счетчик размера очереди
	Node* first; //указатель на начало очереди
	Node* last; //указатель на конец очереди
};

void Creation(Queue* Q) //создание очереди
{
	
	Q->first = new Node;
	Q->first->next = NULL;
	Q->last = Q->first;
	Q->size = 0;
	Q->first->data = rand() % 101 - 50;						//из-за функции Creation выводится мусор, так как first создается там, но не присваивается
}

bool Full(Queue* Q) //проверка очереди на пустоту
{
	if (Q->first == Q->last) return true;
	else return false;
}

void Add(Queue* Q) //добавление элемента
{
	int value;
	cout << "\nЗначение > "; cin >> value;
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data = value; //добавление элемента в конец
	Q->last->next = NULL; //обнуление указателя на следующий элемент
	Q->size++;
	cout << "\nЭлемент добавлен\n\n";
}

void AddNew(Queue *Q, int value)
{
	
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data = value; //добавление элемента в конец
	Q->last->next = NULL; //обнуление указателя на следующий элемент
	Q->size++;
}

void Delete(Queue* Q) //удаление элемента
{
	Q->first = Q->first->next; //смещение указателя
	Q->size--;
	cout << "\nЭлемент удален\n\n";
}

void Print(Queue *Q) 
{
	struct Node* i;
	for (i = Q->first; i != NULL; i = i->next)
	{
		cout << i->data << " ";
	}
	cout << endl;
}		

int Size(Queue* Q) //размер очереди
{
	return Q->size;
}

void Swap(Queue* Q)
{
	swap(Q->first->data, Q->last->data);
}

void main() //главная функция
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	Queue Q;
	Creation(&Q);
	char number;
	do{
		cout << "1. Удалить элемент" << endl;
		cout << "2. Вывести очередь" << endl;
		cout << "3. Узнать размер очереди" << endl;
		cout << "4. Заполнить 10-ю  рандомными числами" << endl;
		cout << "5. Поменять местами первый и последний элемент" << endl;
		cout << "0. Выйти\n\n";
		cout << "Номер команды > "; cin >> number;
		switch (number)
		{

		case '1':
			if (Full(&Q)) cout << endl << "Очередь пуста\n\n";
			else Delete(&Q);
			break;
			//-----------------------------------------------
		case '2':
			if (Full(&Q)) cout << endl << "Очередь пуста\n\n";
			else	Print(&Q);
			break;
			//-----------------------------------------------
		case '3':
			if (Full(&Q)) cout << endl << "Очередь пуста\n\n";
			else cout << "\nРазмер очереди: " << Size(&Q) << "\n\n";
			break;
			//-----------------------------------------------
		case '4':
			
			for (int i = 0; i < 10; i++) 			
				AddNew(&Q, rand() % 101 - 50);
		case '5': Swap(&Q);
		case '0': break;
		default: cout << endl << "Команда не определена\n\n";
			break;
		}
	} while (number != '0');
}