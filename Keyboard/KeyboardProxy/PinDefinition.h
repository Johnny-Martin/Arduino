#pragma once
#include <Arduino.h>

const uint8_t R_ROW_YELLOW 	= 4;
const uint8_t R_ROW_GREEN 	= 3;
const uint8_t R_ROW_RED 	= 2;

const uint8_t R_ROW_WHITE 	= 13;

const uint8_t& R_ROW_1 		= R_ROW_YELLOW;
const uint8_t& R_ROW_2 		= R_ROW_GREEN;
const uint8_t& R_ROW_3 		= R_ROW_RED;
const uint8_t& R_ROW_4 		= R_ROW_WHITE;

const uint8_t R_ROW_VEC[4] = {4,3,2,13};
const uint8_t L_ROW_VEC[4] = {A0,A3,A2,A1};
const uint8_t COLUMN_VEC[8] = {12,11,10,9,8,7,6,5};

const uint8_t FUN_KEY_ROW_PIN = A2;
const uint8_t FUN_KEY_COL_PIN = 9;