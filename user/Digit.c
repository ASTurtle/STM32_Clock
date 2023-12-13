
#include "Digit.h"



extern uint8_t tim1_flag,clk_s;
/**
  * @brief  对四个数码管中指定的一个显示指定数字（字母）
  *
  * @note   
  *         
  *         
  *
  * @param  bit:哪一位数码管，值可以为：1,2,3,4
  * @param  num：要显示的数字，注意值应为字符形式，'0'、'1'、'2'、'3'、'4'、'5'、'6'、'7'、'8'、'9'、'A'、'C'、'E'、'F'
  *          

  * @retval None
  */
void show_num(uint8_t bit,uint8_t num){
     
     
     switch(bit){
           case 4:
             HAL_GPIO_WritePin(COM1_GPIO_Port,COM1_Pin,GPIO_PIN_RESET);
             HAL_GPIO_WritePin(COM2_GPIO_Port,COM2_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(COM3_GPIO_Port,COM3_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(COM4_GPIO_Port,COM4_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(DP_GPIO_Port,DP_Pin,GPIO_PIN_SET);
           break;
           case 3:
             HAL_GPIO_WritePin(COM2_GPIO_Port,COM2_Pin,GPIO_PIN_RESET);
             HAL_GPIO_WritePin(COM1_GPIO_Port,COM1_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(COM3_GPIO_Port,COM3_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(COM4_GPIO_Port,COM4_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(DP_GPIO_Port,DP_Pin,tim1_flag);
           break;
           case 2:
             HAL_GPIO_WritePin(COM3_GPIO_Port,COM3_Pin,GPIO_PIN_RESET);
             HAL_GPIO_WritePin(COM2_GPIO_Port,COM2_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(COM1_GPIO_Port,COM1_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(COM4_GPIO_Port,COM4_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(DP_GPIO_Port,DP_Pin,tim1_flag);
           break;
           case 1:
             HAL_GPIO_WritePin(COM4_GPIO_Port,COM4_Pin,GPIO_PIN_RESET);
             HAL_GPIO_WritePin(COM2_GPIO_Port,COM2_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(COM3_GPIO_Port,COM3_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(COM1_GPIO_Port,COM1_Pin,GPIO_PIN_SET);
           HAL_GPIO_WritePin(DP_GPIO_Port,DP_Pin,GPIO_PIN_SET);
           break;
           default:
             HAL_GPIO_WritePin(COM4_GPIO_Port,COM4_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(COM2_GPIO_Port,COM2_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(COM3_GPIO_Port,COM3_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(COM1_GPIO_Port,COM1_Pin,GPIO_PIN_SET);
             HAL_GPIO_WritePin(DP_GPIO_Port,DP_Pin,GPIO_PIN_SET);
           break;
          }
     HAL_Delay(1);
     

     
     
     
     if(bit<3){
          
          switch(num){
               case '0':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_SET);
               break;
               case '1':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_SET);
               break;
               case '2':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case '3':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case '4':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case '5':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case '6':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case '7':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_SET);
               break;
               case '8':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case '9':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case 'A':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case 'C':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_SET);
               break;
               case 'E':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case 'F':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               default:
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_SET);
               break;
         
          }
     } else if(bit>=3){
          switch(num){
               case '0':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_SET);
               break;
               case '1':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_SET);
               break;
               case '2':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case '3':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case '4':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case '5':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case '6':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case '7':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_SET);
               break;
               case '8':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case '9':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case 'A':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case 'C':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_SET);
               break;
               case 'E':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               case 'F':
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_RESET);
               break;
               default:
                    HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_SET);
               break;
          
          
          
          }  
     
     }
     HAL_Delay(1);
     HAL_GPIO_WritePin(A_GPIO_Port,A_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(B_GPIO_Port,B_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(C_GPIO_Port,C_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(D_GPIO_Port,D_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(E_GPIO_Port,E_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(F_GPIO_Port,F_Pin,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(G_GPIO_Port,G_Pin,GPIO_PIN_SET);


}