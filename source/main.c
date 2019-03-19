#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_utils.h"

void gpioa_pin_wo_init(uint8_t pin){
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    LL_GPIO_InitTypeDef gpio;
    LL_GPIO_StructInit(&gpio);
    gpio.Pin = (0x01 << pin);
    gpio.Mode = LL_GPIO_MODE_OUTPUT;
    LL_GPIO_Init(GPIOA, &gpio);
}

void write_pa5(int8_t state){
     LL_GPIO_SetOutputPin(GPIOA, (state ? 0x1 << 5 : (0x1 << (16 + 5))));
}

int main(){
    gpioa_pin_wo_init(5);
    LL_Init1msTick(16000000);
    
    while(1){
        LL_mDelay(500);
        write_pa5(0);
        LL_mDelay(500);
        write_pa5(1);
    }
}
