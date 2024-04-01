/*
getch is a function found in older versions of the C and C++ standard libraries, 
particularly in implementations targeting DOS and Windows environments. It's part 
of the conio.h header file, which stands for "console input/output."

Here's a brief note on getch:

Purpose: The getch function is used to read a single character directly from the 
console without echoing it. This means that when you press a key, getch reads that 
key's ASCII value but does not display it on the screen.

Usage: In a typical scenario, getch is used for console-based applications where 
you need to read input from the user without them having to press Enter after each input. 
This is particularly useful for creating menu-driven programs or interactive command-line interfaces.

Return Value: The return type of getch is int, as it returns the ASCII value of the character 
read. If an error occurs or if the end-of-file (EOF) is reached, getch returns EOF, which is 
usually defined as -1.

Limitations: Since getch is not a standard function defined by the C or C++ standards, its 
behavior and availability may vary across different compilers and platforms. Additionally, 
it's considered a legacy function and is not recommended for modern C++ programming. Instead, 
for console input in modern C++, you would typically use std::cin from the <iostream> header 
or other standard input functions provided by the standard library.
*/

// #include<iostream>
// #include<string.h>
// #include<conio.h>
// using namespace std;

// int main(){
//     char ch;
//     getch();
//     cout << "I" ;
//     getch();
//     cout << " ";
//     getch();
//     cout << "L";
//     getch();
//     cout << "O";
//     getch();
//     cout << "V";
//     getch();
//     cout << "E" ;
//     getch();
//     cout << " " ;
//     getch();
//     cout << "Y";
//     getch();
//     cout << "O";
//     getch();
//     cout << "U";
//     getch();
//     cout << " " ;
//     getch();
//     cout << "A" ;
//     getch();
//     cout << "N";
//     getch();
//     cout << "S";
//       getch();
//     cout << "H";
//       getch();
//     cout << "U";
//   return 0;
// }