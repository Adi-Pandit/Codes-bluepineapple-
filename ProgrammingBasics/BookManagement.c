#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BookDetails 
{
    int bookId;
    char book[100];
    char author[100];
    struct BookDetails *next;
}*first=NULL,*last=NULL;

struct Student
{
    int bookIssuedId;
    char bookIssued[100];
    char authorIssuedBook[100];
    struct Student *next;
}*head=NULL,*tail=NULL;

int BookId = 1;

void DisplayBooks(struct BookDetails *p)
{
    printf("\nBook Id\tBook name\tAuthor name");
    while(p!=NULL)
    {
        printf("\n%d\t\t%s\t\t%s",p->bookId,p->book,p->author);
        p = p->next;
    }
}

void DisplayIssuedBooks(struct Student *p)
{
    printf("\nBook Id\tBook name\tAuthor name");
    while(p!=NULL)
    {
        printf("\n%d\t\t%s\t\t%s",p->bookIssuedId,p->bookIssued,p->authorIssuedBook);
        p = p->next;
    }
}

void AddBook()
{
    struct BookDetails *temp = (struct BookDetails *)malloc(sizeof(struct BookDetails));
    printf("\nBook id : %d",BookId);
    temp->bookId = BookId;
    printf("\nEnter book name : ");
    scanf("%s",temp->book);
    printf("Enter book author name : ");
    scanf("%s",temp->author);
    temp->next = NULL;
    if(first==NULL)
        first=last=temp;
    else
    {    
        last->next=temp;
        last=temp;
    }
    BookId++;
}

void SearchByAuthor(struct BookDetails *p, char AuthorName[])
{
    printf("\nSearch Result for Author Name %s\n",p->author);
    int flag=0;
    while(p!=NULL)
    {
        if(strcmp(p->author,AuthorName)==0)
        {
            printf("%s",p->book);
            flag = 1;
        }
        p=p->next;
    }
    if(flag==0)
        printf("No Book Found");
}

void SearchByBook(struct BookDetails *p, char BookName[])
{
    printf("\nSearch Result for Book Name %s\n",p->book);
    int flag=0;
    while(p!=NULL)
    {
        if(strcmp(p->book,BookName)==0)
        {
            printf("%s by %s",p->book,p->author);
            flag = 1;
        }
        p=p->next;
    }
    if(flag==0)
        printf("No Book Found");
}

void IssueBook(struct BookDetails *p)
{
    int id;
    DisplayBooks(first);
    struct Student *temp = (struct Student *)malloc(sizeof(struct Student));
    struct BookDetails *q= NULL;
    printf("\nEnter book id : ");
    scanf("%d",&id);

    while(p!=NULL)
    {
        if(p->bookId==id)
        {
            temp->bookIssuedId = id;
            strcpy(temp->bookIssued,p->book);
            strcpy(temp->authorIssuedBook,p->author);
            break;
        }
        p=p->next;
    }
    temp->next = NULL;
    if(head==NULL)
        head=tail=temp;
    else
    {    
        tail->next=temp;
        tail=temp;
    }
    DisplayIssuedBooks(head);
    p = first;
    if(p->bookId==id)
    {
        q = first;
        first = first->next;
        free(q);
    }
    else
    {
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
            if(p->bookId==id)
                break;
        }
        q->next = p->next;
        free(p);
    }
}

void ReturnBook(struct Student *p)
{
    DisplayIssuedBooks(head);
    struct BookDetails *temp = (struct BookDetails *)malloc(sizeof(struct BookDetails));
    struct Student *q= NULL;
    int id;
    printf("\nEnter book id : ");
    scanf("%d",&id);

    while(p!=NULL)
    {
        if(p->bookIssuedId==id)
        {
            temp->bookId = id;
            strcpy(temp->book,p->bookIssued);
            strcpy(temp->author,p->authorIssuedBook);
            break;
        }
        p=p->next;
    }
    temp->next = NULL;
    if(first==NULL)
        first=last=temp;
    else
    {    
        last->next=temp;
        last=temp;
    }
    DisplayBooks(first);
    p = head;
    if(p->bookIssuedId==id)
    {
        q = head;
        head = head->next;
        free(q);
    }
    else
    {
        int i;
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
            if(p->bookIssuedId==id)
                break;
        }
        q->next = p->next;
        free(p);
    }
}

int main()
{
    int choice;
    char AuthorName[30];
    char BookName[30];
    do 
    {
        printf("\n\n1.Add Book\n2.Display Book\n3.Search By Author Name \n4.Search By Book Name\n5.Issue Book\n6.Return Book\n7.Exit\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                AddBook();
                break;
            case 2:
                printf("\nDisplaying books : ");
                DisplayBooks(first);
                break;
            case 3:
                printf("Enter Author Name : ");
                scanf("%s",AuthorName);
                SearchByAuthor(first,AuthorName);
                break;
            case 4:
                printf("Enter Book Name : ");
                scanf("%s",BookName);
                SearchByBook(first,BookName);
                break;
            case 5:
                IssueBook(first);
                break;
            case 6:
                ReturnBook(head);
                break;
            case 7: 
                break;
        }    
    } while(choice!=7);
}