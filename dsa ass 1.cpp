#include<iostream>
using namespace std;

class Seat
{
	public:
	int seat_no;
	bool booking_status;
	string passenger_name;
	Seat*next;
	
	Seat(int seatno, bool booking_status, string passenger_name)
	{
		this->seat_no=seat_no;
		this->booking_status=booking_status;
		this->passenger_name=passenger_name;
		next=NULL;
	}
};

class Reservation_list
{
	private:
		Seat*head;
	public:
		Reservation_list()
		{
			head=NULL;
		}
	
		void book_ticket(int seat_no,string passenger_name)
		{
			bool booking_status=true;
			Seat*newNode=new Seat(seat_no, booking_status, passenger_name);
			if(head==NULL)
			{
				head=newNode;
				cout<<"Seat number "<<seat_no<<" is reserved."<<endl;
			}
			else{
				Seat*temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newNode;
			newNode=NULL;
			cout<<"Seat number "<<seat_no<<" is reserved."<<endl;
		  }
		}
		
		void display()
		{
			if(head==NULL)
			{
				cout<<"List is empty."<<endl;
			}
			else
			{
			Seat*temp=head;
			cout<<"      Reserved seats are"<<endl;
			while(temp!=NULL)
			{
				cout<<temp->seat_no<<" ";
				temp=temp->next;
			}
		}
	}
	
	void cancel_ticket(int seat_no)
	{
		Seat*temp=head;
		if(head!=NULL)
		{
		if(head->seat_no==seat_no)
		{
			temp=head;
			head=head->next;
			delete temp;
			temp=NULL;
		}
		else
		{
			while(temp->next!=NULL)
			{
				if(temp->next->seat_no==seat_no)
				{
					Seat*todelete;
					todelete=temp->next;
					temp->next=todelete->next;
					delete todelete;
					todelete=NULL;
					return;
				}
				temp=temp->next;
			}
		}
	}
	else
	{
		cout<<"EMPTY."<<endl;
	}
	}
	
	bool search_seat(int seat_no)
	{
		if(head==NULL)
		{
			cout<<"List is empty";
			return false;
		}
		else
		{
			Seat*temp=head;
			while(temp!=NULL)
			{
				if(temp->seat_no==seat_no)
				{
					return true;
				}
				temp=temp->next;
			}
		}
      	return false;
	}
	
	void update_seat(int seat_no)
	{
		Seat*temp=head;
		if(head==NULL)
		{
			cout<<"list is empty."<<endl;
		}
		else
		{
			Seat*temp=head;
			while(temp!=NULL)
			{
				if(temp->seat_no==seat_no)
				{
				string passenger_name;
				cout<<"Enter new Seat number."<<endl;
				cin>>seat_no;
				cout<<"Enter name of passenger."<<endl;
				cin>>passenger_name;
				
				temp->seat_no=seat_no;
				temp->passenger_name=passenger_name;
				cout<<"Seat is updated."<<endl;
			}
			temp=temp->next;
			}
		}
	}
};

int main()
{
	Reservation_list l;
	int choice;
	int seat_no;
	string passenger_name;
	do
	{
		cout<<"1 Book ticket"<<endl;
		cout<<"2 Display list"<<endl;
		cout<<"3 Search seat"<<endl;
		cout<<"4 Cancel ticket"<<endl;
		cout<<"5 Update ticket"<<endl;
		cout<<"0 Exit"<<endl;
		
		cout<<"Enter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"Enter passenger name: ";
				cin>>passenger_name;
				cout<<"Enter seat number: ";
				cin>>seat_no;
				l.book_ticket(seat_no,passenger_name);
				break;
			case 2:
				l.display();
				cout<<endl;
				break;
			case 3:
				cout<<"Enter seat number to search: "<<endl;
				cin>>seat_no;
				if(l.search_seat(seat_no))
				{
					cout<<"Seat found."<<endl;
				}
				else
				{
					cout<<"Seat not found."<<endl;
				}
				break;
			case 4:
				cout<<"Enter seat number to cancel: ";
				cin>>seat_no;
				l.cancel_ticket(seat_no);
				break;
			case 5:
				cout<<"Enter seat number to update: ";
				cin>>seat_no;
				l.update_seat(seat_no);
				break;
			case 0:
				cout<<"....THE END...."<<endl;
				break;
			default:
			cout<<"invalid choice"<<endl;
			break;	
		}
	}
	while(choice!=0);
	
	return 0;
}

