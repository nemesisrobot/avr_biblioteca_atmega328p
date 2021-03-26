/***************************************************************
 * Autor:Diego Silva
 * Data:26/02/2021
 * Descrição:Implementando comunicação serial
 * ************************************************************/

#include "configuracao.h"
#include "serial.h"
#include "definicoes_textos.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>


//método para habilitar ou desabilita comunicação serial
void inicia_serial_tx(int habilita){
    //start e strop de comunicação
    UBRR0H = (BRC>>8);
    UBRR0L = BRC;

    //habilita comunicação serial
    //1 - Habilita / 0 - Desabilita
    UCSR0B = (habilita << TXEN0);

    //habilita paridade
    UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);

}


//método para escrever conteudo na porta serial
void escreve_conteudo(char texto[BUFFER_TEXTOS]){

    //loop para escrita de dados na serial
    for(int contador=0;contador<strlen(texto);contador++){
        UDR0 = texto[contador];
        _delay_ms(ESPERAESCRITA);
    }

}

//método para quebra de linha
void quebra_linha(void){
    UDR0='\r';
    _delay_ms(ESPERAESCRITA);
    UDR0='\n';
    _delay_ms(ESPERAESCRITA);
}