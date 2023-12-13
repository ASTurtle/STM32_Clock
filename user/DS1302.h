#ifndef __ds1302_H 
#define __ds1302_H  
 #include "main.h"
 #include "gpio.h"
#include "sys.h" 
 
 
#define CE_L HAL_GPIO_WritePin(DS_RST_GPIO_Port,DS_RST_Pin,GPIO_PIN_RESET)//����ʹ��λ
#define CE_H HAL_GPIO_WritePin(DS_RST_GPIO_Port,DS_RST_Pin,GPIO_PIN_SET)//����ʹ��λ
#define SCLK_L HAL_GPIO_WritePin(DS_SCK_GPIO_Port,DS_SCK_Pin,GPIO_PIN_RESET)//����ʱ����
#define SCLK_H  HAL_GPIO_WritePin(DS_SCK_GPIO_Port,DS_SCK_Pin,GPIO_PIN_SET)//����ʱ����
#define DATA_L  HAL_GPIO_WritePin(DS_DAT_GPIO_Port,DS_DAT_Pin,GPIO_PIN_RESET)//����������
#define DATA_H  HAL_GPIO_WritePin(DS_DAT_GPIO_Port,DS_DAT_Pin,GPIO_PIN_SET)//����������
 
struct TIMEData
{
	u16 year;
	u8  month;
	u8  day;
	u8  hour;
	u8  minute;
	u8  second;
	u8  week;
};//����TIMEData�ṹ�巽��洢ʱ����������
extern struct TIMEData TimeData;//ȫ�ֱ���
void ds1302_gpio_init();//ds1302�˿ڳ�ʼ��
void ds1302_write_onebyte(u8 data);//��ds1302����һ�ֽ�����
void ds1302_wirte_rig(u8 address,u8 data);//��ָ���Ĵ���дһ�ֽ�����
u8 ds1302_read_rig(u8 address);//��ָ���Ĵ�����һ�ֽ�����
void ds1302_init();//ds1302��ʼ������
void ds1302_DATAOUT_init();//IO�˿�����Ϊ���
void ds1302_DATAINPUT_init();//IO�˿�����Ϊ����
void ds1302_read_time();//��ds1302��ȡʵʱʱ�䣨BCD�룩
void ds1302_read_realTime();//��BCD��ת��Ϊʮ��������
void ds1302_write_time(int hour,int minute);   //д��ʱ��
 
#endif