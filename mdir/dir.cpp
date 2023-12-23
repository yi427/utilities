#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
	if (argc < 3) {
		std::cerr << "usage: dirPath fileName!";
		exit(1);
	}
	std::string dirPath = argv[1];
	if (dirPath.back() != '/') dirPath.push_back('/');
	std::unordered_set<std::string> files;
	std::vector<std::string> res;
	for (int i = 2; i < argc; ++i) 
		files.insert(argv[i]);
	bool flag = files.count("*");
	try {
		 for (const auto& entry : fs::directory_iterator(dirPath)) {
			 std::string s = entry.path();
			 auto pos = s.find_last_of('/');
			 if (flag || files.count(s.substr(pos+1)))
				 res.push_back(s.substr(pos+1)); 
		 }
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	for (auto& i : res)
		std::cout << dirPath + i << ' ' << i << std::endl;
	return 0;
}
