void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void TRAFFICLIGHTS_init__(TRAFFICLIGHTS *data__, BOOL retain) {
  __INIT_VAR(data__->INPUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REDN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->YELLOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GREENN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->REDS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->YELLOWS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GREENS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M0,__BOOL_LITERAL(FALSE),retain)
  TP_init__(&data__->TP0,retain);
  TP_init__(&data__->TP1,retain);
  TP_init__(&data__->TP2,retain);
  TP_init__(&data__->TP3,retain);
}

// Code part
void TRAFFICLIGHTS_body__(TRAFFICLIGHTS *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TP0.,IN,,(!(__GET_VAR(data__->M0,)) && __GET_VAR(data__->INPUT,)));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_VAR(data__->,REDN,,__GET_VAR(data__->TP0.Q,));
  __SET_VAR(data__->TP1.,IN,,(__GET_VAR(data__->M0,) || ((!(__GET_VAR(data__->GREENN,)) && !(__GET_VAR(data__->REDN,))) && __GET_VAR(data__->INPUT,))));
  __SET_VAR(data__->TP1.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TP_body__(&data__->TP1);
  __SET_VAR(data__->,YELLOWN,,__GET_VAR(data__->TP1.Q,));
  __SET_VAR(data__->TP2.,IN,,((!(__GET_VAR(data__->REDN,)) && !(__GET_VAR(data__->YELLOWN,))) && __GET_VAR(data__->INPUT,)));
  __SET_VAR(data__->TP2.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
  TP_body__(&data__->TP2);
  __SET_VAR(data__->,GREENN,,__GET_VAR(data__->TP2.Q,));
  __SET_VAR(data__->TP3.,IN,,(((!(__GET_VAR(data__->REDN,)) && !(__GET_VAR(data__->YELLOWN,))) && !(__GET_VAR(data__->GREENN,))) && __GET_VAR(data__->INPUT,)));
  __SET_VAR(data__->TP3.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TP_body__(&data__->TP3);
  __SET_VAR(data__->,M0,,__GET_VAR(data__->TP3.Q,));
  __SET_VAR(data__->,GREENS,,__GET_VAR(data__->TP0.Q,));
  __SET_VAR(data__->,YELLOWS,,__GET_VAR(data__->TP1.Q,));
  __SET_VAR(data__->,REDS,,__GET_VAR(data__->TP2.Q,));

  goto __end;

__end:
  return;
} // TRAFFICLIGHTS_body__() 





