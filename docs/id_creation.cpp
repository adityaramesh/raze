/*
** File Name:	id_creation.cpp
** Author:	Aditya Ramesh
** Date:	07/27/2013
** Contact:	_@adityaramesh.com
*/

#include <cstdint>
#include <iostream>
#include <typeinfo>

struct string
{
	const uintmax_t m_str[64];
	const size_t m_length;

	template <class... Ts>
	constexpr string(const Ts... ts) :
	m_str{(uintmax_t)ts...}, m_length{sizeof...(Ts)} {}

	constexpr size_t size() const { return m_length; }
	constexpr size_t length() const { return m_length; }
	constexpr uintmax_t operator[](size_t n) const { return m_str[n]; }
};

template <uintmax_t... Ts> struct sequence {};

constexpr auto
operator"" _id(const char* str, size_t n)
{
	return n == 0 ? string{} :
	       n == 1 ? string{str[0]} :
	       n == 2 ? string{str[0], str[1]} :
	       n == 3 ? string{str[0], str[1], str[2]} :
	       n == 4 ? string{str[0], str[1], str[2], str[3]} :
	       n == 5 ? string{str[0], str[1], str[2], str[3], str[4]} :
	                string{str[0], str[1], str[2], str[3], str[4], str[5]};
}

int main()
{
	static constexpr auto string = "Hello!"_id;
	using sequence = sequence<string[0], string[1], string[2], string[3], string[4], string[5]>;
	std::cout << typeid(sequence{}).name() << std::endl;
}
