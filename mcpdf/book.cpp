#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>


int main() {
	std::vector<std::pair<std::string, int>> data;
	int total_pages{};
	if (std::ifstream input{"info.txt", std::ios::in}) {
		std::string t;
		std::getline(input, t);
		total_pages = std::stoi(t);
		std::string name, page;
		while (getline(input, name) && getline(input, page)) {
			for (auto& ch : name) if (!isalpha(ch) && !isdigit(ch) ) ch = '_';
			data.push_back({name, std::stod(page)});
		}
	} else {
		std::cerr << "file open error!!";
	}

	int n = std::size(data);
	for (int i = 0; i < n; ++i) {
		int np = (i == n-1) ? total_pages : data[i+1].second - 1;
		auto& d = data[i];
		std::cout << d.second << ' ' << np << ' ' << "\"" << d.first << ".pdf\" && mv \"" << d.first << ".pdf\" \"tmp/" << d.first << ".pdf\"" << std::endl;
	}
	return 0;
}
