#include "stm32f4xx_ll_utils.h"
#include "hlld_uart.h"
#include "math.h"
#include "serial_stdio.h"

#define PI 3.14159265f
#define delta_t 0.1f
int main(){
    LL_Init1msTick(16000000);
    hlld_uart2_init(9600);
    float t = 0;
    float P = 0;
    float T = 0;
    float H = 0;
    
    while(1){
        t += delta_t;
        P = 600 + 500 * sin(t*PI);
        T = 20 + 25 * sin(t*PI*0.5f);
        H = 70 + 20 * sin(t*PI*0.25f);
        serial_printf(hlld_uart2_puts, "$P,%.2f,T,%.2f,H,%.2f,*64\n",P, T, H);
        LL_mDelay(500);
    }
}
