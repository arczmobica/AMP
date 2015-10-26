// AMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void setBestAccelerator()
{
	using namespace concurrency;
	vector<accelerator> accs = accelerator::get_all();
	auto selectedOne = std::find_if(cbegin(accs), cend(accs),[](accelerator a) { return !a.is_emulated; });
	if (selectedOne != accs.cend())
	{
		accelerator::set_default((*selectedOne).device_path);
		std::wcout << (*selectedOne).device_path << '\n';
	}
									
}

void f()
{
	vector<int> vec{ 1,2,3 };
	using namespace concurrency;
	extent<1> e_2;
	array_view<int> av(e_2,vec);
}

int main()
{
	setBestAccelerator();
	vector<int> vec(10);
	
	int i{ 0 };
	std::iota(begin(vec), end(vec), 0);
	std::generate(begin(vec), end(vec),
										[&i] {return ++i; });
	//f();
	/*vector<int> vec{1,2,3,4,5,6,7,8,9};
	array_view<const int> av(vec);
	index<1> idx(2);
	cout << av[idx];*/
    return 0;
}

