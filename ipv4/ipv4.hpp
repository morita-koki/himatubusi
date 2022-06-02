#pragma once
#include <array>
#include <cstdint>
#include <string>
#include <iostream>

class ipv4 {
	std::array<uint8_t, 4> data;
public:
	constexpr ipv4()
        :ipv4(0,0,0,0) 
        {}
	constexpr ipv4(const uint8_t a, const uint8_t b, const uint8_t c, const uint8_t d)
        :data{{a,b,c,d}}
        {}
	explicit constexpr ipv4(uint32_t a)
        :ipv4(static_cast<uint8_t>((a >> 24) & 0xFF)
		,static_cast<uint8_t>((a >> 16) & 0xFF)
		,static_cast<uint8_t>((a >> 8 ) & 0XFF)
		,static_cast<uint8_t>( a        & 0xFF))
    	{}
	ipv4(const ipv4& other) noexcept
    	:data(other.data)
	    {}

	ipv4& operator=(const ipv4& other) noexcept;
	std::string to_string() const;
	constexpr uint32_t to_ulong() const noexcept;
	friend std::ostream& operator<<(std::ostream& ostm, const ipv4& a);
	friend std::istream& operator>>(std::istream& istm, ipv4& a);

	ipv4& operator++();
	ipv4 operator++(int32_t);
	friend bool operator==(const ipv4& lhs, const ipv4& rhs) noexcept;
	friend bool operator!=(const ipv4& lhs, const ipv4& rhs) noexcept;
	friend bool operator< (const ipv4& lhs, const ipv4& rhs) noexcept;
	friend bool operator> (const ipv4& lhs, const ipv4& rhs) noexcept;
	friend bool operator<=(const ipv4& lhs, const ipv4& rhs) noexcept;
	friend bool operator>=(const ipv4& lhs, const ipv4& rhs) noexcept;
};
