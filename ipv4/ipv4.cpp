#include "ipv4.hpp"
#include <regex>
#include <sstream>

ipv4& ipv4::operator=(const ipv4& other) noexcept {
	data = other.data;
	return *this;
}

std::string ipv4::to_string() const {
	std::stringstream sstr;
	sstr << *this;
	return sstr.str();
}

constexpr uint32_t ipv4::to_ulong() const noexcept {
	return {
		(static_cast<uint32_t>(data[0]) << 24) |
		(static_cast<uint32_t>(data[1]) << 16) |
		(static_cast<uint32_t>(data[2]) <<  8) |
		static_cast<uint32_t>(data[3])
	};
}

std::ostream& operator<<(std::ostream& ostm, const ipv4& a) {
	return ostm << static_cast<int32_t>(a.data[0]) << "."
				<< static_cast<int32_t>(a.data[1]) << "."
				<< static_cast<int32_t>(a.data[2]) << "."
				<< static_cast<int32_t>(a.data[3]);
}

std::istream& operator>>(std::istream& istm, ipv4& a) {
	static const std::regex ipv4_format{"\\d{3}.\\d{3}.\\d{3}.\\d{3}"};
	std::string s;
	if (istm >> s) {
		// 入力がうまくいったときの処理
		if (std::regex_match(s, ipv4_format)) {
			// 入力がformatにしたがっている時の処理
			char c; // ","用
			int32_t d[4];
			std::stringstream(s) >> d[0] >> c >> d[1] >> c >> d[2] >> c >> d[3];
			a = ipv4(d[0], d[1], d[2], d[3]);
			return istm;
		}
	} 
	// 入力がうまくいかなかった or formatに従っていない 時の処理
	istm.setstate(std::ios_base::failbit);
	return istm;
}

ipv4& ipv4::operator++() {
	*this = ipv4(1 + to_ulong());
	return *this;
}

ipv4 ipv4::operator++(int32_t) {
	ipv4 result(*this);
	++(*this);
	return result;
}

bool operator==(const ipv4& lhs, const ipv4& rhs) noexcept {
	return lhs.data == rhs.data;
}
bool operator!=(const ipv4& lhs, const ipv4& rhs) noexcept {
	return !(lhs == rhs);
}
bool operator< (const ipv4& lhs, const ipv4& rhs) noexcept {
	return lhs.to_ulong() < rhs.to_ulong();
}
bool operator> (const ipv4& lhs, const ipv4& rhs) noexcept {
	return rhs < lhs;
}
bool operator<=(const ipv4& lhs, const ipv4& rhs) noexcept {
	return !(lhs > rhs);
}
bool operator>=(const ipv4& lhs, const ipv4& rhs) noexcept {
	return !(lhs < rhs);
}
