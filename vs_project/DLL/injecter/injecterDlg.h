
// injecterDlg.h : ͷ�ļ�
//

#pragma once


// CinjecterDlg �Ի���
class CinjecterDlg : public CDialogEx
{
// ����
public:
	CinjecterDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_INJECTER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
//public:
//	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOpen();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedInject();
};
