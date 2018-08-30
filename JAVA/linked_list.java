import java.util.Scanner;
class node{
	public int data;
	public node next;
	
	public node(int item)
	{
		data=item;
		next=null;
	}
}
class link_list{ 
	private node head;
	Scanner sc=new Scanner(System.in);
	public link_list()
	{
		head=null;
	}
	public void create_node()
	{
		System.out.println("Do you want to create a node ? (1/0)");
		int ch;
		ch=sc.nextInt();
		while(ch==1)
		{
			System.out.println("Enter the Data");
			int data=sc.nextInt();
			node link1=new node(data);
			node p;
		if(head==null)
			head=link1;
		else
		{
			p=head;
			while(p.next!=null)
			{
				p=p.next;
			}
			p.next=link1;
		}
		System.out.println("Do you want to create a node ? (1/0)");
		ch=sc.nextInt();
		}
	}
	public void insert_beg(){
		System.out.println("Enter the Data");
		int data=sc.nextInt();
		node link1=new node(data);
		if(head==null)
			head=link1;
		else
		{
			link1.next=head;
			head=link1;
		}
	}
	public void insert_end()
	{
		System.out.println("Enter the Data");
		int data=sc.nextInt();
		node link1=new node(data);
		if(head==null)
			head=link1;
		else if(head.next==null)
		{
			head.next=link1;
		}
		else
		{
			node p=head;
			while(p.next!=null)
			{
				p=p.next;
			}
			p.next=link1;
		}
	}
	public int length()
	{
		int ctr=0;
		node p=head;
		while(p!=null){
			ctr++;
			p=p.next;
			}
		//System.out.println("Length of the list is "+ctr);
		return ctr;
	}
	public void insert_at_pos(int pos)
	{
		
		if((pos < 1 ) || (pos > length()+1))
		{
			System.out.println("Invalid Position");
			return;
		}
		if(pos==1)
			insert_beg();
		else if(pos==length()+1)
			insert_end();
		else
		{
			System.out.println("Enter the Data");
			int data=sc.nextInt();
			node link1=new node(data);
			int ctr=1;
			node p=head;
			while(ctr<pos-1)
			{
				p=p.next;
				ctr++;
			}
			link1.next=p.next;
			p.next=link1;
		}
	}
	public void delete_beg()
	{
		if(head==null)
			return;
		else if(head.next==null)
			head=null;
		else
			head=head.next;
	}
	public void delete_end()
	{
		if(head==null)
			return;
		else if(head.next==null)
			head=null;
		else
		{
			node p=head,q=head;
			while(p.next!=null)
			{
				q=p;
				p=p.next;
			}
			q.next=null;
		}
	}
	public void delete_at_pos(int pos)
	{
		if(pos<1 || pos>length()){
			System.out.println("Invalid Position");
			return;
			}
		if(pos==1)
			delete_beg();
		else if(pos==length())
			delete_end();
		else
		{
			int ctr=1;
			node p=head,q=head;
			while(ctr<pos)
			{
				q=p;
				p=p.next;
				ctr++;
			}
			q.next=p.next;
		}
	}
	public void display()
	{
		node p=head;
		if(length()==0){
			System.out.println("List is Empty\n");
			return;
			}
		while(p!=null){
			System.out.print(p.data+" ");
			p=p.next;
			}
		System.out.println();
	}
}
public class example_5_1 {
	public static void main(String[] args) {
		link_list ob1 =new link_list();
		Scanner sc=new Scanner(System.in);
		System.out.println("\nEnter the choice");
		System.out.println("1. Create Node");
		System.out.println("2. Insert at Beginning");
		System.out.println("3. Insert at End");
		System.out.println("4. Insert at any Position");
		System.out.println("5. Delete at  Beginning");
		System.out.println("6. Delete at End");
		System.out.println("7. Delete at any Position");
		System.out.println("5. Display List");
		int ch;
		ch=sc.nextInt();
		while(ch!=0)
		{
			switch(ch)
			{
				case 1:ob1.create_node();
					   break;
				case 2:ob1.insert_beg();
					   break;
				case 3:ob1.insert_end();
				   	   break;
				case 4:System.out.println("\nEnter the position");
					   int p=sc.nextInt();
					   ob1.insert_at_pos(p);
					   break;
				case 5:ob1.delete_beg();
			   	   	   break;
				case 6:ob1.delete_end();
					   break;
				case 7:System.out.println("\nEnter the position you want to delete");
					   int q=sc.nextInt();
					   ob1.delete_at_pos(q);
		   	   	  	   break;   
				case 8 :ob1.display();
					   break;		   
			}
			System.out.println("\nEnter the choice");
			System.out.println("1. Create Node");
			System.out.println("2. Insert at Beginning");
			System.out.println("3. Insert at End");
			System.out.println("4. Insert at any Position");
			System.out.println("5. Delete at  Beginning");
			System.out.println("6. Delete at End");
			System.out.println("7. Delete at any Position");
			System.out.println("8. Display List");
			ch=sc.nextInt();
		}		
	}

}