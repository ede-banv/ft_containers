#include "vector/vector.hpp"
#include <vector>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include "map/map.hpp"
#include "stack/stack.hpp"
#include <list>
#include <stack>
#include <map>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

void	print_content(TESTED_NAMESPACE::vector<int> &v)
{
	TESTED_NAMESPACE::vector<int>::iterator	it = v.begin();
	TESTED_NAMESPACE::vector<int>::iterator	ite = v.end();

	TESTED_NAMESPACE::vector<int>::const_iterator	cit = v.begin();
	TESTED_NAMESPACE::vector<int>::const_iterator	cite = v.end();

	TESTED_NAMESPACE::vector<int>::reverse_iterator	rev = v.rbegin();
	TESTED_NAMESPACE::vector<int>::reverse_iterator	reve = v.rend();

	std::cout << "\nIt content :\n";
	for (; it != ite; ++it)
		std::cout << "\t\t" << *it << '\n';
	std::cout << "\n";

	std::cout << "Const it content :\n";
	for (; cit != cite; ++cit)
		std::cout << "\t\t" << *cit << '\n';
	std::cout << "\n";

	std::cout << "Reverse it content :\n";
	for (; rev != reve; ++rev)
		std::cout << "\t\t" << *rev << '\n';
	std::cout << "\n";
}

void	print_size(TESTED_NAMESPACE::vector<int> &v)
{
	std::cout << "empty:\t\t" << v.empty() << std::endl;
	std::cout << "size:\t\t" << v.size() << std::endl;
	std::cout << "max_size:\t" << v.max_size() << std::endl;
}

void	print_capacity(TESTED_NAMESPACE::vector<int> &v)
{
	std::cout << "capacity\t" << v.capacity() << std::endl;
}
void	print_content(TESTED_NAMESPACE::map<int, int> &m)
{
	TESTED_NAMESPACE::map<int, int>::iterator	it = m.begin();
	TESTED_NAMESPACE::map<int, int>::iterator	ite = m.end();

	TESTED_NAMESPACE::map<int, int>::reverse_iterator	rev = m.rbegin();
	TESTED_NAMESPACE::map<int, int>::reverse_iterator	reve = m.rend();

	std::cout << "It content :\n";
	for (; it != ite; ++it)
		std::cout << "\t\t" << "Key: " << it->first << "\tVal: " << it->second << '\n';
	std::cout << "\n";

	std::cout << "Reverse it content :\n";
	for (; rev != reve; ++rev)
		std::cout << "\t\t" << "Key: " << rev->first << "\tVal: " << rev->second << '\n';
	std::cout << "\n";
}

void	print_size(TESTED_NAMESPACE::map<int, int> &v)
{
	std::cout << "empty:\t\t" << v.empty() << std::endl;
	std::cout << "size:\t\t" << v.size() << std::endl;
	std::cout << "max_size;\t" << v.max_size() << std::endl;
}

void	vector()
{
	std::cout << "********************\n*                  *\n*     VECTOR       *\n*                  *\n";
	std::cout << "********************\n";

	std::cout << "#################################\n";
	std::cout << " * CONSTRUCTOR & EMPTY & SIZE *\n";

	TESTED_NAMESPACE::vector<int>	v;
	TESTED_NAMESPACE::vector<int>	v1;
	TESTED_NAMESPACE::vector<int>	v_fill(8, 10);
	TESTED_NAMESPACE::vector<int>	v_range(v_fill.begin() + 2, v_fill.end() - 3);
	TESTED_NAMESPACE::vector<int>	v_copy(v_range);
	TESTED_NAMESPACE::vector<int>	const v_const(5, 2);

	std::cout << "\n#################################\n";
	std::cout << " * EMPTY VECTOR *\n";
	print_size(v); print_capacity(v); print_content(v);

	std::cout << "\n#################################\n";
	std::cout << " * FILL VECTOR *\n";
	print_size(v_fill); print_capacity(v_fill); print_content(v_fill);
	std::cout << "front\t\t" << v_fill.front() << std::endl;
	std::cout << "back\t\t" << v_fill.back() << std::endl;
	std::cout << "at\t\t\t" << v_fill.at(2) << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * RANGE VECTOR *\n";
	print_size(v_range); print_capacity(v_range); print_content(v_range);
	std::cout << "front\t\t" << v_range.front() << std::endl;
	std::cout << "back\t\t" << v_range.back() << std::endl;
	std::cout << "at\t\t\t" << v_range.at(2) << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * COPY VECTOR *\n";
	print_size(v_copy); print_capacity(v_copy); print_content(v_copy);
	std::cout << "front\t\t" << v_copy.front() << std::endl;
	std::cout << "back\t\t" << v_copy.back() << std::endl;
	std::cout << "at\t\t\t" << v_copy.at(2) << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * CONST VECTOR *\n";
	std::cout << "front\t\t" << v_const.front() << std::endl;
	std::cout << "back\t\t" << v_const.back() << std::endl;
	std::cout << "at\t\t\t" << v_const.at(2) << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * ASSIGN (FILL) *\n";
	v.assign(5, 54);
	v.push_back(6);
	print_size(v); print_capacity(v); print_content(v);
	std::cout << "front\t\t" << v.front() << std::endl;
	std::cout << "back\t\t" << v.back() << std::endl;
	std::cout << "at\t\t\t" << v.at(2) << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * ASSIGN (RANGE) *\n";
	v1.assign(v_fill.begin() + 1, v_fill.begin() + 3);
	print_size(v1); print_capacity(v1); print_content(v1);
	std::cout << "front\t\t" << v1.front() << std::endl;
	std::cout << "back\t\t" << v1.back() << std::endl;
	std::cout << "at\t\t\t" << v1.at(1) << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * CLEAR *\n";
	v1.clear();
	print_content(v1); print_size(v1); print_capacity(v1);

	std::cout << "\n#################################\n";
	std::cout << " * INSERT (7, 4, 10) *\n";
	v1.insert(v1.begin(), 10);
	v1.insert(v1.begin(), 4);
	v1.insert(v1.begin(), 7);
	print_size(v1); print_capacity(v1); print_content(v1);
	std::cout << "front\t\t" << v1.front() << std::endl;
	std::cout << "back\t\t" << v1.back() << std::endl;
	std::cout << "at\t\t\t" << v1.at(1) << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * ERASE (7) *\n";
	v1.erase(v1.begin(), v1.begin() + 1);
	print_size(v1); print_capacity(v1); print_content(v1);
	std::cout << "front\t\t" << v1.front() << std::endl;
	std::cout << "back\t\t" << v1.back() << std::endl;
	std::cout << "at\t\t\t" << v1.at(1) << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * OPERATORS *\n";
	std::cout << "v1 = v_fill\n";

	v1 = v_fill;

	std::cout << "v1 == v2:\t" << (v1 == v_fill) << std::endl;
	std::cout << "v1 != v2:\t" << (v1 != v_fill) << std::endl;

	std::cout << "\n* Pop last elem of v1\n";
	v1.pop_back();

	std::cout << "v1 < v2:\t" << (v1 < v_fill) << std::endl;
	std::cout << "v1 > v2:\t" << (v1 > v_fill) << std::endl;

	std::cout << "\n* Check operator[] | v1[2] = 10\n";
	std::cout << "v1[2] = " << v1[2] << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * RESERVE *\n";
	v1.reserve(18);
	print_size(v1); print_capacity(v1); print_content(v1);
	std::cout << "front\t\t" << v1.front() << std::endl;
	std::cout << "back\t\t" << v1.back() << std::endl;
	std::cout << "at\t\t\t" << v1.at(1) << std::endl;

	std::cout << "\n#################################\n";
	std::cout << "* RESIZE *\n";
	v1.resize(2);
	print_size(v1); print_capacity(v1); print_content(v1);
	std::cout << "front\t\t" << v1.front() << std::endl;
	std::cout << "back\t\t" << v1.back() << std::endl;
	std::cout << "at\t\t\t" << v1.at(1) << std::endl;

	v_range.push_back(18);
	v_range.push_back(7);
	v_range.push_back(2);
	v_range.push_back(1);
	v_range.push_back(98);

	std::cout << "\n#################################\n";
	std::cout << " * SWAP *\n";
	std::cout << "* Before swap:\n";
	std::cout << "v1 is :\n";
	print_size(v1); print_capacity(v1); print_content(v1);
	std::cout << "\nv_range is :\n";
	print_size(v_range); print_capacity(v_range); print_content(v_range);

	v1.swap(v_range);

	std::cout << "\n* After swap:\n";
	std::cout << "v1 is :\n";
	print_size(v1); print_capacity(v1); print_content(v1);
	std::cout << "\nv_range is :\n";
	print_size(v_range); print_capacity(v_range); print_content(v_range);
}

void	stack()
{
	std::cout << "\n\n********************\n*                  *\n*      STACK       *\n*                  *\n";
	std::cout << "********************\n";

	std::cout << "#################################\n";
	std::cout << " * CONSTRUCTOR & EMPTY & SIZE *\n";

	TESTED_NAMESPACE::stack<int> stack;
	TESTED_NAMESPACE::stack<int> copy_stack;

	std::cout << stack.size() << std::endl;
	std::cout << stack.empty() << std::endl;

	stack.push(10);
	stack.push(2);
	stack.push(4);
	stack.push(18);

	std::cout << stack.size() << std::endl;
	std::cout << stack.empty() << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * COPY STACK *\n";

	copy_stack = stack;
	std::cout << "size:\t| Srcs: " << stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "empty:\t| Srcs: " << stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "top:\t| Srcs: " << stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * POP (18) *\n";

	stack.pop();

	std::cout << "size:\t| Srcs: " << stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "empty:\t| Srcs: " << stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "top:\t| Srcs: " << stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * COMPARE *\n";

	std::cout << "stack1 = stack2:\t" << (stack == copy_stack) << std::endl;
	std::cout << "stack1 != stack2:\t" << (stack != copy_stack) << std::endl;
	std::cout << "stack1 < stack2:\t" << (stack < copy_stack) << std::endl;
	std::cout << "stack1 > stack2:\t" << (stack > copy_stack) << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * SWAP *\n";
	std::cout << "* Before swap:\n";
	std::cout << "size\t| Srcs: " << stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "empty\t| Srcs: " << stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "top\t| Srcs: " << stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;
	std::cout << "size\t| Srcs: " << copy_stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "empty\t| Srcs: " << copy_stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "top\t| Srcs: " << copy_stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;

	swap(stack, copy_stack);

	std::cout << "* After swap:\n";
	std::cout << "size\t| Srcs: " << stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "empty\t| Srcs: " << stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "top\t| Srcs: " << stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;
	std::cout << "size\t| Srcs: " << copy_stack.size() << '\t' << "Copy: " << copy_stack.size() << std::endl;
	std::cout << "empty\t| Srcs: " << copy_stack.empty() << '\t' << "Copy: " << copy_stack.empty() << std::endl;
	std::cout << "top\t| Srcs: " << copy_stack.top() << '\t' << "Copy: " << copy_stack.top() << std::endl;
}

void	map()
{
	std::cout << "\n\n********************\n*                  *\n*       MAP        *\n*                  *\n";
	std::cout << "********************\n";

	std::cout << "#################################\n";
	std::cout << " * CONSTRUCT & INSERT *\n";

	TESTED_NAMESPACE::map<int, int>	m;
	TESTED_NAMESPACE::map<int, int>	m1;
	TESTED_NAMESPACE::map<int, int>	const m2;

	TESTED_NAMESPACE::pair <int,int>			foo;
  	TESTED_NAMESPACE::pair <int,int>			bar;
	TESTED_NAMESPACE::pair <int,int>			foo1;
  	TESTED_NAMESPACE::pair <int,int>			bar1;
	TESTED_NAMESPACE::pair <int,int>			foo2;
  	TESTED_NAMESPACE::pair <int,int>			bar2;
	TESTED_NAMESPACE::pair <int,int>			n1;
  	TESTED_NAMESPACE::pair <int,int>			n2;
	TESTED_NAMESPACE::pair <int,int>			n3;
  	TESTED_NAMESPACE::pair <int,int>			n4;
	TESTED_NAMESPACE::pair <int,int>			n5;
  	TESTED_NAMESPACE::pair <int,int>			n6;

	foo = TESTED_NAMESPACE::make_pair(10, 20);
  	bar = TESTED_NAMESPACE::make_pair(30, 78);
	foo1 = TESTED_NAMESPACE::make_pair(2, 198);
  	bar1 = TESTED_NAMESPACE::make_pair(12, 78);
	foo2 = TESTED_NAMESPACE::make_pair(10, 19);
  	bar2 = TESTED_NAMESPACE::make_pair(85, 5);
  	n1 = TESTED_NAMESPACE::make_pair(38, 2);
  	n2 = TESTED_NAMESPACE::make_pair(0, 56);
  	n3 = TESTED_NAMESPACE::make_pair(1, 2);
  	n4 = TESTED_NAMESPACE::make_pair(99, 7845);
  	n5 = TESTED_NAMESPACE::make_pair(89732, 2);
  	n6 = TESTED_NAMESPACE::make_pair(-1982, 2);

	m1.insert(foo);
	m1.insert(bar);
	m1.insert(foo1);
	m1.insert(bar1);
	m1.insert(foo2);
	m1.insert(bar2);
	m1.insert(n1);
	m1.insert(n2);
	m1.insert(n3);
	m1.insert(n4);
	m1.insert(n5);
	m1.insert(n6);

	TESTED_NAMESPACE::map<int, int>	m_range(++m1.begin(), --m1.end());
	TESTED_NAMESPACE::map<int, int>	m_copy(m_range);

	std::cout << "\n#################################\n";
	std::cout << " * EMPTY MAP *\n";
	print_size(m); print_content(m);

	std::cout << "\n#################################\n";
	std::cout << " * INSERT(val) *\n";
	print_size(m1); print_content(m1);

	std::cout << "\n#################################\n";
	std::cout << " * CONSTRUCT(range) *\n";
	print_size(m_range); print_content(m_range);

	std::cout << "\n#################################\n";
	std::cout << " * CONSTRUCT(map) *\n";
	print_size(m_copy); print_content(m_copy);

  	TESTED_NAMESPACE::pair <int,int>			elem;
	elem = TESTED_NAMESPACE::make_pair(-8, 76823);
	m_copy.insert(++(++(m_copy.begin())), elem);

	std::cout << "\n#################################\n";
	std::cout << " * INSERT(pos, val) *\n";
	print_size(m_copy); print_content(m_copy);

	std::cout << "\n#################################\n";
	std::cout << " * INSERT(begin, end) *\n";
	m.insert(m_copy.begin(), --(--(m_copy.end())));
	print_size(m); print_content(m);

	std::cout << "\n#################################\n";
	std::cout << " * ERASE(pos) *\n";
	std::cout << "* Before erase:\n";
	print_size(m_copy); print_content(m_copy);
	m_copy.erase(++m_copy.begin());

	std::cout << "* After erase:\n";
	print_size(m_copy); print_content(m_copy);

	std::cout << "\n#################################\n";
	std::cout << " * ERASE(key) *\n";
	std::cout << "* Before erase:\n";
	print_size(m_copy); print_content(m_copy);

	m_copy.erase(12);

	std::cout << "* After erase:\n";
	print_size(m_copy); print_content(m_copy);

	std::cout << "\n#################################\n";
	std::cout << " * ERASE(begin, end) *\n";
	std::cout << "* Before erase:\n";
	print_size(m_copy); print_content(m_copy);

	m_copy.erase(m_copy.begin(), --m_copy.end());

	std::cout << "* After erase:\n";
	print_size(m_copy); print_content(m_copy);

	std::cout << "\n#################################\n";
	std::cout << " * SWAP *\n";
	std::cout << "* Before swap:\n";
	print_size(m_copy); print_content(m_copy);
	print_size(m); print_content(m);

	m_copy.swap(m);

	std::cout << "* After swap:\n";
	print_size(m_copy); print_content(m_copy);
	print_size(m); print_content(m);

	std::cout << "\n#################################\n";
	std::cout << " * FIND *\n";
	std::cout << "res: " << m_copy.find(38)->first << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * COUNT *\n";
	std::cout << "res: " << m_copy.count(38) << std::endl;

	std::cout << "\n#################################\n";
	std::cout << " * CLEAR *\n";
	m_copy.clear();
	print_size(m_copy); print_content(m_copy);
}

int main(void)
{
	vector();
	stack();
	map();

    return 0;
}
