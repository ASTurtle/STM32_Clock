/**
 ****************************************************************************************************
 * @file        usart.c
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2020-03-12
 * @brief       ���ڳ�ʼ������(һ���Ǵ���1)��֧��printf
 * @license     Copyright (c) 2020-2032, �������������ӿƼ����޹�˾
 ****************************************************************************************************
 * @attention
 *
 * ʵ��ƽ̨:����ԭ�� STM32H750������
 * ������Ƶ:www.yuanzige.com
 * ������̳:www.openedv.com
 * ��˾��ַ:www.alientek.com
 * �����ַ:openedv.taobao.com
 *
 * �޸�˵��
 * V1.0 20200312
 * ��һ�η���
 *
 ****************************************************************************************************
 */

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/atk_usart.h"
#include "./BSP/ATK_MS901M/atk_ms901m.h"

/* ���ʹ��os,����������ͷ�ļ�����. */
#if SYS_SUPPORT_OS
#include "includes.h"   /* os ʹ�� */
#endif

///******************************************************************************************/
///* �������´���, ֧��printf����, ������Ҫѡ��use MicroLIB */

//#if 1
//#if (__ARMCC_VERSION >= 6010050)            /* ʹ��AC6������ʱ */
//__asm(".global __use_no_semihosting\n\t");  /* ������ʹ�ð�����ģʽ */
//__asm(".global __ARM_use_no_argv \n\t");    /* AC6����Ҫ����main����Ϊ�޲�����ʽ�����򲿷����̿��ܳ��ְ�����ģʽ */

//#else
///* ʹ��AC5������ʱ, Ҫ�����ﶨ��__FILE �� ��ʹ�ð�����ģʽ */
//#pragma import(__use_no_semihosting)

//struct __FILE
//{
//    int handle;
//    /* Whatever you require here. If the only file you are using is */
//    /* standard output using printf() for debugging, no file handling */
//    /* is required. */
//};

//#endif

///* ��ʹ�ð�����ģʽ��������Ҫ�ض���_ttywrch\_sys_exit\_sys_command_string����,��ͬʱ����AC6��AC5ģʽ */
//int _ttywrch(int ch)
//{
//    ch = ch;
//    return ch;
//}

///* ����_sys_exit()�Ա���ʹ�ð�����ģʽ */
//void _sys_exit(int x)
//{
//    x = x;
//}

//char *_sys_command_string(char *cmd, int len)
//{
//    return NULL;
//}

///* FILE �� stdio.h���涨��. */
//FILE __stdout;

///* �ض���fputc����, printf�������ջ�ͨ������fputc����ַ��������� */
//int fputc(int ch, FILE *f)
//{
//    while ((USART_UX->ISR & 0X40) == 0);    /* �ȴ���һ���ַ�������� */

//    USART_UX->TDR = (uint8_t)ch;            /* ��Ҫ���͵��ַ� ch д�뵽DR�Ĵ��� */
//    return ch;
//}
//#endif
///***********************************************END*******************************************/

#if USART_EN_RX     /* ���ʹ���˽��� */

/* ���ջ���, ���USART_REC_LEN���ֽ�. */
uint8_t g_usart_rx_buf[USART_REC_LEN];

/*  ����״̬
 *  bit15��      ������ɱ�־
 *  bit14��      ���յ�0x0d
 *  bit13~0��    ���յ�����Ч�ֽ���Ŀ
*/
uint16_t g_usart_rx_sta = 0;

uint8_t g_rx_buffer[RXBUFFERSIZE];    /* HAL��ʹ�õĴ��ڽ��ջ��� */

UART_HandleTypeDef g_uart1_handle;    /* UART��� */


/**
 * @brief       ����X��ʼ������
 * @param       baudrate: ������, �����Լ���Ҫ���ò�����ֵ
 * @note        ע��: ����������ȷ��ʱ��Դ, ���򴮿ڲ����ʾͻ������쳣.
 *              �����USART��ʱ��Դ��sys_stm32_clock_init()�������Ѿ����ù���.
 * @retval      ��
 */
void usart_init(uint32_t baudrate)
{
    g_uart1_handle.Instance = USART_UX;                    /* USART1 */
    g_uart1_handle.Init.BaudRate = baudrate;               /* ������ */
    g_uart1_handle.Init.WordLength = UART_WORDLENGTH_8B;   /* �ֳ�Ϊ8λ���ݸ�ʽ */
    g_uart1_handle.Init.StopBits = UART_STOPBITS_1;        /* һ��ֹͣλ */
    g_uart1_handle.Init.Parity = UART_PARITY_NONE;         /* ����żУ��λ */
    g_uart1_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;   /* ��Ӳ������ */
    g_uart1_handle.Init.Mode = UART_MODE_TX_RX;            /* �շ�ģʽ */
    HAL_UART_Init(&g_uart1_handle);                        /* HAL_UART_Init()��ʹ��UART1 */
    
    /* �ú����Ὺ�������жϣ���־λUART_IT_RXNE���������ý��ջ����Լ����ջ��������������� */
    HAL_UART_Receive_IT(&g_uart1_handle, (uint8_t *)g_rx_buffer, RXBUFFERSIZE);
}

/**
 * @brief       UART�ײ��ʼ������
 * @param       huart: UART�������ָ��
 * @note        �˺����ᱻHAL_UART_Init()����
 *              ���ʱ��ʹ�ܣ��������ã��ж�����
 * @retval      ��
 */
//void HAL_UART_MspInit(UART_HandleTypeDef *huart)
//{
//    GPIO_InitTypeDef gpio_init_struct;
//    if(huart->Instance == USART1)                                   /* ����Ǵ���1�����д���1 MSP��ʼ�� */
//    {
//        USART_UX_CLK_ENABLE();                                      /* USART1 ʱ��ʹ�� */
//        USART_TX_GPIO_CLK_ENABLE();                                 /* ��������ʱ��ʹ�� */
//        USART_RX_GPIO_CLK_ENABLE();                                 /* ��������ʱ��ʹ�� */

//        gpio_init_struct.Pin = USART_TX_GPIO_PIN;                   /* TX���� */
//        gpio_init_struct.Mode = GPIO_MODE_AF_PP;                    /* ����������� */
//        gpio_init_struct.Pull = GPIO_PULLUP;                        /* ���� */
//        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;              /* ���� */
//        gpio_init_struct.Alternate = USART_TX_GPIO_AF;              /* ����ΪUSART1 */
//        HAL_GPIO_Init(USART_TX_GPIO_PORT, &gpio_init_struct);       /* ��ʼ���������� */

//        gpio_init_struct.Pin = USART_RX_GPIO_PIN;                   /* RX���� */
//        gpio_init_struct.Alternate = USART_RX_GPIO_AF;              /* ����ΪUSART1 */
//        HAL_GPIO_Init(USART_RX_GPIO_PORT, &gpio_init_struct);       /* ��ʼ���������� */

//#if USART_EN_RX
//        HAL_NVIC_EnableIRQ(USART_UX_IRQn);                          /* ʹ��USART1�ж�ͨ�� */
//        HAL_NVIC_SetPriority(USART_UX_IRQn, 3, 3);                  /* ��ռ���ȼ�3�������ȼ�3 */
//#endif
//    }
//    else if (huart->Instance == ATK_MS901M_UART_INTERFACE)              /* �����ATK-MS901M UART */
//    {
//        ATK_MS901M_UART_TX_GPIO_CLK_ENABLE();                           /* ʹ��UART TX����ʱ�� */
//        ATK_MS901M_UART_RX_GPIO_CLK_ENABLE();                           /* ʹ��UART RX����ʱ�� */
//        ATK_MS901M_UART_CLK_ENABLE();                                   /* ʹ��UARTʱ�� */
//        
//        gpio_init_struct.Pin        = ATK_MS901M_UART_TX_GPIO_PIN;      /* UART TX���� */
//        gpio_init_struct.Mode       = GPIO_MODE_AF_PP;                  /* ����������� */
//        gpio_init_struct.Pull       = GPIO_NOPULL;                      /* �������� */
//        gpio_init_struct.Speed      = GPIO_SPEED_FREQ_HIGH;             /* ���� */
//        gpio_init_struct.Alternate  = ATK_MS901M_UART_TX_GPIO_AF;       /* ����ΪUSART2 */
//        HAL_GPIO_Init(ATK_MS901M_UART_TX_GPIO_PORT, &gpio_init_struct); /* ��ʼ��UART TX���� */
//        
//        gpio_init_struct.Pin        = ATK_MS901M_UART_RX_GPIO_PIN;      /* UART RX���� */
//        gpio_init_struct.Mode       = GPIO_MODE_AF_PP;                  /* ����������� */
//        gpio_init_struct.Pull       = GPIO_NOPULL;                      /* �������� */
//        gpio_init_struct.Speed      = GPIO_SPEED_FREQ_HIGH;             /* ���� */
//        gpio_init_struct.Alternate  = ATK_MS901M_UART_RX_GPIO_AF;       /* ����ΪUSART2 */
//        HAL_GPIO_Init(ATK_MS901M_UART_RX_GPIO_PORT, &gpio_init_struct); /* ��ʼ��UART RX���� */
//        
//        HAL_NVIC_SetPriority(ATK_MS901M_UART_IRQn, 0, 0);               /* ��ռ���ȼ�0�������ȼ�0 */
//        HAL_NVIC_EnableIRQ(ATK_MS901M_UART_IRQn);                       /* ʹ��UART�ж�ͨ�� */
//        
//        __HAL_UART_ENABLE_IT(huart, UART_IT_RXNE);                      /* ʹ��UART�����ж� */
//    }
//}

/**
 * @brief       Rx����ص�����
 * @param       huart: UART�������ָ��
 * @retval      ��
 */
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//    if(huart->Instance == USART1)                             /* ����Ǵ���1 */
//    {
//        if((g_usart_rx_sta & 0x8000) == 0)                    /* ����δ��� */
//        {
//            if(g_usart_rx_sta & 0x4000)                       /* ���յ���0x0d */
//            {
//                if(g_rx_buffer[0] != 0x0a) 
//                {
//                    g_usart_rx_sta = 0;                       /* ���մ���,���¿�ʼ */
//                }
//                else 
//                {
//                    g_usart_rx_sta |= 0x8000;                 /* ��������� */
//                }
//            }
//            else                                              /* ��û�յ�0X0D */
//            {
//                if(g_rx_buffer[0] == 0x0d)
//                {
//                    g_usart_rx_sta |= 0x4000;
//                }
//                else
//                {
//                    g_usart_rx_buf[g_usart_rx_sta & 0X3FFF] = g_rx_buffer[0] ;
//                    g_usart_rx_sta++;
//                    if(g_usart_rx_sta > (USART_REC_LEN - 1))
//                    {
//                        g_usart_rx_sta = 0;                   /* �������ݴ���,���¿�ʼ���� */
//                    }
//                }
//            }
//        }
//    }
//}

/**
 * @brief       ����1�жϷ�����
 * @param       ��
 * @retval      ��
 */
void USART_UX_IRQHandler(void)
{ 
    uint32_t timeout = 0;
    uint32_t maxDelay = 0x1FFFF;
    
#if SYS_SUPPORT_OS                        /* ʹ��OS */
    OSIntEnter();    
#endif

    HAL_UART_IRQHandler(&g_uart1_handle); /* ����HAL���жϴ������ú��� */

    timeout = 0;
    while (HAL_UART_GetState(&g_uart1_handle) != HAL_UART_STATE_READY) /* �ȴ����� */
    {
        timeout++;                       /* ��ʱ���� */
        if(timeout > maxDelay)
        {
            break;
        }
    }
     
    timeout=0;
    
    /* һ�δ������֮�����¿����жϲ�����RxXferCountΪ1 */
    while (HAL_UART_Receive_IT(&g_uart1_handle, (uint8_t *)g_rx_buffer, RXBUFFERSIZE) != HAL_OK)
    {
        timeout++;                  /* ��ʱ���� */
        if (timeout > maxDelay)
        {
            break;
        }
    }

#if SYS_SUPPORT_OS                  /* ʹ��OS */
    OSIntExit();
#endif

}

#endif


 

 



