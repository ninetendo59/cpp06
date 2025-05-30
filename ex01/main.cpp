#include "Serializer.hpp"

int main()
{
	Data *dat = new Data;
	dat->index = 0;
	dat->name = "name";
	dat->wages = 100.12;

	uintptr_t raw = Serializer::serialize(dat);
	Data *newdat = Serializer::deserialize(raw);

	
	std::cout << "Serialization: " << raw << std::endl << std::endl;

	std::cout
		<< "Data before Serialise.. " << dat << std::endl
		<< dat->index << std::endl
		<< dat->name << std::endl
		<< dat->wages << std::endl << std::endl;

		std::cout
		<< "Data after Serialise.. " << newdat << std::endl
		<< newdat->index << std::endl
		<< newdat->name << std::endl
		<< newdat->wages << std::endl << std::endl;

	delete dat;
	return 0;
}