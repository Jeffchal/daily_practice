#include "stdafx.h"
#include "CUIThreadApp.h"
#include <iostream>
#include <memory.h>


CUIThreadApp::CUIThreadApp()
{
}


CUIThreadApp::~CUIThreadApp()
{
	
}

//������
//������أ�����ͼѡ���Ӧ���࣬�������-��д����ɫС��ť��
BOOL CUIThreadApp::InitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	
	//���ģ��Ի���
	//CTESTDlg dlg; 
	//dlg.DoModal();
	//return FALSE;

	//��ӷ�ģ��Ի���
	//CTESTDlg *pTestDlg = new CTESTDlg();
	std::unique_ptr<CTESTDlg> pTestDlg(new CTESTDlg());
	pTestDlg->Create(IDD_DIALOG1);
	pTestDlg->ShowWindow(SW_SHOW);
	//return TRUE;
	pTestDlg->RunModalLoop(); //ִ��ģ̬����ѭ��
	return FALSE;


}


int CUIThreadApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	return CWinThread::ExitInstance();
}


