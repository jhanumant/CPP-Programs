/*--------------------------------------------------------------------
		PROGRAM TO CREATE BIN TREE AND DISPLAY MIRROR IMAGE
		AND ORIGINAL TREE USING BFS ALSO COUNT THE HEIGHT
------------------------------------------------------------------*/
#include<iostream.h>
#include<conio.h>
/*-----------------------------------------------------------------
			CLASS DECLARATION
-----------------------------------------------------------------*/
class bin_tree
{
	private:
		struct node
		{
			int data;
			struct node *lchild,*rchild;
		}*root;
		struct node *queue[20];
		int rear,front,cnt;
	public:
		bin_tree();        	          //CONSTRUCTOR
		void create(void); 	          //TO CREATE BIN TREE
		void display(void);
		void add(node *);
		node* del();
		void bfs(node *);
		void height(void);
		void mirror(node *);
};

bin_tree::bin_tree()
{
	root=NULL;
	rear=-1;
	front=0;
	cnt=0;

}

/*---------------------------------------------------------------------
			TO CREATE BINARY TREE
-----------------------------------------------------------------------*/
void bin_tree::create()
{
	node *temp,*current;
	char ans,c;
	do
	{
	    temp=new node;
	    cout<<"\nEnter the node:-";
	    cin>>temp->data;
	    temp->lchild=NULL;
	    temp->rchild=NULL;
	    if(root==NULL)         //if it is first node
	    {
		root=temp;
	    }
	    else
	    {
		current=root;
		while(1)
		{
			cout<<"\nEnter the side(L/R):-";
			c=getche();
			if(c=='l'||c=='L')
			{
				if(current->lchild==NULL)
				{
					current->lchild=temp;
					break;
				}
				else
				{
					current=current->lchild;
				}
			}
			if(c=='r'||c=='R')
			{
				if(current->rchild==NULL)
				{
					current->rchild=temp;
					break;
				}
				else
				{
					current=current->rchild;
				}
			}
		}
	    }
	    cout<<"\nDo u want to add a new node?(y/n)";
	    ans=getche();
	}while(ans=='y'||ans=='Y');
}
/*------------------------------------------------------------------
			QUEUE OPERATIONS
------------------------------------------------------------------*/
void bin_tree::add(node *temp)
{
	rear=rear+1;
	queue[rear]=temp;
}

node* bin_tree::del()
{
	node *x;
	x=queue[front];
	front=front+1;
	return(x);
}
/*-------------------------------------------------------------------
				BFS
--------------------------------------------------------------------*/
void bin_tree::bfs(node *temp)
{
	cout<<"\n";
	rear=-1;
	front=0;
	add(temp);
	add(NULL);
	while(front!=rear)
	{
		temp=del();
		if(temp!=NULL)
		{
			 cout<<"\t"<<temp->data;
			 if(temp->lchild!=NULL)
				   add(temp->lchild);
			 if(temp->rchild!=NULL)
				   add(temp->rchild);

		}
		else
		{
			cnt++;
			add(NULL);
			cout<<"\n";
		}

	}
}
void bin_tree::height()
{
	cout<<"\nThe height is::"<<cnt;
}
/*-----------------------------------------------------------------
			MIRROR IMAGE
-----------------------------------------------------------------*/
void bin_tree::mirror(node *temp)
{
	node *temp1;
	if(temp->rchild!=NULL&&temp->lchild!=NULL)
	{
		temp1=temp->lchild;
		temp->lchild=temp->rchild;
		temp->rchild=temp1;
		mirror(temp->rchild);
		mirror(temp->lchild);
	}


}
void bin_tree::display()
{
	char ans;
	do
	{
		cout<<"\n1.original\n2.mirror image";
		cout<<"\nEnter your choice::";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:
					cnt=0;
					bfs(root);
					break;
			case 2:
					mirror(root);
					cnt=0;
					bfs(root);
					break;
			default:
					cout<<"\nWrong choice!!!";
					break;
		}
		cout<<"\nDo u want to continue??(y/n)";
		ans=getche();
	}while(ans=='y'||ans=='Y');
}
//============================MAIN===========================
void main()
{
	bin_tree b;
	char ans;
	clrscr();
	do
	{
		cout<<"\n%%%%MENU%%%%";
		cout<<"\n1.create\n2.display\n3.height" ;
		cout<<"\nEnter your choice::";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:
					b.create();
					break;
			case 2:
					b.display();
					break;
			case 3:
					b.height();
					break;
			default:
					cout<<"\nWrong choice!!!";
					break;
		}
		cout<<"\nDo u want to continue?";
		ans=getche();
	}while(ans=='y'||ans=='Y');
	getch();
}
