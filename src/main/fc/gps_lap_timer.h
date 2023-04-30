/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Betaflight. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "io/gps.h"

#include "pg/pg.h"

#define MAX_N_RECORDED_PREVIOUS_LAPS 3

typedef struct gpsLapTimerData_s {
    gpsLocation_t gateLocation;
    uint32_t previousLaps[MAX_N_RECORDED_PREVIOUS_LAPS];
    uint32_t currentLapTime;
    uint16_t numberOfSetReadings;
    uint32_t bestLapTime;
    uint32_t best3Consec;
    uint32_t distToPoint;
    int32_t dirToPoint;
    bool timerRunning;
    uint32_t timeOfLastLap;
} gpsLapTimerData_t;

typedef struct gpsLapTimerConfig_s {
    int32_t gateLat;
    int32_t gateLon;
    uint16_t minimumLapTimeSeconds;
    uint8_t gateTolerance;
} gpsLapTimerConfig_t;

PG_DECLARE(gpsLapTimerConfig_t, gpsLapTimerConfig);

extern gpsLapTimerData_t gpsLapTimerData;

void gpsLapTimerInit(void);
void lapTimerNewGpsData(void);
void gpsLapTimerStartSetGate(void);
void gpsLapTimerEndSetGate(void);
