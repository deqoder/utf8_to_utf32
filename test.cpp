#include <iostream>
#include "utf8_to_utf32.hpp"
std::string stream2str(std::istream &istr) {
        std::string out;
        for (std::string tmp; std::getline(istr, tmp); out += tmp);
        return out;
}
int main() {
	std::string in;
	in = stream2str(std::cin);
	std::u32string out, out2;
	utf8_to_utf32(in, out);
	for (size_t i = 0; i < out.size(); i++) {
		if (out[i] < 0x80) {
			out2.push_back(out[i]);
		} else {
			out2.push_back( '[');
			out2.push_back(out[i]);
			out2.push_back(']');
		}
	}
	utf32_to_utf8(out2, in);
	std::cout << in;
	return 0;
}


