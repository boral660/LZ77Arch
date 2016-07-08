#include "stdafx.h"
#include <fstream>

/*!
* Проверить корректность аргументов командной строки 
* \param[in] argsCount Количество аргументов командной строки
* \param[in] argsMass Аргументы командной строки
* \return 0 - при некорректных аргументах, 1 - при аргументе упаковки, 2 - при аргументе распаковки
*/
int checkArguments(int argsCount, char* argsMass[]);

/*!
* Выгрузить N байт файла в массив
* \param[in] file Дескриптор файла, из которого необходимо выгрузить информацию
* \param[out] inputMass Массив, в который необходимо выгрузить информацию
* \param[in] bytesCount Количество байт, которое необходимо выгрузить из файла
* \return Настоящее количество выгруженных байт
*/
int loadInfoFromFile(FILE* file, char* inputMass, int bytesCount);

/*!
* Запаковать содержимое
* \param[in] data Данные для запаковки
* \param[in] outputFile Дескриптор файла, в который будут сжаты данные
* \return Коэффициент сжатия
*/
double pack(char* data, FILE* outputFile);

/*!
* Сжать содержимое массива размером  N по алгоритму
* \param[in] data Данные для сжатия
* \param[in] dataSize Размер данных для сжатия
* \param[in] outputFile Дескриптор файла, в который будут сжаты данные
* \param[in] logFile Дескриптор файла, в который будет записываться информация об операциях
* \return Размер данных после сжатия
*/
int compressData(char* data, int dataSize, FILE* outputFile, FILE* logFile);

/*!
* Записать код сжатия в выходной файл
* \param[in] code Код сжатия
* \param[in] outputFile Дескриптор файла, в который будут сжаты данные
* \return Количество записанных байт
*/
int addCompressCodeToFile(char* code, FILE* outputFile);

/*!
* Записать лог операции в специальный файл
* \param[in] logString Строка, содержащая лог операции
* \param[in] logFile Дескриптор файла, в который будет записываться информация об операциях
*/
void addStringToLog(char* logString, FILE* logFile);

/*!
* Распаковать содержимое
* \param[in] inputFile Дескриптор файла, в котором хранятся данные для распаковки
* \param[out] unpackedData Распакованные данные
* \return Коэффициент распаковки
*/
double unpack(FILE* inputFile, char* unpackedData);

/*!
* Обработать код сжатия и добавить распакованную информацию в массив
* \param[in] inputFile Дескриптор файла, в котором хранятся данные для распаковки
* \param[out] unpackedData Распакованные данные
* \param[in] logFile Дескриптор файла, в который будет записываться информация об операциях
* \return Размер данных после распаковки
*/
int translateCompressedData (FILE* inputFile, char* unpackedData, FILE* logFile);