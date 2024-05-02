#include <iostream>
#include <unistd.h>
using namespace std;

static int slash_n(int i, int k, char *s) {
    while (s[i--] != '\n')
        k--;
    return(k);
}

static char *ft_utf_rus(char *buf, size_t k, int fd, size_t l)
{
    char *s = new char [l + 1];
    size_t i = read(fd, s, l);
    s[l] = '\0';
    k += i;
    if (i == l && s[i - 1] != '\n')
        buf = ft_utf_rus(buf, k, fd, l);
    else
    {
        k = slash_n(i, k, s);
        buf = new char [++k];
        buf[k] = '\0';
    }
    while (i != 0)
        buf[--k] = s[--i];
    delete []s;
    return(buf);
}

char *ft_cin() {
    char *s;
    return(ft_utf_rus(s, 0, 0, 1024));
}

char *ft_cin(size_t buf_size)
{
    char *s;
    if (buf_size ==0)
        return (ft_utf_rus(s, 0, 0, 1024));
    return(ft_utf_rus(s, 0, 0, buf_size));
}


int main()
{
    int i = 0;

    do {
        cout << "Для шифрования введите 1. Для дешифровки 2. Для выхода 0." << endl;
        cin >> i;
        if ( i == 1)
        {
            cout << "Введите размер сдвига" << endl;
            cin >> i;
            cout << "Введите строку" << endl;
            char *s = ft_cin(10);
            for (int k = 0; s[k] != '\0';)
            {
                if ((s[k] + i > 90 && s[k] < 97) || (s[k] + i > 122))
                    s[k] = s[k] - 26;
                s[k] += i;
                k++;
            }
            cout << endl << "Результат:" << endl << s << endl << endl;
            delete []s;
        }
        else if (i == 2)
        {
            cout << "Введите размер сдвига" << endl;
            cin >> i;
            cout << "Введите строку" << endl;
            char *s = ft_cin(10);
            for (int k = 0; s[k] != '\0';)
            {
                if (s[k] - i < 65 || (s[k] - i < 97 && s[k] > 90))
                    s[k] = s[k] + 26;
                s[k] -= i;
                k++;
            }
            cout << endl << "Результат:" << endl << s << endl << endl;
            delete []s;
        }
        else
            cout << "Извините. Такая функция пока не представлена." << endl;
    } while (i != 0);
    return 0;
}