#include <Windows.h> //�ײ�ʵ�ִ��ڵ�ͷ�ļ� �� �ײ���û��CPP�� ����Ҫʹ��c�ļ�����ʽ 

//6.�����ڹ���

//CALLBACK ��һ���꣬����_stdcall �����Ĵ���˳�򣺴��ҵ��� �Ӵ���ջ�������ں�������ǰ ��ն�ջ
LRESULT CALLBACK WindowProc(
	HWND hwnd,				//��Ϣ�����Ĵ��ھ��
	UINT uMsg,				//��Ϣ�������� WM_XXXX��Ϣ��
	WPARAM wParam,			//���̸�����Ϣ
	LPARAM lParam           //��긽����Ϣ
	)
{
	switch(uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);	//DestroyWindow������һ����ϢWM_DESTROY
		break;
	case WM_DESTROY:
		PostQuitMessage(0);     //���X�ţ��˳�����
		break; 
	}


	//����ֵ��Ĭ�ϴ���ʽ
	return DefWindowProc(hwnd,uMsg, wParam, lParam);
}						 
						 
						 
������ں��� main����

WINAPI ��һ���꣬����_stdcall �����Ĵ���˳�򣺴��ҵ��� �Ӵ���ջ�������ں�������ǰ ��ն�ջ
int WINAPI WinMain(
	HINSTANCE hInstance,              //Ӧ�ó���ʵ�����
	HINSTANCE hPrevInstance,          //��һ��Ӧ�ó���������Win32�����£�����һ��ΪNULL������������
	LPSTR lpCmdLine,                  //char *argv[]
	int nShowCmd )					  //��ʾ���� ��� ��С�� ����
{
	1.��ƴ���
	2.ע�ᴰ��
	3.��������
	4.��ʾ�͸���
	5.ͨ��ѭ��ȡ��Ϣ
	6.������Ϣ�����ڹ��̣�
	HWND hwnd;

	1.��ƴ���
	WNDCLASS wc;
	wc.cbClsExtra = 0;				         //��Ķ�����ڴ�
	wc.cbWndExtra = 0;						 //���ڵĶ�����ڴ�
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	 //���ñ���,��ǿ��ת��Ϊwc.hbrBackground�ķ���ֵ����(HBRUSH)
	wc.hCursor = LoadCursor(NULL , IDC_HAND);			 //���ù��,�����һ������ΪNULL,��ʹ��ϵͳ�ṩ�Ĺ��
	wc.hIcon = LoadIcon(NULL , IDC_ICON);				//����ͼ��
	wc.hInstance = hInstance;                           //Ӧ�ó���ʵ�����
	wc.lpfnWndProc = WindowProc;						//�ص����������ڹ���
	wc.lpszClassName = TEXT("WIN");						//ָ������������
	wc.lpszMenuName = NULL ;							//�˵�����
	wc.style = 0;										//��ʾ���0����Ĭ�Ϸ��

	2.ע�ᴰ��
	RegisterClass(&wc);

	3.��������
	/*
	 lpClassName  ����
	 lpWindowName ������
	 dwStyle, WS_OVERPLAPPEDWINDOW Ĭ��ֵ
	 x,y		  ��ʾ����
	 nwidth,nHeight			���
	 hWndParent    ������ NULL
	 hMenu         �˵� NULL
	 hInstance     ʵ����� hInstance
	 lpParam       ����ֵ����긽��ֵ
	 */

	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("WINDOWS"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	

	4.��ʾ�͸���
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	5.ͨ��ѭ��ȡ��Ϣ
	/*
	HWND        hwnd;    �����ھ��
    UINT        message; ������Ϣ����
    WPARAM      wParam;  ������Ϣ��������Ϣ
    LPARAM      lParam;  ������Ϣ�������Ϣ
    DWORD       time;    ��Ϣ����ʱ��
    POINT       pt;      ������Ϣ  �����Ϣ x y
	*/
	MSG msg;

	while(1)
	{   
		/*
		  __out LPMSG lpMsg,         ��Ϣ
		  __in_opt HWND hWnd,        ������Ϣ����NULL���������еĴ���
		  __in UINT wMsgFilterMin,   ��С�Ĺ��˶����Ϣ��һ����0�����������д���
		  __in UINT wMsgFilterMax);  ���Ĺ��˶����Ϣ��һ����0��������������Ϣ
		 */
		if(GetMessage(&msg, NULL, 0, 0) == FALSE)
		{
			break;
		}

		������Ϣ
		TranslateMessage(&msg);

		��Ϊfalse
		�ַ���Ϣ
		DispatchMessage(&msg);

	}

	return 0;
}

