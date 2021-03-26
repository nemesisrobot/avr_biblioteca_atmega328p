/*************************************************
 * Autor:Diego Silva
 * Data:26/03/2021
 * Descrição:arquivos com configuração de hardware
**************************************************/

#define F_CPU 16000000
#define BAUD 9600
#define BRC ((F_CPU/16/BAUD)-1)
#define BUFFER_TEXTOS 100