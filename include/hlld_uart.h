#ifndef HLLD_UART_H_INCLUDED
#define HLLD_UART_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

   void hlld_uart2_init(int baudrate); 

   void hlld_uart2_puts(const char* string); 

#ifdef __cplusplus
}
#endif

#endif
