#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>

using std::string;

typedef unsigned long uintptr_t;

typedef struct Data
{
	int index;
	double wages;
	std::string name;
}	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &source);
		Serializer &operator=(const Serializer &source);
	public:
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif