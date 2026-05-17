#include<stdio.h>

int main()
{
    int page_size,logical,frame,page,offset,physical;

    printf("Enter page size: ");
    scanf("%d",&page_size);

    printf("Enter logical address: ");
    scanf("%d",&logical);

    printf("Enter frame number: ");
    scanf("%d",&frame);

    page=logical/page_size;
    offset=logical%page_size;

    physical=(frame*page_size)+offset;

    printf("Page Number = %d\n",page);
    printf("Offset = %d\n",offset);
    printf("Physical Address = %d\n",physical);

    return 0;
}