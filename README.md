<img title="42_GNL" alt="42_GNL" src="./subject/banner.png" width="100%">

|          Grade          |          Tests          |
|:-----------------------:|:-----------------------:|
| ![](./subject/grade.png) | ![](./subject/detail.png) |

<br>

---

<details>
<summary>🇫🇷 FRENCH VERSION</summary>

<p align="center">
	Il s'agit du deuxième <a href="./subject/Get_Next_Line.fr.subject.pdf">projet</a> de l'école 42 (réalisé en novembre 2023). 
</p>

## Préambule
Le but est d’implémenter une fonction en C qui lit un fichier ligne par ligne, sans charger le fichier entier en mémoire. Ce projet vous apprend à manipuler les file descriptors, les variables statiques et la gestion de la mémoire.

## Fonction:
```c
char *get_next_line(int fd);
```
- Retourne une chaîne se terminant par `\n` lue depuis le file descriptor `fd`.
- Retourne `NULL` si la fin du fichier est atteinte ou en cas d'erreur.
- Une version `bonus` est également disponible, prenant en charge plusieurs file descriptors simultanément.

## Installation
```bash
git clone https://github.com/N0fish/GetNextLine.git
cd GetNextLine
```

Pour la partie obligatoire :
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

Pour la version bonus :
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

</details>

---

<details>
<summary>🇬🇧 ENGLISH VERSION</summary>

<p align="center">
	This is the second <a href="./subject/Get_Next_Line.en.subject.pdf">project</a> at 42 School (completed in November 2023).
</p>

## Preamble
The goal is to implement a function in C that reads a file line by line, without loading the entire file into memory. This project teaches how to work with file descriptors, static variables, and memory management.

## Function:
```c
char *get_next_line(int fd);
```
- Returns a string ending with `\n` read from the file descriptor `fd`.
- Returns `NULL` if the end of file is reached or an error occurs.
- A `bonus` version is also implemented, supporting multiple file descriptors simultaneously.

## Installation
```bash
git clone https://github.com/N0fish/GetNextLine.git
cd GetNextLine
```

For the mandatory part:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

For the bonus version:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

</details>

---

<details>
<summary>🇷🇺 RUSSIAN VERSION</summary>

<p align="center">
	Это второй <a href="./subject/Get_Next_Line.en.subject.pdf">проект</a> в школе 42 (выполненный в ноябре 2023 года).
</p>

## Преамбула
Цель — реализовать функцию на C, которая читает файл построчно, без загрузки всего файла в память. Проект учит работе с файловыми дескрипторами, статическими переменными и управлением памятью.

## Функция
```c
char *get_next_line(int fd);
```
- Возвращает строку, заканчивающуюся `\n`, считанную из дескриптора файла `fd`.
- Возвращает `NULL`, если достигнут конец файла или произошла ошибка.
- Также реализована `bonus`-версия, поддерживающая множество дескрипторов файлов одновременно.

## Установка
```bash
git clone https://github.com/N0fish/GetNextLine.git
cd GetNextLine
```

Для обязательной части:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

Для bonus-версии:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

</details>

---

<br>

<a name="functions"></a>
## GNL functions

| gnl functions                                    | gnl_bonus functions                                        |
| ------------------------------------------------ | ---------------------------------------------------------- |
| [get_next_line.c](get_next_line.c)               | [get_next_line_bonus.c](get_next_line_bonus.c)             |
| [get_next_line_utils.c](get_next_line_utils.c)   | [get_next_line_utils_bonus.c](get_next_line_utils_bonus.c) |
| [get_next_line.h](get_next_line.h)               | [get_next_line_bonus.h](get_next_line_bonus.h)             |
