#include <iostream>
using namespace std;

//typedef unsigned long Item;
//
//class CEnumTest
//{
//public:
//	//CEnumTest();
//	//~CEnumTest();
//
//	const void show() const;		//�����const��ʾ�ú������ɸ��������Ҳ���ǲ��ܸ��������ĳ�Ա����
//private:
//	enum { One = 1, Two = 2, Three = 4 };
//
//	Item item[Three];
//};
//
////CEnumTest::CEnumTest()
////{
////}
////CEnumTest::~CEnumTest()
////{
////}
//
//const void CEnumTest::show() const
//{
//	std::cout << "this->Three==" << this->Three << std::endl;
//}
//
//
//int main()
//{
//	CEnumTest *enumTest = new CEnumTest();
//	enumTest->show();
//
//	system("pause");
//	return true;
//}

// https://mp.weixin.qq.com/s?__biz=Mzg2NzA4MTkxNQ==&mid=2247486954&idx
// =1&sn=747968cc77ca57602077c56f0d8294ff&chksm=ce40463ef937cf28629c1c9
// 35bf8e219ee0c17d20330c6222766f7a2d6275d5d15d412153170&mpshare=1&scene
// =23&srcid=&sharer_sharetime=1581667098639&sharer_shareid=84cb414b098b6c0d73da06b926caecab#rd

public interface RoleOperation
{
	String op();
	// ��ʾĳ����ɫ��������Щop����
}

public enum RoleEnum implements RoleOperation
{
	// ϵͳ����Ա(��A����Ȩ��)
	ROLE_ROOT_ADMIN {
		@Override
		public String op() {
				return "ROLE_ROOT_ADMIN:"+" has AAA permission"
		}
	},

	// ��������Ա(��B����Ȩ��)
	ROLE_ORDER_ADMIN {
		@Override
		public	String op() {
			return	"ROLE_ORDER_ADMIN:"+" has BBB permission"
		}
	},

	// ��ͨ�û�(��C����Ȩ��)
	ROLE_NORMAL {
		@Override
		public	String op() {
			return "ROLE_NORMAL:"+" has CCC permission"
		}
	};
}

public class JudgeRole
{
	public String judge(String roleName) {
		// һ�д���㶨��֮ǰ��if/elseû�ˣ�
		return RoleEnum.valueOf(roleName).op();
	}
}


// https://schneide.blog/2010/12/13/avoid-switch-use-enum/
enum Status {
	INACTIVE{
		public void doSomething() {
			//do something
		}
	},
	ACTIVE{
		void doSomething() {
			//do something else
		}
	 },
	UNKNOWN{
		void doSomething() {
			//do something totally different
		 }
	}

	// void doSomething();
};

int main() {


	return 0;
}