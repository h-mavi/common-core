# include <iostream>

int main(int argc, char **argv)
{
    int i = -1, x = 1;

    if (argc == 1)
        return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
    while (x != argc)
    {
        while (argv[x][++i] != '\0')
        {
            if (argv[x][i] > 96 && argv[x][i] < 123)
                argv[x][i] -= 32;
        }
        std::cout << argv[x];
        i = -1;
        x++;
    }
    return (std::cout << std::endl, 0);
}
