#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM TRAFFICLIGHTS
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INPUT)
  __DECLARE_VAR(BOOL,REDN)
  __DECLARE_VAR(BOOL,YELLOWN)
  __DECLARE_VAR(BOOL,GREENN)
  __DECLARE_VAR(BOOL,REDS)
  __DECLARE_VAR(BOOL,YELLOWS)
  __DECLARE_VAR(BOOL,GREENS)
  __DECLARE_VAR(BOOL,M0)
  TP TP0;
  TP TP1;
  TP TP2;
  TP TP3;

} TRAFFICLIGHTS;

void TRAFFICLIGHTS_init__(TRAFFICLIGHTS *data__, BOOL retain);
// Code part
void TRAFFICLIGHTS_body__(TRAFFICLIGHTS *data__);
#endif //__POUS_H
