#include "stdio.h"
#include "conio.h"
#include "iostream"

using namespace std;

//Khai báo cấu trúc dữ liệu danh sách liên kết đơn dữ liệu có sẵn

 struct NODE
{

	int data;
	NODE *pNext;
};
 struct List
{

	 NODE *pHead;
	 NODE *pTail;
};

 // Khoi tao danh sach lien ket
 void initLinkList(List& list){
	
	 list.pHead = list.pTail = NULL;
 }
 
 bool isEmpty(List list){
	
	 if (list.pHead == NULL){
		
		 
		 return true;
	 }
	 return false;
 }

 NODE* getNode(int data){
	
	 NODE *p = new NODE;
	 p->data = data;
	 p->pNext = NULL;
	 return p;
 }
 void addHeadNode(List &list, int data){

	 NODE *p = getNode(data);
	 if (isEmpty(list)){

		 list.pHead = list.pTail = p;

	 }
	 else{
		
		 p->pNext = list.pHead;
		 list.pHead = p;
	 }
 }

 void addTailNode(List &list, int data){

	 NODE *p = getNode(data);
	 if (isEmpty(list)){

		 list.pHead = list.pTail = p;

	 }
	 else{

		 list.pTail->pNext = p;
		 list.pTail = p;
	 }
 }
 void showList(List list){
	
	 for (NODE *p = list.pHead; p != NULL; p = p->pNext){

		 cout << p->data << "\t";
	 }
 }

 NODE* searchNode(List list, int x){
	
	 for (NODE *p = list.pHead; p != NULL; p = p->pNext){
		
		 if (p->data == x){
			
			 return p;
		 }
	 }
	 return NULL;
 }
 void addNodeLastNode(List &list, int y, int x){
	
	 NODE *q = searchNode(list, y);
	 if (q == NULL){
		
		 cout << "NOt found node with data! \n";
	 }
	 else
	 {
		 NODE *p = getNode(x); 
		 p->pNext = q->pNext;
		 q->pNext = p;

	 }
 }
 void addNodeFirstNode(List &list, int y, int x){

	 NODE *q = searchNode(list, y);
	 if (q == NULL){

		 cout << "NOt found node with data! \n";
	 }
	 else
	 {
		 NODE *z = list.pHead;
		 NODE *p = getNode(x);
		 while (z->pNext != q)
		 {
			 z = z->pNext;
		 }
		 z->pNext = p;
		 p->pNext = q;

	 }
 }

 void deleteNodeHead(List &list){
	
	 if (isEmpty(list)){
		
		 return;
	 }
	 else
	 {
		 NODE *p = list.pHead;
		 list.pHead = list.pHead->pNext;
		 delete p;
	 }
 }
 void deleteNodeTail(List &list){
	
	 if (isEmpty(list)){

		 return;
	 }
	 else
	 {
		 NODE *p = list.pHead;
		 while (p->pNext != list.pTail)
		 {
			 p = p->pNext;
		 }
		 p->pNext = NULL;
		 list.pTail = p;
	 }
 }

 void deleteNodeX(List &list, int x){

	 NODE *q = searchNode(list, x);
	 if (q == list.pHead){

		 deleteNodeHead(list);
	 }
	 else if (q == list.pTail)
	 {
		 deleteNodeTail(list);
	 }
	 else
	 {
		 NODE *z = list.pHead;
		 while (z ->pNext != q)
		 {
			 z = z->pNext;
		 }
		 z->pNext = q->pNext;
		 delete q;
	 }
 }
 void clearNodeAll(List &list){
	
	 while (isEmpty(list) == false){
		
		 deleteNodeHead(list);
	 }
}
 
int main(){

	List list;
	initLinkList(list);
	int data;
	//int y, x;
	int choice;
	do
	{
		system("ls");
		cout << "0. Thoat\n\n";
		cout << "1. Add head\n\n";
		cout << "2. Add Tail\n\n";
		cout << "3. Is Empty\n\n";
		cout << "4. Show list\n\n";
		cout << "5. Add Node first Node\n\n";
		cout << "6. Add Node Last Node\n\n";
		cout << "7. Delete Node Head\n\n";
		cout << "8. Delete Node Tail\n\n";
		cout << "9. Delete Node X\n\n";
		cout << "10. Clear Node All\n\n";
		cout << "Make your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			break;
		case 1:
			cout << "Input data\n";
			cin >> data;
			addHeadNode(list, data);
			break;
		case 2:
			cout << "Input data\n";
			cin >> data;
			addTailNode(list, data);
			break;
		case 3:
			if (isEmpty(list)){

				cout << "Link list empty ! \n";
			}
			else
			{
				cout << " List has Node ! \n";
			}
			system("pause");
			break;
		case 4:
			showList(list);
			system("pause");
			break;
		case 5:
			{
				 int y, x;
				 cout << "Input data of Node q: \n";
				 cin >> y;
				 cout << "Input data of Node p: \n";
				 cin >> x;
				 addNodeFirstNode(list, y, x);
				 system("pause");
			}
			break;
		case 6:
			{
				  int y, x;
				  cout << "Input data of Node q: \n";
				  cin >> y;
				  cout << "Input data of Node p: \n";
				  cin >> x;
				  addNodeLastNode(list, y, x);
				  system("pause");
			}
			
			break;
		case 7:
			{
				  deleteNodeHead(list);
			}
			break;
		case 8:
			{
				  deleteNodeTail(list);
			}
			break;

		case 9:
			int i;
			cout << "Input i = ";
			cin >> i;
			NODE *q = searchNode(list, i);
			while (q != NULL)
			{
				deleteNodeX(list, i);
				q = searchNode(list, i);
			}
			break;
		case 10:
			clearNodeAll(list);
			break;
		default:
			break;
		}

	} while (choice != 0);

	return 0;
}