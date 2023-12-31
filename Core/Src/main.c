/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "DS1302.h"
#include "Digit.h"
#include "delay.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

uint8_t show_data[4]={0};
uint8_t tim1_flag=0,clk_s=0,change_flag=0,isBeep=0,isAlarm=0,isAlarmOn=0;
uint8_t state=0,state_changed=0,isSettingAlarm=0;
uint8_t index=0;
extern struct TIMEData TimeData;
uint8_t set_minute=0,set_hour=0;
uint8_t alarm_hour=0,alarm_minute=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
     u8 min=0;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  

     delay_init(72);
//     ds1302_init();  
    delay_ms(5);
     ds1302_read_realTime();
     min=TimeData.minute;
     show_data[3]=TimeData.minute%10+0x30;
     show_data[2]=TimeData.minute/10+0x30;
     show_data[1]=TimeData.hour%10+0x30;
     show_data[0]=TimeData.hour/10+0x30;
     
     delay_ms(5);
       HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//       HAL_Delay(1000);
//       HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
       if(state_changed){
            state_changed=0;
//            isBeep=1;
            set_minute=TimeData.minute;
            set_hour=TimeData.hour;    
       }
       if(isAlarm) state=7;
       
     switch(state){
          case 0:  

                    show_data[3]=TimeData.minute%10+0x30;
                    show_data[2]=TimeData.minute/10+0x30;
                    show_data[1]=TimeData.hour%10+0x30;
                    show_data[0]=TimeData.hour/10+0x30;      //state 0  显示当前时间
           
          break;
          case 1:                                        // state1 校准小时
               
              if(tim1_flag){
                    show_data[3]=TimeData.minute%10+0x30;
                    show_data[2]=TimeData.minute/10+0x30;
                   show_data[1]=set_hour%10+0x30;
                    show_data[0]=set_hour/10+0x30;
              } 
              else {
                   show_data[3]=TimeData.minute%10+0x30;
                    show_data[2]=TimeData.minute/10+0x30;
                  show_data[1]=0;
                    show_data[0]=0;
              
              }
              if(change_flag==1) set_hour=(set_hour+1)%24;
              else  if(change_flag==2) {
                   set_hour=(set_hour==0)?(23):(set_hour-1);
                   
              }
              change_flag=0;
              
              ds1302_write_time(set_hour,TimeData.minute);
              
          break;
          case 2:                             //state2 校准分钟
               if(tim1_flag){
                    show_data[1]=TimeData.hour%10+0x30;
                    show_data[0]=TimeData.hour/10+0x30;
                   show_data[3]=set_minute%10+0x30;
                    show_data[2]=set_minute/10+0x30;
              } 
              else {
                   show_data[1]=TimeData.hour%10+0x30;
                    show_data[0]=TimeData.hour/10+0x30;
                  show_data[3]=0;
                    show_data[2]=0;
              
              }
              if(change_flag==1) set_minute=(set_minute+1)%60;
              else  if(change_flag==2) {
                   set_minute=(set_minute==0)?(59):(set_minute-1);
                   
              }
              change_flag=0;
              
              ds1302_write_time(TimeData.hour,set_minute);
               
          break;
          case 4:
               if(tim1_flag){
                    show_data[3]=TimeData.minute%10+0x30;
                    show_data[2]=TimeData.minute/10+0x30;
                   show_data[1]=alarm_hour%10+0x30;
                    show_data[0]=alarm_hour/10+0x30;
              } 
              else {
                   show_data[3]=TimeData.minute%10+0x30;
                    show_data[2]=TimeData.minute/10+0x30;
                  show_data[1]=0;
                    show_data[0]=0;
              
              }
              if(change_flag==1) alarm_hour=(alarm_hour+1)%24;
              else  if(change_flag==2) {
                   alarm_hour=(alarm_hour==0)?(23):(alarm_hour-1);
                   
              }
              change_flag=0;
          break;
          case 5:
                if(tim1_flag){
                    show_data[1]=TimeData.hour%10+0x30;
                    show_data[0]=TimeData.hour/10+0x30;
                   show_data[3]=alarm_minute%10+0x30;
                    show_data[2]=alarm_minute/10+0x30;
              } 
              else {
                   show_data[1]=TimeData.hour%10+0x30;
                    show_data[0]=TimeData.hour/10+0x30;
                  show_data[3]=0;
                    show_data[2]=0;
              
              }
              if(change_flag==1) alarm_minute=(alarm_minute+1)%60;
              else  if(change_flag==2) {
                   alarm_minute=(alarm_minute==0)?(59):(alarm_minute-1);
                   
              }
              change_flag=0;
          break;
              
          case 7:
              if(tim1_flag){
                    show_data[1]=TimeData.hour%10+0x30;
                    show_data[0]=TimeData.hour/10+0x30;
                   show_data[3]=TimeData.minute%10+0x30;
                    show_data[2]=TimeData.minute/10+0x30;
              } 
              else {
                   show_data[1]=0;
                    show_data[0]=0;
                  show_data[3]=0;
                    show_data[2]=0;
              
              }
              isBeep=8;
              if(!isAlarm) state=0;
          break;
    }
     
    
     
//                   show_num(1,show_data[0]);
//                   show_num(2,show_data[1]);
//                   show_num(3,show_data[2]);
//                   show_num(4,show_data[3]);

       
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htim);
   if(htim==&htim2){
          ds1302_read_realTime();    //读取此时时刻
        index=(index+1)%4;
        show_num(index+1,show_data[index]);
        if(isAlarmOn&&TimeData.hour==alarm_hour&&TimeData.minute==alarm_minute) isAlarm=1;
        if(isBeep){
          
          HAL_GPIO_WritePin(BEEP_GPIO_Port,BEEP_Pin,GPIO_PIN_SET);
             isBeep=isBeep-1;
        }
        else HAL_GPIO_WritePin(BEEP_GPIO_Port,BEEP_Pin,GPIO_PIN_RESET);
   
   }

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);
   if(GPIO_Pin==KEY1_Pin){
        delay_ms(10);
        if(HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)==GPIO_PIN_RESET){
      state++;
        if(state==3||state==6) state=0;
        state_changed=1;
        isBeep=1;
             
        }     
   
   }
   if(GPIO_Pin==KEY2_Pin){
                delay_ms(10);
        if(HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin)==GPIO_PIN_RESET){
        if(state!=0)  
             change_flag=1;  //加
        else {
          state=4;
          state_changed=1;
          isBeep=5;
        }
   }
   
   }
   if(GPIO_Pin==KEY0_Pin){
                delay_ms(10);
        if(HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin)==GPIO_PIN_RESET){
        
        if(state==7){
          isAlarm=0;
          isAlarmOn=0;
        } 
        else if (state==0){
          isAlarmOn=!isAlarmOn;
        
        } else  change_flag=2;   //减

   }
   
   }
   
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
