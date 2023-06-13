#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Paratha{
    int qnty;
    int price;
};

struct Vegetable{
    int qnty;
    int price;
};

struct MineralWater{
    int qnty;
    int price;
};

int main(){
    float total;

    struct Paratha paratha;
    printf("Quantity of Paratha: ");
	scanf("%d",&paratha.qnty);
	printf("Unit price: ");
	scanf("%d",&paratha.price);

    struct Vegetable vegetable;
    printf("Quantity of Vegetable: ");
	scanf("%d",&vegetable.qnty);
	printf("Unit price: ");
	scanf("%d",&vegetable.price);

    struct MineralWater mineralwater;
    printf("Quantity of Mineral water: ");
	scanf("%d",&mineralwater.qnty);
	printf("Unit price: ");
	scanf("%d",&mineralwater.price);

    int people;
    printf("Number of people: ");
	scanf("%d",&people);

    total = (paratha.qnty*paratha.price + vegetable.qnty*vegetable.price + mineralwater.qnty*mineralwater.price);
    float final = total / people;
    printf("Individual people will pay: %.2f tk",final);

    return 0;
}