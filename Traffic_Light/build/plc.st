TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM TrafficLights
  VAR
    Input : BOOL;
    RedN : BOOL;
    YellowN : BOOL;
    GreenN : BOOL;
    RedS : BOOL;
    YellowS : BOOL;
    GreenS : BOOL;
    M0 : BOOL;
    TP0 : TP;
    TP1 : TP;
    TP2 : TP;
    TP3 : TP;
  END_VAR

  TP0(IN := NOT(M0) AND Input, PT := T#5s);
  RedN := TP0.Q;
  TP1(IN := M0 OR NOT(GreenN) AND NOT(RedN) AND Input, PT := T#2s);
  YellowN := TP1.Q;
  TP2(IN := NOT(RedN) AND NOT(YellowN) AND Input, PT := T#5s);
  GreenN := TP2.Q;
  TP3(IN := NOT(RedN) AND NOT(YellowN) AND NOT(GreenN) AND Input, PT := T#2s);
  M0 := TP3.Q;
  GreenS := TP0.Q;
  YellowS := TP1.Q;
  RedS := TP2.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : TrafficLights;
  END_RESOURCE
END_CONFIGURATION
