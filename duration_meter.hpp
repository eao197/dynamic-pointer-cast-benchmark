#pragma once

#include <chrono>
#include <string_view>
#include <iostream>

class duration_meter
{
	std::string_view _name;
	const std::chrono::high_resolution_clock::time_point _started_at;

public:
	duration_meter( std::string_view name )
		: _name{ name }
		, _started_at{ std::chrono::high_resolution_clock::now() }
	{}
	~duration_meter()
	{
		const auto f = std::chrono::high_resolution_clock::now();

		std::cout << "*** " << _name << ": "
			<< std::chrono::duration_cast<std::chrono::microseconds>(
				f - _started_at ).count()
			<< "us *** " << std::endl;
	}
};

template<typename Lambda>
decltype(auto)
measure( std::string_view name, Lambda && lambda )
{
	duration_meter meter{ name };
	return lambda();
}

