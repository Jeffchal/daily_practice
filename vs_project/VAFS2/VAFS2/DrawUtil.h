//DrawUtil.h
/*
* Copyright (c) 2006, �������ϿƼ��������ι�˾
* All rights reserved.
* 
* �ļ����ƣ�DrawUtil.h
* �ļ���ʶ��DrawUtil.h
* ժ    Ҫ��DrawUtil.hl�����������
*
* ����������Microsoft Win32 SDK, Visual C++ 6.00
* 
* ��ǰ�汾��1.0.0.1
* ��    �ߣ���ɺ
* ������ڣ�2006��6��2��
*
* ȡ���汾��1.1.7.1102
* ԭ �� �ߣ�star
* ������ڣ�2007��11��2��
*
* �޸ļ�¼��

* �汾:    �汾1.1.7.1102
* ʱ��:    07-11-02
* �޸���:  ���Ӻ���: FD_StretchDrawImage��FD_DrawActualImage

*/
//////////////////////////////////////////////////////////////////////
#ifndef _DRAW_UTIL_H
#define _DRAW_UTIL_H

#ifdef DRAWUTIL_API
#define DRAWUTIL_API __declspec(dllexport)
#else
#define DRAWUTIL_API __declspec(dllimport)
#endif

typedef enum tagFD_FILE_TYPE
{
	FILE_BITMAP = 0,
	FILE_JPEG	= 1,
	FILE_RAW	= 2
}FD_FILE_TYPE;

////////////////////////////////////////////////////////////////////////////////////////////////
//GDI��ͼ��������������GDI��ʽ�ڴ����ϻ�ͼ������������ͼ����ͬһ�����ϻ��ơ�

/* By C++ language compiler */
#ifdef __cplusplus
extern "C"{
#endif

/*
*����˵����������ͼ���󣬱���ʹ��FD_ReleaseDraw�ͷŶ���
*���������hDisp����ʾ���ھ��
*          nWidth����ʾ��ͼ����
*          nHeight����ʾ��ͼ��߶�
*          nBitCnt����ʾͼ��λ�֧��RGB24��ʽλͼ��8λ�Ҷ�ͼ����Ӧ��ֵ�ֱ�Ϊ24��8
*          bTopToDown��ͼ�������Ƿ��ǵ�λͼ����λͼ��һ��ɨ�����Ƿ���ͼ�����ݾ�������һ��
*          bDwordAligned��ͼ�����ݿ��Ƿ����ֽڱ߽����
*�����������
*�� �� ֵ��λͼ������������ʧ���򷵻�NULL
*/
DRAWUTIL_API
HANDLE __stdcall FD_CreateDraw(HWND hDisp, int nWidth, int nHeight, 
				int nBitCnt, bool bTopToDown, bool bDwordAligned);

/*
*����˵�����ͷ��Ѵ����Ļ�ͼ����
*���������hDraw����ͼ������
*�����������
*�� �� ֵ����
*/
DRAWUTIL_API 
void __stdcall FD_ReleaseDraw(HANDLE hDraw);

////////////////��������ʾ�ĺ���///////////////////////////////////////////////
/*
*����˵������ָ���Ĵ����ϻ�ͼ����������ʾ�Ŀ�Ȼ�߶�Ϊ0����ԭ��С��ʾ
*���������hDraw����ͼ������
*          pBits��ͼ�����ݻ�������ַ
*          nSize��ͼ�����ݻ�������С
*          nLeft��ͼ���ڴ�����ʾʱ�����Ͻ�����ڴ���ͻ����ĺ�����
*          nTop��ͼ���ڴ�����ʾʱ�����Ͻ�����ڴ���ͻ�����������
*          nPlayWidth��������ʾʱ�Ŀ��
*          nPlayHeight��������ʾʱ�ĸ߶�
*�����������
*�� �� ֵ����
*/
DRAWUTIL_API
void __stdcall FD_DrawImage(HANDLE hDraw, PVOID pBits, UINT nSize,  int nLeft, 
								int nTop, UINT nPlayWidth, UINT nPlayHeight);

/*
*����˵������ָ���Ĵ��崰��������ʾԴͼ����ָ�����������ͼ��
*���������hDraw����ͼ������
*          pBits��ͼ�����ݻ�������ַ
*          nSize��ͼ�����ݻ�������С
*		   rcInput������ʾ��Դͼ���������
*          rcOutput�������е���ʾ�������������������Դͼ�������С��һ�£����Զ�������ʾ
*�����������
*�� �� ֵ����
*/
DRAWUTIL_API
void __stdcall FD_DrawImageEx(HANDLE hDraw, PVOID pBits, UINT nSize,  RECT &rcInput, RECT &rcOutput);

////////////////////////////////////////////////////////////////////////////////////////////
/*
*����˵�����ػ����һ�ε���FD_DrawImageEx��FD_DrawImage����������ͼ��
*		   ͼ������������ο��Ը�����Ҫ������
*���������hDraw����ͼ������
*		   rcInput������ʾ��Դͼ���������
*          rcOutput���ڴ�������ʾʱ�����ͼ��ľ�������
*�����������
*�� �� ֵ����
*/
DRAWUTIL_API
void __stdcall FD_RedrawImage(HANDLE hDraw, RECT &rcInput, RECT &rcOutput);

/////////////////////////////////////////////////////////////////////////////////////////////
/*
*����˵������ָ���Ĵ��ڻ�ͼ���ú�����������, �ֲ���ʾ����Ч�ʸ���FD_DrawImage��FD_DrawImageEx������
*���������
*hDraw��    ��ͼ��������
*pBits��    ͼ�����ݻ�������ַ��
*ulSize     ͼ�����ݻ�������С��
*rtSorRect��Դͼ���������
*rtDesRect����ʾ����������Դͼ�������������ʾ���������С��һ�£����Զ�������ʾ��
*��������� ��
*/
DRAWUTIL_API
void __stdcall FD_StretchDrawImage(HANDLE hDraw, PVOID pBits, ULONG nSize, RECT rtSorRect, RECT rtDesRect);

///////////////////////////////////////////////////////////////////////////////////////////////////////
/*
*����˵������ָ���Ĵ��ڻ�ͼ���ú�����֧�����ţ���Ч�ʸߣ�CPUռ����С
*���������
*hDraw��    ��ͼ��������
*pBits��    ͼ�����ݻ�������ַ��
*nSize      ͼ�����ݻ�������С��
*nLeft��    ͼ���ڴ�����ʾʱ�����Ͻ�����ڴ���ͻ����ĺ�����
*nTop��     ͼ���ڴ�����ʾʱ�����Ͻ�����ڴ���ͻ�����������
*��������� ��
*/
DRAWUTIL_API
void __stdcall FD_DrawActualImage(HANDLE hDraw, PVOID pBits, UINT nSize, int nLeft, int nTop);

///////////////////////////////////////////////////////////////////////////////////////////////
/*
*����˵�������浱ǰ֡ͼ�񣬱���ͼ��ΪFD_DrawImage������ʾ������ͼ����FD_DrawImage�����
*���������
*		   hDraw����ͼ������
*          szSaveName�������ͼ����
*          FileType�������ļ����ͣ�FILE_BITMAP������ΪBMPͼ��FILE_JPEG������ΪJPEGͼ��
*					 FILE_RAW������Ϊԭʼ�����ļ���
*�����������
*�� �� ֵ����
*/
DRAWUTIL_API
void __stdcall FD_SaveImage(HANDLE hDraw, const char *szSaveName, FD_FILE_TYPE FileType);

/* extren "C" { */
#ifdef __cplusplus
}
#endif

#endif