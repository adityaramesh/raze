/*
** File Name:	id_creation.cpp
** Author:	Aditya Ramesh
** Date:	07/27/2013
** Contact:	_@adityaramesh.com
*/

template <class Char, class... Chars>
struct basic_string {};

template <class Char, Char... Chars>
constexpr basic_string<Char, Char...> operator"" _id()
{ return basic_string<Char, Chars...>{}; }

int main()
{

}
