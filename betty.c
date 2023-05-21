/**
 * add_numbers - Adds two numbers
 * @num1: The first number
 * @num2: The second number
 *
 * Return: The sum of the two numbers
 */
int add_numbers(int num1, int num2)
{
	return (num1 + num2);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int num1 = 10;
	int num2 = 20;
	int sum;

	sum = add_numbers(num1, num2);

	return (0);
}

