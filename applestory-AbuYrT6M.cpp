#include<iostream>
using namespace std;
void Run(void);

int main(int argc, char*argv[])
{
	Run();
	return 0;
}

void Run(void)
{
	int apples;
	char *name = new char[32];
	
	printf("Please enter your name: ");scanf("%s", name);
	printf("Please enter how many apples you picked: ");scanf("%d", &apples);
	
	printf("Apple Picking Story\n\n");
	printf("%s picked %d apples in this story.\n", name, apples);
	printf("The End!\n\n");
	printf("P.S. Steve Jobs died.\n");
}
