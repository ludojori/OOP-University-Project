#pragma once
class Test
{
private:
	int number;
public:
	Test() { number = 0; }
	Test& operator=(const Test& other);
};