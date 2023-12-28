#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator& other) : m_type_book(other.m_type_book) {}

TargetGenerator& TargetGenerator::operator=(const TargetGenerator& other) {
	if (this != &other)
		this->m_type_book = other.m_type_book;

	return (*this);
}

TargetGenerator::~TargetGenerator() {}


void TargetGenerator::learnTargetType(ATarget* type) {
	if (type)
		this->m_type_book[type->getType()] = type->clone();
}

void TargetGenerator::forgetTargetType(std::string const &typeName) {
	std::map<std::string, ATarget*>::iterator it;

	it = this->m_type_book.find(typeName);
	if (it != this->m_type_book.end())
	{
		delete it->second;
		this->m_type_book.erase(it);
	}
}

ATarget* TargetGenerator::createTarget(std::string const &typeName) {
	if (this->m_type_book.find(typeName) != this->m_type_book.end())
		return (this->m_type_book[typeName]);
	return (NULL);
}
