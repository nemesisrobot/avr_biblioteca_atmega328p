#include "configuracao.h"
#include "definicoes_textos.h"
#include "analogica.h"
#include <avr/io.h>
#include <util/delay.h>

int leitura_analogica(int porta_analogica){

    int valor=0;
    
    ADMUX = porta_analogica;
    ADMUX |=(1 << REFS0);
    ADMUX &=~(1 << ADLAR);

    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    ADCSRA |= (1 << ADEN); //Habilitando canal adc
    ADCSRA |= (1 << ADSC); //Faz a conversão do sinal

    while(ADCSRA & (1 << ADSC));//espera a leitura ser finalizada

    valor = ADCL;
    valor = (ADCH << 8 ) + valor;

    return valor;

}