//FCAM_Def.h
/*
* Copyright (c) 2007, �������ϿƼ��������ι�˾
* All rights reserved.
* 
* �ļ����ƣ�FCAM_Def.h
* �ļ���ʶ��FCAM_Def.h
* ժ    Ҫ��FCAM.dll�������Ͷ���ͷ�ļ�
*
* ����������Microsoft Win32 SDK, Visual C++ 6.00
* 
* ��ǰ�汾��V2.0.7.1116
* ��    �ߣ�����÷
* ������ڣ�2007��11��16��
*
*�ڶ��汾����������ǰ�汾
*/
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
#ifndef __FCAM_DEF_H__
#define __FCAM_DEF_H__
//////////////////////////////////////////////////////////////////////////
#include <windows.h>
///////////////////////////////////////////////////////////////////////////
//������� 
typedef enum enumCAMERATYPE
{
    CAMERA_1394 = 0x00000000,      //1394�ӿ������IKϵ��
    CAMERA_USB  = 0x00000001       //USB�ӿ������ID��IEϵ��

}FCAM_CAMERA_TYPE;
//////////////////////////////////////////////////////////////////////////
//������Ϣ����
typedef enum enumPARAMINFO_TYPE
{
    FEATURE_INFO    = 0x00000000,   //���Բ�����Ϣ����Ӧ��Ϣ�ṹ��FCAM_FEATURE_INFO
    IMAGE_INFO      = 0x00000001,   //��Ƶ������Ϣ����Ӧ��Ϣ�ṹ��FCAM_IMAGE_INFO
    DATATRANS_INFO  = 0x00000002,   //���ݴ�����Ϣ����Ӧ��Ϣ�ṹ��FCAM_DATATRANS_INFO
    HARDWARE_INFO   = 0x00000003,   //Ӳ����Ϣ����Ӧ��Ϣ�ṹ��FCAM_HARDWARE_INFO
    TRIGGER_INFO    = 0x00000004,   //������Ϣ����Ӧ��Ϣ�ṹ��FCAM_TRIGGER_INFO
    STROBE_INFO     = 0x00000005,   //Ƶ������Ϣ����Ӧ��Ϣ�ṹ��FCAM_STROBE_INFO

    INTERFACE_INFO	= 0x00000006    //����ӿ���Ϣ����Ӧ��Ϣ�ṹ��FCAM_INTERFACE_INFO

}FCAM_PARAMINFO_TYPE;

//for CAMERA_FEATURE_INFO---------
//�����������
typedef enum enumCAMERAFEATURETYPE
{
    BRIGHTNESS              = 0x00000000,   //����
    AUTO_EXPOSURE           = 0x00000001,   //�Զ��ع�
    SHARPNESS               = 0x00000002,   //��
    WHITE_BALANCE           = 0x00000003,	//��ƽ��,B��R����
    HUE                     = 0x00000004,   //ɫ��
    SATURATION              = 0x00000005,   //���Ͷ�
    GAMMA                   = 0x00000006,   //٤��У��
	SHUTTER                 = 0x00000007,   //�ع�ʱ�䣬1��32.944us
	ANG_GAIN                = 0x00000008,	//ģ������
	IRIS                    = 0x00000009,   //IRIS����
	FOCUS                   = 0x0000000a,   //�Խ�
	TEMPERATURE             = 0x0000000b,   //�¶�
	TRIG_DELAY              = 0x0000000c,   //�����ӳ�
	WHITE_SHADING           = 0x0000000d,   //ͨ������,R��G��Bͨ��ֵ
	FRAME_RATE_PRIORITYS    = 0x0000000e,   //֡Ƶ����
	ZOOM                    = 0x0000000f,   //�佹
	PAN                     = 0x00000010,   //ң��
	TILT                    = 0x00000011,   //�����б��
	OPTICAL_FILTER          = 0x00000012,   //��ѧ�˲�
	CAPTURE_SIZE_FORMAT6    = 0x00000013,   //F6M0_EXIF_FORMAT��Ƶ��ʽ��Ӧ���������ԣ������С
	CAPTURE_QUALITY_FORMAT6 = 0x00000014,   //F6M0_EXIF_FORMAT��Ƶ��ʽ��Ӧ���������ԣ�ͼ������
	DIGITAL_SHIFT           = 0x00000015,	//����λ��
	BIT_INVERSE             = 0x00000016,	//λ��ת
	PROCESS_SPEED			= 0x00000017,	//����ڲ����������ٶ�
	CLOCK					= 0x00000018	//�����ʱ��Ƶ��
}FCAM_FEATURE_TYPE;

//���Բ������ڷ�ʽ
typedef enum enumAdjustMode
{
	AUTO      = 0x00000000,   //����Զ�����
	MANUAL    = 0x00000001,   //�ֶ����ڣ��û����ڣ�
	ONE_PUSH  = 0x00000002    //���һ�ε���ģʽ

}FCAM_ADJUST_MODE;

//����ֵ����
typedef enum enumValueType
{
	FLOAT_VALUE = 0x00000000,   //������
    LONG_VALUE  = 0x00000001    //����    

}FCAM_VALUE_TYPE;

//FCAM_PARAMINFO_TYPE��FEATURE_INFO��Ӧ�Ľṹ��
typedef struct __CAMERA_FEATURE__
{	

	FCAM_FEATURE_TYPE featureType;   //����������ͣ�Ϊ�������

	BOOL    bAvaliable;              //�����Ե�ǰ�Ƿ���ã�TRUEΪ���ã�FALSEΪ������
	BOOL    bCanOnePush;             //�������Ƿ�֧��one push����ģʽ��TRUE֧�֣�FALSE��֧��
	BOOL    bCanOnOff;               //�������Ƿ�֧��ʹ�ܺͲ�ʹ�ܵ��л�������TRUE֧�֣�FALSE��֧��
	BOOL    bCanReadOut;             //�����ԵĲ���ֵ�Ƿ�ɶ���TRUE֧�֣�FALSE��֧��
	BOOL    bCanAuto;                //�������Ƿ�֧���Զ�����ģʽ��TRUE֧�֣�FALSE��֧��
	BOOL    bCanManual;              //�������Ƿ�֧���ֶ�����ģʽ��TRUE֧�֣�FALSE��֧��

	struct
	{
		
		BOOL       bLongValueValid;     //������Ϣ�Ƿ���Ч����ΪTRUE��lMax_Value��lMin_Value��lStep��Ч����֮��Ч

		LONG       lMax_Value;          //���Ͳ���ֵ�����ֵ
		LONG       lMin_Value;          //���Ͳ���ֵ����Сֵ
		LONG       lStep;               //���Ͳ���ֵ�ĵ�λ����ֵ

		BOOL       bFloatValueValid;    //��������Ϣ�Ƿ���Ч����ΪTRUE��fMax_Value��fMin_Value��fStep��Ч����֮��Ч

		float      fMax_Value;          //�����Ͳ���ֵ�����ֵ
		float      fMin_Value;          //�����Ͳ���ֵ����Сֵ
		float      fStep;               //�����Ͳ���ֵ�ĵ�λ����ֵ

	}FeatureInfoValue;

}FCAM_FEATURE_INFO, *PFCAM_FEATURE_INFO;

typedef struct __FCAM_INTERFACE__
{
	FCAM_CAMERA_TYPE CameraType;  //������ͣ���ΪCAMERA_USB��SUsbSpec�ṹ����Ϣ��Ч

	struct
	{
		BOOL		bIsUsb20;     //������ӵ�USB�ӿ��Ƿ���USB2.0�ӿڣ������ǣ�����޷���������

	}SUsbSpec;
		
}FCAM_INTERFACE_INFO, *PFCAM_INTERFACE_INFO;

//end CAMERA_FEATURE--------------------

//for HARDWARE_INFO---------------------
//HARDWARE_INFO��Ӧ�Ľṹ��
typedef struct __HARDWARE_INFO__
{
	char     VendorName[100];    //������
	char     ModelName[100];     //�ͺ���
	ULONG    ulCameraID[2];      //���ID
	BYTE     byHdEdition[4];     //Ӳ���汾��
    BYTE     byHdUpdateTime[4];  //Ӳ����������

}FCAM_HARDWARE_INFO, *PFCAM_HARDWARE_INFO;
//end HARDWARE_INFO-----------------------

//for IMAGE_INFO--------------------------
//���ظ�ʽ��Ϣ
typedef enum enumPixel_Format
{
	Raw8       = 0x00000000,        //��ɫ�����������8λԭʼ����
	Raw16      = 0x00000001,        //��ɫ�����������16λԭʼ����
	YMono8     = 0x00000002,        //8λ������Ϣ����
	YMono16    = 0x00000003,        //16λ������Ϣ����,�޷���
	S_YMono16  = 0x00000004,        //16λ������Ϣ����,�з���  
	RGB8       = 0x00000005,        //R=B=G=8bit  R-G-B-R-G-B
	RGB16      = 0x00000006,        //R=B=G=16bit R-G-B-R-G-B
	S_RGB16    = 0x00000007,        //R=B=G=16bit,�з�������

	YUV444     = 0x00000008,        //U-Y-V-U-Y-V���У���ռ8bit��pixel bit = 24 
	YUV422     = 0x00000009,        //U-Y-V-Y-U-Y-V-Y���У���ռ8bit,pixel bit = 16
	YUV411     = 0x0000000a         //U-Y-Y-V-Y-Y-U���У���ռ8bit, pixel bit = 12    

}FCAM_PIXEL_FORMAT;

//��Ƶ��ʽ����
typedef enum enumVideoFM
{
	F0M0_160_120YUV444  = 0x00000000,  //ͼ��ֱ���Ϊ160 * 120�����ظ�ʽΪYUV444
	F0M1_320_240YUV422  = 0x00000001,  //ͼ��ֱ���Ϊ320 * 240�����ظ�ʽΪYUV422
	F0M2_640_480YUV411  = 0x00000002,  //ͼ��ֱ���Ϊ640 * 480�����ظ�ʽΪYUV411
	F0M3_640_480YUV422  = 0x00000003,  //ͼ��ֱ���Ϊ640 * 480�����ظ�ʽΪYUV422
	F0M4_640_480RGB8    = 0x00000004,  //ͼ��ֱ���Ϊ640 * 480�����ظ�ʽΪRGB8
	F0M5_640_480YMono8  = 0x00000005,  //ͼ��ֱ���Ϊ640 * 480�����ظ�ʽΪYMono8
	F0M6_640_480YMono16 = 0x00000006,  //ͼ��ֱ���Ϊ640 * 480�����ظ�ʽΪYMono16


	F1M0_800_600YUV422   = 0x00000007, //ͼ��ֱ���Ϊ800 * 600�����ظ�ʽΪYUV422
	F1M1_800_600RGB8     = 0x00000008, //ͼ��ֱ���Ϊ800 * 600�����ظ�ʽΪRGB8
	F1M2_800_600YMono8   = 0x00000009, //ͼ��ֱ���Ϊ800 * 600�����ظ�ʽΪYMono8
	F1M3_1024_768YUV422  = 0x0000000a, //ͼ��ֱ���Ϊ1024 * 768�����ظ�ʽΪYUV422
	F1M4_1024_768RGB8    = 0x0000000b, //ͼ��ֱ���Ϊ1024 * 768�����ظ�ʽΪRGB8
	F1M5_1024_768YMono8  = 0x0000000c, //ͼ��ֱ���Ϊ1024 * 768�����ظ�ʽΪYMono8
	F1M6_800_600YMono16  = 0x0000000d, //ͼ��ֱ���Ϊ800 * 600�����ظ�ʽΪYMono16
	F1M7_1024_768YMono16 = 0x0000000e, //ͼ��ֱ���Ϊ1024 * 768�����ظ�ʽΪYMono16

	F2M0_1280_960YUV422   = 0x0000000f, //ͼ��ֱ���Ϊ1280 * 960�����ظ�ʽΪYUV422
	F2M1_1280_960RGB8     = 0x00000010, //ͼ��ֱ���Ϊ1280 * 960�����ظ�ʽΪRGB8
	F2M2_1280_960YMono8   = 0x00000011, //ͼ��ֱ���Ϊ1280 * 960�����ظ�ʽΪYMono8
	F2M3_1600_1200YUV422  = 0x00000012, //ͼ��ֱ���Ϊ1600 * 1200�����ظ�ʽΪYUV422
	F2M4_1600_1200RGB8    = 0x00000013, //ͼ��ֱ���Ϊ1600 * 1200�����ظ�ʽΪRGB8
	F2M5_1600_1200YMono8  = 0x00000014, //ͼ��ֱ���Ϊ1600 * 1200�����ظ�ʽΪYMono8
	F2M6_1280_960YMono16  = 0x00000015, //ͼ��ֱ���Ϊ1280 * 960�����ظ�ʽΪYMono16
	F2M7_1600_1200YMono16 = 0x00000016, //ͼ��ֱ���Ϊ1600 * 1200�����ظ�ʽΪYMono16

	F6M0_EXIF_FORMAT      = 0x00000017, //��ֹͼ���ʽ

	//�����Զ����ʽ
    F7M0_CUSTOM           = 0x00000018, //�����Զ����ʽ0
	F7M1_CUSTOM           = 0x00000019, //�����Զ����ʽ1
	F7M2_CUSTOM           = 0x0000001a, //�����Զ����ʽ2
	F7M3_CUSTOM           = 0x0000001b, //�����Զ����ʽ3
	F7M4_CUSTOM           = 0x0000001c, //�����Զ����ʽ4
	F7M5_CUSTOM           = 0x0000001d, //�����Զ����ʽ5
	F7M6_CUSTOM           = 0x0000001e, //�����Զ����ʽ6
	F7M7_CUSTOM           = 0x0000001f  //�����Զ����ʽ7

}FCAM_VIDEO_FORMAT;

//֡Ƶ��ʽ
typedef enum enumFRAME_RATE
{
	RATE_1_875    = 0x00000000,    //1.875֡ÿ��
	RATE_3_75     = 0x00000001,    //3.75֡ÿ��
	RATE_7_5      = 0x00000002,    //7.5֡ÿ��
	RATE_15       = 0x00000003,    //15֡ÿ��
	RATE_30       = 0x00000004,    //30֡ÿ��
	RATE_60       = 0x00000005,    //60֡ÿ��
	RATE_120      = 0x00000006,    //120֡ÿ��
	RATE_240      = 0x00000007,    //240֡ÿ��
	RATE_ANY      = 0x00000008,     //֡Ƶ�����ޣ�����Ϊ�κ�ֵ�������Ӳ�����̾���
}FCAM_FRAME_RATE;

//�˹�Ƭ���и�ʽ
typedef enum enumColorFilterArray
{
	NONE  = 0x00000000,    //��Bayer����
	RG_GB = 0x00000001,    //Bayer���У����з�ʽΪ����һ�У�R G R G���� �ڶ��У�G B G B����
	GB_RG = 0X00000002,    //Bayer���У����з�ʽΪ����һ�У�G B G B���� �ڶ��У�R G R G����
	GR_BG = 0x00000003,    //Bayer���У����з�ʽΪ����һ�У�G R G R���� �ڶ��У�B G B G����
	BG_GR = 0x00000004     //Bayer���У����з�ʽΪ����һ�У�B G B G���� �ڶ��У�G R G R����

}FCAM_COLORFILTER_PATTERN;

typedef struct __Image_Info__
{
	FCAM_VIDEO_FORMAT   FormatMode;       //FCAM_VIDEO_FORMAT��Ƶ��ʽ���ͣ��������

	BOOL                bSupport;         //����Ƿ�֧�ָ���Ƶ��ʽ��TRUE֧�֣�FALSE��֧��

	BOOL                bAOI;             //����Ƶ��ʽ�Ƿ�֧�ֿ���������TRUE֧�֣�FALSE��֧��
	ULONG               ulMaxWidthSize;   //����Ƶ��ʽ֧�ֵ�ͼ���ȵ����ֱ���
	ULONG               ulMaxHeightSize;  //����Ƶ��ʽ֧�ֵ�ͼ��߶ȵ����ֱ���
	ULONG               ulLeftPosUnit;    //������ʼ�в�����λ��bAOIΪFALSEʱ�ò�����Ч������
	ULONG               ulTopPosUnit;     //������ʼ�в�����λ��bAOIΪFALSEʱ�ò�����Ч������
	ULONG               ulWidthSizeUnit;  //������Ȳ�����λ��bAOIΪFALSEʱ�ò�����Ч������
	ULONG               ulHeightSizeUnit; //�����߶Ȳ�����λ��bAOIΪFALSEʱ�ò�����Ч������

	FCAM_COLORFILTER_PATTERN  ColorFilterPattern;      //����Ƶ��ʽ�Ĳ�ɫ�˹�Ƭ����ģʽ
	BOOL                      bSupportFrameRate[9];    //��FCAM_1394_FRAME_RATE֡Ƶ��֧��
	BOOL                      bSupportPixelFormat[11]; //��FCAM_PIXEL_FORMAT���ظ�ʽ��֧��
 
	
	FCAM_CAMERA_TYPE    CameraType;   //��ǰ��������ͣ���ΪCAMERA_1394��S1394Spec�ṹ����Ч
     
	struct
	{
		float   fFrameInterval;       //֡���,Ϊ0ֵ������

	}S1394Spec;

}FCAM_IMAGE_INFO, *PFCAM_IMAGE_INFO;
//end IMAGE_INFO----------------------

//for STROBE_INFO---------------------
typedef struct __CAMERA_STROBE_INFO__
{	
	ULONG      ulStrobeIndex;        //Ƶ����ͨ��ѡ�������������0~3

	BOOL       bAvaliable;           //����Ƿ�֧�ָ�·Ƶ���Ʋ�����TRUE��ʾ֧�֣�FALSEΪ��֧��
	BOOL       bCanOnOff;            //��ͨ���Ƿ�֧��ʹ�ܻ��߲�ʹ�ܵ��л�������TRUE֧�֣�FALSE��֧��
	BOOL       bCanReadOut;          //��ͨ���Ĳ���ֵ�Ƿ�ɶ���TRUE�ɶ���FALSE���ɶ�
	BOOL       bCanChangePolarity;   //Ƶ���Ƽ����Ƿ�ɸı䣬TRUE��ʾ���Ըı䣬FALSE���ɸı�

	struct
	{	
		BOOL       bLongValueValid;  //Ƶ���Ʋ����Ƿ����������ֵ������
		LONG       lMax_Value;       //����ֵ���ֵ
		LONG       lMin_Value;       //����ֵ��Сֵ
		LONG	   lStep;		     //���͵��ڲ���ֵ

	
		BOOL       bFloatValueValid;  //Ƶ���Ʋ����Ƿ�����Ը���ֵ������
		float      fMax_Value;        //������ֵ���ֵ
		float      fMin_Value;        //������ֵ��Сֵ
		float	   fStep;	          //������ֵ���ڲ���ֵ

	}StrobeInfoValue; 

}FCAM_STROBE_INFO, *PFCAM_STROBE_INFO;
//--end STROBE_INFO---------------------------------

//for TRIGGER_INFO-----------------------------------
//����Դ����
typedef enum enumTriggerSource
{
	TRIGGER_SOR0     = 0x00000000,     //Ӳ��0����Դ
	TRIGGER_SOR1     = 0x00000001,     //Ӳ��1����Դ
	TRIGGER_SOR2     = 0x00000002,     //Ӳ��2����Դ
	TRIGGER_SOR3     = 0x00000003,     //Ӳ��3����Դ
	TRIGGER_SOR4     = 0x00000004,     //Ӳ��4����Դ
	TRIGGER_SOR5     = 0x00000005,     //Ӳ��5����Դ
	TRIGGER_SOR6     = 0x00000006,     //Ӳ��6����Դ
	TRIGGER_SOFT     = 0x00000007      //�������

}FCAM_TRIGGER_SOURCE;

typedef struct __CAMERA_TRIGGER_INFO__
{	
	BOOL    bAvaliable;               //������Ƿ�֧�ִ������ܣ�TRUE��ʾ֧�֣�FALSEΪ��֧��
	BOOL    bCanOnOff;                //���������Ƿ�֧��ʹ�ܻ��߲�ʹ�ܵ��л�������TRUEΪ֧�֣�FALSE��֧��
	BOOL    bCanReadOut;              //��������ֵ�Ƿ�ɶ���TRUE�ɶ���FALSE���ɶ�         
	BOOL    bCanChangePolarity;       //���������Ƿ�ɸı䣬TRUE��ʾ���Ըı䣬FALSE���ɸı�
	BOOL    bCanReadRawTrgInput;      //ԭʼ���������ź�ֵ�Ƿ�ɶ�����bCanReadOutΪFALSE����ֵ����

	BOOL    bHdTriggerSor[7];         //�����FCAM_TRIGGER_SOURCE�����TRIGGER_SOR0��TRIGGER_SOR6���ִ���ͨ����֧��
	BOOL    bSoftWareTrigger;         //����Ƿ�֧������������ܣ�TRUEΪ֧�֣�FALSEΪ��֧��
	BOOL    bTriggerMode[16];         //�����16�ִ���ģʽ��֧�֣�TRUEΪ֧�֣�����֧��	
	
}FCAM_TRIGGER_INFO, *PFCAM_TRIGGER_INFO;

//end TRIGGER_INFO------------------------------------

//for DATASTREAM_INFO---------------------------------
//���ݴ���ģʽ
typedef enum enumTransType
{
	IDLE            = 0x00000000,     //��ǰ�������������
	ONE_SHOT        = 0x00000001,     //��ǰ����Ĵ�������Ϊ����һ֡ͼ�����ݺ�תΪIDLEģʽ
	MUTI_SHOT       = 0x00000002,     //��ǰ����Ĵ�������Ϊ�����֡ͼ�����ݺ�תΪIDLEģʽ
	CONTINUOUS_SHOT = 0x00000003      //��ǰ����Ĵ�������Ϊ��������

}FCAM_TRANSTYPE;

//1394����Ĵ����ٶ�
typedef enum enum1394Speed
{
	SPEED_100M  = 0x00000000,       //100M bps/s
	SPEED_200M  = 0x00000001,       //200M bps/s
	SPEED_400M  = 0x00000002,       //400M bps/s
	SPEED_800M  = 0x00000003,       //800M bps/s
	SPEED_1_6G  = 0x00000004,       //1600M bps/s
	SPEED_3_2G  = 0x00000005        //3200M bps/s

}FCAM_1394SPEED;

typedef struct __STREAM_INFO__
{
	
	BOOL bCanMutiShot;              //����Ƿ�֧�������ɼ�����ģʽ��TRUEΪ֧�֣�FALSEΪ��֧��
	BOOL bCanContinusShot;          //����Ƿ�֧�ֶ�֡�ɼ�����ģʽ��TRUE֧�֣�FALSE��֧��
	BOOL bCanOneShot;               //����Ƿ�֧�ֵ�֡�ɼ�����ģʽ��TRUE֧�֣�FALSE��֧��

	ULONG    ulMaxStreamBufferCount;     //���ݻ����������������
	ULONG    ulMaxFrameCountOfBuffer;    //���仺�������������֡��

	FCAM_CAMERA_TYPE CameraType;         //������ͣ���ΪCAMERA_1394��S1394Spec�ṹ����Ϣ��Ч

	struct  
	{
		BOOL       bSpeedSupport[6];      //��FCAM_1394SPEED�����6���ٶȵ�֧�֣�TRUEΪ֧�֣�FALSEΪ��֧��
		ULONG      ulMaxChannelNumber;    //���֧�ֵ�������ͨ��ֵ,��0��ʼ
		
	}S1394Spec;

}FCAM_DATATRANS_INFO, *PFCAM_DATATRANS_INFO;

/////////////////////Get/Set�������úͻ�ȡ����//////////////////////////////////////////

typedef enum enumGSP_Parameter
{
	GSP_FEATURE                = 0x00000000,   //���Բ������ͣ���ӦFCAM_GSP_FEATURE�ṹ��

	GSP_IMAGE                  = 0x00000001,   //ͼ��������ͣ���ӦFCAM_GSP_IMAGE�ṹ��
	GSP_TRANS                  = 0x00000002,   //����������ͣ���ӦFCAM_GSP_TRANS�ṹ��            

	GSP_STROBE                 = 0x00000003,   //Ƶ���Ʋ������ͣ���ӦFCAM_GSP_STROBE�ṹ��
	GSP_TRIGGER                = 0x00000004    //�����������ͣ���ӦFCAM_GSP_TRIGGER�ṹ��

}FCAM_GSP_PARAME_TYPE;

//for GSP_FEATURE------------------------------------------
typedef struct __GSP_FEATURE__
{
	FCAM_FEATURE_TYPE FeatureType; //FCAM_FEATURE_TYPE������������ͣ��������

	BOOL             bAvaliable;   //����Ƿ�֧�ָ��������ã�ͬ��FCAM_FEATURE_INFO�е�bAvaliable,ֻ��

	BOOL             bPresentOn;   //��ΪTRUE��������ʹ�ܣ�����ʹ�ܣ�
	                               //��FCAM_FEATURE_INFO�е�bCanOnOffΪFALSE����ò���Ϊֻ�������ɸı�

	FCAM_ADJUST_MODE  AdjustMode;  //FCAM_ADJUST_MODE���Ͷ���ĵ���ģʽ

	BOOL              bValueValid; //����ֵ�Ƿ���Ч����ΪTRUE����ValueType��FeatureValue�е�ֵ��Ч����֮��Ч

	FCAM_VALUE_TYPE   ValueType;    //��ǰ����ֵ���ͣ���FCAM_VALUE_TYPE���塣��ΪFLOAT_VALUE��
	                                //��FloatValue�ṹ����Ч����ΪLONG_VALUE����LongValue�ṹ����Ч

	struct
	{
		ULONG      ulValueCnt;     //��ǰ���Ͳ���ֵ���������Ϊ3
		long       lValue[3];      //��ValueTypeΪLONG_VALUE��ǰuValueCnt��ֵΪ��Ӧ�Ĳ���ֵ

	}LongValue;

	struct
	{
		ULONG      ulValueCnt;      //��ǰ�������ֵ���������Ϊ3
		float      fValue[3];       //��ValueTypeΪFLOAT_VALUE��ǰuValueCnt��ֵΪ��Ӧ�Ĳ���ֵ

	}FloatValue;

}FCAM_GSP_FEATURE, *PFCAM_GSP_FEATURE;

//-for GSP_VIDEO_FORMAT----------------
typedef struct __GSP_IMAGE__
{
	FCAM_VIDEO_FORMAT   FormatMode;    //��ǰ��Ƶ��ʽ
	FCAM_FRAME_RATE     FrameRate;     //��ǰ֡Ƶģʽ

	FCAM_PIXEL_FORMAT   PixelFormat;   //��ǰ�����ظ�ʽ
	ULONG               ulPixelBits;   //����λ��,read only,����ʱ���Ը�ֵ
	
	ULONG               ulLeft;        //��ʾͼ�����ʼ�У�����õ�FCAM_IMAGE_INFO��Ϣ�ṹ���е�bAOIΪTRUEʱ����ֵ�ɰ���ulLeftPosUnit���ã�����ֻ��
	ULONG               ulTop;         //��ʾͼ�����ʼ�С�����õ�FCAM_IMAGE_INFO��Ϣ�ṹ���е�bAOIΪTRUEʱ����ֵ�ɰ���ulTopPosUnit���ã�����ֻ��
	ULONG               ulWidth;       //��ʾͼ��Ŀ�ȣ�����õ�FCAM_IMAGE_INFO��Ϣ�ṹ���е�bAOIΪTRUEʱ����ֵ�ɰ���ulWidthSizeUnit���ã�����ֻ��
	ULONG               ulHeight;      //��ʾͼ��ĸ߶ȣ�����õ�FCAM_IMAGE_INFO��Ϣ�ṹ���е�bAOIΪTRUEʱ����ֵ�ɰ���ulHeightSizeUnit���ã�����ֻ��

	FCAM_CAMERA_TYPE    CameraType;    //������ͣ�����ֵΪCAMERA_1394,S1394Spec�ṹ����Ч������S1394Spec��Ч
	
	struct
	{
		BOOL        bDataVerify;                  //�Ƿ�����ݽ���У�飬��ֵ�ڵ�ǰ�汾����

		BOOL        bPacketSetable;               /*ֻ����������ʾ��ǰ����С�Ƿ���裬TRUEΪ���裬��ulUnitBytePerPacket
						                            ulMaxBytePerPacket��ulRecBytePerPacket��Ч����֮��Ч����ulPacketSizeΪֻ������*/

        ULONG       ulUnitBytePerPacket;          //����С���õ�λ��ҲΪ����С�������Сֵ��ֻ�� 
		ULONG       ulMaxBytePerPacket;           //����С��������ֵ��ֻ��
		ULONG       ulRecBytePerPacket;           //����Ƽ��İ���С��Ϊ0��ʾ���ԣ�ֻ�� 

		ULONG       ulPacketSize;                 //��ǰ����С��������С�����裬��ֵֻ����������С�����Ҹ�ֵΪ0�������С���ú���

		ULONG       ulPacketPerFrame;             //��ǰһ֡ͼ�����ݵİ�������ֻ��
	
	}S1394Spec;
}FCAM_GSP_IMAGE, *PFCAM_GSP_IMAGE;

//for GSP_STROBE-----------------------------
typedef struct __GSP_STROBE__
{

	ULONG             ulStrobeIndex;  //Ƶ����ͨ��ֵ����0-3,�������

	BOOL              bAvaliable;     //����Ƿ�֧��Ƶ����ͨ�����ã�ͬ��ͬ��ͨ��FCAM_STROBE_INFO��Ϣ�е�
                                      //bAvaliable���ò���Ϊֻ����������ֻ�ܻ�ȡ�������á����ò���ΪFALSE��
                                      //�������в���ֵ��Ч

	BOOL              bPresentOn;     //��ΪTRUE������������ʹ�ܣ�����ʹ�ܣ���FCAM_STROBE_INFO�е�bCanOnOffΪFALSE����ò���Ϊֻ������������

	ULONG             ulPolarity;     //Ƶ���Ƽ��ԣ���FCAM_STROBE_INFO�е�bCanChangePolarityΪTRUE����ò����ɶ����裬����ò���ֻ��

	BOOL              bValueValid;    //����ֵ�Ƿ���Ч����ΪTRUE����ValueType��StrobeValue�е�ֵ��Ч����֮��Ч

	FCAM_VALUE_TYPE   ValueType;      //��ǰ����ֵ���ͣ���FCAM_VALUE_TYPE���塣��ΪFLOAT_VALUE����FloatValue�ṹ����Ч��
	                                  //��ΪLONG_VALUE����LongValue�ṹ����Ч
	
	struct 
	{
		LONG       lDelayValue;      //��ValueTypeΪLONG_VALUE����ֵ��Ч��ΪƵ�����ӳ�ʱ�䣬����
		LONG       lDurationValue;   //��ValueTypeΪLONG_VALUE����ֵ��Ч��ΪƵ���Ƴ���ʱ�䣬����

	}LongValue;

	struct 
	{
		float      fDelayValue;      //��ValueTypeΪFLOAT_VALUE����ֵ��Ч��ΪƵ�����ӳ�ʱ�䣬������
		float      fDurationValue;   //��ValueTypeΪFLOAT_VALUE����ֵ��Ч��ΪƵ���Ƴ���ʱ�䣬������
		
	}FloatValue;

	

}FCAM_GSP_STROBE, *PFCAM_GSP_STROBE;

//-for GSP_TRIGGER-------------------
typedef struct __GSP_TRIGGER__
{

	BOOL                bAvaliable;       //����Ƿ�֧�ִ������ã�ͬ��FCAM_TRIGGER_INFO��Ϣ�е�bAvaliable��
	                                      //�ò���Ϊֻ����������ֻ�ܻ�ȡ�������á����ò���ΪFALSE���������в���ֵ��Ч
	
	BOOL                bPresentOn;       //��ΪTRUE������������ʹ�ܣ�����ʹ�ܣ�����Ӧ��FCAM_TRIGGER_INFO��Ϣ�е�bCanOnOffΪFALSE����ò���Ϊֻ������������
 
	ULONG               ulTrgPolarity;    //�������ԣ���FCAM_TRIGGER_INFO�е�bCanChangePolarityΪTRUE����ò����ɶ����裬����ò���ֻ��
	FCAM_TRIGGER_SOURCE TrgSorce;         //����Դ
	ULONG               ulTrgleMode;      //����ģʽ

	BOOL                bValueValid;      //�����ź�ֵ�Ƿ���Ч
	ULONG               ulTrgInputValue;  //�����źţ�ֻ��


}FCAM_GSP_TRIGGER, *PFCAM_GSP_TRIGGER;

//for GSP_TRANS-----------------------
typedef struct __GSP_TRANS__
{
	FCAM_TRANSTYPE   TransMode;            //��ǰ����ģʽ
	ULONG            ulTransFrameCnt;      //��֡����ģʽ�Ĵ���֡����������ģʽΪMUTI_SHOTʱ����ֵ��Ч���������
	  
	ULONG            ulStreamBufferCnt;    //����������ݻ��������������ֵ��ӦFCAM_DATATRANS_INFO�е�uMaxStreamBufferCount

	ULONG            ulFrameCntOfOneBuffer; //һ�����ݻ������洢��֡������ONE_SHOT����ģʽ�£���ֵ����Ϊ1����MUTI_SHOTģʽ�£�
	                                        //��ֵӦ������uTransFrameCnt�����ֵ��ӦFCAM_DATATRANS_INFO�е�uMaxFrameCountOfBuffer
	
	ULONG            ulStreamBufferSize;    //����������ݻ�������С�����ֽ�Ϊ��λ��ֻ��

	FCAM_CAMERA_TYPE CameraType;            //������ͣ�����ֵΪCAMERA_1394ʱ��S1394Spec��Ч��������Ч
        
	struct
	{
		ULONG            ulChannel;         //����ͨ��ֵ�����ֵ��ӦFCAM_DATATRANS_INFO�е�uMaxChannelNumber
		FCAM_1394SPEED  TransSpeed;         //�����ٶȣ��Ը��ٶ����͵�֧�ּ�FCAM_DATATRANS_INFO�е�bSpeedSupport[6]


	}S1394Spec;

}FCAM_GSP_TRANS, *PFCAM_GSP_TRANS;

//value of DIGITAL_SHIFT------------------9/26/2007
//DIGITAL_SHIFT����ֵ��Ӧ������
typedef enum tagVAL_DIGITAL_SHIFT
{
	DS_HIGH_8BITS	= 0,     //�߰�λ
	DS_MID_8BITS	= 1,     //�а�λ
	DS_LOW_8BITS	= 2      //�Ͱ�λ
}VAL_DIGITAL_SHIFT;

//vale of polarity---------------------------26/2007
//��������Ƶ���Ƽ���ֵ��Ӧ������
typedef enum tagVAL_POLARITY
{
	POL_LOW_ACTIVE	= 0,     //�͵�ƽ��Ч
	POL_HIGH_ACTIVE = 1      //�ߵ�ƽ��Ч
}VAL_POLARITY;

/////////////////////////����ֵ����//////////////////////////////////////
#define FCAM_SUCCESS                 0x20000000    //�����ɹ�

#define FCAM_UNSUCCESSFUL            0xE0000000    //����ʧ��
#define FCAM_NO_SUCH_DEVICE          0xE0000001    //�Ҳ���ָ�����豸
#define FCAM_DEVICE_INIT_FAIL        0xE0000002    //�豸��ʼ��ʧ��
#define FCAM_DEVICE_NOT_MATCH        0xE0000003    //�豸��ƥ��
#define FCAM_DEVICE_TRANS_FAILED     0xE0000004    //�豸����ʧ�ܣ��ڻ�ø����͵ķ���ֵ��Ӧ���������������ݴ���
#define FCAM_CONFIGFILE_NOT_MATCH    0xE0000005    //�����ļ���ƥ��

#define FCAM_INVALID_PARAMETER       0xE0000020    //��Ч����
#define FCAM_INVALID_TRIGGER_SOURCE  0xE0000021    //��Ч�Ĵ���Դ
#define FCAM_INVALID_TRIGGER_MODE    0xE0000022    //��Ч�Ĵ���ģʽ
#define FCAM_INVALID_HANDLE_VALUE    0xE0000023    //��Ч�ľ��ֵ

#define FCAM_INSUFFICIENT_RESOURCE   0xE0000040    //��Դ����
#define FCAM_REASONLESS_PARAMETER    0xE0000041    //������Ĳ���
#define FCAM_RESONLESS_PACKETSIZE    0xE0000042    //������İ���С

#define FCAM_FEATURE_NOT_SUPPORT     0xE0000050    //�������Բ�֧��
#define FCAM_VIDEOFORMAT_NOT_SUPPORT 0xE0000051    //��Ƶ��ʽ��֧��
#define FCAM_TRIGGER_NOT_SUPPORT     0xE0000052    //������֧��
#define FCAM_STROBE_NOT_SUPPORT      0xE0000053    //Ƶ����ͨ����֧��
#define FCAM_FRAMERATE_NOT_SUPPORT   0xE0000054    //֡Ƶ��֧��
#define FCAM_PIXELFORMAT_NOT_SUPPORT 0xE0000055    //���ظ�ʽ��֧��
#define FCAM_AOI_NOT_SUPPORT         0xE0000056    //������֧��
#define FCAM_REGISTER_RW_NOT_SUPPORT 0xE0000057    //ĳ��ַ�ļĴ�����д��֧��
#define FCAM_AUTOWHB_NOT_SUPPORT     0xE0000058    //�Զ���ƽ�ⲻ֧��

//add on 2007-11-27 by zxm
#define FCAM_TRANSMODE_NOT_SUPPORT   0xE0000059    //����ģʽ��֧��
#define FCAM_TRANSSPEED_NOT_SUPPORT  0xE0000060    //�����ٶȲ�֧��

#define FCAM_SOFTTRIGGER_BUSY        0xE0000070    //��һ֡�������û�н���    
//////////////////////////////////////////////////////////////////////////////////////
typedef struct __COMMU_INFO__
{
	PVOID              pDataBuffer;             //��ǰ���ݻ������ĵ�ַ
	ULONG              ulDataSizes;             //���ݻ������Ĵ�С���ֽ�Ϊ��λ
	ULONG              ulFrameCountOfData;      //�����ݻ�����������֡��

	ULONG              ulFrameLeft;             //ÿ֡����ͼ��Ŀ�����ʼ����
	ULONG              ulFrameTop;              //ÿ֡����ͼ��Ŀ�����ʼ����
	ULONG              ulFrameWidth;            //ÿ֡����ͼ��Ŀ��
	ULONG              ulFrameHeight;           //ÿ֡����ͼ��ĸ߶�
	ULONG              ulFrameSizes;            //һ֡ͼ�����ݵĴ�С���ֽ�Ϊ��λ
	ULONG              ulFrameAvaliableSizes;   //һ֡ͼ�����ݵ���Ч�ֽ���

	FCAM_PIXEL_FORMAT  PixelFormat;             //���ظ�ʽ
	ULONG              ulFramePixelBits;        //����λ��

	ULONG              ulDeviceIndex;           //��ǰ������
	FCAM_CAMERA_TYPE   CameraType;              //��ǰ�������
	
	PVOID              pUserParam;              //�û��Զ�����������ָ��

}FCAM_COMMU_INFO, *PFCAM_COMMU_INFO;

//�ص�����
typedef int(CALLBACK* PFCAM_CALLBACK)(PFCAM_COMMU_INFO pCommuParam);
//�Զ����ڻص�����
typedef void(CALLBACK* PFCAM_AUTOSET_CALLBACK)(PVOID pParam, PVOID pContext);
//////////////////////////////////////////////////////////////////////////
//��Ϣ����
#define WM_FCAM_MESSAGE     WM_USER + 500         //����Ϣ
#define WM_FCAM_ONE_RSVD    WM_FCAM_MESSAGE + 1   //�յ�ͼ�񻺳�����С��ͼ������
#define WM_FCAM_ONE_FAILED  WM_FCAM_MESSAGE + 2	  //��ȡͼ������ʧ��  
//////////////////////////////////////////////////////////////////////////

#endif