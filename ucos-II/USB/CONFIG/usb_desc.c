/**
  ******************************************************************************
  * @file    usb_desc.c
  * @author  MCD Application Team
  * @version V4.0.0
  * @date    21-January-2013
  * @brief   Descriptors for Joystick Mouse Demo
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* USB Standard Device Descriptor */
const uint8_t HID_Joystick_DeviceDescriptor[HID_JOYSTICK_SIZ_DEVICE_DESC] =
  {
    0x12,                       /*bLength 该描述符的长度*/
    USB_DEVICE_DESCRIPTOR_TYPE, /*bDescriptorType 该描述符的类型 设备描述符呢还是配置描述符等*/
    0x00,                       /*bcdUSB 2字节  本设备使用的usb协议版本*/
    0x02,
    0x00,                       /*bDeviceClass    类代码*/
    0x00,                       /*bDeviceSubClass   子类代码*/
    0x00,                       /*bDeviceProtocol   设备所使用的协议*/
    0x40,                       /*bMaxPacketSize 64    端点0最大包长 取值可为8 16 32 64*/
    0x88,                       /*idVendor (0x0483)  小端模式 BCD码 低字节在前 2字节 厂商ID*/
    0x88,
    0x00,                       /*idProduct = 0x5710   2字节  产品ID*/
    0x06,
    0x00,                       /*bcdDevice rel. 2.00   2字节  设备版本号*/
    0x02,
    1,                          /*Index of string descriptor describing   字符索引不能取相同的
                                                  manufacturer   描述厂商字符串索引*/
    2,                          /*Index of string descriptor describing
                                                 product         描述产品字符串索引*/
    3,                          /*Index of string descriptor describing the
                                                 device serial number   产品序列号字符串索引*/
    0x01                        /*bNumConfigurations   可能的配置数*/
  }
  ; /* Joystick_DeviceDescriptor */


/* USB Configuration Descriptor */
/*   All Descriptors (Configuration, Interface, Endpoint, Class, Vendor */
const uint8_t HID_Joystick_ConfigDescriptor[HID_JOYSTICK_SIZ_CONFIG_DESC] =
  {
    0x09, /* bLength: Configuration Descriptor size 该描述符长度为9个字节*/
    USB_CONFIGURATION_DESCRIPTOR_TYPE, /* bDescriptorType: Configuration  配置描述符为0x02*/
    HID_JOYSTICK_SIZ_CONFIG_DESC,   //配置描述符集合长度  一共34字节  2字节表示
    /* wTotalLength: Bytes returned */
    0x00,
    0x01,         /*bNumInterfaces: 1 interface  该配置所支持的接口数*/
    0x01,         /*bConfigurationValue: Configuration value    该配置的值*/
    0x00,         /*iConfiguration: Index of string descriptor describing
                                     the configuration      描述该配置的字符串的索引值 若为0表示没有字符串*/
    0xE0,         /*bmAttributes: Self powered               该设备的属性，D7保留，默认为1  
																															D6表示设备供电方式，1：自供电的   0；需要总线供电
																															D5表示是否支持远程唤醒， 1：支持远程唤醒  0：不支持
																															D4-D0保留，默认为0*/
    0x32,         /*MaxPower 100 mA: this current is used for detecting Vbus   设备所需的电流，单位为2ma，一个就表示2ma，最大500ma*/

    /************** Descriptor of Joystick Mouse interface ****************/
    /* 09 */
    0x09,         /*bLength: Interface Descriptor size 接口描述符长度 9 */
    USB_INTERFACE_DESCRIPTOR_TYPE,/*bDescriptorType: Interface descriptor type  接口描述符类型 0x04 */
    0x00,         /*bInterfaceNumber: Number of Interface     该接口的编号，，从0开始的*/
    0x00,         /*bAlternateSetting: Alternate setting    该接口的备用编号  */
    0x02,         /*bNumEndpoints                           该接口所使用的端点数  不包括0端点  若为0表示没有非0端点*/
    0x03,         /*bInterfaceClass: HID 										该接口所使用的类*/
    0x00,         /*bInterfaceSubClass : 1=BOOT, 0=no boot  0x01该接口所使用的子类 1：支持引导启动*/
    0x00,         /*nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse 0x02该接口所使用的协议*/
    0,            /*iInterface: Index of string descriptor   描述该接口的字符串的索引值*/
    /******************** Descriptor of Joystick Mouse HID ********************/
    /* 18 */
    0x09,         /*bLength: HID Descriptor size          HID描述的长度*/
    HID_DESCRIPTOR_TYPE, /*bDescriptorType: HID						HID描述类型  0x21*/
    0x00,         /*0bcdHID: HID Class Spec release number	HID类的协议版本 2字节表示*/
    0x01,
    0x00,         /*bCountryCode: Hardware target country  设备适用的国家代码 美国的话为21*/
    0x01,         /*bNumDescriptors: Number of HID class descriptors to follow  下级描述符的数量 至少为1报告/物理描述符*/
    0x22,         /*bDescriptorType																							下级描述符的类型，22：报告描述符
																																																	 23：物理描述符*/
    HID_JOYSTICK_SIZ_REPORT_DESC,/*wItemLength: Total length of Report descriptor   下级报告描述符的长度，2字节*/
    0x00,
    /******************** Descriptor of Joystick Mouse endpoint ********************/
    /* 27 */
    0x07,          /*bLength: Endpoint Descriptor size    端点描述符的长度*/
    USB_ENDPOINT_DESCRIPTOR_TYPE, /*bDescriptorType:			端点描述符的类型*/

    0x81,          /*bEndpointAddress: Endpoint Address (IN)  该端点地址，D7表示传输方向，1：输入 0：输出
																															D6-D4保留，默认为0
																															D3-D0为端点号*/
    0x03,          /*bmAttributes: Interrupt endpoint         该端点的属性， D7-D2保留，默认为0
																															D1-D0表示端点传输类型，0：控制传输 1：等时传输
																																											2：批量传输 3：中断传输*/
    0x40,          /*wMaxPacketSize: 4 Byte max               0x04该端点支持的最大包长度 2字节表示*/
    0x00,
    0x0A,          /*bInterval: Polling Interval (32 ms)			端口查询时间，对于中断传输就是查询帧间隔时间
																															对于其他传输类型，该字段没有意义*/
    /* 34 */
		
		0x07,	/* bLength: Endpoint Descriptor size */
    USB_ENDPOINT_DESCRIPTOR_TYPE,	/* bDescriptorType: */
			/*	Endpoint descriptor type */
    0x01,	/* bEndpointAddress: */
			/*	Endpoint Address (OUT) */
    0x03,	/* bmAttributes: Interrupt endpoint */
    0x40,	/* wMaxPacketSize: 64 Bytes max  */
    0x00,
    0x0A,	/* bInterval: Polling Interval (10 ms) */
  }
  ; /* MOUSE_ConfigDescriptor */
	//   					8 4 2 1         8  4        2  1
/*	前缀1byte bTag（7-4） bType（3 2） bSize（1 0）
							该条目功能  条目类型     前缀后跟字节数 0 1 2 4
													0主条目：输入、输出、特性、集合、关集合
													1全局:选择用途页usage，定义数据长度、数量、报告ID
													2局部  
													3保留  	*/
const uint8_t HID_Joystick_ReportDescriptor[HID_JOYSTICK_SIZ_REPORT_DESC] =
  {										
//		//主项目会对每个操作产生一个报告字段，字段大小由report_size决定，而report_count用来设定主项目报告字段
//		//的数目，其等于操作的数目。
////http://www.cnblogs.com/wzh206/archive/2010/06/13/1757694.html		
//		// 鼠标是三个按键，每个按键占用一个位的字段，则report size = 1，report count = 3，表示有3个操作的项目，
//		//每个项目变化占用一个位.那么鼠标报告符就有三个位
//    0x05,          /*Usage Page(Generic Desktop) 这是一个全局条目（bType为1），选择用途页为 普通桌面，
//										后面跟一个数据（bsize为1）*/
//    0x01,
//    0x09,          /*Usage(Mouse)这是一个局部条目（bType为2），说明接下来的应用集合用途用于鼠标*/
//    0x02,
//    0xA1,          /*Collection(Logical)  这是一个主条目btype为0，开集合，后面跟的0x01表示该集合
//									是一个应用集合，他的性质在前面用途页和用途定义为普通桌面鼠标*/
//    0x01,
//				0x09,          /*Usage(Pointer) 这是一个局部条目，说明用途为指针集合 指针设备*/
//				0x01,
//				/* 8 */
//				0xA1,          /*Collection(Linked) 这是主条目开集合，后面跟0x00表示该集合适合一个物理集合，用途由
//												前面的局部条目定义为指针集合*/
//				0x00,
//						0x05,          /*Usage Page(Buttons) 全局条目，选择用途页为按键（button page0x09）*/
//						0x09,
//						0x19,          /*Usage Minimum(1) 局部条目，用途最小值为1，实际上是鼠标左键*/
//						0x01,
//						0x29,          /*Usage Maximum(3) 局部条目，用途最小值为3，实际上是鼠标中间 1表示左键，2表示右键，3中键*/
//						0x03,
//						/* 16 */
//						//logic num是说明每个报告字段的数值范围，mini（-1）max（1）说明只会出现-1 0 1三种数值，所以需要用两个位来表示
//						//0b11表示-1 0b00表示0 0b01表示1 那么report_size就应该为2，在以下例子中只有0 1两种数字，所以只需要report_size为0就可以表示
//						//report_count表示有多少个操作项
//						0x15,          /*Logical Minimum(0)全局条目，说明返回的数据逻辑值（就是我们返回的数据域的值）最小为0
//														因为这里用“位”来表示一个数据域，因此最小为0，最大为1*/
//						0x00,
//						0x25,          /*Logical Maximum(1) 全局条目，说明逻辑值最大为1*/
//						0x01,
//						0x95,          /*Report Count(3) 全局条目，说明数据域的数量为3个 3bits*/
//						0x03,
//						0x75,          /*Report Size(1) 全局条模 说明每个数据域的长度为1个位*/
//						0x01,
//						/* 24 */
//						0x81,          /*Input(Variable) 主条目，说明有3个长度为1的数据域（数量和长度由前面两个全局条目所定义�
//														用来作为输入，属性为data,var,bas.data表示这些数据是可以变动，var表示这些数据是独立的变量
//														即是每个与表示一个意思，bas表示绝对值，最终结果就是第一个数据域位bit0表示按键（左键）是否按下
//														第二个数据域为bit1表示按键2（右键）是否按下，第三个数据域位bit2表示按键3（中键）是否按下
//														*/
//						0x02,
//						//填充5个bit，补足一个字节
//						0x95,          /*Report Count(1) 全局条目，数据域数量为1个*/
//						0x01,
//						0x75,          /*Report Size(5) 全局条目，每个数据域长度为5位*/
//						0x05,
//						0x81,          /*Input(Constant,Array) 主条目，输入用，由前面两个全局条目可知长度为5数量为1个
//														他的属性为常量（返回的数据一直是0），这个只是为了凑齐1字节（前面用了三个位）而填充的一些数据，没有实际用途*/
//						0x01,
//						/* 32 */
//						0x05,          /*Usage Page(Generic Desktop) 全局条目，用途页为普通桌面*/
//						0x01,
//						0x09,          /*Usage(X axis) 局部条目，用途为x轴*/
//						0x30,
//						0x09,          /*Usage(Y axis) 局部条目，用途为y轴*/
//						0x31,
//						0x09,          /*Usage(Wheel) 局部条目，用途为滚轮*/
//						0x38,
//						/* 40 */
//						0x15,          /*Logical Minimum(-127) 下面两个全局条目，说明返回的逻辑最小和最大值，因为鼠标指针移动通常用相对值表示，
//													指针移动时，只发送移动量。往右移动，x值为正，往下移动y为正，滚轮往上时值为正*/
//						0x81,
//						0x25,          /*Logical Maximum(127)*/
//						0x7F,
//						0x75,          /*Report Size(8) 全局条目，数据域长度为8位*/
//						0x08,
//						0x95,          /*Report Count(3)全局条目，数据域的个数为3个*/
//						0x03,
//						/* 48 */
//						0x81,          /*Input(Variable, Relative) 主条目，三个8位数据是输入用的，属性为data，var，rel
//														第一个8位表示x轴，第二个8位表示y轴，第三个8位表示滚轮，rel表示这些值都是相对值*/
//						0x06,
//				0xC0,          /*End Collection  关闭物理集合*/
//				
//				0x09,   //局部条目用途 运动唤醒，全局条目性质仍然是0x05 0x01 (desktop)
//				0x3c,
//				0x05, //这是一个全局条目用途页，用于用户自定义
//				0xff,
//				0x09, //主条目
//				/* 56 */
//				0x01,
//				0x15,//全局条目，logic_minnum 0
//				0x00,
//				0x25,//全局条目，logic_maxnum 1 由0和1逻辑值得出数据域只有1位
//				0x01,
//				0x75,//report_size 1
//				0x01,
//				0x95,//report_count 2
//				/* 64 */
//				0x02,
//				0xb1,//主条目，feature ，变量、数组、非优选状态
//				0x22,
//				0x75,//全局条目，report_size 6
//				0x06,
//				0x95,  //全局条目，report_count 1
//				0x01,
//				0xb1, //主条目，feature 常量
//				/* 72 */
//				0x01,
//    0xc0  //关闭鼠标应用集合
		
		  	0x05, 0x8c, /* USAGE_PAGE (ST Page) */ 
  	0x09, 0x01, /* USAGE (Demo Kit) */ 
  	0xa1, 0x01, /* COLLECTION (Application) */ 
  	
  	// The Input report 
  	0x09,0x03, // USAGE ID - Vendor defined 
  	0x15,0x00, // LOGICAL_MINIMUM (0) 
  	0x26,0x00, 0xFF, // LOGICAL_MAXIMUM (255) 
  	0x75,0x08, // REPORT_SIZE (8bit) 
  	0x95,0x40, // REPORT_COUNT (64Byte) 
  	0x81,0x02, // INPUT (Data,Var,Abs) 
  
  	// The Output report 
  	0x09,0x04, // USAGE ID - Vendor defined 
  	0x15,0x00, // LOGICAL_MINIMUM (0) 
  	0x26,0x00,0xFF, // LOGICAL_MAXIMUM (255) 
  	0x75,0x08, // REPORT_SIZE (8bit) 
  	0x95,0x40, // REPORT_COUNT (64Byte) 
  	0x91,0x02, // OUTPUT (Data,Var,Abs) 
  
  	0xc0 /* END_COLLECTION */ 
 
  }
  ; /* Joystick_ReportDescriptor */

/* USB String Descriptors (optional) */
const uint8_t HID_Joystick_StringLangID[HID_JOYSTICK_SIZ_STRING_LANGID] =
  {
    HID_JOYSTICK_SIZ_STRING_LANGID,
    USB_STRING_DESCRIPTOR_TYPE,
    0x09,
    0x04
  }
  ; /* LangID = 0x0409: U.S. English  美式英语 一般只用这个*/
//厂商字符串
const u8 HID_Joystick_StringVendor[HID_JOYSTICK_SIZ_STRING_VENDOR] =	    
{
	HID_JOYSTICK_SIZ_STRING_VENDOR, /* Size of manufaturer string */
	USB_STRING_DESCRIPTOR_TYPE,           /* bDescriptorType = String descriptor */
	/* Manufacturer: "广州星翼电子科技有限公司"  UNICODE 编码的字符串 2字节表示一个字符 若是英文，在ascii前
			\u6210\u90fd\u6dde\u5e78\u79d1\u6280\u6709\u9650\u8d23\u4efb\u516c\u53f8	
																				补1字节的0填充为2字节*/
	0x10,0x62,//成
	0xfd,0x90,//都
	0xde,0x6d,//淞
	0x78,0x5e,//幸
	0xd1,0x79,//科
	0x80,0x62,//技
	0x09,0x67,//有
	0x50,0x96,//限
	0x23,0x8d,//责
	0xfb,0x4e,//任
	0x6c,0x51,//公
	0xf8,0x53,//司
//	0X7F,0X5E,//广
//	0XDE,0X5D,//州
//	0X1F,0X66,//星
//	0XFC,0X7F,//翼
//	0X35,0X75,//电
//	0X50,0X5B,//子
//	0XD1,0X79,//科
//	0X62,0X80,//技
//	0X09,0X67,//有
//	0X50,0X96,//限
//	0X6C,0X51,//公
//	0XF8,0X53,//司	  
};
//使用UNICODE编码 产品字符串
const u8 HID_Joystick_StringProduct[HID_JOYSTICK_SIZ_STRING_PRODUCT] =
{
	HID_JOYSTICK_SIZ_STRING_PRODUCT,          /* bLength */
	USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
	'S', 0, 
	'U', 0, 
	'N', 0, 
	'S', 0, 
	'H', 0, 
	'E', 0, 
	'E', 0, 
	'N', 0,//ALIENTEK  小端模式  低位在前
	' ', 0, 
	'U', 0,
	'S', 0, 
	'B', 0,//\u6570\u636e\u4f20\u8f93
	0X70,0X65,//数
	0X6e,0X63,//据
  0x20,0x4f,//传
	0x93,0x8f,//输
};
//产品序列号字符串
uint8_t HID_Joystick_StringSerial[HID_JOYSTICK_SIZ_STRING_SERIAL] =
  {
    HID_JOYSTICK_SIZ_STRING_SERIAL,           /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'S', 0, 
		'T', 0, 
		'M', 0, 
		'3', 0, 
		'2', 0
  };
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
const uint8_t MassStorage_Joystick_DeviceDescriptor[MassStorage_JOYSTICK_SIZ_DEVICE_DESC] =
{
	0x12,   /* bLength  */
	0x01,   /* bDescriptorType */
	0x00,   /* bcdUSB, version 2.00 */
	0x02,
	0x00,   /* bDeviceClass : each interface define the device class */
	0x00,   /* bDeviceSubClass */
	0x00,   /* bDeviceProtocol */
	0x40,   /* bMaxPacketSize0 0x40 = 64 */
	0x83,   /* idVendor     (0483) */
	0x04,
	0x20,   /* idProduct */
	0x57,
	0x00,   /* bcdDevice 2.00*/
	0x02,
	1,              /* index of string Manufacturer  */
	/**/
	2,              /* index of string descriptor of product*/
	/* */
	3,              /* */
	/* */
	/* */
	0x01    /*bNumConfigurations */
};
const uint8_t MassStorage_Joystick_ConfigDescriptor[MassStorage_JOYSTICK_SIZ_CONFIG_DESC] =
  {

    0x09,   /* bLength: Configuration Descriptor size */
    0x02,   /* bDescriptorType: Configuration */
    MassStorage_JOYSTICK_SIZ_CONFIG_DESC,

    0x00,
    0x01,   /* bNumInterfaces: 1 interface */
    0x01,   /* bConfigurationValue: */
    /*      Configuration value */
    0x00,   /* iConfiguration: */
    /*      Index of string descriptor */
    /*      describing the configuration */
    0xC0,   /* bmAttributes: */
    /*      Self powered */
    0x32,   /* MaxPower 100 mA */

    /******************** Descriptor of Mass Storage interface ********************/
    /* 09 */
    0x09,   /* bLength: Interface Descriptor size */
    0x04,   /* bDescriptorType: */
    /*      Interface descriptor type */
    0x00,   /* bInterfaceNumber: Number of Interface */
    0x00,   /* bAlternateSetting: Alternate setting */
    0x02,   /* bNumEndpoints*/
    0x08,   /* bInterfaceClass: MASS STORAGE Class */
    0x06,   /* bInterfaceSubClass : SCSI transparent*/
    0x50,   /* nInterfaceProtocol */
    4,          /* iInterface: */
    /* 18 */
    0x07,   /*Endpoint descriptor length = 7*/
    0x05,   /*Endpoint descriptor type */
    0x81,   /*Endpoint address (IN, address 1) */
    0x02,   /*Bulk endpoint type */
    0x40,   /*Maximum packet size (64 bytes) */
    0x00,
    0x00,   /*Polling interval in milliseconds */
    /* 25 */
    0x07,   /*Endpoint descriptor length = 7 */
    0x05,   /*Endpoint descriptor type */
    0x02,   /*Endpoint address (OUT, address 2) */
    0x02,   /*Bulk endpoint type */
    0x40,   /*Maximum packet size (64 bytes) */
    0x00,
    0x00     /*Polling interval in milliseconds*/
    /*32*/
  };
const uint8_t MassStorage_Joystick_StringLangID[MassStorage_JOYSTICK_SIZ_STRING_LANGID] =
  {
    MassStorage_JOYSTICK_SIZ_STRING_LANGID,
    0x03,
    0x09,
    0x04
  }
  ;    /* LangID = 0x0409: U.S. English */
const u8 MassStorage_Joystick_StringVendor[MassStorage_JOYSTICK_SIZ_STRING_VENDOR] =
{
	MassStorage_JOYSTICK_SIZ_STRING_VENDOR, /* Size of manufaturer string */
	0x03,           /* bDescriptorType = String descriptor */
	/* Manufacturer: "广州星翼电子科技有限公司" */
		0x10,0x62,//成
	0xfd,0x90,//都
	0xde,0x6d,//淞
	0x78,0x5e,//幸
	0xd1,0x79,//科
	0x80,0x62,//技
	0x09,0x67,//有
	0x50,0x96,//限
	0x23,0x8d,//责
	0xfb,0x4e,//任
	0x6c,0x51,//公
	0xf8,0x53,//司
//	0X7F,0X5E,//广
//	0XDE,0X5D,//州
//	0X1F,0X66,//星
//	0XFC,0X7F,//翼
//	0X35,0X75,//电
//	0X50,0X5B,//子
//	0XD1,0X79,//科
//	0X62,0X80,//技
//	0X09,0X67,//有
//	0X50,0X96,//限
//	0X6C,0X51,//公
//	0XF8,0X53,//司	  
};
const u8 MassStorage_Joystick_StringProduct[MassStorage_JOYSTICK_SIZ_STRING_PRODUCT] =
  {
    MassStorage_JOYSTICK_SIZ_STRING_PRODUCT,
    0x03,
//    /* Product name: "ALIENTEK SD卡读卡器" */
//    'A', 0, 'L', 0, 'I', 0, 'E', 0, 'N', 0, 'T', 0, 'E', 0, 'K', 0, ' ', 0, 'S', 0,
//	'D', 0,0X61,0X53,0XFB,0X8B,0X61,0X53,0X68,0X56
	'S', 0, 
	'U', 0, 
	'N', 0, 
	'S', 0, 
	'H', 0, 
	'E', 0, 
	'E', 0, 
	'N', 0,//ALIENTEK  小端模式  低位在前
	' ', 0, 
	0x27,0x59,//大
	0xb9,0x5b,//容
	0xcf,0x91,//量
	0x58,0x5b,//存
	0xa8,0x50,//储
	0x68,0x56,//器
  };

u8 MassStorage_Joystick_StringSerial[MassStorage_JOYSTICK_SIZ_STRING_SERIAL] =
  {
    MassStorage_JOYSTICK_SIZ_STRING_SERIAL,
    0x03,
    /* Serial number*/
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, '1', 0, '0', 0
  };
const u8 MassStorage_Joystick_StringInterface[MassStorage_JOYSTICK_MASS_SIZ_STRING_INTERFACE] =
  {
    MassStorage_JOYSTICK_MASS_SIZ_STRING_INTERFACE,
    0x03,
    /* Interface 0: "ST Mass" */
    'S', 0, 'T', 0, ' ', 0, 'M', 0, 'a', 0, 's', 0, 's', 0
  };
  
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

