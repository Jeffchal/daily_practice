#include <iostream>
#include <vector>
using namespace std;


//�������캯�� 
class TextFile {
public:
	TextFile() {};
	TextFile(const TextFile& tf) { cout << "copy" << endl; };
	TextFile& operator=(TextFile& tf) { cout << "operator=" << endl;      return *this; };
};

int main() {
	vector<TextFile> text_files;
	text_files.push_back(TextFile());             //���� copy
	TextFile text_file_a;
	//TextFile text_file_b = text_file_a;		  //���� copy

	TextFile text_file_b;
	text_file_b = text_file_a;                   //���� operator=
}

// �ƶ����캯��
class TextFile {
public:
	TextFile() {};
	TextFile(TextFile && tf) { cout << "move" << endl; };
};

int main() {
	vector<TextFile> text_files;
	text_files.push_back(TextFile());     //���й���������һģһ���� TextFile ����
										 //һ������ TextFile ��ʱ������ʱ��
										 //һ���������� push_back ʱ����ʱ�����ֿ���һ�ݣ����ڶ��ι��������ǿ��Ա���ġ�

}

//����ֵ�Ż�
class TextFile {
public:
	TextFile() {};
	TextFile(const TextFile& tf) { cout << "copy" << endl; };
	TextFile& operator=(TextFile& tf) { cout << "operator=" << endl; return *this; };
};
TextFile get_tmp_text_file() { TextFile tf; return tf; }

int main()
{
	TextFile tf = get_tmp_text_file();
}