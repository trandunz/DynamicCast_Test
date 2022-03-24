#include <vector>

#include <iostream>

class Base
{
public:
	Base() {}
	virtual ~Base() {}
};

class DerivedOne : public Base
{
};

class DerivedTwo : public Base
{
public:
	DerivedTwo() { }
	~DerivedTwo() {}

	int SomeInt = 5;


};

int main()
{

	std::vector<Base*> items;
	items.emplace_back(new DerivedOne());
	items.emplace_back(new DerivedTwo());

	for (auto& item : items)
	{
		DerivedOne* result1 = dynamic_cast<DerivedOne*> (item);
		if (result1)
		{
			std::cout << "Is Of Type DerivedOne!" << std::endl;
			continue;
		}
		DerivedTwo* result2 = dynamic_cast<DerivedTwo*> (item);
		if (result2)
		{
			std::cout << "Is Of Type DerivedTwo!" << std::endl;
			std::cout << "Retrieved Data: " << result2->SomeInt << std::endl;
			continue;
		}
	}

	for (auto& item : items)
	{
		if (item)
			delete item;
		item = nullptr;
	}
	items.clear();

	return 0;
}

