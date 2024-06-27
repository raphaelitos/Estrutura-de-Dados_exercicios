#ifndef _UTILS_H_
#define UTILS_H_

char *LeNome();

void DesalocaNome(char *nome);

void TratarStructNula(const char *nomeFuncao, const char *nomeVariavel);

void TratarFalhaAlocacao(const char *nomeStruct);

#endif