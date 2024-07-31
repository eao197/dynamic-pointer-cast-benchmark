#pragma once

#include <memory>

class value_provider_base
{
public:
	virtual ~value_provider_base();

	[[nodiscard]] virtual int
	value() const = 0;
};

using value_provider_shptr = std::shared_ptr< value_provider_base >;

class first_provider : public value_provider_base
{
public:
	int
	value() const override;
};

class second_provider : public value_provider_base
{
	unsigned _n;

public:
	second_provider(unsigned n);

	int
	value() const override;

	[[nodiscard]] unsigned
	get_n() const;
};

[[nodiscard]] value_provider_shptr
make_provider();

