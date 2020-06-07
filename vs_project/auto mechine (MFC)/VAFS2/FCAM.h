//FCAM.h
/*
* Copyright (c) 2006, �������ϿƼ��������ι�˾
* All rights reserved.
* 
* �ļ����ƣ�FCAM.h
* �ļ���ʶ��FCAM.h
* ժ    Ҫ��FCAM.dll�����������
*
* ����������Microsoft Win32 SDK, Visual C++ 6.00
* 
* ��ǰ�汾��V2.0.7.1116
* ��    �ߣ�����÷
* ������ڣ�2007��11��16��
*
*/
//////////////////////////////////////////////////////////////////////

#ifndef __FCAM_H__
#define __FCAM_H__

#include "FCAM_Def.h"

#ifdef FCAM_EXPORTS
#define FCAM_API __declspec(dllexport)
#else
#define FCAM_API __declspec(dllimport)
#endif

//////////////////////////////////////////////////////////////////////////
/*
*����˵��: ���ָ�����кź�������͵���������
*�������: uDeviceIndex:  ������кţ���1��ʼ��
           CameraType:    �������,��FCAM_Def.h�ļ���FCAM_CAMERA_TYPE���Ͷ��塣
*�������: �ޡ� 
*�� �� ֵ: �ɹ����ش����������豸��������򷵻�NULL��
*/
FCAM_API HANDLE __stdcall FCAM_GetDevice(UINT uDeviceIndex, FCAM_CAMERA_TYPE CameraType);

/*

*����˵��: �ͷŻ�ȡ���豸�����
*�������: hDev:  ���ͷŵ��豸�����
*�������: �ޡ� 
*�� �� ֵ: �ɹ�����FCAM_SUCCESS�����򷵻���Ӧ�Ĵ�����롣

ע: FCAM_GetDevice������FCAM_ReleaseDevice���ʹ�ã���ʹ��n��FCAM_GetDevice��
    ��Ӧ��Ҫ����n��FCAM_ReleaseDevice������������ȷ�ͷ��豸�����

*/
FCAM_API HRESULT __stdcall FCAM_ReleaseDevice(HANDLE hDev);

/*
*����˵��: ����豸��������ü�����������FCAM_GetDevice�ɹ��Ĵ���������������ü�
           ���ε�FCAM_ReleaseDevice�������������豸����

*�������: hDev:   �ѻ�ȡ���豸�����
*�������: �ޡ� 
*�� �� ֵ: �����豸��������ü�����
*/
FCAM_API int __stdcall FCAM_GetDeviceReferenceCount(HANDLE hDev);

/*
*����˵��: ����������ݴ�������
*�������: hDev: ��ȡ���豸���
*�������: ��
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������
*/
FCAM_API HRESULT __stdcall FCAM_StartCapture(HANDLE hDev);

/*
*����˵��: ȡ��(ֹͣ)��������ݴ���
*�������: hDev: ��ȡ���豸���
*�������: ��
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������
*/
FCAM_API HRESULT __stdcall FCAM_StopCapture(HANDLE hDev);

/*
*����˵��: ������������Ͳ����ĵ�ǰֵ
*�������: hDev:          ��ȡ���豸���
*          uType:         FCAM_GSP_PARAME_TYPEö�����ͣ����FCAM_Def.h�ļ�
*          pParamStruct:  uType����Ӧ�Ľṹ��ָ�룬�����洢���õĲ���ֵ
*�������: ��
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������
*/
FCAM_API HRESULT __stdcall FCAM_SetParameter(HANDLE hDev, FCAM_GSP_PARAME_TYPE uType, PVOID pParamStruct);

/*
*����˵��: ��ȡ��������Ͳ����ĵ�ǰֵ
*�������: hDev:          ��ȡ���豸���
*          uType:         FCAM_GSP_PARAME_TYPEö�����ͣ����FCAM_Def.h�ļ�
*          pParamStruct:  uType����Ӧ�Ľṹ��ָ�룬�����洢��ȡ���Ĳ����ĵ�ǰֵ
*�������: ��
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������
*/
FCAM_API HRESULT __stdcall FCAM_GetParameter(HANDLE hDev, FCAM_GSP_PARAME_TYPE uType, PVOID pParamStruct);

/*
*����˵��: ��ȡ�������������Ϣ
*�������: hDev:               ��ȡ���豸���
*          uType:              FCAM_PARAMINFO_TYPE��Ϣ�������ͣ���FCAM_Def.h�ļ�
*          pParamInfoStruct:   uType����Ӧ�Ĵ洢������Ϣ�Ľṹ��ָ�� 
*�������: ��
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������ 
*/
FCAM_API HRESULT __stdcall FCAM_GetParameterInfo(HANDLE hDev, FCAM_PARAMINFO_TYPE uType, PVOID pParamInfoStruct);
//////////////////////////////////////////////////////////////////////////
//���ݻ�ȡ
/*
*����˵��: ��ȡһ��ͼ�����ݻ�����ָ�룬������FCAM_PutInFrameBuffer�ɶ�ʹ��
*�������: hDev:              ��ȡ���豸�����
           pBuffer:           �洢ͼ������ָ��Ļ�������ַ��
           pulBufferSizes:    �洢buffer��С�Ļ�������ַ,��С���ֽ�Ϊ��λ��
           dwWaitMillTime:    ��ȡ�����ĵȴ�ʱ�䡣
*�������: ��
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������ 
*/
FCAM_API HRESULT __stdcall FCAM_GetOutFrameBuffer(HANDLE hDev, PVOID &pBuffer, ULONG &ulBufferSizes, DWORD dwWaitMillTime);

/*
*����˵��: �黹��ȡ��ͼ�����ݻ�����ָ��
*�������: hDev:         ��ȡ���豸���
*          pBuffer:      ��ȡ��ͼ������ָ��
*�������: ��
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������ 
*/
FCAM_API HRESULT __stdcall FCAM_PutInFrameBuffer(HANDLE hDev, PVOID pBuffer);
/////////////////////////////////////////////////////////////////////////////////////////////////
//�������
/*
*����˵������ǰ�豸״̬Ϊ�������ʱ����һ����������źţ�����ӵ��źź�ʼ�ع⣬һ֡ͼ���ع���Ϻ�
*		   ֹͣ�ع⣬�ȴ���һ�������źš���
*���������hDev����ȡ���豸���
*����������ޡ�
*�� �� ֵ�������ɹ��򷵻�FCAM_SUCCESS������Ϊ��Ӧ�Ĵ����롣
*/
FCAM_API HRESULT __stdcall FCAM_SoftWareTrigger(HANDLE hDev);
/////////////////////////////////////////////////////////////////////////////////////////////////
//�������
/*
*����˵��: ���浱ǰ��������õ�ָ���ļ�
*�������: hDev:          ��ȡ���豸���
		   pFileName:     ָ���ļ���
*�������: ��
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������
*/
FCAM_API HRESULT __stdcall FCAM_SaveCameraConfiguration(HANDLE hDev, const char *pFileName);

/*
*����˵��: ��ָ���ļ��ж�ȡ�����������Ϣ�����ص�����У�����ǰ�����ѽ�������ֹͣ������ٵ��øú���
*�������: hDev:          ��ȡ���豸���
		   pFileName:     ָ���ļ���
*�������: ��
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������
*/
FCAM_API HRESULT __stdcall FCAM_LoadCameraConfiguration(HANDLE hDev, const char *pFileName);

//////////////////////////////////////////////////////////////////////////
//�Ĵ�����д
/*
*����˵��: ָ����ַ�Ĵ�����
*�������: hDev:          ��ȡ���豸���
		   ucRegAddr:     �Ĵ�����ַ
		   ucValue:       ��ȡ��ȡ�������ݵ����飬4�ֽ�
*�������: ��
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������
*/
FCAM_API HRESULT __stdcall FCAM_ReadRegister(HANDLE hDev, UCHAR ucRegAddr[4], UCHAR ucValue[4]);

/*
*����˵��: ָ����ַ�Ĵ���д
*�������: hDev:          ��ȡ���豸���
		   ucRegAddr:     �Ĵ�����ַ
		   ucValue:       ��ȡд������ݵ����飬4�ֽ�
*�������: ��
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������
*/
FCAM_API HRESULT __stdcall FCAM_WriteRegister(HANDLE hDev, UCHAR ucRegAddr[4], UCHAR ucValue[4]);

//////////////////////////////////////////////////////////////////////////
//�豸�¼�����
/*
*����˵��: ����������Ļص��������ú�����ÿ����һ�����ݻ������󣬸ú���������һ��
*�������: hDev:         ��ȡ���豸���
           pCallBack:    �ص����̺�����ַ
           pUserParam:   �û��Զ���ṹ��ָ��, ���FCAM_Def.h�ļ�
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������
*/
FCAM_API HRESULT __stdcall FCAM_SetStreamCallBackRoutine(HANDLE hDev, PFCAM_CALLBACK pCallBack, PVOID pUserParam);

/*
*����˵��: ������������¼�֪ͨ���ھ��, ��ÿ������һ��buffer���ô��ڽ����յ�WM_FCAM_MESSAGE���͵���Ϣ
           ��Ϣ���FCAM_Def.h�ļ�
*�������: hDev:         ��ȡ���豸���
           hMsgWnd:      ��Ϣ���մ��ھ��
		   pUserParam:   �û��Զ���ṹ��ָ��, ���FCAM_Def.h�ļ�
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������
*/
FCAM_API HRESULT __stdcall FCAM_SetMessageNotifyWindow(HANDLE hDev, HWND hMsgWnd, PVOID pUserParam);
//////////////////////////////////////////////////////////////////////////
//����Զ����ڣ�Ŀǰֻ���FUNCTION-TECH��130���������
/*
*����˵��: ����������Զ���ƽ����ڣ���������Ϊͼ����������480*360, ��ͼ���С���㣬��ȫͼ����
*�������: hDev:               ��ȡ���豸���
           pAutoCallBack:      �ص����������Զ���ƽ�������Ϻ󣬸ú���������
           pAutoContext:       �û��������pAutoCallBack�������õ�������ָ��
*����ֵ:   �ɹ�����FCAM_SUCCESS,���򷵻���Ӧ�Ĵ������
*/
FCAM_API HRESULT __stdcall FCAM_SetDoAutoWHB(HANDLE hDev, PFCAM_AUTOSET_CALLBACK pAutoCallBack, PVOID pAutoContext);

//////////////////////////////////////////////////////////////////////////


#endif
