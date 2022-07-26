unsigned char swap_bits(unsigned char c)
{
	return ((c >> 4) | (c << 4));
}

// int main()
// {
// 	int num = 2;
// 	int n = swap_bits(num);
// 	printf("number before bit swap %d\n", num);
// 	printf("bits before swap ");
// 	print_bits(num);
// 	printf("\nnumber after bit swap %d\n", n);
// 	printf("bits after swap\t");
// 	print_bits(n);
// 	return (0);
// }
