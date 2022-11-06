#include < stdio.h> //library is closed incorectly 
#pragma warning(disable : 4996) //added pragma

int main() {
	int a = 4, b = 7; //int a had ; insted of , before b which excluded b from the int 
	float c;
	scanf("%f", &c); //& was missing before c 
	if (c == 5)
	{
		printf("%f", c); //added f to change into print f
	}

}
