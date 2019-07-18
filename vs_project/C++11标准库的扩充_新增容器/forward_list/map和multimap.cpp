#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

int main() {

	// ����ṹ��ͬ����˳���ʼ��
	std::unordered_map<int, std::string> umap = {
		{1, "1"},
		{3, "3"},
		{2, "2"}
	};
	std::map<int, std::string> map = {
		{1, "1"},
		{3, "3"},
		{2, "2"}
	};

	// �ֱ�������������б���
	std::cout << "std::unordered_map" << std::endl;
	for (const auto &n : umap)
		std::cout  << &n <<" "<< "Key:[" << n.first << "] Value:[" << n.second << "]\n";

	std::cout << std::endl;
	std::cout << "std::map" << std::endl;
	for (const auto & n : map)
		std::cout << &n << " " << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
}