#include "ds1302.h"
#include "sys.h"
#include "delay.h"
 
struct TIMEData TimeData;
u8 read_time[7];
 
//void ds1302_gpio_init()//CE,SCLK�˿ڳ�ʼ��
//{
//GPIO_InitTypeDef GPIO_InitStructure;
//RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; //PC.11  CE
//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//�������
//GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIOC.11
//GPIO_ResetBits(GPIOC,GPIO_Pin_11); 
// 
//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; //PC.12  SCLK
//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//�������
//GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIOC.12
//GPIO_ResetBits(GPIOC,GPIO_Pin_12); 
//}
// 
void ds1032_DATAOUT_init()//����˫��I/O�˿�Ϊ���̬
{
GPIO_InitTypeDef GPIO_InitStructure;
__HAL_RCC_GPIOB_CLK_ENABLE();
 
GPIO_InitStructure.Pin = DS_DAT_Pin; //  DATA
GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
GPIO_InitStructure.Mode =  GPIO_MODE_OUTPUT_PP;
HAL_GPIO_Init(DS_DAT_GPIO_Port, &GPIO_InitStructure);//��ʼ��GPIOC.10
HAL_GPIO_WritePin(DS_DAT_GPIO_Port,DS_DAT_Pin,0);
}
 
void ds1032_DATAINPUT_init()//����˫��I/O�˿�Ϊ����̬
{
GPIO_InitTypeDef GPIO_InitStructure;
__HAL_RCC_GPIOB_CLK_ENABLE();
GPIO_InitStructure.Pin = DS_DAT_Pin; // DATA
GPIO_InitStructure.Mode = GPIO_MODE_INPUT ;
HAL_GPIO_Init(DS_DAT_GPIO_Port, &GPIO_InitStructure);//��ʼ��GPIOC.10
}
 
 
void ds1302_write_onebyte(u8 data)//��DS1302����һ�ֽ�����
{
ds1032_DATAOUT_init();
    
u8 count=0;
SCLK_L;
for(count=0;count<8;count++)
	{	SCLK_L;
		if(data&0x01)
		{DATA_H;}
		else{DATA_L;}//��׼���������ٷ���
		SCLK_H;//����ʱ���ߣ���������
		data>>=1;
	}
}
 
void ds1302_wirte_rig(u8 address,u8 data)//��ָ���Ĵ�����ַ��������
{
u8 temp1=address;
u8 temp2=data;
CE_L;SCLK_L;delay_us(1);
CE_H;delay_us(2);
ds1302_write_onebyte(temp1);
ds1302_write_onebyte(temp2);
CE_L;SCLK_L;delay_us(2);
}
 
u8 ds1302_read_rig(u8 address)//��ָ����ַ��ȡһ�ֽ�����
{
u8 temp3=address;
u8 count=0;
u8 return_data=0x00;
CE_L;SCLK_L;delay_us(3);
CE_H;delay_us(3);
ds1302_write_onebyte(temp3);
//ds1302_DATAINPUT_init();//����I/O��Ϊ����
delay_us(2);
for(count=0;count<8;count++)
	{
	delay_us(2);//ʹ��ƽ����һ��ʱ��
	return_data>>=1;
	SCLK_H;delay_us(4);//ʹ�ߵ�ƽ����һ��ʱ��
	SCLK_L;delay_us(14);//��ʱ14us����ȥ��ȡ��ѹ������׼ȷ
	if(HAL_GPIO_ReadPin(DS_DAT_GPIO_Port,DS_DAT_Pin))
	{return_data=return_data|0x80;}
	
	}
delay_us(2);
CE_L;DATA_L;
return return_data;
}
 
void ds1302_init()
{
ds1302_wirte_rig(0x8e,0x00);//�ر�д����
ds1302_wirte_rig(0x80,0x37);//seconds37��
ds1302_wirte_rig(0x82,0x20);//minutes20��
ds1302_wirte_rig(0x84,0x22);//hours22ʱ
ds1302_wirte_rig(0x86,0x12);//date12��
ds1302_wirte_rig(0x88,0x12);//months12��
ds1302_wirte_rig(0x8a,0x02);//days������
ds1302_wirte_rig(0x8c,0x23);//year2023��
ds1302_wirte_rig(0x8e,0x80);//�ر�д����
}

void ds1302_write_time(int hour,int minute)
{
     
     int h=((hour/10)<<4)+(hour%10);
     int m=((minute/10)<<4)+(minute%10);
ds1302_wirte_rig(0x8e,0x00);//�ر�д����
//ds1302_wirte_rig(0x80,0x37);//seconds37��
ds1302_wirte_rig(0x82,m);//minutes20��
ds1302_wirte_rig(0x84,h);//hours22ʱ
//ds1302_wirte_rig(0x86,0x12);//date12��
//ds1302_wirte_rig(0x88,0x12);//months12��
//ds1302_wirte_rig(0x8a,0x02);//days������
//ds1302_wirte_rig(0x8c,0x23);//year2023��
ds1302_wirte_rig(0x8e,0x80);//�ر�д����
}
 
void ds1302_read_time()
{
read_time[0]=ds1302_read_rig(0x81);//����
read_time[1]=ds1302_read_rig(0x83);//����
read_time[2]=ds1302_read_rig(0x85);//��ʱ
read_time[3]=ds1302_read_rig(0x87);//����
read_time[4]=ds1302_read_rig(0x89);//����
read_time[5]=ds1302_read_rig(0x8B);//������
read_time[6]=ds1302_read_rig(0x8D);//����
}
 
void ds1302_read_realTime()
{
ds1302_read_time();  //BCD��ת��Ϊ10����
TimeData.second=(read_time[0]>>4)*10+(read_time[0]&0x0f);
TimeData.minute=((read_time[1]>>4)&(0x07))*10+(read_time[1]&0x0f);
TimeData.hour=(read_time[2]>>4)*10+(read_time[2]&0x0f);
TimeData.day=(read_time[3]>>4)*10+(read_time[3]&0x0f);
TimeData.month=(read_time[4]>>4)*10+(read_time[4]&0x0f);
TimeData.week=read_time[5];
TimeData.year=(read_time[6]>>4)*10+(read_time[6]&0x0f)+2000;
}