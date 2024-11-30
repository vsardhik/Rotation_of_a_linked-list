#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
};
struct node *insertatbeg(struct node *head){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Memory is not allocated");
	}
	else{
		printf("Enter info:");
		scanf("%d",&temp->info);
		temp->next=head;
		head=temp;
	}
	return head;
}


struct node *insertatlast(struct node *head){
	struct node *temp,*p1;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Memory is not allocated");
	}
	else if(head==NULL){
		printf("Enter info:");
		scanf("%d",&temp->info);
		temp->next=NULL;
		head=temp;
	}
	else{
		printf("Enter info:");
		scanf("%d",&temp->info);
		temp->next=NULL;
		p1=head;
		while(p1->next!=NULL){
			p1=p1->next;
		}
		p1->next=temp;
	}
	return head;
}

void display(struct node *head){
	struct node *p1;
	if(head==NULL){
		printf("List is empty\n");
	}
	else{
		p1=head;
		while(p1!=NULL){
			printf("%d ",p1->info);
			p1=p1->next;
		}
		printf("NULL\n");
	}
}


struct node *rotate_clock_wise(struct node *head,int k){
	struct node *p1=head;
	if(k==0 || head==NULL)
	return head;
	for(int i=0;i<k;i++){
		while(p1->next!=NULL)
		p1=p1->next;
		p1->next=head;
		p1=p1->next;
		head=head->next;
		p1->next=NULL;
	}
	return head;
	
}




int main(){
struct node *head=NULL;
	int choice;
	char ch;
	do{
		printf("Enter choice\n");
		printf("1.Insert at begning\n");
		printf("2.Insert at Last\n");
		printf("3.Display\n");
		printf("4.Rotate the singly linked list\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				head=insertatbeg(head);
				break;
				case 2:
					head=insertatlast(head);
					break;
					case 3:
						display(head);
						break;
						case 4:
							int k;
							printf("Enter number of rotations (k): ");
                            scanf("%d", &k);
                            head = rotate_clock_wise(head, k);
                            display(head);
                            break;
						default:
							printf("Invalid choice");
							break;
						}
		printf("Do you want to continue? (Y or N): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}

