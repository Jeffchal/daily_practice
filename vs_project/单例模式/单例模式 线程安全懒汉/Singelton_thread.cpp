#include <iostream>
#include <process.h>
#include <windows.h>
#include <mutex>
#include <cstdio>

#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

using namespace std;

class singleton
{
protected:
	singleton()
	{
		// ��ʼ��
		pthread_mutex_init(&mutex, NULL);
		m_count++;
		printf("Singelton begin\n");
		Sleep(1000);                            // ��sleepΪ�˷Ŵ�Ч��
		printf("Singelton end\n");
	}

private:
	static singleton* p;

public:
	static pthread_mutex_t mutex;
	static singleton* initance();
	static void print();
	static int m_count;
};

int singleton::m_count = 0;
pthread_mutex_t singleton::mutex;
singleton* singleton::p = NULL;


singleton* singleton::initance()
{
	if (p == NULL)
	{
		// ����
		pthread_mutex_lock(&mutex);
		if (p == NULL)
			p = new singleton();
		pthread_mutex_unlock(&mutex);
	}
	return p;
}

void singleton::print() {
	//cout << "This is Print the m_count:  " << m_count << endl;
	cout << m_count << endl;
}
// �ص�����
void threadFunc(void *p) {
	DWORD id = GetCurrentThreadId();        // ����߳�id
	cout << id << endl;
	singleton::initance()->print();      // ���캯�������ʵ�������þ�̬��Ա����
}

int main(int argc, const char * argv[]) {
	int threadNum = 3;
	HANDLE threadHdl[100];

	// ����3���߳�
	for (int i = 0; i < threadNum; i++) {
		threadHdl[i] = (HANDLE)_beginthread(threadFunc, 0, nullptr);
	}

	// �������̵ȴ����е��߳̽��������˳�
	for (int i = 0; i < threadNum; i++) {
		WaitForSingleObject(threadHdl[i], INFINITE);
	}
	cout << "main" << endl;                 // ��֤�������Ƿ�������˳�
	return 0;
}

