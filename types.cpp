#include "types.hpp"

value_provider_base::~value_provider_base()
{}

int
first_provider::value() const
{
	return 1;
}

second_provider::second_provider(unsigned n)
	: _n{ n }
{}

int
second_provider::value() const
{
	return 2;
}

unsigned
second_provider::get_n() const { return _n; }

[[nodiscard]] value_provider_shptr
make_provider()
{
	static unsigned i = 0u;

	const unsigned n = ++i;
	if( i > 10u ) i = 0u;

	return std::make_shared< second_provider >( n );
}

